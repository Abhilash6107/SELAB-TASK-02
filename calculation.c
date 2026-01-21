#include<string.h>
#include "calculation.h"

static void assignGrade(struct Student *s){
    if( s->percentage >= 90)
        strcpy(s->grade, "O");
    else if(s->percentage >= 85)
        strcpy(s->grade, "A+");
    else if(s->percentage >= 75)
        strcpy(s->grade, "A");
    else if(s->percentage >= 65)
        strcpy(s->grade, "B+");
    else if(s->percentage >= 60)
        strcpy(s->grade, "B");
    else if(s->percentage >= 55)
        strcpy(s->grade, "C");
    else if(s->percentage >= 50)
        strcpy(s->grade, "D");
    else
        strcpy(s->grade, "F");
}

void calculateResult(struct Student *s){
    int sum = 0;
    int pass = 1;

    for(int i = 0; i < MAX_SUBJECTS; i++){
        s->total[i] = s->minor[i] + s->major[i];
        if(s->total[i]<50)
            pass = 0;
        sum = sum + s->total[i];
    }

    s->percentage = sum / (float)MAX_SUBJECTS;
    if(!pass){
        strcpy(s->grade, "F");
    }
    else{
        assignGrade(s);
    }
    s->cgpa = s->percentage/10.0;
    
}