#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdlib>

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

char choice; 
string name, last, address, tel, cep;
fstream arquivo("out.txt", ios::app);

void question(){ //lendo os dados do usuario conforme pedido
    system(CLEAR);
    cout << "digite seu primeiro nome: ";
    cin >> name;
    system(CLEAR);
    cout << "digite seu ultimo nome: ";
    cin >> last;
    system(CLEAR);
    cout << "digite seu endereco: ";
    cin >> address;
    system(CLEAR);    
    cout << "digite seu telefone: ";
    cin >> tel;
    system(CLEAR);    
    cout << "digite seu cep: ";
    cin >> cep;
    system(CLEAR);
}
void choose(){ //escolher atraves de linha de comando o metodo de organizacao
    system(CLEAR);
    cout << "como deseja listar os registros:" << endl;
    cout << "(1) campos de tamanho fixo" << endl;
    cout << "(2) campos de tamanho no inicio" << endl;
    cout << "(3) campos com separadores" << endl;
    cout << "(4) campos com atributo = valor" << endl;
    cin >> choice;
    while (choice != '1' and choice != '2' and choice != '3' and choice != '4'){ 
        //tratamento de erro
        printf("--- opcao invalida, escreva uma opcao valida ---\n");
        printf("opcao: ");
        cin >> choice;
    }
}
void writeFile(){ //escrever no arquivo conforme o metodo escolhido
    char Char;

    if(choice == '1'){
        char nome[15], ultimo[15], end[15], tele[15], zip[15];
        //setando previamente todos os valores dos char* para '-',
        //para evitar lixo de memoria
        memset(nome, '-', 16);
        memset(ultimo, '-', 16);
        memset(end, '-', 16);
        memset(tele, '-', 16);
        memset(zip, '-', 16);

        int i;
        //copiando arquivos das striings lidas e transformando-os em char*
        strcpy(nome, name.c_str());
        strcpy(ultimo, last.c_str());
        strcpy(end, address.c_str());
        strcpy(tele, tel.c_str());
        strcpy(zip, cep.c_str());
        for (i = 0; i <= 15; i++) arquivo << nome[i];
        for (i = 0; i <= 15; i++) arquivo << ultimo[i];
        for (i = 0; i <= 15; i++) arquivo << end[i];
        for (i = 0; i <= 15; i++) arquivo << tele[i];
        for (i = 0; i <= 15; i++) arquivo << zip[i];
    } 
    if (choice == '2'){ //utilizando a funcao size() para achar o tamanho da string
        arquivo << name.size() << name;
        arquivo << last.size() << last;
        arquivo << address.size() << address;
        arquivo << tel.size() << tel;
        arquivo << cep.size() << cep;
    }
    if (choice == '3'){
        cout << "qual caracter sera o separador: ";
        //eh possivel escolher qual o caracter separador
        cin >> Char;
        arquivo << name << Char;
        arquivo << last << Char;
        arquivo << address << Char;
        arquivo << tel << Char;
        arquivo << cep << Char;
    }
    if (choice == '4'){
        cout << "waat" << endl;

    }
    arquivo << "\n";
}
void showTxt(){ //mostrar ao usuario o resultado do arquivo texto gerado
   
}
int main(){
   question();
   choose();
   writeFile();
   system(CLEAR);
   cout << "--- arquivo out.txt ---" << "\n\n";
   showTxt();
}