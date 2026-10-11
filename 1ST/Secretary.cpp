#include "Secretary.h"
using namespace std;
Secretary::Secretary() {
    cout << "constructed Secretary" << endl;
}

Secretary::Secretary(const Secretary& other) {
    for (const Person* p : other.v) {	 
            v.push_back(new Person(*p));	
        }
}

Secretary::~Secretary() {
    cout << "deconstructed Secretary" << endl;
   for (Person* p : v) {				
            delete p;					
        }
}

Secretary Secretary::operator+(const Person& p) {
   v.push_back(new Person(p));	
    return *this;
}

bool Secretary::personExists(const int& ID) const {
    for (const Person* p : this->v) {		
        if (p->getid() == ID) {
            cout << "exists" << endl;		
            return true;
        }					
    }
    cout << "does not exist" << endl;
    return false;
}

istream& operator>>(istream& is, Secretary& s) {
      Person* person = new Person;				
        is >> *person;							
        s.v.push_back(person);
    return is;
}

ostream& operator<<(ostream& os, const Secretary& s) {
    for (const auto &Person : s.v) {			
         os<< *Person << endl;							
    }
    return os;
}

Secretary& Secretary::operator=(const Secretary& other) {
	if (this != &other) {						
            for (Person* p : v) {					
                delete p;							
            }
            v.clear();																
            for (const Person* p : other.v) {		
                v.push_back(new Person(*p));
            }
        }
    return *this;
}

