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
}
void menu(){
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

int main(){
    menu();
    int header;
    string time;
    char traco;
    string op;
    bool go = true;
    fstream arquivo, arquivo2;
    
    arquivo.open("computer.txt", ios::in);
    arquivo >> header >> traco >> time;
    arquivo.close();
    
    arquivo.open("computer.txt", ios::app);
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