#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a structure for a student
struct Student {
 int studentID; // Unique ID for each student
 char name[100]; // Name of the student
 struct Student* next; // Pointer to the next student in the list
};
// Function to create a new student node
struct Student* createStudent(int studentID, const char* name) {
 struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
 newStudent->studentID = studentID;
 strcpy(newStudent->name, name); // Copy name to the student structure
 newStudent->next = NULL;
 return newStudent;
}
// Function to add a new student to the enrollment system
void addStudent(struct Student** head, int studentID, const char* name) {
 struct Student* newStudent = createStudent(studentID, name);
 newStudent->next = *head; // Add new student at the beginning of the list
 *head = newStudent;
 printf("Student ID %d with name '%s' added successfully.\n", studentID, name);
}
// Function to search for a student by ID
struct Student* searchStudent(struct Student* head, int studentID) {
 struct Student* current = head;
 while (current != NULL) {
 if (current->studentID == studentID) {
 return current; // Student found
 }
 current = current->next; // Move to the next student
 }
 return NULL; // Student not found
}
// Function to delete a student by ID
void deleteStudent(struct Student** head, int studentID) {
 struct Student* current = *head;
 struct Student* previous = NULL;
 while (current != NULL && current->studentID != studentID) {
 previous = current;
 current = current->next; // Move to the next student
 }
 if (current == NULL) {
 printf("Student ID %d not found.\n", studentID);
 return; // Student not found
 }
 if (previous == NULL) {
 // Deleting the first student in the list
 *head = current->next;
 } else {
 previous->next = current->next; // Bypass the current student
 }
 free(current); // Free the memory
 printf("Student ID %d deleted successfully.\n", studentID);
}
// Function to display all enrolled students
void displayStudents(struct Student* head) {
 if (head == NULL) {
 printf("No students enrolled.\n");
 return;
 }
 struct Student* current = head;
 printf("Enrolled Students:\n");
 while (current != NULL) {
 printf("Student ID: %d, Name: %s\n", current->studentID, current->name);
 current = current->next; // Move to the next student
 }
}
// Main function to demonstrate the Student Enrollment System
int main() {
 struct Student* head = NULL; // Head of the linked list
 int choice, studentID;
 char name[100];
 while (1) {
 printf("\n--- Student Enrollment System Menu ---\n");
 printf("1. Add New Student\n");
 printf("2. Search for Student by ID\n");
 printf("3. Delete Student Record\n");
 printf("4. Display All Enrolled Students\n");
 printf("5. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 getchar(); // Consume newline character
 switch (choice) {
 case 1:
 printf("Enter Student ID: ");
 scanf("%d", &studentID);
 getchar(); // Consume newline character
 printf("Enter Student Name: ");
 fgets(name, sizeof(name), stdin);
 name[strcspn(name, "\n")] = '\0'; // Remove newline character
 addStudent(&head, studentID, name);
 break;
case 2:
 printf("Enter Student ID to search: ");
 scanf("%d", &studentID);
 struct Student* foundStudent = searchStudent(head, studentID);
 if (foundStudent != NULL) {
 printf("Student ID %d found: %s\n", foundStudent->studentID, foundStudent-
>name);
 } else {
 printf("Student ID %d not found.\n", studentID);
 }
 break;
 case 3:
 printf("Enter Student ID to delete: ");
 scanf("%d", &studentID);
 deleteStudent(&head, studentID);
 break;
 case 4:
 displayStudents(head);
 break;
 case 5:
 printf("Exiting the program.\n");
 exit(0);
 default:
 printf("Invalid choice! Please try again.\n");
 }
 }
 return 0;
}
