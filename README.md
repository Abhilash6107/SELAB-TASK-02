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



# Input File:

25MCMI01 SUJITH KUMAR
40 60
38 55
36 54
35 53
34 52
25MCMI02 Ravi Kumar
40 60
39 59
38 58
37 57
36 56
25MCMI03 Suresh Reddy
34 56
33 55
32 54
31 53
30 52
25MCMI04 Ananya Sharma
30 20
10 40
30 20
20 30
30 20
25MCMI05 Priya Verma
30 45
35 55
38 57
40 58
32 53


# Output File:

ID         Name               Percentage Grade  CGPA  
25MCMI01   SUJITH KUMAR       91.40      O      9.14  
25MCMI02   Ravi Kumar         96.00      O      9.60  
25MCMI03   Suresh Reddy       86.00      A+     8.60  
25MCMI04   Ananya Sharma      50.00      D      5.00  
25MCMI05   Priya Verma        88.60      A+     8.86  
25MCMI06   Abhilash Dakarapu  89.60      A+     8.96  
25MCMI07   Rohit Singh        70.60      F      7.06  
25MCMI08   Neha Gupta         86.00      A+     8.60  
25MCMI09   Arjun Mehta        91.00      O      9.10  
25MCMI10   Sneha Patel        86.00      A+     8.60  
25MCMI11   Vikas Jain         96.00      O      9.60  
25MCMI12   Pooja Nair         86.00      A+     8.60  
25MCMI13   Aman Yadav         80.00      A      8.00  
25MCMI14   Ritu Malhotra      84.60      A      8.46  
25MCMI15   Sanjay Das         91.00      O      9.10  
25MCMI16   Kavya Iyer         96.00      O      9.60  
25MCMI17   Nikhil Sharma      86.00      A+     8.60  
25MCMI18   Deepa Joshi        86.00      A+     8.60  
25MCMI19   Manish Gupta       87.20      A+     8.72  
25MCMI20   Aishwarya Roy      75.00      A      7.50  
25MCMI21   Rohan Kulkarni     91.00      O      9.10  
25MCMI22   Meena Pillai       86.00      A+     8.60  
25MCMI23   Akash Mishra       96.00      O      9.60  
25MCMI24   Pankaj Verma       86.00      A+     8.60  
25MCMI25   Swathi Ramesh      89.60      A+     8.96  
25MCMI26   Harish Chandra     48.00      F      4.80  
25MCMI27   Bhavana Shetty     86.00      A+     8.60  
25MCMI28   Siddharth Malhotra 91.00      O      9.10  
25MCMI29   Nandini Gupta      96.00      O      9.60  
25MCMI30   Mohit Aggarwal     86.00      A+     8.60  
25MCMI31   Rahul Khanna       88.60      A+     8.86  
25MCMI32   Isha Kapoor        86.00      A+     8.60  
25MCMI33   Varun Saxena       91.00      O      9.10  
25MCMI34   Tanya Arora        96.00      O      9.60  
25MCMI35   Kunal Bansal       86.00      A+     8.60  
25MCMI36   Pritam Sen         84.60      A      8.46  
25MCMI37   Ankit Verma        86.00      A+     8.60  
25MCMI38   Shalini Bose       91.00      O      9.10  
25MCMI39   Abdul Musthaffa    96.00      O      9.60  
25MCMI40   Sunita Deshpande   86.00      A+     8.60  
25MCMI42   Pallavi Joshi      86.00      A+     8.60  
25MCMI43   Vinod Nair         91.00      O      9.10  
25MCMI44   Riya Chatterjee    96.00      O      9.60  
25MCMI45   Prakash Menon      86.00      A+     8.60  
25MCMI46   Aditi Sengupta     89.60      A+     8.96  
25MCMI47   Suman Das          87.20      A+     8.72  
25MCMI48   Nilesh Pawar       86.00      A+     8.60  
25MCMI49   Shreya Kulkarni    91.00      O      9.10  
25MCMI50   Devendra Singh     96.00      O      9.60  

Class Average Percentage: 86.91
Highest Percentage: 96.00
Lowest Percentage: 48.00

No. of Students in each Grade:
O:18  A+:24  A:4  B+:0  B:0  C:0  D:1  F:2
