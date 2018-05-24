#include <bits/stdc++.h>

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

fstream arquivo;

void read(int id){
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
    time_t time;
    char traco;
    string op;
    bool go = true;
    
    arquivo.open("computer.txt", ios::in);
    arquivo >> header >> traco >> time;
    arquivo.close();
    
    arquivo.open("computer.txt", ios::app);

    while(go){
        read(++header);
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

}