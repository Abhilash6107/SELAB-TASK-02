TARGET = gradesheet

all:
	gcc main.c student.c validation.c calculation.c report.c -o gradesheet

run: $(TARGET)
	./$(TARGET) input.txt output.txt

clean:
	rm -f gradesheet

