#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float grade;
};

class StudentManager {
private:
    vector<Student> students;
    int nextId = 1;

public:
    void addStudent(const string& name, float grade) {
        students.push_back({nextId++, name, grade});
        cout << "Student added.\n";
    }

    void listStudents() {
        if (students.empty()) {
            cout << "No students available.\n";
            return;
        }
        cout << "\nStudent List:\n";
        for (const auto& s : students) {
            cout << "ID: " << s.id << ", Name: " << s.name << ", Grade: " << s.grade << "\n";
        }
    }

    void findStudent(int id) {
        for (const auto& s : students) {
            if (s.id == id) {
                cout << "Found: Name: " << s.name << ", Grade: " << s.grade << "\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice;

    while (true) {
        cout << "\n1. Add Student\n2. List Students\n3. Find Student\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            float grade;
            cout << "Enter name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter grade: ";
            cin >> grade;
            manager.addStudent(name, grade);
        } else if (choice == 2) {
            manager.listStudents();
        } else if (choice == 3) {
            int id;
            cout << "Enter student ID: ";
            cin >> id;
            manager.findStudent(id);
        } else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
