#include <iostream>
#include <vector>
#include "Person.h"
#include "Student.h"
#include "Professor.h"
#include "Course.h"
#include "Secretary.h"
#include "Academicsemester.h"
#include "Department.h"

using namespace std;

int main() {
    Secretary gram;
    Academicsemester acasem;
    Student student;
    Professor professor;
    Course course;
    vector<Student> students;
    vector<Professor*> professors;
    
    int choice, ID, id2, age2, year2, earnedECTS2, grade2, semester2, CODE, code2, courseECTS2;
    string phone2, firstname2, surname2, coursename2; // Το phone2 έγινε string
    bool ismandatory2;
    
    cout << "select your preference from (0-9): "<<endl;
    cout <<"0 for app termination"<<endl;
    cout <<"1 for Professor addition"<<endl;
    cout <<"2 for Professor modification"<<endl;
    cout <<"3 for Professor removal"<<endl;
    cout <<"4 for Student addition"<<endl;
    cout <<"5 for Student modification"<<endl;
    cout <<"6 for Student removal"<<endl;
    cout <<"7 for Course addition"<<endl;
    cout <<"8 for Course modification"<<endl;
    cout <<"9 for Course removal"<<endl;
    cout <<"10 for Professor assignment"<<endl;
    cout <<"11 for Student enrollment"<<endl;
    cout <<"12 for number of students that passed a Course"<<endl;
    cout <<"13 for Professor printing statistics"<<endl;
    cout <<"14 for Student printing grades in this semester"<<endl;
    cout <<"15 for Student printing grades so far"<<endl;
    cout <<"16 for display students that can graduate"<<endl;
    cin >> choice;
    
    while (choice != 0) {
        try {
            if (choice < 0) {
                throw "Choice must be a non-negative number.";
            }
            switch (choice) {
                case 1: {
                    cin >> professor;
                    gram = gram + professor;
                    break;
                }
                case 2: {
                    cout << "Give the Professor's id you want to modify: "<< endl;
                    cin >> ID;
                    gram = gram - ID;
                    cout<<"give new id"<<endl;
                    cin>>id2;
                    cout<<"give new age"<<endl;
                    cin>>age2;
                    cout<<"give new phone"<<endl;
                    cin>>phone2;
                    cout<<"give new firstname"<<endl;
                    cin>>firstname2;
                    cout<<"give new surname"<<endl;
                    cin>>surname2;
                    professor.modifyPerson(id2, age2, phone2, firstname2, surname2);
                    gram = gram + professor;
                    cout << "Modified Professor to Secretary" << endl;
                    break;
                }
                case 3: {
                    cout << "Give the Professor's id you want to erase: "<< endl;
                    cin >> ID;
                    gram = gram - ID;
                    break;
                }
                case 4: {
                    cin >> student;
                    gram = gram + student;
                    break;
                }
                case 5: {
                    cout << "Give the Students's id you want to modify: "<< endl;
                    cin >> ID;
                    gram = gram - ID;
                    cout<<"give new id"<<endl;
                    cin>>id2;
                    cout<<"give new age"<<endl;
                    cin>>age2;
                    cout<<"give new phone"<<endl;
                    cin>>phone2;
                    cout<<"give new year"<<endl;
                    cin>>year2;
                    cout<<"give new earnedECTS"<<endl;
                    cin>>earnedECTS2;
                    cout<<"give new grade"<<endl;
                    cin>>grade2;
                    cout<<"give new semester"<<endl;
                    cin>>semester2;
                    cout<<"give new firstname"<<endl;
                    cin>>firstname2;
                    cout<<"give new surname"<<endl;
                    cin>>surname2;
                    student.modifyPerson(id2, age2, phone2, year2, earnedECTS2, grade2, semester2, firstname2, surname2);
                    gram = gram + student;
                    cout << "Modified Student to Secretary" << endl;
                    break;
                }
                case 6: {
                    cout << "Give the Students's id you want to erase: "<< endl;
                    cin >> ID;
                    gram = gram - ID;
                    break;
                }
                case 7: {
                    Course course;
                    cin >> course;
                    acasem = acasem + course;
                    cout << "Added Course to Academic semester" << endl;
                    break;
                }
                case 8: {
                    cout << "Give the Course's code you want to modify: "<< endl;
                    cin >> CODE;
                    acasem = acasem - CODE;
                    Course course;
                    cout<<"give new code"<<endl;
                    cin>> code2;
                    cout<<"give new course's ECTS"<< endl;
                    cin>> courseECTS2;
                    cout<<"give new year"<<endl;
                    cin>> year2;
                    cout<<"give new course's name"<< endl;
                    cin>> coursename2;
                    cout<<"Is the course mandatory? (1:yes 0:no)"<< endl;
                    cin>> ismandatory2;
                    course.modifyCourse(code2, courseECTS2, year2, coursename2, ismandatory2);
                    acasem = acasem + course;
                    cout << "Modified Course to Academic semester" << endl;
                    break;
                }
                case 9: {
                    cout << "Give the Course's code you want to erase: "<< endl;
                    cin >> CODE;
                    acasem = acasem - CODE;
                    break;
                }
                case 10: {
                    gram.addCourse(&course);
                    gram.assignProfessorToCourse(&professor, &course);
                    gram.addTeachingCourseByIDAndCode(gram, acasem);
                    break;
                }
                case 11: {
                    cout << "Enter the Student's ID you want to enroll: ";
                    cin >> ID;
                    Student* student = gram.getStudentbyID(ID);
                    cout << "Give the Course's code you want to check the enrolled Students "<< endl;
                    cin >> CODE;
                    if (student) {
                        Course* course = acasem.getCoursebyCode(CODE);
                        student->enrollToCourse(ID, course, gram);
                        vector<Student*> enrolledStudents = course->getEnrolledStudents();  
                        cout << "Enrolled students for Course " << course->getCode() << ":\n";
                        for (const auto& enrolledStudent : enrolledStudents) {
                            cout << "ID: " << enrolledStudent->getid() << endl;
                        }
                    } else {
                        cout << "No Student found with ID: " << ID << endl;
                    }
                    break;
                }
                case 12: {
                    cout << "Give the Course's code you want to check the passed Students "<< endl;
                    cin >> CODE;
                    vector<Student> passedStudents = acasem.getPassedStudentsForCourse(CODE);
                    cout << "Students who passed the course:" << endl;
                    for (const Student& student : passedStudents) {
                        cout << "Student ID: " << student.getid() << endl;
                    }
                    break;
                }
                case 13: {
                    cout << "Enter the Professor's ID for statistics: ";
                    cin >> ID;
                    Professor* selectedProfessor = gram.getProfessorbyID(ID);
                    if (selectedProfessor) {
                        cout << "Enter the Course code: ";
                        cin >> CODE;
                        selectedProfessor->printStatisticsForProfessor(acasem, CODE);
                    } else {
                        cout << "Professor not found with ID: " << ID << endl;
                    }
                    break;
                }
                case 14: {
                    cout << "Enter the Student's ID to print grades: ";
                    cin >> ID;
                    Student* student = gram.getStudentbyID(ID);
                    if (student) {
                        student->printGradesThisSemester();
                    } else {
                        cout << "Student not found with ID: " << ID << endl;
                    }
                    break;
                }
                case 15: {
                    cout << "Enter the Student's ID to print cumulative grades: ";
                    cin >> ID;
                    Student* student = gram.getStudentbyID(ID);
                    if (student) {
                        student->printGradesSoFar();
                    } else {
                        cout << "Student not found with ID: " << ID << endl;
                    }   
                    break;
                }
                case 16: {
                    cout << "Studets who can get degree:\n";
                    for (const Student& student : students) {
                        if (student.canGraduate()) {
                            cout << "ID: " << student.getid() <<endl;
                        }
                    }
                    break;
                }
                default:
                    throw "Invalid choice. Please choose a valid option.";
            }
        }
        catch (const char* errorMessage) {
            cout << "Error: " << errorMessage << endl;
        }
        cout << "select your preference from (0-9): "<<endl;
        cout <<"0 for app termination"<<endl;
        cout <<"1 for Professor addition"<<endl;
        cout <<"2 for Professor modification"<<endl;
        cout <<"3 for Professor removal"<<endl;
        cout <<"4 for Student addition"<<endl;
        cout <<"5 for Student modification"<<endl;
        cout <<"6 for Student removal"<<endl;
        cout <<"7 for Course addition"<<endl;
        cout <<"8 for Course modification"<<endl;
        cout <<"9 for Course removal"<<endl;
        cout <<"10 for Professor assignment"<<endl;
        cout <<"11 for Student enrollment"<<endl;
        cout <<"12 for number of students that passed a Course"<<endl;
        cout <<"13 for Professor printing statistics"<<endl;
        cout <<"14 for Student printing grades in this semester"<<endl;
        cout <<"15 for Student printing grades so far"<<endl;
        cout <<"16 for display students that can graduate"<<endl;
        cin >> choice;
    }
    return 0;
}