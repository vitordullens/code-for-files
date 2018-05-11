/* 
Simple c++ library to define data structures and operations necessary to
generate and use the huffman-style trie for codes in the huffman's algorithm compression.

By Giovanni Guidini and Vitor Dullens
*/

#include <bits/stdc++.h>
// value for chars in the internal nodes
#define INTERNAL_CHAR 2

namespace hufftrie {
    #define endl std::endl
    // classes
    class Huffnode{
        char ch;
        int freq;
        std::vector<bool> code;
        Huffnode* left;
        Huffnode* right;

    public:
        Huffnode(char Char, int Freq);
        Huffnode(int Freq, Huffnode* Left, Huffnode* Right);
        int getFreq();
        char getChar();
        Huffnode* getLeft();
        Huffnode* getRight();
        std::vector<bool> getCode();
        void setCode(std::vector<bool> Code);
    };

    class Compare;
    // functions
    Huffnode* getRoot();
    Huffnode* makeTrie(std::map<char,int> &freq);
    std::map<char,int>& makeFreq(std::ifstream* fd);
    void renderCodes(Huffnode* root, std::vector<bool> cd, std::map<char,Huffnode*>& codes);


    // necessary to make priority queue work right when creating trie
    class Compare {
    public:
        bool operator() (Huffnode* lhs, Huffnode* rhs){
            if (lhs->getFreq() > rhs->getFreq())
                return true;
            else
                return false;
        }
    };

        // class for the nodes in the trie - functions definitions
        // constructor for leaf nodes
        Huffnode::Huffnode(char Char, int Freq){
            ch = Char;
            freq = Freq;
            left = NULL;
            right = NULL;
        }

        // constructor for internal nodes
        Huffnode::Huffnode(int Freq, Huffnode* Left, Huffnode* Right){
            ch = INTERNAL_CHAR;
            freq = Freq;
            left = Left;
            right = Right;
        }

        // getters and setters
        int Huffnode::getFreq(){
            return freq;
        }
        char Huffnode::getChar(){
            return ch;
        }

        Huffnode* Huffnode::getLeft(){
            return left;
        }

        Huffnode* Huffnode::getRight(){
            return right;
        }

        std::vector<bool> Huffnode::getCode(){
            return code;
        }
        void Huffnode::setCode(std::vector<bool> Code){
            code = Code;
        }

/* ----------------------------- END OF HUFFNODE CLASS DEFINITION ------------------------------ */
    // to be updated once trie is created (variable of namespace)
    Huffnode* TrieRoot = NULL;

    // returns the trie root, if any exists
    Huffnode* getRoot(){
        return TrieRoot;
    }
    // create the trie of codes
    Huffnode* makeTrie(std::map<char,int> &freq){
        // priority queue to create trie
        std::priority_queue<Huffnode*, std::vector<Huffnode*>, Compare> trie;
        // initial nodes
        for (auto key: freq){
            char k = key.first;
            Huffnode* pt = new Huffnode(k, freq[k]);
            // DEBUG std::cout << "Creating initial Huffnode - " << *pt << endl;
            trie.push(pt);
        }
        // creating the bloddy trie
        while(trie.size() > 1){
            Huffnode* left = trie.top(); trie.pop();
            Huffnode* right = trie.top(); trie.pop();
            Huffnode* parent = new Huffnode(left->getFreq() + right->getFreq(), left, right);
            // DEBUG std::cout << "Creating new Huffnode from: " << *left << " and " << *right << " result: " << *parent << endl;
            trie.push(parent);
        }

        // only root Huffnode remains in queue now
        TrieRoot = trie.top(); // updates root reference inside lib
        return trie.top();
    }

    // create frequence for the characters in the file
    std::map<char,int>& makeFreq(std::ifstream* fd){
        std::string line;
        static std::map<char,int> freq;
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
    void renderCodes(Huffnode* root, std::vector<bool> cd, std::map<char,Huffnode*>& codes){
        // DEBUG cout << "Im in " << *root << " with code " << cd << endl;
        if(root->getChar() != 2){
            root->setCode(cd);
            codes[root->getChar()] = root;
            return;
        }
        
        Huffnode* l = root->getLeft();
        // DEBUG cout << "To explore next:\nLeft - " << *l << endl;
        cd.push_back(false);
        renderCodes(l, cd, codes);
        cd.pop_back();
        l = root->getRight();
        // DEBUG cout << "To explore next:\nRight - " << *l << endl;
        cd.push_back(true);
        renderCodes(l, cd, codes);
    }
}
/* ------------------------- END OF NAMESPACE Hufftrie ------------------------- */
using namespace hufftrie;


// makes it easier to print Huffnode info
std::ostream& operator<<(std::ostream& os, Huffnode& n){  
    char out = n.getChar();
    if(out == '\n'){
        out = 1;
    }
    os << "char: " << out << " freq: " << n.getFreq();  
    return os;  
    }  

// makes it easier to print the nodes codes
std::ostream& operator<<(std::ostream& os, std::vector<bool> v){
    for(bool b : v){
        os << b << " ";
    }
    return os;
}