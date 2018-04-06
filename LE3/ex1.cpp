#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdlib>
#include <vector>

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

char choice; 
vector<string> data(5);
fstream arquivo("out.txt", ios::app);

void question(){ //lendo os dados do usuario conforme pedido
    for (int i = 0; i < 5; i++){
        system(CLEAR);
        if (i == 0) cout << "digite seu primeiro nome: ";
        else if (i == 1) cout << "digite seu ultimo nome: ";
        else if (i == 2) cout << "digite endereco: ";
        else if (i == 3) cout << "digite seu telefone: ";
        else cout << "digite seu cep: ";
        cin >> data[i];
    }
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
    if(choice == '1'){
        for (int i = 0; i < 5; i++){
            arquivo << data[i];
            for (int j = data[i].size(); j < 15; j++) arquivo << '0';
        }
    } 
    if (choice == '2'){ //utilizando a funcao size() para achar o tamanho da string
        for(int i = 0; i < 5; i++) arquivo << data[i].size() << data[i];
    }
    if (choice == '3'){
        char Char;
        cout << "qual caracter sera o separador: ";
        //eh possivel escolher qual o caracter separador
        cin >> Char;
        for (int i = 0; i < 5; i++) arquivo << Char << data[i];
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