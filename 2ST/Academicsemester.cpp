#include "Academicsemester.h"

Academicsemester::Academicsemester() {
    cout << "Academic semester constructed" << endl;
}

Academicsemester::~Academicsemester() {
    cout << "Academic semester destructed" << endl;
    for (Course* c : courses) {
        delete c;
    }
}

Academicsemester::Academicsemester(const Academicsemester& other) {
    for (const Course* c : other.courses) {
        courses.push_back(new Course(*c));
    }
}

Academicsemester Academicsemester::operator+(const Course& c) {
    courses.push_back(new Course(c));
    return *this;
}

bool Academicsemester::courseExists(const int& CODE) const {
    for (const Course* c : this->courses) {
        if (c->getCode() == CODE) {
            cout << "Course exists" << endl;
            return true;
        }
    }
    cout << "Course does not exist" << endl;
    return false;
}

Academicsemester Academicsemester::operator-(const int& CODE) {
    for (auto it = courses.begin(); it != courses.end(); ++it) {
        if (courseExists(CODE)) {
            delete *it;
            courses.erase(it);
            cout << "Course with" << CODE << " has been erased from Academic semester" << endl;
            return *this;
        } else {
            cout << "So, it cannot be erased" << endl;
        }
    }
    return *this;
}

Academicsemester& Academicsemester::operator=(const Academicsemester& other) {
    if (this != &other) {
        for (Course* c : courses) {
            delete c;
        }
        courses.clear();
        for (const Course* c : other.courses) {
            courses.push_back(new Course(*c));
        }
    }
    return *this;
}

Course* Academicsemester::getCoursebyCode(int CODE) const {
    if (courses.empty()) {
        cout << "No Courses available." << endl;
        return nullptr;
    }
    for (Course* course : courses) {
        if (course && course->getCode() == CODE) {
            cout << "Course found with CODE: " << CODE << endl;
            return course;
        }
    }
    return nullptr;
}

vector<Course*> Academicsemester::getCourses() const {
    return courses;
}

vector<Student> Academicsemester::getPassedStudents(const Course& course) const {
    vector<Student> passedStudents;
    vector<Student*> enrolledStudents = course.getEnrolledStudents();
    for (const Student* student : enrolledStudents) {
        if (student->hasPassed(course)) {
            passedStudents.push_back(*student);
        }
    }
    return passedStudents;
}

vector<Student> Academicsemester::getPassedStudentsForCourse(int courseCode) const {
    Course* course = getCoursebyCode(courseCode);
    if (course) {
        return getPassedStudents(*course);
    } else {
        cout << "Course not found with code: " << courseCode << endl;
        return vector<Student>();
    }
}

int Academicsemester::getNumberOfPassedStudentsForCourse(const Course& course) const {
    int count = 0;
    for (const Student* student : course.getEnrolledStudents()) {
        if (student->getGrade() >= 5) {
            count++;
        }
    }
    return count;
}

void Academicsemester::printEnrolledStudentsForCourse(const Secretary& gram) const {
    int courseCode;
    cout << "Give the Course's code you want to check the enrolled Students: ";
    cin >> courseCode;
    Course* course = getCoursebyCode(courseCode);
    if (course) {
        vector<Student*> enrolledStudents = course->getEnrolledStudents();
        cout << "Enrolled students for Course " << course->getCode() << " (" << endl;
        for (const Student* student : enrolledStudents) {
            cout << "Student ID: " << student->getid() << endl;
        }
    } else {
        cout << "Course not found with code: " << courseCode << endl;
    }
}

int Academicsemester::getSemester() const {
    return semester; 
}

istream& operator>>(istream& is, Academicsemester& a) {
    Course* course = new Course;
    is >> *course;
    a.courses.push_back(course);
    return is;
}

ostream &operator<<(ostream &os, const Academicsemester &a) {
    for (const auto &Course : a.courses) {
        os << *Course << endl;
    }
    return os;
}