#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Patient
{
protected:
    string name;
    int age;
    string address;
    string diagnosis;
public:
    void enterInfo()
    {
        cout << "Enter patient name: ";
        cin>>name;
        cout << "Enter patient age: ";
        cin >> age;
        cout << "Enter patient address: ";
        cin>>address;
        cout << "Enter diagnosis: ";
        cin>>diagnosis;
    }
    void displayInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Address: " << address << endl;
        cout << "Diagnosis: " << diagnosis << endl;
    }
};
class PediatricPatient : public Patient
{
private:
    string guardianName;
public:
    void enterInfo()
    {
        Patient::enterInfo();
        cout << "Enter guardian's name: ";
        cin>>guardianName;
    }
    void displayInfo()
    {
        Patient::displayInfo();
        cout << "Guardian's Name: " << guardianName <<"\n";
    }
};
int main()
{
    const int MAX_PATIENTS = 100;
    Patient *patients[MAX_PATIENTS];
    int numPatients = 0;
    int choice;
    while(1){
        cout << "\n1-Add a patient\n2-Display all patients\n3-Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            char patientType;
            cout << "Enter patient type (P for pediatric, A for adult): ";
            cin >> patientType;
            if (patientType == 'P') {
                PediatricPatient *pedPatient = new PediatricPatient();
                pedPatient->enterInfo();
                patients[numPatients] = pedPatient;
                numPatients++;
            } else if (patientType == 'A') {
                Patient *patient = new Patient();
                patient->enterInfo();
                patients[numPatients] = patient;
                numPatients++;
            } else {
                cout << "Invalid patient type." << endl;
            }
            break;
        }
        case 2:
            if (numPatients == 0) {
                cout << "No patients in the database." << endl;
            } else {
                for (int i = 0; i < numPatients; i++) {
                    cout << "Patient " << (i + 1) << ":" << endl;
                    patients[i]->displayInfo();
                    cout << endl;
                }
            }
            break;
        case 3:
            cout << "Exiting program\n";
            exit(0);
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } 
    return 0;
}
