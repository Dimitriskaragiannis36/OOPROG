#ifndef PROFESSOR_H
#define PROFESSOR_H
#include "Person.h"
#include <vector>

class Course;
class Academicsemester;

class Professor : public Person {
private:
    vector<Course*> courses;

public:
    Professor();
    ~Professor();
    
    void addTeachingCourse(Course* course);
    friend istream &operator >> (istream &is, Professor &prof);
    friend ostream &operator << (ostream &os, Professor &prof);
    
    vector<Course*> getCourses() const;
    void modifyPerson(int id2, int age2, string phone2, string firstname2, string surname2);
    Professor(const Professor &other);
    void print(ostream& os) const;
    void printStatisticsForProfessor(const Academicsemester& semester, int courseCode) const;
};
#endif