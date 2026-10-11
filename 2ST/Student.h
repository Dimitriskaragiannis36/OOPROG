#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Department.h"
#include <vector>
#include <map>

// Forward declarations για να αποφύγουμε τα include loops
class Course;
class Secretary;

class Student : public Person {
private:
    // Αφαιρέθηκαν τα id, age, phone, firstname, surname (τα παίρνει από την Person)
    int year, earnedECTS, grade, semester;
    vector<Course*> enrolledCourses;
    vector<Course*> passedCourses; 
    map<Course*, int> gradesForCourses; 
    const Department* department; 
    vector<int> grades;

public:
    Student();
    ~Student();
    
    friend istream &operator >> (istream &is, Student &stu);
    friend ostream &operator << (ostream &os, Student &stu);
    
    int getCurrentSemester() const;
    void modifyPerson(int id2, int age2, string phone2, int year2, int earnedECTS2, int grade2, int semester2, string firstname2, string surname2);
    Student(const Student &other);
    Student(const Department* dept);
    
    void enrollToCourse(int studentID, Course* course, Secretary& secretary);
    void setGrade(int newGrade);
    int getGrade() const;
    void addGrade(int grade);
    void print(ostream& os) const;
    bool hasPassed(const Course& course) const;
    void printGradesThisSemester() const;
    void printGradesSoFar() const;
    bool canGraduate() const;
    int calculateTotalEarnedECTS() const;
    int getCourseECTSForIndex(size_t index) const;
};
#endif