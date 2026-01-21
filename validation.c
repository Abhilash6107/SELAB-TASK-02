#include<string.h>
#include<ctype.h>
#include "validation.h"

int validName(char Name[]){
    for(int i = 0; Name[i]; i++ ){
        if(!isalpha(Name[i]) && Name[i] != ' ')
            return 0;
    }
    return 1;
}

int validID(char RollNumber[]){
    for(int i = 0; RollNumber[i]; i++ ){
        if(!isalnum(RollNumber[i]))
            return 0;
    }
    return 1;
}

int duplicateID(struct Student students[], int count, char RollNumber[]){
    for(int i = 0; i < count; i++){
        if(strcmp(students[i].RollNumber, RollNumber) == 0)
            return 1;
    }
    return 0;
}