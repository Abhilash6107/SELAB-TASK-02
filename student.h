#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 50
#define MAX_SUBJECTS 5
#define NAME_LENGTH 50

struct Student{
    char Name[NAME_LENGTH];
    char RollNumber[9];
    int minor[MAX_SUBJECTS];
    int major[MAX_SUBJECTS];
    int total[MAX_SUBJECTS];
    float percentage;
    float cgpa;
    char grade[3];
};

int readFile(struct Student students[], const char *filename);

#endif