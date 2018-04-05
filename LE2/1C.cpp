// File for OA - UnB 2018/1
// By Giovanni M Guidini and Vitor F Dullens

// 1.c Make a program that does what 1B does, but
// allowing register size and cluster size to be informed

// File used to collect data is dummy.txt and it's filled with lorem ipsu
#include <bits/stdc++.h>
using namespace std;

int main(int argv, char** argc) {
    fstream dummy ("smile.bmp", ios::in | ios::binary);
    vector<char*> data; 
    int regSize, cluSize;
    if(argv == 3){
        regSize = stoi(string(argc[1]));
        cluSize = stoi(string(argc[2]));
    }
    else{
        printf("Usage: ./1C <regSize> <cluSize>\n");
        return 1;
    }

    // get length of file:
    dummy.seekg (0, dummy.end);
    int length = dummy.tellg(), chunks = 0;
    while(chunks < length){
            char* curr_blk = (char*) malloc(regSize);
            memset(curr_blk, 0, regSize);
            if(chunks+regSize <= length)
                dummy.read(curr_blk, regSize);
            else
                dummy.read(curr_blk, length-chunks);
            data.push_back(curr_blk);    // adds data to that block factor
            chunks += regSize;
        }

    printf("Reading finished. Total of %d blocks\n", (int) data.size());
    string filename = "OutWithSpecifics_regSize" + to_string(regSize) + ".bmp";
    fstream out (filename, ios::out | ios::binary);

    for(auto blk : data){
        out.write(blk, regSize);
    }

}
