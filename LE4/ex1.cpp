// Partindo de uma imagem no format DICOM (.dcm), desenvolver um programa em c ou c++ 
// para extrair os metadados de imagem.Fazer isto para mais de uma imagem.

// Understand how DICOM files are structured at http://dicom.nema.org/medical/Dicom/2017d/output/chtml/part10/chapter_7.html
// List of DICOM tags https://www.dicomlibrary.com/dicom/dicom-tags/
// Thorough explanation on DICOM standard: https://www.leadtools.com/help/leadtools/v19/dh/to/di-topics-basicdicomfilestructure.html
// Data Element Structure: https://www.leadtools.com/help/leadtools/v19/dh/to/di-topics-dataelementstructure.html
// All the TAGS http://dicom.nema.org/medical/dicom/current/output/pdf/part06.pdf
// Online viewer for metadata https://www.get-metadata.com/
#include <bits/stdc++.h>
#include "HeaderElements.h"

#define lsDcm() std::system("ls *.dcm")

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

HE::Element readNextMeta(ifstream* fd);
void readData(ifstream* fd, string vr, unsigned int len, HE::Element el);
// Some images have preamble followed by prefix DICM before metadata, others don't
// This functions will skip preamble if it exists.
void managePreamble(ifstream* fd){
    fd->seekg(128);
    char prefix[4];
    fd->read(prefix, 4);
    if(strcmp(prefix, "DICM") != 0){
        printf("Este arquivo não tem o preambulo!!!\n");
        fd->seekg(0);
    }
}

// A lot of problems were happening when comparing strings, so decided to do it the hard way
bool specialVR(char* vr){
    if(vr[0] == 'O'){
        if(vr[1] == 'B' || vr[1] == 'W' || vr[1] == 'F'){
            return true;
        }
    }
    else if(vr[0] == 'S' && vr[1] == 'Q'){
        return true;
    }
    else if(vr[0] == 'U'){
        if(vr[1] == 'T' || vr[1] == 'N'){
            return true;
        }
    }
    return false;
}

bool implicitVR(char* vr){
    if(vr[0] > 90 || vr[0] < 65){
        return true;
    }
    else if(vr[1] > 90 || vr[1] < 65){
        return true;
    }
    return false;
}

void readData(ifstream* fd, string vr, unsigned int len, HE::Element el){
    if(vr == "SQ" || len == (unsigned int) -1){
        // Sequência de itens sem valor definido.
        printf("Sequence of Undefined Length\n");
        HE::Element probe = HE::Element();
        while(probe.getName() != "EndOfItem" && probe.getName() != "EndOfSequence"){
            cout << "+-------------------------- Still in the loop..." << fd->tellg() << endl;
            probe = readNextMeta(fd);
        }
        return;
    }
    else if(el.getName() == "EndOfItem" || el.getName() == "EndOfSequence"){
        cout << "Found Something: " << el.getName() << endl;
        return;
    }
    else if(el.getName() == "PixelInformation-TheImage"){
        cout << "END OF METADATA\n";
        return;
    }
    char buff[len+1];
    fd->read(buff, len);
    buff[len] = '\0';
    printf("%s\n", buff);

}

// tag for pixel data (7FE0,0010) ?
HE::Element readNextMeta(ifstream* fd){
    char buff[128], vr[10];
    uint16_t tag[2];
    unsigned int len;
    fd->read(buff, 4);
    printf("buff for tag: %x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
    tag[0] =  (buff[1] << 8) | (0x00FF & buff[0]);
    tag[1] =  (buff[3] << 8) | (0x00FF & buff[2]);
    fd->read(vr, 2);

    // Dealing with cases OB, OW, OF, SQ, UT or UN for explicit VR, which have 2 reserved bytes
    if (specialVR(vr)){
        // forwards two bytes
        cout << "Forwarded 2 bytes because of specialVR\n";
        fd->read(buff, 2);

        fd->read(buff, 4);  // special values have 4 bytes of length
        len = (buff[3] << 24) | (buff[2] << 16) | (buff[1] << 8) | buff[0];
    }
    // Some cases may contain implicit vr (?)
    else if(implicitVR(vr)){
        // backwards two bytes
        cout << "Backwarded 2 bytes because of implicitVR\n";
        int curr = fd->tellg();
        fd->seekg(curr-2);
        strcpy(vr, "Implicit\0");

        fd->read(buff, 4);  // special values have 4 bytes of length
        len = (buff[3] << 24) | (buff[2] << 16) | (buff[1] << 8) | buff[0];
    }
    else{
        fd->read(buff, 2);
        len = (buff[1] << 8) | buff[0];
    }
    HE::Element specs = HE::getElement(make_pair(tag[0], tag[1]));
    printf("TAG: (%#x,%#x) - %s\n", tag[0], tag[1], specs.getName().c_str());
    printf("VR: %c%c\n", vr[0], vr[1]);
    printf("LEN: %#x\n", len);
    readData(fd, string(vr), len, specs);
    return specs;
}

int main(){
    string file;
    system(CLEAR);
    cout << "Choose a file to analyse. Options are:" << endl;
    lsDcm();
    cin >> file;
    system(CLEAR);

    cout << "File chosen: " << file << endl;
    ifstream fd (file, ios::binary);
    if(!fd){
        cout << "Error 404 - File not Found\n";
        return 1;
    }
    
    managePreamble(&fd);
    HE::makeTag();
    unsigned int g, e, i = 0;
    HE::Element prev = HE::Element();
    prev.getTag(&g, &e);
    while(!(g == 0x7FE0 && e == 0x0010)){
        prev = readNextMeta(&fd);
        cout << "------------------------+" << endl;
        prev.getTag(&g, &e);
        cout << "Tellg:" << fd.tellg() << endl;
        printf("PrevTag: %#x,%#x\n", g,e);
        i++;
    }
    
    return 0;
}
