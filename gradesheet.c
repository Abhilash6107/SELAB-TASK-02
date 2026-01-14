#include<stdio.h>
#include<string.h>
#include<ctype.h>

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

void assignGrade(struct Student *s){
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

    return 0;
}
