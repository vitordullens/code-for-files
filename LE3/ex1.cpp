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
fstream arquivo;

void question(){ //lendo os dados do usuario conforme pedido
    for (int i = 0; i < 5; i++){
        system(CLEAR);
        if (i == 0) cout << "digite seu primeiro nome: ";
        else if (i == 1) cout << "digite seu ultimo nome: ";
        else if (i == 2) cout << "digite endereco: ";
        else if (i == 3) cout << "digite seu telefone: ";
        else cout << "digite seu cep: ";
        getline(cin, data[i]); // so it can read fields with space
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
        arquivo.open("out_fixedSize.txt", ios::app);
        for (int i = 0; i < 5; i++){
            if(data[i].size() < 15)
                arquivo << data[i];
            else
                arquivo << data[i].substr(0,15);
            for (int j = data[i].size(); j < 15; j++) arquivo << '-'; // hifen eh melhor para separar visualmente
        }
    } 
    else if (choice == '2'){ //utilizando a funcao size() para achar o tamanho da string
        arquivo.open("out_informSize.txt", ios::app);
        for(int i = 0; i < 5; i++) arquivo << data[i].size() << data[i];
    }
    else if (choice == '3'){
        arquivo.open("out_separator.txt", ios::app);
        char Char;
        cout << "qual caracter sera o separador: ";
        //eh possivel escolher qual o caracter separador
        cin >> Char;
        // char escolhido eh o primeiro char do registro para poder ser re-lido corretamente depois
        for (int i = 0; i < 5; i++) arquivo << Char << data[i];
    }
    else {
        arquivo.open("out_keyAttribute.txt", ios::app);
        arquivo << "Nome=" + data[0] + "|";
        arquivo << "Sobrenome=" + data[1] + "|";
        arquivo << "Address=" + data[2] + "|";
        arquivo << "Telefone=" + data[3] + "|";
        arquivo << "CEP=" + data[4];
    }
    arquivo << "\n";
    arquivo.close();
}
void showTxt(){ //mostrar ao usuario o resultado do arquivo texto gerado
    string content;
    // changed file
    string file = "out_";
    switch (choice) {
        case '1': 
            file += "fixedSize.txt";
            break;
        case '2':
            file += "informSize.txt";
            break;
        case '3':
            file += "separator.txt";
            break;
        case '4':
            file += "keyAttribute.txt";
            break;    
    }
    ifstream openfile(file);
    if (openfile.is_open()){
        while (!openfile.eof()){
            getline(openfile, content);
            cout << content << endl;
        }
    }
}

int main(){
   question();
   choose();
   writeFile();
   system(CLEAR);
   cout << "--- arquivos de saida atualizados ---" << "\n\n";
   showTxt();
}
