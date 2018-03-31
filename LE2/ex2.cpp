#include <bits/stdc++.h>

using namespace std;

int main(){
    string file;
    file = "test.txt";
    fstream f(file, ios::out | ios::app);
    f << "hello world!";
    cout << "--- arquivo gerado ---" << endl;
    return 0;
}