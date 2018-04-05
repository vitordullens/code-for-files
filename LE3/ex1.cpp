#include <bits/stdc++.h>

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

int choice;
string name, last, address, tel, cep;

void question(){
    system(CLEAR);
    cout << "digite seu primeiro nome: ";
    cin >> name;
    system(CLEAR);
    cout << "digite seu ultimo nome: ";
    cin >> last;
    system(CLEAR);
    /*
    cout << "digite seu endereco: ";
    cin >> address;
    system(CLEAR);    
    cout << "digite seu telefone: ";
    cin >> tel;
    system(CLEAR);    
    cout << "digite seu cep: ";
    cin >> cep;
    system(CLEAR);    
    */
}
void choose(){
    system(CLEAR);
    cout << "como deseja listar os registros:" << endl;
    cout << "(1) campos de tamanho fixo" << endl;
    cout << "(2) campos de tamanho no inicio" << endl;
    cout << "(3) campos com separados" << endl;
    cout << "(4) campos com atributo = valor" << endl;
    cin >> choice;
    while (choice < 0 or choice > 4){ //tratamento de erro
        printf("--- opcao invalida, escreva uma opcao valida ---\n");
        printf("opcao: ");
        cin >> choice;
    }
}
void listReg(){
    if(choice == 1) 
        cout << "1" << endl;
    if (choice == 2)
        cout << "2" << endl;
    if (choice == 3)
        cout << "3" << endl;
    if (choice == 4)
        cout << "4" << endl;
}
int main(){
   question();
   choose();
   listReg();
}