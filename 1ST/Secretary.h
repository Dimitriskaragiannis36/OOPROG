#ifndef SECRETARY_H
#define SECRETARY_H

#include "Person.h"
#include <vector>
using namespace std;
class Secretary {
    vector<Person*> v;

public:
    Secretary();
    Secretary(const Secretary& other);
    ~Secretary();

    Secretary operator+(const Person& p);
    bool personExists(const int& ID) const;

    friend istream& operator>>(istream& is, Secretary& s);
    friend ostream& operator<<(ostream& os, const Secretary& s);
    Secretary& operator=(const Secretary& other);
};

#endif 
