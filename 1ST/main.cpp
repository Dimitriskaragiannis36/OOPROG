#include "Secretary.h"
using namespace std;
int main() {
    Secretary gram;
	int press, ID;
	cout << "for STUDENT press 1\n";
    cout << "for PROFESSOR press 2\n";
    cout << "for SEARCH press 3\n";
    cout << "for DISPLAY ALL press 4\n";
    cout << "for EXIT press 0\n";
	cin>>press;							
	 while (press != 0) {				
        if (press == 1) {
            Person student;
            cin >> student;				
            gram = gram + student;		
            cout << "Added Student to Secretary" << endl;		
        } else if (press == 2) {
            Person professor;
            cin >> professor;			
            gram = gram + professor;
            cout << "Added Professor to Secretary" << endl;
        } else if (press == 3) {
            cout << "give id: ";			 
            cin >> ID;						
            gram.personExists(ID);			
        } else if (press == 4) {
            cout << "All Persons in Secretary:" << endl;
            cout << gram;					
        }								

        cout << endl;
        cout << "for STUDENT press 1\n";		
    	cout << "for PROFESSOR press 2\n";
        cout << "for SEARCH press 3\n";
    	cout << "for DISPLAY ALL press 4\n";
        cout << "for EXIT press 0\n";
        cin >> press;
    }
    cout << "Number of Person objects created: " << Person::getcount() << endl;

    return 0;
}

