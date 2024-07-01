#include <stdbool.h>

typedef struct {
    char name[100];
    unsigned int studentID;
    char gender;
    int academicYear;
    float GPA;
} Student;
void displayStudents();
bool validID(unsigned int id);
void addStudent();
bool removeStudent(unsigned int studentID);
bool searchStudentByID(int studentID);
void searchStudentByName(const char *studentName);
bool updateStudent(int studentID, int fieldChoice, int newValue);
bool isValidName(const char *name);
