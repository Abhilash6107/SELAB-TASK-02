#include<stdio.h>
#include<string.h>
#include "report.h"

void printReport(FILE *out, struct Student students[], int n){
    float sum = 0;
    float max = students[0].percentage;
    float min = students[0].percentage;
    int gradeCount[8] = {0};

    fprintf(out, "\n%-10s %-18s %-10s %-6s %-6s\n", "ID", "Name", "Percentage", "Grade", "CGPA");

    for(int i = 0; i < n; i++){
        fprintf(out, "%-10s %-18s %-10.2f %-6s %-6.2f\n", students[i].RollNumber, students[i].Name, students[i].percentage, students[i].grade, students[i].cgpa);

        sum = sum + students[i].percentage;
        if(students[i].percentage > max)
            max = students[i].percentage;
        if(students[i].percentage < min)
            min = students[i].percentage;

        if(strcmp(students[i].grade, "O") == 0)
            gradeCount[0]++;
        else if(strcmp(students[i].grade, "A+") == 0)
            gradeCount[1]++;
        else if(strcmp(students[i].grade, "A") == 0)
            gradeCount[2]++;
        else if(strcmp(students[i].grade, "B+") == 0)
            gradeCount[3]++;
        else if(strcmp(students[i].grade, "B") == 0)
            gradeCount[4]++;
        else if(strcmp(students[i].grade, "C") == 0)
            gradeCount[5]++;
        else if(strcmp(students[i].grade, "D") == 0)
            gradeCount[6]++;
        else
            gradeCount[7]++;
    }

    fprintf(out, "\nClass Average Percentage: %.2f", sum / n);
    fprintf(out, "\nHighest Percentage: %.2f", max);
    fprintf(out, "\nLowest Percentage: %.2f\n", min);

    fprintf(out, "\nNo.of Students in each Grade:\n");
    fprintf(out, "O: %d  A+: %d  A: %d  B+: %d  B: %d  C: %d  D: %d  F: %d\n", gradeCount[0], gradeCount[1], gradeCount[2], gradeCount[3], gradeCount[4], gradeCount[5], gradeCount[6], gradeCount[7]);
}
