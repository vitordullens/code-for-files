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

/* ================================ COMPRESSING FILE =================================*/
// writes trie has a stream of bits
void addTrieToFile(CompactStorage& storage, hft::Huffnode* root){
    cout << "Node: " << *root << endl;
    if(root->getChar() != INTERNAL_CHAR){
        storage.writeBool(1);
        storage.writeInt(root->getChar(), 8);
        return;
    }
    // write internal node
    storage.writeBool(0);
    cout << "The trie: " << endl;
    storage.dump();
    // explore left
    addTrieToFile(storage, root->getLeft());
    // explore Right
    addTrieToFile(storage, root->getRight());

    cout << "The trie: " << endl;
    storage.dump();
}

string shrinkFile(map<char, hft::Huffnode*>& ref, string fileName){
    int done = 0; 
    ifstream in (fileName); // file to read from
    fileName += ".hfm"; // .hfm for huffman
    fstream fd (fileName, ios::out | ios::binary); // file to write into
    CompactStorage storage;
    // first thing in file needs to be the trie
    addTrieToFile(storage, hft::getRoot());
    // storage.dump(); // DEBUG
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
    for(bool b : ref[EOT]->getCode()){
        storage.writeBool(b);
    }
    // dump remaining contents
    storage.dump(&fd);
    fd.close();
    // returns name of compressed file
    return fileName;
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

/* ================================ COMPRESSING FILE END =================================*/
/* ================================ DECOMPRESSING FILE =================================*/
void reWrite(CompactStorage& storage){
    int byte = storage.curByte();
    storage.reset();
    vector<char> content;
    while(byte >= 0){
        content.push_back(storage.readInt(8));
        byte--;
    }
    byte = storage.curByte();
    byte--;
    int i = 0;
    storage.resetHard();
    while(i <= byte){
        storage.writeInt(content[i], 8);
        i++;
    }
}

CompactStorage& readTrie(fstream& fd){
    bool done = false;
    static CompactStorage storage(5);
    char ch;
    hft::Huffnode* curr = NULL;
    while(!done){

        // cout << "Sai do for aqui\n"; // DEBUG
        // next byte to process
        if(!done){
            ch = fd.get();
            storage.resetHard();
            storage.writeInt(ch, 8);
        }
        storage.reset();
        for(int i = 0; i < 8; i++){
            // cout << "Curr Bit " << storage.curBit() << " Curr Byte " << storage.curByte() << endl; // DEBUG
            // storage.dump(); // DEBUG
            bool b = storage.readBool();
            if(b){
                // cout << "Leaf node\n" << endl; // DEBUG
                // rewrite storage
                int byte = storage.curByte(); // current byte
                reWrite(storage);
                // expand with new char
                ch = fd.get();
                storage.writeInt(ch, 8);
                storage.reset(); // back to start
                storage.readInt(byte*8+i+1); // forward to curr position
                char v = storage.readInt(8);
                // cout << "v = " << (int) v << endl; // DEBUG
                hft::Huffnode* n = new hft::Huffnode(v, 0, curr);

                // cout << "Found char: " << v << endl; // DEBUG
                if(curr->getLeft() == NULL)
                    curr->setLeft(n);
                else{
                    curr->setRight(n);
                    curr = curr->getParent(); // this node is done
                }
            }
            else{
                // cout << "found internal node\n"; // DEBUG
                hft::Huffnode* now = new hft::Huffnode(curr);
                if(curr != NULL){
                    if(curr->getLeft() == NULL)
                        curr->setLeft(now);
                    else
                        curr->setRight(now);
                }
                curr = now;
            }
            if(curr->getLeft() != NULL && curr->getRight() != NULL){
                done = true;
                break;
            }
        }
    }
    // get the root of the trie and set it
    while(curr->getParent() != NULL){
        curr = curr->getParent();
    }
    hft::setRoot(curr);
    // cout << "returning trie. Storage: " << endl; // DEBUG
    // storage.dump(); // DEBUG
    return storage;
}

// DEBUG
void showTrie(hft::Huffnode* root){
    cout << *root << " " << root->getLeft() << " " << root->getRight() << endl;
    if(root->getLeft() != NULL)
        showTrie(root->getLeft());
    if(root->getRight() != NULL)
        showTrie(root->getRight());
}
// write to stdout
void readFile(fstream& in, hft::Huffnode* root, CompactStorage& storage){
    int i = storage.curBit();
    hft::Huffnode* it = root;
    char out = 0;
    char read;
    // file to be read
    while(out != EOT){
        // storage.dump(); // DEBUG
        // getchar(); // DEBUG
        // next byte to read
        while(i < 8){
            // cout << "Curr Bit " << storage.curBit() << " Curr Byte " << storage.curByte() << endl; // DEBUG
            i++;
            bool b = storage.readBool();
            // cout << b << endl; // DEBUG
            // cout << *it << endl; // DEBUG
            // getchar(); // DEBUG
            if(b){
                it = it->getRight();
            }
            else{
                it = it->getLeft();
            }
            out = it->getChar();
            if(out != INTERNAL_CHAR){
                if (out == EOT)
                    break;
                cout << out;
                it = root;
            }
        }
        if(out != EOT){
            storage.resetHard();
            read = in.get();
            storage.writeInt(read, 8);
            i = 0;
            storage.reset();
        }
    }
}

// write into another file
void readFile(fstream& in, hft::Huffnode* root, CompactStorage& storage, fstream& ou){
    int i = storage.curBit();
    hft::Huffnode* it = root;
    char out = 0;
    char read;
    // file to be read
    while(out != EOT){
        // next byte to read
        while(i < 8){
            i++;
            bool b = storage.readBool();
            if(b){
                it = it->getRight();
            }
            else{
                it = it->getLeft();
            }
            out = it->getChar();
            if(out != INTERNAL_CHAR){
                ou.write(&out, 1);
            }
        }
        if(out != EOF){
            i = 0;
            storage.reset();
            read = in.get();
            storage.writeInt(read, 8);
        }
    }
}

void decompress(string file, string  outFile = ""){
    CompactStorage storage;
    hft::Huffnode* root;
    fstream fd (file, ios::in);
    // created trie. Returns last byte possibly unused
    // cout << "reading trie now\n"; // DEBUG
    // getchar(); // DEBUG
    storage = readTrie(fd);
    // actual trie root
    root = hft::getRoot();
    // dumping file
    // cout << "reading trie done\n"; // DEBUG
    // showTrie(root); // DEBUG
    // getchar(); // DEBUG
    if(outFile != ""){
        fstream out (outFile, ios::out | ios::trunc);
        readFile(fd, root, storage, out);
        cout << "Done! Output in file " << outFile << endl;
    }
    else{
        cout << "Decrypting file now\n";
        readFile(fd, root, storage);
        // cout << "Fim :D\n"; // DEBUG
    }
}
/* ================================ DECOMPRESSING FILE END =================================*/
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
    /* int fileSize;
    fd.seekg(0, fd.end);
    fileSize = fd.tellg();
    fd.close(); */

    /*int compressedSize = compress(file);

    cout << "Size of original file:\t" << fileSize << "bytes\n";
    cout << "Size of compressed file:\t" << compressedSize << "bytes\n";
    cout << "Compression rate:\t" << 1 - ((double) compressedSize/(double) fileSize) << "%\n"; */
    file += ".hfm";

    decompress(file);
}