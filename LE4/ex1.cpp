// Partindo de uma imagem no format DICOM (.dcm), desenvolver um programa em c ou c++ 
// para extrair os metadados de imagem.Fazer isto para mais de uma imagem.

// Understand how DICOM files are structured at http://dicom.nema.org/medical/Dicom/2017d/output/chtml/part10/chapter_7.html
// List of DICOM tags https://www.dicomlibrary.com/dicom/dicom-tags/
// Thorough explanation on DICOM standard: https://www.leadtools.com/help/leadtools/v19/dh/to/di-topics-basicdicomfilestructure.html
// Data Element Structure: https://www.leadtools.com/help/leadtools/v19/dh/to/di-topics-dataelementstructure.html

// Online viewer for metadata https://www.get-metadata.com/

#include <bits/stdc++.h>
#define lsDcm() std::system("ls *.dcm")

#ifdef WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

// Some images have preamble followed by prefix DICM before metadata, others don't
// This functions will skip preamble if it exists.
void managePreamble(ifstream* fd){
    fd->seekg(128);
    char prefix[4];
    fd->read(prefix, 4);
    if(strcmp(prefix, "DICM") != 0){
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
void readNextMeta(ifstream* fd){
    char buff[128], vr[10];
    uint16_t tag[2], len;
    unsigned long UL;
    fd->read(buff, 4);
    tag[0] = (uint16_t) buff[0];
    tag[1] = (uint16_t) buff[1];
    fd->read(vr, 2);

    // Dealing with cases OB, OW, OF, SQ, UT or UN for explicit VR, which have 2 reserved bytes
    if (specialVR(vr)){
        // forwards two bytes
        cout << "Forwarded 2 bytes because of specialVR\n";
        fd->read(buff, 2);
        int len;
        fd->read(buff, 4);  // special values have 4 bytes of length
        len = (int) buff[0];
        fd->read(buff, len);
        UL = (unsigned long) buff[0];
    }
    // Some cases may contain implicit vr (?)
    else if(implicitVR(vr)){
        // backwards two bytes
        cout << "Backwarded 2 bytes because of implicitVR\n";
        int curr = fd->tellg();
        fd->seekg(curr-2);
        strcpy(vr, "Implicit\0");

        int len;
        fd->read(buff, 4);  // special values have 4 bytes of length
        len = (int) buff[0];
        fd->read(buff, len);
        UL = (unsigned long) buff[0];
    }
    else{
        fd->read(buff, 2);
        len = (uint16_t) buff[0];
        fd->read(buff, len);
        UL = (unsigned long) buff[0];
    }

    printf("TAG: (%#x,%#x)\n", tag[0], tag[1]);
    printf("VR: %c%c\n", vr[0], vr[1]);
    printf("LEN: %#x\n", len);
    printf("DATA: %lu\n", UL);
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

    for(int i = 0; i < 5; i++){
        readNextMeta(&fd);
        cout << "--------+" << endl;
    }
    
}