#include "main.h"
int countLines(char* fileinput){
    int lines=0, count=0;
    FILE* txt = fopen(fileinput, "r");
    if(txt==NULL){
        printf("\nFile Not Found, Exiting Program\n");
        exit(0);
    }
    for(lines = getc(txt); lines!=EOF; lines = getc(txt)){    /*EOF stands for End of File, as long as it's not end of the file, count will keep adding*/
        if (lines=='\n'){
            count+=1;
        }
    }
    fclose(txt);
    return count;
}
