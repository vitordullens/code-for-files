# To do

- Partindo de uma imagem no format DICOM (qualquerimagem), desenvolver um programa em c ou c++ para extrair os metadados de dita imagem.Fazer isto para mais de uma imagem.

# Getting Started
Compile code:
```
g++ -std=c++11 -Wall -o ex1 ex1.cpp
```
Execute `./ex1`

Choose a  file during program execution from the files listed.

# Files in this folder
- All .dcm files are DICOM images we used.
- ex1.cpp is the main file to be compiled and executed.
- HeaderElements.h is a lib for main file.
- tags.txt is a list of DICOM tags.
- VR.txt is a list of sone VR values and their respective types.
- scrapper.py is a simple script used to acquire tag information from a .html file
