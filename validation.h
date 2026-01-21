#ifndef VALIDATION_H
#define VALIDATION_H

#include "student.h"

int validName(char Name[]);
int validID(char RollNumber[]);
int duplicateID(struct Student students[], int count, char RollNumber[]);

#endif