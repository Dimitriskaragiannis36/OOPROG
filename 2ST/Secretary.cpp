#include "Secretary.h"
#include "Academicsemester.h"

Secretary::Secretary() {
    cout << "Secretary constructed" << endl;
}

Secretary::~Secretary() {
    for (Professor* prof : professors) {
        delete prof;
    }
    professors.clear();
    for (Student* stu : students) {
        delete stu;
    }
    students.clear();
}

Secretary::Secretary(const Secretary& other) {
    for (const Professor* prof : other.professors) {
        professors.push_back(new Professor(*prof));
    }
    for (const Student* stu : other.students) {
        students.push_back(new Student(*stu));
    }
}

Secretary& Secretary::operator+(const Professor& prof) {
    for (const Professor* existingProf : professors) {
        if (existingProf->getid() == prof.getid()) {
            cout << "Error: Professor with the same ID already exists." << endl;
            return *this;
        }
    }
    professors.push_back(new Professor(prof));
    cout << "Added Professor to Secretary" << endl;
    return *this;
}

Secretary& Secretary::operator+(const Student& stu) {
    for (const Student* existingStu : students) {
        if (existingStu->getid() == stu.getid()) {
            cout << "Error: Student with the same ID already exists." << endl;
            return *this;
        }
    }
    students.push_back(new Student(stu));
    cout << "Added Student to Secretary" << endl;
    return *this;
}

bool Secretary::personExists(const int& ID) const {
    for (const Professor* prof : this->professors) {
        if (prof->getid() == ID) {
            cout << "Professor exists" << endl;
            return true;
        }
    }
    for (const Student* stu : this->students) {
        if (stu->getid() == ID) {
            cout << "Student exists" << endl;
            return true;
        }
    }
    cout << "Person does not exist" << endl;
    return false;
}

Secretary Secretary::operator-(const int& ID) {
    for (auto it = professors.begin(); it != professors.end(); ++it) {
        if (personExists(ID)) {
            delete *it;
            professors.erase(it);
            cout << "Professor with" << ID << " has been erased from Secretary" << endl;
            return *this;
        }
    }
    for (auto it = students.begin(); it != students.end(); ++it) {
        if (personExists(ID)) {
            delete *it;
            students.erase(it);
            cout << "Student with" << ID << " has been erased from Secretary" << endl;
            return *this;
        }
    }
    cout << "So, it cannot be erased" << endl;
    return *this;
}

Secretary& Secretary::operator=(const Secretary& other) {
    if (this != &other) {
        for (Professor* prof : professors) {
            delete prof;
        }
        professors.clear();
        for (const Student* stu : other.students) {
            students.push_back(new Student(*stu));
        }
    }
    return *this;
}

Professor* Secretary::getProfessorbyID(int ID) {
    if (professors.empty()) {
        cout << "No Professors available." << endl;
        return nullptr;
    }
    for (Professor* prof : professors) {
        if (prof && prof->getid() == ID) {
            cout << "Professor found with ID: " << ID << endl;
            return prof;
        }
    }
    cout << "No Professor found with ID: " << ID << endl;
    return nullptr;
}

Student* Secretary::getStudentbyID(int ID) {
    if (students.empty()) {
        cout << "No Students available." << endl;
        return nullptr;
    }
    for (Student* stu : students) {
        if (stu && stu->getid() == ID) {
            cout << "Student found with ID: " << ID << endl;
            return stu;
        }
    }
    cout << "No Student found with ID: " << ID << endl;
    return nullptr;
}

void Secretary::addCourse(Course* c) {
    courses.push_back(new Course(*c));
}

void Secretary::assignProfessorToCourse(Professor* professor, Course* course) {
    course->addProfessor(professor);
    cout << professor->getid() << endl;
}

void Secretary::addTeachingCourseByIDAndCode(Secretary& secretary, Academicsemester& academicSemester) {
    int id, code;
    cout << "Enter Professor's ID: ";
    cin >> id;
    cout << "Enter Course's Code: ";
    cin >> code;
    Professor* professor = secretary.getProfessorbyID(id);
    Course* course = academicSemester.getCoursebyCode(code);
    if (professor && course) {
        professor->addTeachingCourse(course);
        cout << "Professor assigned to course successfully.\n";
        cout << "Details of the assignment:\n";
        cout << "Professor ID: " << professor->getid() << "\n";
        cout << "Course Code: " << course->getCode() << endl;
    } else {
        cout << "Error: Invalid Professor ID or Course Code. Assignment failed." << endl;
    }
}

istream& operator>>(istream& is, Secretary& s) {
    char choice;
    do {
        cout << "Enter 'S' for Student, 'P' for Professor, or 'Q' to quit: ";
        is >> choice;

        if (choice == 'S') {
            Student* stu = new Student;
            is >> *stu;
            s.students.push_back(stu);
        } else if (choice == 'P') {
            Professor* prof = new Professor;
            is >> *prof;
            s.professors.push_back(prof);
        }
    } while (choice != 'Q');
    return is;
}

ostream &operator<<(ostream &os, const Secretary &s) {
    os << "Students:" << endl;
    for (const auto& student : s.students) {
        student->print(os);
        os << endl;
    }
    os << "Professors:" << endl;
    for (const auto& professor : s.professors) {
        professor->print(os);
        os << endl;
    }
    return os;
}