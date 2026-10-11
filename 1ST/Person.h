#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person {
    int static count;
    int id, age; // Αφαιρέθηκε το phone από εδώ
    string phone, firstname, surname, university, department, birthplace, home, mail; // Προστέθηκε εδώ

public:
    Person();
    ~Person();

    int static getcount();
    bool operator==(const Person& other) const;
    int getid() const;

    friend istream& operator>>(istream& is, Person& p);
    friend ostream& operator<<(ostream& os, const Person& p);
};

#endif