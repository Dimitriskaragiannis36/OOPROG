#include "Student.h"
#include "Course.h"
#include "Secretary.h"

Student::Student() {
    cout << "Student constructed" << endl;
}

Student::~Student() {
    cout << "Student destructed" << endl;
}

Student::Student(const Department* dept) : year(0), earnedECTS(0), department(dept) {}

int Student::getCurrentSemester() const {
    return semester;
}

void Student::modifyPerson(int id2, int age2, string phone2, int year2, int earnedECTS2, int grade2, int semester2, string firstname2, string surname2) {
    this->id = id2;
    this->age = age2;
    this->phone = phone2;
    this->year = year2;
    this->earnedECTS = earnedECTS2;
    this->grade = grade2;
    this->semester = semester2;
    this->firstname = firstname2;
    this->surname = surname2;
}

Student::Student(const Student &other) : Person(other) {
    this->year = other.year;
    this->earnedECTS = other.earnedECTS;
    this->grade = other.grade;
    this->semester = other.semester;
}

void Student::enrollToCourse(int ID, Course* course, Secretary& secretary) {
    if (course->getYear() <= this->year) {
        enrolledCourses.push_back(course);
        this->id = ID; 
        cout << "Enrolled in course successfully.\n";
        course->enrollStudent(this);
    } else {
        cout << "Error: Cannot enroll in this course. Invalid year.\n";
    }
}

void Student::setGrade(int newGrade) {
    grade = newGrade;
}

int Student::getGrade() const {
    return grade;
}

void Student::addGrade(int grade) {
    grades.push_back(grade);
}

void Student::print(ostream& os) const {
    os << "Student: " << endl;
    os << "id: " << id << endl;
    os << "age: " << age << endl;
    os << "phone: " << phone << endl;
    os << "year: " << year << endl;
    os << "earnedECTS: " << earnedECTS << endl;
    os << "grade: " << grade << endl;
    os << "semester: " << semester << endl;
    os << "firstname: " << firstname << endl;
    os << "surname: " << surname << endl;
}

bool Student::hasPassed(const Course& course) const {
    return course.isStudentEnrolled(getid()) && grade >= 5;
}

void Student::printGradesThisSemester() const {
    cout << "Grades for Student ID " << id << " in the current semester:\n";
    for (size_t i = 0; i < grades.size(); ++i) {
        cout << "Course " << i + 1 << ": Grade " << grades[i] << "\n";
    }
}

void Student::printGradesSoFar() const {
    cout << "Cumulative Grades for Student ID " << id << ":\n";
    int cumulativeGrade = 0;
    for (size_t i = 0; i < grades.size(); ++i) {
        cumulativeGrade += grades[i];
        cout << "Course " << i + 1 << ": Cumulative Grade " << cumulativeGrade << "\n";
    }
}

bool Student::canGraduate() const {
    if (year < 4) {  
        return false;
    }
    for (int grade : grades) {
        if (grade < 100) { // Όπως ακριβώς ήταν στο αρχικό αρχείο
            return false;
        }
    }
    int totalEarnedECTS = calculateTotalEarnedECTS();
    return totalEarnedECTS >= 200; 
}

int Student::calculateTotalEarnedECTS() const {
    int totalEarnedECTS = 0;
    for (size_t i = 0; i < grades.size(); ++i) {
        if (grades[i] >= 5) {
            totalEarnedECTS += getCourseECTSForIndex(i);
        }
    }
    return totalEarnedECTS;
}

int Student::getCourseECTSForIndex(size_t index) const {
    if (index < passedCourses.size() && passedCourses[index]) {
        return passedCourses[index]->getCourseECTS();
    } else {
        cout << "Error: Index out of bounds or null pointer" << endl;
        return 0; 
    }
}

istream &operator >> (istream &is, Student &p) {
    cout << endl << "give id" << endl;
    is >> p.id;
    cout << "give age" << endl;
    is >> p.age;
    cout << "give phone" << endl;
    is >> p.phone;
    cout << "give year" << endl;
    is >> p.year;
    cout << "give earnedECTS" << endl;
    is >> p.earnedECTS;
    cout << "give grade" << endl;
    is >> p.grade;
    cout << "give semester" << endl;
    is >> p.semester;
    cout << "give firstname" << endl;
    is >> p.firstname;
    cout << "give surname" << endl;
    is >> p.surname;
    return is;
}

ostream &operator << (ostream &os, Student &p) {
    os << "id: " << p.id << endl;
    os << "age: " << p.age << endl;
    os << "phone: " << p.phone << endl;
    os << "year: " << p.year << endl;
    os << "earndECTS: " << p.earnedECTS << endl;
    os << "grade: " << p.grade << endl;
    os << "semester: " << p.semester << endl;
    os << "firstname: " << p.firstname << endl;
    os << "surname: " << p.surname << endl;
    return os;
}