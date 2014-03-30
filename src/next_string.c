#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void eraseSpaces(FILE *pFile, char *c){
    do{
        *c = fgetc(pFile);
    }while( (*c == ' ') || (*c == '\n'));
}

void buildString(FILE *pFile, char *strOut, char *c){
    while( (*c != ' ') && (*c != '\n') && (*c != EOF)){
        strcat(strOut,c);
        *c = fgetc(pFile);
    }
}

//this function get the next String, ignoring line breaks and spaces
//the return if it finds EOF -> -1, and EOF for str
//if ok return 0 and str with a string
//take care of \n in windows SO, its 2 chars there
int getNextString(FILE *pFile, char *str){
    str[0] = '\0';
    int out = 0;
    char *strOut = malloc(sizeof(str));
    strOut[0] = '\0';
    char *c = malloc(sizeof(char));
    c[0] = '\0';
    
    eraseSpaces(pFile, c);
    buildString(pFile, strOut, c);
    //strcpy(str, strOut);
        
    if(*c == EOF) out = -1;
    return out;
}
