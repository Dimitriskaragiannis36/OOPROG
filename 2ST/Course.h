#ifndef COURSE_H
#define COURSE_H
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Professor;
class Student;

class Course {
private:
    int code, courseECTS, year, grade;
    string coursename;
    bool ismandatory;
    vector<Professor*> professors;
public:
    vector<Student*> enrolledStudents;
    
    Course();
    ~Course();
    
    friend istream &operator >> (istream &is, Course &c);
    friend ostream &operator << (ostream &os, Course &c);
    
    int getCode() const;
    int getYear() const;
    int getCourseECTS() const;
    bool operator==(const Course& other) const;
    void modifyCourse(int code2, int courseECTS2, int year2, string coursename2, bool ismandatory2);
    Course(const Course &other);
    
    void addProfessor(Professor* prof);
    void printProfessors() const;
    bool isProfessorTeachingCourse(int professorId, int courseCode) const;
    void enrollStudent(Student* student);
    vector<Student*> getEnrolledStudents() const;
    void assignGrade(Student* student, int grade);
    int getNumberOfPassedStudents() const;
    void printStudentGrades() const;
    bool isStudentEnrolled(int studentID) const;
    int getTotalEnrolledStudents() const;
};
#endif