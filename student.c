
#include <stdbool.h>
#include <stdio.h>
#include<stdlib.h>
#include "student.h"



Student students[100];
static unsigned int count1;


bool validID(unsigned int id){
unsigned int x = id;
for(int i = 0;i <= count1 ; i++){
if(students[i].studentID == x) {
        return false;}

     }
return true;
}
bool isValidName(const char *name) {
    int wordCount = 0;
    int len = strlen(name);

    for (int i = 0; i < len; i++) {
        if (isalpha(name[i])) {
            wordCount++;

            while (isalpha(name[i])) {
                i++;
            }
        }
    }

    return (wordCount == 2);
}

void addStudent(){
if(count1 < 100){
Student newstudent;
do{
printf("Enter student name First and Last names : ");
       gets(newstudent.name);
       if (isValidName(newstudent.name)== false) {
                printf("Invalid name. Please enter the first and last name separated by a space: ");
            }
        } while (!isValidName(newstudent.name));
       fflush(stdin);
do{
printf("enter student ID : ");
scanf("%i",&newstudent.studentID);

if(newstudent.studentID < 1000000 || newstudent.studentID > 9999999 )
printf("Invalid ID, enter 7-digit ID\n");
if(validID(newstudent.studentID) == false){
printf("student ID already exists. Please enter a unique ID.\n");
}

}while(newstudent.studentID < 1000000 || newstudent.studentID > 9999999 || validID(newstudent.studentID)==false);

do{
    printf("Enter student gender (M/F): ");
    scanf(" %c", &newstudent.gender);
    if (newstudent.gender != 'M' && newstudent.gender != 'F') {
    printf("Invalid gender. Please enter 'M' or 'F'.\n");
            }
        } while (newstudent.gender != 'M' && newstudent.gender != 'F');

do {
            printf("Enter academic year (1 to 5): ");
            scanf("%d", &newstudent.academicYear);
            if (newstudent.academicYear < 1 || newstudent.academicYear > 5) {
                printf("Invalid academic year. Please enter a value between 1 and 5.\n" );
            }
        } while (newstudent.academicYear < 1 || newstudent.academicYear > 5);

do {
            printf("Enter GPA (0.0 to 4.0): ");
            scanf("%f", &newstudent.GPA);
            if (newstudent.GPA < 0 || newstudent.GPA > 4.0) {
                printf("Invalid GPA. Please enter a value between 0.0 and 4.0.\n");
            }
        } while (newstudent.GPA < 0 || newstudent.GPA > 4.0);


students[count1] = newstudent;
        count1++;
        printf("Student added successfully!\n");


}else {
        printf("Maximum number of students reached.\n");
    }

}
bool removeStudent(unsigned int studentID) {
    for (int i = 0; i < count1; i++) {
        if (students[i].studentID == studentID) {
            // Move the last student in the array to the position of the removed student
            students[i] = students[count1 - 1];
            count1--;
            printf("Student with ID %d has been removed.\n", studentID);
            return true;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
    return false;
}

bool searchStudentByID(int studentID) {
    for (int i = 0; i < count1; i++) {
        if (students[i].studentID == studentID) {
            printf("Student Information:\n");
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].studentID);
            printf("Gender: %c\n", students[i].gender);
            printf("Academic Year: %d\n", students[i].academicYear);
            printf("GPA: %.2f\n", students[i].GPA);
            printf("---------------\n");
            return true;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
    return false;
}

void searchStudentByName(const char *studentName) {
    int foundCount = 0;

    printf("Students with the name %s:\n", studentName);
    for (int i = 0; i < count1; i++) {
        if (strcmp(students[i].name, studentName) == 0) {
            printf("Name: %s\n", students[i].name);
            printf("ID: %d\n", students[i].studentID);
            printf("Gender: %c\n", students[i].gender);
            printf("Academic Year: %d\n", students[i].academicYear);
            printf("GPA: %.2f\n", students[i].GPA);
            printf("---------------\n");
            foundCount++;
        }
    }

    if (foundCount == 0) {
        printf("No students with the name %s found.\n", studentName);
    }
}
bool updateStudent(int studentID, int fieldChoice, int newValue) {
    for (int i = 0; i < count1; i++) {
        if (students[i].studentID == studentID) {
            switch (fieldChoice) {
                case 1: // Update Academic Year
                    if (newValue >= 1 && newValue <= 5) {
                        students[i].academicYear = newValue;
                        printf("Academic Year updated successfully!\n");
                    } else {
                        printf("Invalid Academic Year value.\n");
                        return false;
                    }
                    break;
                case 2: // Update GPA
                    if (newValue >= 0 && newValue <= 4.0) {
                        students[i].GPA = newValue;
                        printf("GPA updated successfully!\n");
                    } else {
                        printf("Invalid GPA value.\n");
                        return false;
                    }
                    break;
                default:
                    printf("Invalid field choice.\n");
                    return false;
            }
            return true;
        }
    }
    printf("Student with ID %d not found.\n", studentID);
    return false;
}
void displayStudents() {
    printf("Student Information:\n");
    for (int i = 0; i < count1; i++) {
        printf("Name: %s\n", students[i].name);
        printf("ID: %d\n", students[i].studentID);
        printf("Gender: %c\n", students[i].gender);
        printf("Academic Year: %d\n", students[i].academicYear);
        printf("GPA: %.2f\n", students[i].GPA);
        printf("---------------\n");
    }
}
