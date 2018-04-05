// File for OA - UnB 2018/1
// By Giovanni M Guidini and Vitor F Dullens

// 1.b Make a program that generates five files with the same data,
// each with a different block factor of: 
// 512B, 1/4, 1/2, 3/4 and 1 cluster.

// File used to collect data is dummy.txt and it's filled with lorem ipsu
#include <bits/stdc++.h>
#define CLUSTER 4096

using namespace std;

int main() {
    fstream dummy ("test.txt", ios::in | ios::binary);
    vector<int> blockFactor = {512, CLUSTER/4, CLUSTER/2, 3*CLUSTER/4, CLUSTER};
    vector<char*> data[5]; // 5 vectors, one for each block factor.

    // get length of file:
    dummy.seekg (0, dummy.end);
    int length = dummy.tellg(), chunks;
    for(int i = 0; i < 5; i++){
        int bfr = blockFactor[i];
        dummy.seekg(0); // returns to begin of file
        chunks = 0;
        while(chunks < length){
            char* curr_blk = (char*) malloc(bfr);
            memset(curr_blk, 0, bfr);
            
            if(chunks + bfr <= length)
                dummy.read(curr_blk, bfr);
            else
                dummy.read(curr_blk, length-chunks);
            data[i].push_back(curr_blk);    // adds data to that block factor
            chunks += bfr;
        }
    }

    printf("Blocks completed\n");
    printf("512K : %d blocks\n", (int) data[0].size());
    printf("CLUSTER/4 : %d blocks\n", (int) data[1].size());
    printf("CLUSTER/2 : %d blocks\n", (int) data[2].size());
    printf("3*CLUSTER/4 : %d blocks\n", (int) data[3].size());

    string filename = "";
    fstream out;
    for(int i = 0; i < 5; i++){
        int bfr = blockFactor[i];
        filename = "testes/out_" + to_string(bfr) + ".txt";
        out.open(filename, ios::out | ios::binary);

        // writed data from blocks to another file
        for(auto blk : data[i]){
            out.write(blk, bfr);
        }

        out.close();
    }
    
}


