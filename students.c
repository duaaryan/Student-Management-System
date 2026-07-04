// Student Management System by Aryan Dua
#include <stdio.h>

struct Student {
    char name[50];
    int rollNo;
    float marks;
    char grade;
};

void saveToFile(struct Student s[], int count) {
    FILE *f = fopen("students.txt", "w");
    int i;
    for (i = 0; i < count; i++) {
        fprintf(f, "%s %d %.1f %c\n", s[i].name, s[i].rollNo, s[i].marks, s[i].grade);
    }
    fclose(f);
    printf("Data saved!\n");
}

void loadFromFile(struct Student s[], int *count) {
    FILE *f = fopen("students.txt", "r");
    if (f == NULL) return;
    while (fscanf(f, "%s %d %f %c", s[*count].name, &s[*count].rollNo, &s[*count].marks, &s[*count].grade) == 4) {
        (*count)++;
    }
    fclose(f);
}

int main() {
    int choice, count = 0, i;
    struct Student s[100];

    loadFromFile(s, &count);
    if (count > 0) printf("Loaded %d students from file!\n", count);

    while (1) {
        printf("\nStudent Management System\n");
        printf("--------------------------\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Save & Exit\n");
        printf("4. Clear All Records\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Name: ");
            scanf("%s", s[count].name);
            printf("Enter Roll Number: ");
            scanf("%d", &s[count].rollNo);
            printf("Enter Marks (out of 100): ");
            scanf("%f", &s[count].marks);

            if (s[count].marks >= 90) s[count].grade = 'A';
            else if (s[count].marks >= 75) s[count].grade = 'B';
            else if (s[count].marks >= 60) s[count].grade = 'C';
            else if (s[count].marks >= 40) s[count].grade = 'D';
            else s[count].grade = 'F';

            printf("Student Added! Total: %d\n", count + 1);
            count++;

        } else if (choice == 2) {
            if (count == 0) {
                printf("No students added yet!\n");
            } else {
                printf("\n%-15s %-10s %-10s %-5s\n", "Name", "Roll No", "Marks", "Grade");
                printf("----------------------------------------\n");
                for (i = 0; i < count; i++) {
                    printf("%-15s %-10d %-10.1f %-5c\n",
                        s[i].name, s[i].rollNo, s[i].marks, s[i].grade);
                }
            }

       } else if (choice == 3) {
            saveToFile(s, count);
            printf("Goodbye!\n");
            break;
        } else if (choice == 4) {
            count = 0;
            FILE *f = fopen("/Users/aryandua/Documents/C_Projects/students.txt", "w");
            fclose(f);
            printf("All records cleared!\n");
        } else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}