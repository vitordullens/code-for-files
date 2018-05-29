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

void copy(fstream& file1, fstream& file2, bool aux){
    string content = "";
    while(file1.eof()!=true)
        content += file1.get();
    content.erase(content.end()-1);
    int i=0;
    if(aux)
        content.erase(0,content.find("\n"));
    file2 << content;
}
void tratamento(fstream& arquivo, fstream& arquivo2, int header, char traco, string time){
    arquivo.open("computer.txt", ios::in);
    arquivo2.open("header.txt", ios::out);

    arquivo2 << header << traco << time;
    copy(arquivo, arquivo2, true);
    arquivo.close();
    arquivo2.close();

    arquivo.open("computer.txt", ios::out);
    arquivo2.open("header.txt", ios::in);

    copy(arquivo2, arquivo, false);

    arquivo.close();
    arquivo2.close();
    system("rm header.txt");
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
void search( ifstream& fd, vector<pair<int, int>>* idx = NULL){
    int pk;
    if (idx==NULL){
        ifstream index("index.txt");
        string trash;
        int num, offset;
        getline(index, trash);
        while(!index.eof()){
            index >> num;
            index >> offset;
            idx->push_back(make_pair(num, offset));
        }
    }
    cout << "Informe o indice do arquivo que deseja buscar: ";
    cin >> pk;
    
    int off = binSearch(*idx, 0, idx->size()-1, pk);
    if(off == -1){
        cout << "Registro nao existe\n";
    }
    else{
        char enter;
        fd.seekg(off);
        string content;
        getline(fd, content);
        cout << content << endl;
        cin >> enter;
    }
    return;
}
vector<pair<int, int>> index(){
    ifstream arquivo;
    arquivo.open("computer.txt");
    fstream index;
    index.open("index.txt", ios::in);
    string header, indexHeader;
    vector<pair<int, int>> idx;
    int offset, num;

    getline(arquivo, header);
    getline(index, indexHeader);
    
    if(header == indexHeader) search(arquivo);
    else
        while(!arquivo.eof()){
            offset = arquivo.tellg();
            arquivo >> num;
            idx.push_back(make_pair(num, offset));
            getline(arquivo, indexHeader);            
        }
    index.close();

    index.open("index.txt", ios::out);
    index << header << endl;
    for(auto q : idx) {
        index << q.first << " " << q.second << " ";
    }
    index.close();

    return idx;
    
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
    fstream arquivo, arquivo2;
    vector<pair<int, int>> idx;
    
    arquivo.open("computer.txt", ios::in);
    arquivo >> header >> traco >> time;
    arquivo.close();
    
    arquivo.open("computer.txt", ios::app);
    int opc;
    opc = menu();
    while(opc != 3){
        if(opc == 1){
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
            arquivo.close();
            time = currentDateTime();
            tratamento(arquivo, arquivo2, header, traco, time);
        }
        if(opc == 2){
            idx = index();
            ifstream file ("computer.txt");
            search(file , &idx);
        }
    opc = menu();

    }
    
}