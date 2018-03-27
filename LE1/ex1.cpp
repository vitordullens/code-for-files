/* Estudantes: 
        Giovanni Guidini    
        Vitor Fernandes Dullens 16/0148260; 
  Disciplina: 
        Organizacao de Arquivos 1/2018
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <map>

//define para limpar a tela
#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

void menu() { //menu inicial
    system(CLEAR);
    printf("==============================\n");
    printf(" Concatenador de Arquvios .txt\n");
    printf("==============================\n");
    getchar();
}

int qnt() { //funcao para escolher quantidade de arquivos a serem concatenados
    int qnt;
    system(CLEAR);
    printf("Quantos arquivos para concatenar?  ");
    scanf("%d", &qnt);
    return qnt;
}

int type(){ //como que o usuario deseja concatenar os arquivos
    int type;
    printf("Concatenar:\n");
    printf("\t1 - linha por linha\n");
    printf("\t2 - palavra por palavra\n");
    printf("\t3 - char por char\n");
    printf("opcao: ");
    scanf("%d", &type);
    while(type < 0 or type > 3){
        printf("--- opcao inválida, escreva uma opcao válida ---\n");
        printf("opcao: ");
        scanf("%d", &type);
    }
    return type; 
}

bool open_files(vector<string> files, int qnt){
    fstream arquivos;
    while(qnt){
        printf("rola\n");
        qnt--;
    } 
        

}

int main(){
    vector <string> files;
    string file;
    int t; 
    int q;

    menu();
    q = qnt();
    t = type();
    for(int i=0; i<q; i++) {
        printf("Digite o nome do arquivo: ");
        cin >> file;
        files.push_back(file);
    
    }
    open_files(files, q);
}
