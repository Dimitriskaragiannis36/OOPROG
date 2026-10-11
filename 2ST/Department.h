#ifndef DEPARTMENT_H
#define DEPARTMENT_H
class Department {
private:
    int requiredStudyYears, mandatoryCourses, requiredECTS;           
public:
    Department(int studyYears, int courses, int ects)
        : requiredStudyYears(studyYears), mandatoryCourses(courses), requiredECTS(ects) {}
    int getRequiredStudyYears() const { return requiredStudyYears; }
    int getMandatoryCourses() const { return mandatoryCourses; }
    int getRequiredECTS() const { return requiredECTS; }
};
#endif