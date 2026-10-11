#include "Person.h"
using namespace std;
int Person::count = 0;

Person::Person() {
    cout << "constructed" << endl;
    count++;
}

Person::~Person() {
    cout << "deconstructed" << endl;
}

int Person::getcount() {
    return count;
}

bool Person::operator==(const Person& other) const {
    return (this->id == other.id);
}

int Person::getid() const {
    return id;
}

istream& operator>>(istream& is, Person& p) {
    cout<<endl<<"give id"<<endl;			
    is >> p.id;								
    cout<<"give age"<<endl;						
    is >> p.age;								
    cout<<"give phone"<<endl;					
    is >> p.phone;
    
    cout<<"give firstname"<<endl;
    getline(is >> ws, p.firstname);
    
    cout<<"give surname"<<endl;
    getline(is >> ws, p.surname);
    
    cout<<"give university"<<endl;
    getline(is >> ws, p.university);
    
    cout<<"give department"<<endl;
    getline(is >> ws, p.department);
    
    cout<<"give birthplace"<<endl;
    getline(is >> ws, p.birthplace);
    
    cout<<"give home"<<endl;
    getline(is >> ws, p.home);
    
    cout<<"give mail"<<endl;
    is >> p.mail; // Το email δεν έχει κενά, οπότε το αφήνουμε ως έχει
    
    return is;
}

ostream& operator<<(ostream& os, const Person& p) {
    os <<"id: "<< p.id<<endl;					
	os <<"age: "<< p.age<<endl;					  
	os <<"phone: "<< p.phone<<endl;				
	os << "firstname: "<< p.firstname<<endl;
	os << "surname: " << p.surname<<endl;
	os << "university: "<< p.university<<endl;
	os << "department: " << p.department<<endl;
	os << "birthplace: "<< p.birthplace<<endl;
	os << "home: " << p.home<<endl;
	os << "mail: "<< p.mail<<endl;	
    return os;
}

