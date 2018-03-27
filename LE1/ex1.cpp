/* Estudantes: 
        Giovanni Guidini    
        Vitor Fernandes Dullens 16/0148260; 
  Disciplina: 
        Organizacao de Arquivos 1/2018
*/

#include <stdio.h>
#include <iostream>
#include <fstream>
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



int type(){ //como que o usuario deseja concatenar os arquivos
    int type;

    printf("Concatenar:\n");
    printf("\t1 - linha por linha\n");
    printf("\t2 - palavra por palavra\n");
    printf("\t3 - char por char\n");
    printf("\t4 - arquivo por arquivo\n");
    printf("opcao: ");
    scanf("%d", &type);

    while(type < 0 or type > 4){
        printf("--- opcao inválida, escreva uma opcao válida ---\n");
        printf("opcao: ");
        scanf("%d", &type);
    }
    return type; 
}


int main(){
    string file;
    int t; 

    menu();
    t = type();

}
