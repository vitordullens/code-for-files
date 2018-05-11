/* 
    [X] Implemente o método de Huffman para compressão de dados.
    Implementação por Vitor F Dullens - 16/0148260 e Giovanni M Guidini - 16/0122660
    Código de Huffman de tamanho variável.

    Fazendo uso da biblioteca compactstorage para manipulação de bits. Copyright (C) 2012 Franz Liedke
    Fazendo uso da biblioteca hufftrie para criação da árvore de huffman. Ours.
*/

#include <bits/stdc++.h>
#include "compactstorage-master/compactstorage.h"
#include "hufftrie.hpp"
using namespace std;
namespace hft = hufftrie;

// writes trie has a stream of bits
void addTrieToFile(CompactStorage& storage, hft::Huffnode* root){
    if(root->getChar() != INTERNAL_CHAR){
        storage.writeBool(1);
        storage.writeInt(root->getChar(), 8);
        return;
    }
    // write internal node
    storage.writeBool(0);
    // explore left
    addTrieToFile(storage, root->getLeft());
    // explore Right
    addTrieToFile(storage, root->getRight());
}

string shrinkFile(map<char, hft::Huffnode*>& ref, string fileName){
    int done = 0; 
    ifstream in (fileName); // file to read from
    fileName += ".hfm"; // .hfm for huffman
    fstream fd (fileName, ios::out | ios::binary); // file to write into
    CompactStorage storage;
    // first thing in file needs to be the trie
    addTrieToFile(storage, hft::getRoot());
    char ch;
    while(in.get(ch)){      // hft::Huffnode*    code
        vector<bool> code = ref[ch]->getCode();
        // cout << "char: " << ch << " code: " << code << endl;
        done += code.size();
        for(bool b : code){
            // adds code to storage
            storage.writeBool(b);
            // cout << "written: " << done << endl;
        }
        // TODO: Relief storage for very large files by dumping it partially when number of bits
        // written is a multiple of 8. Otherwise large files will create seg fault
    }
    // last character is EOF, but get() will not get it
    // so we manually add EOF
    for(bool b : ref[EOF]->getCode()){
        storage.writeBool(b);
    }
    // dump remaining contents
    storage.dump(&fd);
    fd.close();
    // returns name of compressed file
    return fileName;
}

void testShrink(string fSmall, hft::Huffnode* root){
    ifstream fd (fSmall, ios::binary);
    CompactStorage storage;
    char byte;
    // save all file into storage, for now
    while(fd.get(byte)){
        storage.writeInt(byte, 8);
    }
    byte = 0;
    storage.reset(); // goes back to beginning of storage
    hft::Huffnode* it = root;
    while(byte != EOF){
        if(it->getChar() != INTERNAL_CHAR){
            byte = it->getChar();
            cout << byte;
            it = root;
            
            continue;
        }
        bool next = storage.readBool();
        // moves down the trie
        if(next){
            it = it->getRight();
        }
        else{
            it = it->getLeft();
        }
        
    }
    
}

// automate file compression process
int compress(string fileName){
    ifstream fd (fileName); // we know it exists because test was in main
    
    // frequence of characters
    map<char, int>& frequencies = hft::makeFreq(&fd);
    fd.close(); // no longer necessary
    // Trie of codes
    hft::Huffnode* root = hft::makeTrie(frequencies);
    // Important data containers
    vector<bool> codeCreator;
    map<char, hft::Huffnode*> refTable;
    // Extract codes from trie into refTable
    hft::renderCodes(root, codeCreator, refTable);

    // print codes in screen
    for(auto x: refTable){
        cout << "Char: " << x.first << " Value: " << x.second->getCode() << endl;
    }

    cout << "creating new file...\n";
    // created the compressed file
    fileName = shrinkFile(refTable, fileName);
    cout << "...done!\n";

    int r; // size of new file
    fd.open(fileName);
    fd.seekg(0, fd.end);
    r = fd.tellg();
    fd.close();

    return r;
}

string intro(){
    printf("#################################\n");
    printf("# Huffman Compression Algorithm #\n");
    printf("#################################\n");
    printf("#     Aluno: Vitor Dullens      #\n");
    printf("#    Matrícula: 16/0148260      #\n");
    printf("#                               #\n");
    printf("#   Aluno: Giovanni Guidini     #\n");
    printf("#    Matrícula: 16/0122660      #\n");
    printf("#################################\n");
    printf("\n\nInform name of file to compress. Leave blank to use \"sample.txt\"\n");
    string file;
    getline(cin,file); // gets entire line to allow for blank characters
    file = file.substr(0, file.find(" ")); // gets only fist word
    return file;  
}
int main(){
    system("clear");
    string file = intro();
    if (file == ""){
        file = "sample.txt";
    }

    ifstream fd (file);
    if(!fd){
        cout << "Arquivo " << file << " inexistente\n";
        return 1;
    }
    // size of original file
    int fileSize;
    fd.seekg(0, fd.end);
    fileSize = fd.tellg();
    fd.close();

    int compressedSize = compress(file);

    cout << "Size of original file:\t" << fileSize << "bytes\n";
    cout << "Size of compressed file:\t" << compressedSize << "bytes\n";
    cout << "Compression rate:\t" << 1 - ((double) compressedSize/(double) fileSize) << "%\n";
}