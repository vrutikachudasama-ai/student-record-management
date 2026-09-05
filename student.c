#include <stdio.h>
#include <string.h>

struct Student {
    int rollNo;
    char name[50];
    float marks;
};

void addStudent(struct Student students[], int *count);
void displayStudents(struct Student students[], int count);
void searchStudent(struct Student students[], int count);
void updateStudent(struct Student students[], int count);
void deleteStudent(struct Student students[], int *count);

int main() {

    struct Student students[100];
    int count = 0;
    int choice;

    while (1) {

        printf("\n===== Student Record Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent(students, &count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                searchStudent(students, count);
                break;

            case 4:
                updateStudent(students, count);
                break;

            case 5:
                deleteStudent(students, &count);
                break;

            case 6:
                printf("\nExiting program...\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}


void addStudent(struct Student students[], int *count) {

    if (*count >= 100) {
        printf("Student limit reached!\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[*count].rollNo);

    printf("Enter Name: ");
    getchar();
    fgets(students[*count].name, 50, stdin);

    students[*count].name[
        strcspn(students[*count].name, "\n")
    ] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[*count].marks);

    (*count)++;

    printf("\nStudent added successfully!\n");
}

void displayStudents(struct Student students[], int count) {

    if (count == 0) {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\n===== Student Records =====\n");

    for (int i = 0; i < count; i++) {

        printf("\nStudent: %d\n", i + 1);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

void searchStudent(struct Student students[], int count) {

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {

        if (students[i].rollNo == rollNo) {

            printf("\nStudent found!\n");
            printf("Roll Number: %d\n", students[i].rollNo);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}


void updateStudent(struct Student students[], int count) {

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < count; i++) {

        if (students[i].rollNo == rollNo) {

            printf("Enter new name: ");
            getchar();
            fgets(students[i].name, 50, stdin);

            students[i].name[
                strcspn(students[i].name, "\n")
            ] = '\0';

            printf("Enter new marks: ");
            scanf("%f", &students[i].marks);

            printf("\nStudent updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}


void deleteStudent(struct Student students[], int *count) {

    int rollNo;
    int found = 0;

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &rollNo);

    for (int i = 0; i < *count; i++) {

        if (students[i].rollNo == rollNo) {

            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }

            (*count)--;

            printf("\nStudent deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}