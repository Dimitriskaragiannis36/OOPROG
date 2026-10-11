#include "Course.h"
#include "Professor.h"
#include "Student.h"

Course::Course() {
    cout << "Course constructed" << endl;
}

Course::~Course() {
    cout << "Course destructed" << endl;
}

int Course::getCode() const { return code; }
int Course::getYear() const { return year; }
int Course::getCourseECTS() const { return courseECTS; }

bool Course::operator==(const Course& other) const {
    return (this->code == other.code);
}

void Course::modifyCourse(int code2, int courseECTS2, int year2, string coursename2, bool ismandatory2) {
    this->code = code2;
    this->courseECTS = courseECTS2;
    this->year = year2;
    this->coursename = coursename2;
    this->ismandatory = ismandatory2;
}

Course::Course(const Course &other) {
    this->code = other.code;
    this->courseECTS = other.courseECTS;
    this->year = other.year;
    this->coursename = other.coursename;
    this->ismandatory = other.ismandatory;
}

void Course::addProfessor(Professor* prof) {
    professors.push_back(prof);
}

void Course::printProfessors() const {
    cout << "Professors teaching this course:\n";
    for (const Professor* professor : professors) {
        cout << "Professor ID: " << professor->getid() << "\n";
    }
}

bool Course::isProfessorTeachingCourse(int professorId, int courseCode) const {
    for (const Professor* prof : professors) {
        if (prof->getid() == professorId) {
            for (const Course* course : prof->getCourses()) {
                if (course->getCode() == courseCode) {
                    return true;
                }
            }
        }
    }
    return false;
}

void Course::enrollStudent(Student* student) {
    enrolledStudents.push_back(student);
}

vector<Student*> Course::getEnrolledStudents() const {
    return enrolledStudents;
}

void Course::assignGrade(Student* student, int grade) {
    for (Student* enrolledStudent : enrolledStudents) {
        if (enrolledStudent == student) {
            enrolledStudent->setGrade(grade);
            break;
        }
    }
}

int Course::getNumberOfPassedStudents() const {
    int count = 0;
    for (const Student* student : enrolledStudents) {
        if (student->getGrade() >= 5) {
            count++;
        }
    }
    return count;
}

void Course::printStudentGrades() const {
    cout << "Student Grades for the Course:" << endl;
    for (const Student* student : enrolledStudents) {
        cout << "Student ID: " << student->getid() << ", Grade: " << student->getGrade() << endl;
    }
}

bool Course::isStudentEnrolled(int studentID) const {
    for (const Student* enrolledStudent : enrolledStudents) {
        if (enrolledStudent->getid() == studentID) {
            return true;
        }
    }
    return false;
}

int Course::getTotalEnrolledStudents() const {
    return enrolledStudents.size();
}

istream &operator >> (istream &is, Course &c) {
    cout << endl << "give code" << endl;
    is >> c.code;
    cout << "give Course's ECTS'" << endl;
    is >> c.courseECTS;
    cout << "give Course's year'" << endl;
    is >> c.year;
    cout << "give Course's name'" << endl;
    is >> c.coursename;
    cout << "Is it mandatory? (1:yes 0:no)" << endl;
    is >> c.ismandatory;
    return is;
}

ostream &operator << (ostream &os, Course &c) {
    os << "code: " << c.code << endl;
    os << "course's ECTS: " << c.courseECTS << endl;
    os << "course's year: " << c.year << endl;
    os << "course's name': " << c.coursename << endl;
    os << "mandatory: (1:yes 0:no) " << c.ismandatory << endl;
    return os;
}