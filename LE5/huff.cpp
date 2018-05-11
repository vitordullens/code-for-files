/* header
    blah blha
*/

#include <bits/stdc++.h>
#include "compactstorage-master/compactstorage.h"
using namespace std;

#define DEBUG " "
class node{
    char ch;
    int freq;
    vector<bool> code;
    node* left;
    node* right;

public:
    node(char Char, int Freq){
        ch = Char;
        freq = Freq;
        left = NULL;
        right = NULL;
    }

    node(int Freq, node* Left, node* Right){
        ch = 2;
        freq = Freq;
        left = Left;
        right = Right;
    }

    int getFreq(){
        return freq;
    }
    char getChar(){
        return ch;
    }

    node* getLeft(){
        return left;
    }

    node* getRight(){
        return right;
    }
    void setCode(vector<bool> Code){
        code = Code;
    }

    vector<bool> getCode(){
        return code;
    }
};

// necessary to make priority queue work right
class Compare {
public:
    bool operator() (node* lhs, node* rhs){
        if (lhs->getFreq() > rhs->getFreq())
            return true;
        else
            return false;
    }
};

ostream& operator<<(ostream& os, node& n){  
    char out = n.getChar();
    if(out == '\n'){
        out = 1;
    }
    os << "char: " << out << " freq: " << n.getFreq();  
    return os;  
    }  

ostream& operator<<(ostream& os, vector<bool> v){
    for(bool b : v){
        os << b << " ";
    }
    return os;
}
// create the trie of codes
node* makeTrie(map<char,int> &freq){
    // priority queue to create trie
    priority_queue<node*, vector<node*>, Compare> trie;
    // initial nodes
    for (auto key: freq){
        char k = key.first;
        node* pt = new node(k, freq[k]);
        // DEBUG cout << "Creating initial node - " << *pt << endl;
        trie.push(pt);
    }
    // creating the bloddy trie
    while(trie.size() > 1){
        node* left = trie.top(); trie.pop();
        node* right = trie.top(); trie.pop();
        node* parent = new node(left->getFreq() + right->getFreq(), left, right);
        // DEBUG cout << "Creating new node from: " << *left << " and " << *right << " result: " << *parent << endl;
        trie.push(parent);
    }

    // only root node remains in queue now
    return trie.top();
}

// create frequence for the characters in the file
map<char,int>& makeFreq(ifstream* fd){
    string line;
    static map<char,int> freq;
    // only because getline() consumes the \n at end of lines
    freq['\n'] = -1; // -1 because last line will not contain a \n
    // count occurence of all characters in the file
    while(getline(*fd, line)){
        freq['\n']++;
        for(auto ch : line){
            // if char appeared before
            if(freq.count(ch)){
                freq[ch]++;  // another hit
            }
            // if char is new in map
            else{
                freq[ch] = 1;
            }
        }
    }
    freq[EOF] = 1; // last char in file
    return freq;
}

// add codes to nodes and create map of chars to nodes
void renderCodes(node* root, vector<bool> cd, map<char,node*>& codes){
    // DEBUG cout << "Im in " << *root << " with code " << cd << endl;
    if(root->getChar() != 2){
        root->setCode(cd);
        codes[root->getChar()] = root;
        return;
    }
    
    node* l = root->getLeft();
    // DEBUG cout << "To explore next:\nLeft - " << *l << endl;
    cd.push_back(false);
    renderCodes(l, cd, codes);
    cd.pop_back();
    l = root->getRight();
    // DEBUG cout << "To explore next:\nRight - " << *l << endl;
    cd.push_back(true);
    renderCodes(l, cd, codes);
}

void shrinkFile(map<char, node*>& ref, string fileName){
    int done = 0;
    ifstream in (fileName); // file to read from
    fileName += ".hfm"; // .hfm for huffman
    fstream fd (fileName, ios::out | ios::binary); // file to write into
    CompactStorage storage;
    char ch;
    while(in.get(ch)){      // node*    code
        vector<bool> code = ref[ch]->getCode();
        // cout << "char: " << ch << " code: " << code << endl;
        done += code.size();
        for(bool b : code){
            // adds code to storage
            storage.writeBool(b);
            // cout << "written: " << done << endl;
        }
    }
    // last character is EOF, but get() will not get it
    // so we manually add EOF
    for(bool b : ref[EOF]->getCode()){
        storage.writeBool(b);
    }
    // finally, creates new file
    DEBUG storage.dump();
    storage.dump(&fd);
    fd.close();

}

void testShrink(string fSmall, node* root){
    ifstream fd (fSmall | ios:::binary);
    CompactStorage storage;
    char byte;
    while(fd.get(byte)){
        storage.add(byte, 8);
    }
    DEBUG storage.dump();
}
int main(int argc, char const *argv[]){
    string file = "sample.txt";
    if (argc > 1){
        file = argv[1];
    }

    ifstream fd (file);
    map<char, int>& frequencies = makeFreq(&fd);
    fd.close(); // no longer necessary (yet)
    node* root = makeTrie(frequencies);
    vector<bool> codeCreator;
    map<char, node*> refTable;
    // save codes to nodes
    renderCodes(root, codeCreator, refTable);
    for(auto x: refTable){
        cout << "Char: " << x.first << " Value: " << x.second->getCode() << endl;
    }
    cout << "creating new file\n";
    shrinkFile(refTable, file);
}