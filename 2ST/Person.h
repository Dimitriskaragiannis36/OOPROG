#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;

class Person {
protected: // ΑΛΛΑΓΗ: Έγιναν protected για να τα βλέπουν οι Student & Professor
    static int count;
    int id, age;
    string phone, firstname, surname; // ΑΛΛΑΓΗ: Το phone έγινε string

public:
    Person();
    virtual ~Person();
    
    static int getcount();
    friend istream &operator >> (istream &is, Person &p);
    friend ostream &operator << (ostream &os, Person &p);
    
    int getid() const;
    bool operator==(const Person& other) const;
    void modifyPerson(int id2, int age2, string phone2, string firstname2, string surname2);
    Person(const Person &other);
};
#endif