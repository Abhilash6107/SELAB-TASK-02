#include<stdio.h>

#include "student.h"
#include "validation.h"
#include "calculation.h"

int readFile(struct Student students[], const char *filename){
    FILE *fp = fopen(filename, "r");
    int n = 0;

    if(!fp){
        printf("File open failed");
        return 0;
    }

    while(fscanf(fp, "%8s %[^\r\n]", students[n].RollNumber, students[n].Name) == 2){
        if (!validID(students[n].RollNumber) || !validName(students[n].Name) || duplicateID(students, n, students[n].RollNumber)) {
            printf("Invalid record skipped: %s %s\n", students[n].RollNumber, students[n].Name);

            for(int i = 0; i < MAX_SUBJECTS; i++){
                fscanf(fp, "%*d %*d");
            }
            continue;
        }

        int validMarks = 1;
        for(int i = 0; i < MAX_SUBJECTS; i++){
            fscanf(fp, "%d %d", &students[n].minor[i], &students[n].major[i]);

            if(students[n].minor[i] < 0 || students[n].minor[i] > 40 || students[n].major[i] < 0 || students[n].major[i] > 60)
                validMarks = 0;
        }

        if(!validMarks){
            printf("Invalid marks skipped: %s %s\n", students[n].RollNumber, students[n].Name);
            continue;
        }

        calculateResult(&students[n]);
        n++;

        if(n >= MAX_STUDENTS)
            break;
    }

    fclose(fp);
    return n;
}