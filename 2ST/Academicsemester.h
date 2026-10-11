#ifndef ACADEMICSEMESTER_H
#define ACADEMICSEMESTER_H
#include <iostream>
#include <vector>
#include "Course.h"
#include "Student.h"
#include "Secretary.h"

class Academicsemester {
private:
    vector<Course*> courses;
    int semester;
public:
    Academicsemester();
    ~Academicsemester();
    Academicsemester(const Academicsemester& other);
    
    Academicsemester operator+(const Course& c);
    bool courseExists(const int& CODE) const;
    Academicsemester operator-(const int& CODE);
    
    friend istream& operator>>(istream& is, Academicsemester& a);
    friend ostream& operator<<(ostream& os, const Academicsemester& a);
    Academicsemester& operator=(const Academicsemester& other);
    
    Course* getCoursebyCode(int CODE) const;
    vector<Course*> getCourses() const;
    vector<Student> getPassedStudents(const Course& course) const;
    vector<Student> getPassedStudentsForCourse(int courseCode) const;
    int getNumberOfPassedStudentsForCourse(const Course& course) const;
    void printEnrolledStudentsForCourse(const Secretary& gram) const;
    int getSemester() const;
};
#endif