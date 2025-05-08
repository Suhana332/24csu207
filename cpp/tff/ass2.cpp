#include <iostream>
#include <string>
#include <vector>

using namespace std;

//  Person class
class Person {
private:
    string name;
    int age;
    string id;
    string contact;

public:
    Person(string n, int a, string i, string c) {
        setName(n);
        setAge(a);
        id = i;
        contact = c;
    }

    // Getters
    string getName() { return name; }
    int getAge() { return age; }
    string getId() { return id; }
    string getContact() { return contact; }

    // Setters 
    void setName(string n) {
        if(!n.empty()) name = n;
    }

    void setAge(int a) {
        if(a > 0 && a < 120) age = a;
    }

    void setContact(string c) { contact = c; }

    void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nID: " << id << "\nContact: " << contact << endl;
    }

    double calculatePayment() { return 0.0; }
};

class Student : public Person {
private:
    string enrollmentDate;
    string program;
    double gpa;

public:
    Student(string n, int a, string i, string c, 
            string ed, string p, double g) 
        : Person(n, a, i, c), enrollmentDate(ed), program(p) {
        setGpa(g);
    }

    void setGpa(double g) {
        if(g >= 0.0 && g <= 4.0) gpa = g;
    }

    void displayDetails() {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate
             << "\nProgram: " << program << "\nGPA: " << gpa << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string specialization;
    string hireDate;

public:
    Professor(string n, int a, string i, string c,
             string d, string s, string hd)
        : Person(n, a, i, c), department(d), specialization(s), hireDate(hd) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Department: " << department 
             << "\nSpecialization: " << specialization
             << "\nHire Date: " << hireDate << endl;
    }

    double calculatePayment() {
        return 5000.0; // Base salary calculation
    }
};

// Grade management 
class GradeBook {
private:
    struct GradeEntry {
        string studentId;
        double grade;
    };
    vector<GradeEntry> grades;

public:
    void addGrade(string studentId, double grade) {
        if(grade >= 0 && grade <= 4.0) {
            grades.push_back({studentId, grade});
        }
    }

    double calculateAverageGrade() {
        double total = 0;
        for(auto& entry : grades) total += entry.grade;
        return grades.empty() ? 0 : total / grades.size();
    }
};

// Enrollment management 
class EnrollmentManager {
private:
    struct Enrollment {
        string courseCode;
        string studentId;
    };
    vector<Enrollment> enrollments;

public:
    void enrollStudent(string courseCode, string studentId) {
        enrollments.push_back({courseCode, studentId});
    }

    int getEnrollmentCount(string courseCode) {
        int count = 0;
        for(auto& e : enrollments) {
            if(e.courseCode == courseCode) count++;
        }
        return count;
    }
};

// Polymorphism 
void displayPersonDetails(Person& p) {
    p.displayDetails();
}

int main() {
    // Object creation
    Student s1("Kim Jisoo", 30, "S1001", "jisoo@uni.edu", 
              "2023-09-01", "Computer Science", 3.8);
    Professor p1("Dr.Jeon Rose", 40, "P2001", "joen@uni.edu",
                "Computer Science", "AI", "2010-05-15");

    // Polymorphic
    Person* people[] = {&s1, &p1};
    for(auto person : people) {
        person->displayDetails();
        cout << "Payment: $" << person->calculatePayment() << "\n\n";
    }

    // Gradebook test
    GradeBook gb;
    gb.addGrade("S1001", 3.8);
    cout << "Average grade: " << gb.calculateAverageGrade() << endl;

    return 0;
}