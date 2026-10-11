#include "Person.h"

int Person::count = 0; // Αρχικοποίηση στατικού μέλους

Person::Person() {
    cout << "Person constructed" << endl;
    count++;
}

Person::~Person() {
    cout << "Person destructed" << endl;
}

int Person::getcount() {
    return count;
}

int Person::getid() const {
    return id;
}

bool Person::operator==(const Person& other) const {
    return (this->id == other.id);
}

void Person::modifyPerson(int id2, int age2, string phone2, string firstname2, string surname2) {
    this->id = id2;
    this->age = age2;
    this->phone = phone2;
    this->firstname = firstname2;
    this->surname = surname2;
}

Person::Person(const Person &other) {
    this->id = other.id;
    this->age = other.age;
    this->phone = other.phone;
    this->firstname = other.firstname;
    this->surname = other.surname;
}

istream &operator >> (istream &is, Person &p) {
    cout << endl << "give id" << endl;
    is >> p.id;
    cout << "give age" << endl;
    is >> p.age;
    cout << "give phone" << endl;
    is >> p.phone;
    cout << "give firstname" << endl;
    is >> p.firstname;
    cout << "give surname" << endl;
    is >> p.surname;
    return is;
}

ostream &operator << (ostream &os, Person &p) {
    os << "id: " << p.id << endl;
    os << "age: " << p.age << endl;
    os << "phone: " << p.phone << endl;
    os << "firstname: " << p.firstname << endl;
    os << "surname: " << p.surname << endl;
    return os;
}