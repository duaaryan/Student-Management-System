#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    float marks;
    char grade;

    void calcGrade() {
        if (marks >= 90) grade = 'A';
        else if (marks >= 75) grade = 'B';
        else if (marks >= 60) grade = 'C';
        else if (marks >= 40) grade = 'D';
        else grade = 'F';
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << rollNo << endl;
        cout << "Marks: " << marks << endl;
        cout << "Grade: " << grade << endl;
    }
};

void saveToFile(vector<Student> students) {
    ofstream f("students_v2.txt");
    for(Student s : students) {
        f << s.name << " " << s.rollNo << " " << s.marks << " " << s.grade << "\n";
    }
    f.close();
    cout << "Data saved!" << endl;
}

vector<Student> loadFromFile() {
    vector<Student> students;
    ifstream f("students_v2.txt");
    if(!f) return students;
    Student s;
    while(f >> s.name >> s.rollNo >> s.marks >> s.grade) {
        students.push_back(s);
    }
    f.close();
    return students;
}

int main() {
    vector<Student> students = loadFromFile();
    if(students.size() > 0) {
        cout << "Loaded " << students.size() << " students!" << endl;
    }

    int choice;
    while(1) {
        cout << "\nStudent Management System v2.0" << endl;
        cout << "----------------------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. View All Students" << endl;
        cout << "3. Save & Exit" << endl;
        cout << "4. Clear All Records" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            Student s;
            cout << "Enter Name: ";
            cin >> s.name;
            cout << "Enter Roll No: ";
            cin >> s.rollNo;
            cout << "Enter Marks: ";
            cin >> s.marks;
            s.calcGrade();
            students.push_back(s);
            cout << "Student Added! Total: " << students.size() << endl;

        } else if(choice == 2) {
            if(students.size() == 0) {
                cout << "No students yet!" << endl;
            } else {
                cout << "\n";
                for(Student s : students) {
                    s.display();
                    cout << "----------" << endl;
                }
            }

        } else if(choice == 3) {
            saveToFile(students);
            cout << "Goodbye!" << endl;
            break;

        } else if(choice == 4) {
            students.clear();
            saveToFile(students);
            cout << "All records cleared!" << endl;

        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}