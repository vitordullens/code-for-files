#include <bits/stdc++.h>

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;


void read(int id, fstream& arquivo){
    vector<string> data(10);
    vector<string> question = {"Modelo?", "Marca?", "Placa mae?", "CPU?", "GPU?", "Resolucao?", "RAM?", "Ano de lancamento?", "Tamanho do HD?", "Preco?"};
        
    cout << "## Preencha o formulario com base nas informacoes do seu Computador ##" << endl;
    arquivo << id << "|";
    for(int i=0;i<10;i++){
        cout << question[i] << "  ";
        getline(cin, data[i]) ;
        arquivo << data[i] << "|";
    }
    arquivo << endl;

}
const string currentDateTime()
{
    time_t now = time(0);
    struct tm tstruct;
    char buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}
void showResult(string str){
    string now;
    vector<string> parts = {"Registro", "Modelo", "Marca", "Placa mae", "CPU", "GPU", "Resolucao", "RAM", "Ano de lancamento", "Tamanho do HD", "Preco"};
    int count = 0, it = 0;
    while(count < 11){
        now = "";
        while(str[it] != '|'){
            now += str[it];
            it++;
        }
        cout << parts[count] << ": " << now << endl;
        count++;
        it++;
    }
}
int binSearch(vector<pair<int,int>>& idx, int low, int high, int target){
    if(low > high) return -1;
    int mid = (low+high)/2;
    if(idx[mid].first == target){
        return idx[mid].second;
    }
    else if(idx[mid].first < target){
        return binSearch(idx, mid+1, high, target);
    }
    else{
        return binSearch(idx, low, mid-1, target);
    }
}
void search( ifstream& fd, vector<pair<int, int>>& idx, bool flag = false){
    int pk;
    if (flag){
        ifstream index(".index.txt");
        string trash;
        int num, offset;
        getline(index, trash);
        while(!index.eof()){
            index >> num;
            index >> offset;
            idx.push_back(make_pair(num, offset));
        }
    }
    cout << "Informe o indice do arquivo que deseja buscar: ";
    cin >> pk;
    
    int off = binSearch(idx, 0, idx.size()-1, pk);
    if(off == -1){
        cout << "Registro nao existe\n";
    }
    else{
        fd.seekg(off);
        string content;
        getline(fd, content);
        showResult(content);
        cin.clear(); cin.ignore(INT_MAX, '\n');
        cout << "----press ENTER to continue----" << endl;
        getchar();
    }
    return;
}
void index(){
    ifstream arquivo;
    arquivo.open("computer.txt");
    fstream index;
    index.open(".index.txt", ios::in);
    string header, indexHeader;
    vector<pair<int, int>> idx;
    int offset, num, total;
    arquivo >> total;
    arquivo.seekg(0);
    getline(arquivo, header);
    getline(index, indexHeader);
    
    index.close();
    
    if(header == indexHeader){
        search(arquivo, idx, true);
        return;
    }
    else
        while(!arquivo.eof() && num < total){
            offset = arquivo.tellg();
            arquivo >> num;
            idx.push_back(make_pair(num, offset));
            getline(arquivo, indexHeader);            
        }

    index.open(".index.txt", ios::out);
    index << header << endl;
    for(auto q : idx) {
        index << q.first << " " << q.second << " ";
    }
    index.close();
    arquivo.seekg(0);
    search(arquivo, idx);
}
void intro(){
    system(CLEAR);
    printf("#################################\n");
    printf("#         LE6 Exercise 4        #\n");
    printf("#################################\n");
    printf("#     Aluno: Vitor Dullens      #\n");
    printf("#    Matrícula: 16/0148260      #\n");
    printf("#                               #\n");
    printf("#   Aluno: Giovanni Guidini     #\n");
    printf("#    Matrícula: 16/0122660      #\n");
    printf("#################################\n");
    getchar();
    system(CLEAR);
}

int menu(){
    int op;
    system(CLEAR);
    cout << "1 - inserir um novo computador" << endl;
    cout << "2 - buscar um computador" << endl;
    cout << "3 - sair" << endl;
    cin >> op;
    getchar();
    while(op<1 or op>3) menu();
    return op;
}

int main(){
    intro();
    int header;
    string time;
    char traco;
    string op;
    bool go = true;
    fstream arquivo;
    vector<pair<int, int>> idx;
    
    arquivo.open("computer.txt", ios::in | ios::out);
    arquivo >> header >> traco >> time;
    getline(arquivo, op); // chew trailing spaces
    int opc;
    opc = menu();
    while(opc != 3){
        if(opc == 1){
            arquivo.seekp(0, arquivo.end);
            while(go){
                read(++header, arquivo);
                cout << "quer digitar outro computador? [y/n]  ";
                while(true){
                    getline(cin,op);
                    if(op[0] == 'n' or op[0] == 'N'){
                        go = false;
                        break;
                    } 
                    else if(op[0] =='y' or op[0] == 'Y') break;
                    cout << "## digite y ou n apenas:  ";
                }
            }
            time = currentDateTime();
            arquivo.seekp(0, arquivo.beg);
            arquivo << header << "-" << time << "          \n"; // extra espaces to manage growing headers
            arquivo.close(); // flush changes
        }
        else if(opc == 2){
            index();
        }
    opc = menu();

    }
    
}