/* header
    blah blha
*/

#include <bits/stdc++.h>
using namespace std;

class node{
    char ch;
    int freq;
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

ostream& operator<<(ostream& os, node& n)  {  
    char out = n.getChar();
    if(out == '\n'){
        out = 1;
    }
    os << "char: " << out << " freq: " << n.getFreq();  
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
        cout << "Creating initial node - " << *pt << endl;
        trie.push(pt);
    }
    // creating the bloddy trie
    while(trie.size() > 1){
        node* left = trie.top(); trie.pop();
        node* right = trie.top(); trie.pop();
        node* parent = new node(left->getFreq() + right->getFreq(), left, right);
        cout << "Creating new node from: " << *left << " and " << *right << " result: " << *parent << endl;
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
    return freq;
}


int main(int argc, char const *argv[]){
    string file = "sample.txt";
    if (argc > 1){
        file = argv[1];
    }

    ifstream fd (file);
    map<char, int>& frequencies = makeFreq(&fd);
    node* root = makeTrie(frequencies);
    cout << "ROOT: " << *root << endl;
}
