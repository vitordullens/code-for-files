/* Estudantes: 
        Giovanni Guidini    16/0122660;
        Vitor Fernandes Dullens 16/0148260; 
   Disciplina: 
        Organizacao de Arquivos 1/2018
        
   Compiled using g++ (GCC) 7.3.1 20180312
   with flags -std=c++11 -Wall
   in Linux 4.14.30-1-MANJARO
*/

#include <stdio.h> 
#include <iostream> //comandos de E/S (cin, cout)
#include <fstream> //ler arquivos externos
#include <string> //trabalhar com strings

//define, para limpar a tela em diferentes sistemas operacionais
#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

// define utilizacao do namespace
using namespace std;

void menu() { //menu inicial
    system(CLEAR);
    printf("==============================\n");
    printf(" Concatenador de Arquvios     \n");
    printf("==============================\n");

    printf("\n\n(press ENTER to continue)\n");
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
    getchar();

    while(type < 0 or type > 4){ //tratamento de erro
        printf("--- opcao invalida, escreva uma opcao valida ---\n");
        printf("opcao: ");
        scanf("%d", &type);
        getchar();
    }
    return type; 
}

string readFile(fstream file, int mode){ //ler arquivo dependendo do comando escolhido na funcao type()
    int n;
    if(mode == 1){
        printf("Ler quantas linhas?\n");
        cin >> n;
    }
    else if(mode == 2){
        printf("Ler quantas palavras?\n");
        cin >> n;
    }
    else if(mode == 3){
        printf("Ler quantos caracteres?\n");
        cin >> n;
    }
    else{
        // arquivo inteiro == numero enorme de linhas
        n = 100000;
    }
    
    string r = "", line;
    if(mode == 1 || mode == 4){
        int i = 0;
        while(getline(file, line) && i < n){
            r += line + "\n"; // getline function removes \n from line
            i++;
        }
    }
    else if(mode == 2){
        int i = 0;
        while(i < n){
            file >> line;
            r += line + " ";
            i++;
        }
    }
    else{
        char read[n+1];
        file.get(read, n+1);
        r += string(read);
    }
    
    return r;
}

fstream openFile(string file){ // abrir arquivo
    fstream arquivo (file, ios::in);
    if(!arquivo){ //tratamento de erro
        cout << "Failed to open\n";
        return (fstream) NULL;
    }

    return arquivo;
}

string fileOP(){ //manuseio de arquivo
    string file;
    system(CLEAR);
    printf("Qual o nome do arquivo?\n");
    cin >> file;
    fstream ini = openFile(file);
    if(!ini){ //tratamento de erro
        string again;
        printf("Tentar novamente? [Y/n]\n");
        cin >> again;
        if(again == "Y" || again == "y")
            return fileOP();
        else
            return "";
    }
    
    int t = type();
    return readFile(openFile(file), t);
}

int continua(){ //segundo menu de opcoes
    printf("\nO que voce quer fazer agora?\n");
    printf("\t(1) - Adicionar outro arquivo\n");
    printf("\t(2) - Mostrar resultados\n");
    printf("\t(3) - Finalizar operacao\n");

    int type;
    scanf("%d", &type);
    getchar();
    while(type < 0 or type > 3){ //tratamento de erro
        printf("--- opcao invalida, escreva uma opcao valida ---\n");
        printf("opcao: ");
        scanf("%d", &type);
        getchar();
    }
    return type; 
}

int main(){
    menu();
    string file;
    string content = "";    
    // arquivo inicial
    content += fileOP();
    
    // menu das operacoes
    int go = continua();
    while(go != 3){
        if(go == 1){
            content += fileOP();
        }
        else{
            system(CLEAR);
            cout << content;

            printf("\n\n(press ENTER to continue)\n");
            getchar();
        }
        go = continua();
    }

    printf("Qual arquivo voce quer salvar?\n");
    cin >> file;
    fstream f (file, ios::out | ios::app);
    f << content;
    return 0;

}
