# Module Specifications


# 1. Student Module
Files:
student.h
student.c
Purpose: Defines the student data structure and handles reading student records from an input file.
Input: Input file name containing student data.
Pre-Condition: Input file must exist, File must follow the predefined format.
Logic:
1.	Open input file
2.	Read roll number and name
3.	Read minor and major marks
4.	Call validation and calculation modules
5.	Store valid student records
Output: Array of valid Student structures and Number of students successfully read.


# 2. Validation Module
Files:
validation.h
validation.c
Purpose: Ensures correctness and integrity of input data.
Input: Student name, Roll number, Existing student list.
Pre-Condition: Student data must be read from file.
Logic: 
1.	Check if name contains only alphabets and spaces.
2.	Check if roll number is alphanumeric.
3.	Check for duplicate roll numbers.
Output: Validation result (valid / invalid)


# 3. Calculation Module
Files:
calculation.h
calculation.c
Purpose: Calculates total marks, percentage, CGPA, and assigns grades.
Input: Minor and major marks of a student.
Pre-Condition: Marks must be validated (range: minor 0–40, major 0–60)
Logic: 
FOR each subject
    total = minor + major
    IF total < 50
        mark student as failed
END FOR

percentage = sum / number_of_subjects
cgpa = percentage / 10

IF student passed
   	assign grade based on percentage
ELSE
    grade = F
Output: Percentage, CGPA, and Grade


# 4. Report Module
Files:
report.h
report.c
Purpose: Generates a formatted result report and class statistics.
Input: Student data and output file pointer.
Pre-Condition: Student results must be computed.
Logic: 
1.	Print student details (ID, Name, Percentage, CGPA, Grade)
2.	Calculate class Average.
3.	Find Highest and Lowest Percentage.
4.	Count number of students per Grade.
Output: Output File Containing complete report.


# 5. Main Module
Files:
main.c
Purpose: Controls program execution and integrates all modules.
Input: Command-line arguments: input file and output file.
Pre-Condition: Correct number of command-line arguments provided.
Logic: 
1.	Read input arguments.
2.	Call readFile()
3.	Open output file
4.	Call printReport()
Output: Final result written to output file.
