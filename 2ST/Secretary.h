#ifndef SECRETARY_H
#define SECRETARY_H
#include <iostream>
#include <vector>
#include "Professor.h"
#include "Student.h"
#include "Course.h"

class Academicsemester;

class Secretary {
private:
    vector<Course*> courses;  
public:
    vector<Professor*> professors;
    vector<Student*> students;
    
    Secretary();
    virtual ~Secretary();
    Secretary(const Secretary& other);
    
    Secretary& operator+(const Professor& prof);
    Secretary& operator+(const Student& stu);
    bool personExists(const int& ID) const;
    Secretary operator-(const int& ID);
    
    friend istream& operator>>(istream& is, Secretary& s);
    friend ostream& operator<<(ostream& os, const Secretary& s);
    Secretary& operator=(const Secretary& other);
    
    Professor* getProfessorbyID(int ID);
    Student* getStudentbyID(int ID);
    void addCourse(Course* c);
    void assignProfessorToCourse(Professor* professor, Course* course);
    void addTeachingCourseByIDAndCode(Secretary& secretary, Academicsemester& academicSemester);
};
#endif