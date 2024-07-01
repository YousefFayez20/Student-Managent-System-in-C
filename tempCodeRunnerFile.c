#include<stdio.h>
#include<stdlib.h>
#include"student.h"
#include <stdbool.h>

int main(){
unsigned int choice;
unsigned int removeID = 0;
unsigned int searchChoice;
unsigned int updateID,fieldChoice,newValue;

printf("/********************************************************************************/ \n");
     printf( " \t\t\t Student Management System \t\t\t \n" );
 printf("/*******************************************************************************/ \n");


do{
printf("1- Add a new student \n");
printf("2- Remove a student \n");
printf("3- Retrieve Student Data \n");
printf("4- Update Student's Data \n");
printf("5- Exit \n");


scanf("%i",&choice);
fflush(stdin);

switch (choice)
{
case 1:
    addStudent();
    displayStudents();
    break;
case 2:

        printf("Enter student ID to remove: ");
        scanf("%d", &removeID);

        if (removeStudent(removeID)) {
            printf("Student removed successfully!\n");
        }
        void displayStudents();
        break;
case 3:

        printf("Search by:\n");
        printf("1. Name\n");
        printf("2. ID\n");
        printf("Enter your choice: ");
        scanf("%d", &searchChoice);

        if (searchChoice == 1) { // Search by Name
            char searchName[100];
            printf("Enter student name: ");
            scanf("%s", searchName);
            searchStudentByName(searchName);
        } else if (searchChoice == 2) { // Search by ID
            int searchID;
            printf("Enter student ID: ");
            scanf("%d", &searchID);
            searchStudentByID(searchID);
        } else {
            printf("Invalid choice.\n");
        }

        break;
case 4:
        printf("Enter student ID to update: ");
        scanf("%d", &updateID);
        printf("Which field do you want to update?\n");
        printf("1. Academic Year\n");
        printf("2. GPA\n");
        printf("Enter your choice: ");
        scanf("%d", &fieldChoice);
        printf("Enter the new value: ");
        scanf("%d", &newValue);

        if (updateStudent(updateID, fieldChoice, newValue)) {
            printf("Student data updated successfully!\n");
        }
        displayStudents();
        break;
case 5:
    printf("I hope You've Enjoyed our program");
    break;
default:
    printf("invalid input");
    break;
}


}while (!(choice == 5 ));





}
