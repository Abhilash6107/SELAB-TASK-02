#include<stdio.h>
#include "student.h"
#include "report.h"

int main(int argc, char *argv[]){
    struct Student students[MAX_STUDENTS];

    if(argc < 3){
        printf("Usage: %s <inputfile> <outputfile>\n", argv[0]);
        return 1;
    }

    int count = readFile(students, argv[1]);
    FILE *out = fopen(argv[2], "w");
    if(!out){
        printf("Could not open Output file\n");
        return 1;
    }

    if(count > 0)
        printReport(out, students, count);

    fclose(out);
    return 0;
}