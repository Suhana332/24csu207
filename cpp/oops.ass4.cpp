#include <iostream>
#include <string>
#include <vector>
using namespace std;


class UniversitySystemException {
protected:
    string message;
public:
    UniversitySystemException(string msg) : message(msg) {}
    string getMessage() { return message; }
};

class EnrollmentException : public UniversitySystemException {
public:
    EnrollmentException(string msg) : UniversitySystemException("Enrollment Error: " + msg) {}
};

class GradeException : public UniversitySystemException {
public:
    GradeException(string msg) : UniversitySystemException("Grade Error: " + msg) {}
};

class PaymentException : public UniversitySystemException {
public:
    PaymentException(string msg) : UniversitySystemException("Payment Error: " + msg) {}
};


class Person {
protected:
    string name;
    int age;
    string id;
    string contact;

public:
    Person(string n, int a, string i, string c) : name(n), age(a), id(i), contact(c) {}

    void displayDetails() {
        cout << "Name: " << name << "\nAge: " << age 
             << "\nID: " << id << "\nContact: " << contact << endl;
    }

    double calculatePayment() { return 0.0; }
};

// Student Class
class Student : public Person {
protected:
    string enrollmentDate;
    string program;
    double gpa;

public:
    Student(string n, int a, string i, string c, 
            string ed, string p, double g) 
        : Person(n, a, i, c), enrollmentDate(ed), program(p), gpa(g) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Enrollment Date: " << enrollmentDate 
             << "\nProgram: " << program 
             << "\nGPA: " << gpa << endl;
    }
};

// Professor Class
class Professor : public Person {
protected:
    string department;
    int yearsOfService;

public:
    Professor(string n, int a, string i, string c,
              string dpt, int yos)
        : Person(n, a, i, c), department(dpt), yearsOfService(yos) {}

    void displayDetails() {
        Person::displayDetails();
        cout << "Department: " << department 
             << "\nYears of Service: " << yearsOfService << endl;
    }

    double calculatePayment() {
        return 5000 + (yearsOfService * 200); 
    }
};


class Course {
private:
    string code;
    string title;
    int credits;
    Professor* instructor;

public:
    Course(string c, string t, int crdts, Professor* instr)
        : code(c), title(t), credits(crdts), instructor(instr) {}

    void displayCourseDetails() {
        cout << "Course Code: " << code 
             << "\nTitle: " << title 
             << "\nCredits: " << credits;
    }
};

class Department {
private:
    string name;
    vector<Professor*> professors;

public:
    Department(string n) : name(n) {}

    void addProfessor(Professor* prof) { professors.push_back(prof); }

    void displayProfessors() {
        cout << "Professors in Department: " << name << endl;
        for (size_t i = 0; i < professors.size(); ++i) {
            professors[i]->displayDetails();
            cout << endl;
        }
    }
};

class GradeBook {
private:
    struct GradeEntry {
        string studentId;
        double grade;
    };
    vector<GradeEntry> grades;

public:
    void addGrade(string studentId, double grade) {
        if (grade < 0 || grade > 4.0)
            throw GradeException("Invalid grade value.");
        grades.push_back({studentId, grade});
    }

    double calculateAverageGrade() {
        double total = 0;
        for (size_t i = 0; i < grades.size(); ++i)
            total += grades[i].grade;

        if (grades.empty())
            throw GradeException("No grades available to calculate average.");

        return total / grades.size();
    }
};


class UniversitySystem {
private:
    vector<Department> departments;

public:
    void addDepartment(Department dept) { departments.push_back(dept); }

    void displayAllDepartments() {
        for (size_t i = 0; i < departments.size(); ++i)
            departments[i].displayProfessors();
    }
};


int main() {
    try {
        // Create Professors
        Professor prof1("Dr. Smith", 45, "P001", "smith@uni.edu", "Computer Science", 20);
        Professor prof2("Dr. Johnson", 50, "P002", "johnson@uni.edu", "Mathematics", 25);

        // Create Courses
        Course course1("CS101", "Intro to Programming", 3, &prof1);
        Course course2("MATH101", "Calculus I", 4, &prof2);

        // Create Students
        Student student1("Alice", 20, "S001", "alice@uni.edu", "2023-09-01", "CS", 3.8);
        
        // Create Department and Add Professors
        Department csDept("Computer Science");
        csDept.addProfessor(&prof1);

        Department mathDept("Mathematics");
        mathDept.addProfessor(&prof2);

        // Create University System and Add Departments
        UniversitySystem university;
        university.addDepartment(csDept);
        university.addDepartment(mathDept);

        // Display All Departments
        university.displayAllDepartments();

        GradeBook gb;
        gb.addGrade("S001", 3.8);
        
        cout << "\nAverage Grade: " << gb.calculateAverageGrade() << endl;

    } catch (UniversitySystemException& e) {
        cerr << e.getMessage() << endl;
    }

    return 0;
}