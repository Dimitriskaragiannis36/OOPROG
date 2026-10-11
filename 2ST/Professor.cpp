#include "Professor.h"
#include "Course.h"
#include "Academicsemester.h"

Professor::Professor() {
    cout << "Professor constructed" << endl;
}

Professor::~Professor() {
    cout << "Professor destructed" << endl;
}

void Professor::addTeachingCourse(Course* course) {
    courses.push_back(course);
}

vector<Course*> Professor::getCourses() const {
    return courses; 
}

void Professor::modifyPerson(int id2, int age2, string phone2, string firstname2, string surname2) {
    this->id = id2;
    this->age = age2;
    this->phone = phone2;
    this->firstname = firstname2;
    this->surname = surname2;
}

Professor::Professor(const Professor &other) : Person(other) {}

void Professor::print(ostream& os) const {
    os << "Professor: " << id << endl;
    os << "id: " << id << endl;
    os << "age: " << age << endl;
    os << "phone: " << phone << endl;
    os << "firstname: " << firstname << endl;
    os << "surname: " << surname << endl;
}

void Professor::printStatisticsForProfessor(const Academicsemester& semester, int courseCode) const {
    cout << "Statistics for all courses taught by Professor " << getid() << ":" << endl;
    for (const Course* course : courses) {
        if (course->isProfessorTeachingCourse(getid(), courseCode)) {
            int totalStudents = course->getTotalEnrolledStudents();
            int passedStudents = semester.getNumberOfPassedStudentsForCourse(*course);
            cout << "Course: " << course->getCode() << endl;
            cout << "Total students: " << totalStudents << endl;
            cout << "Passed students: " << passedStudents << endl;
            cout << "Passing rate: " << (totalStudents > 0 ? (static_cast<double>(passedStudents) / totalStudents) * 100 : 0) << "%" << endl;
            cout << "------------------------" << endl;
        }
    }
}

istream &operator >> (istream &is, Professor &p) {
    cout << endl << "give id" << endl;
    is >> p.id;
    cout << "give age" << endl;
    is >> p.age;
    cout << "give phone" << endl;
    is >> p.phone;
    cout << "give firstname" << endl;
    is >> p.firstname;
    cout << "give surname" << endl;
    is >> p.surname;
    return is;
}

ostream &operator << (ostream &os, Professor &p) {
    os << "id: " << p.id << endl;
    os << "age: " << p.age << endl;
    os << "phone: " << p.phone << endl;
    os << "firstname: " << p.firstname << endl;
    os << "surname: " << p.surname << endl;
    return os;
}