#include <iostream>
#include <string>
using namespace std;
class PersonalRecord{
protected:
    string name, address, phone;
    int age;

public:
    void acceptPersonal(){
        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Address: ";
        cin >> address;

        cout << "Enter Phone Number: ";
        cin >> phone;
    }

    void displayPersonal(){
        cout << "\n--- Personal Record ---" << endl;
        cout << "Name    : " << name << endl;
        cout << "Age     : " << age << endl;
        cout << "Address : " << address << endl;
        cout << "Phone   : " << phone << endl;
    }
};

class ProfessionalRecord{
protected:
    string company, designation;
    float salary;

public:
    void acceptProfessional(){
        cout << "\nEnter Company Name: ";
        cin >> company;

        cout << "Enter Designation: ";
        cin >> designation;

        cout << "Enter Salary: ";
        cin >> salary;
    }

    void displayProfessional(){
        cout << "\n--- Professional Record ---" << endl;
        cout << "Company     : " << company << endl;
        cout << "Designation : " << designation << endl;
        cout << "Salary      : " << salary << endl;
    }
};

class AcademicRecord{
protected:
    string qualification, university;
    float percentage;

public:
    void acceptAcademic(){
        cout << "\nEnter Qualification: ";
        cin >> qualification;

        cout << "Enter University: ";
        cin >> university;

        cout << "Enter Percentage: ";
        cin >> percentage;
    }

    void displayAcademic(){
        cout << "\n--- Academic Record ---" << endl;
        cout << "Qualification : " << qualification << endl;
        cout << "University    : " << university << endl;
        cout << "Percentage    : " << percentage << "%" << endl;
    }
};

class BioData : public PersonalRecord,public ProfessionalRecord,public AcademicRecord{
public:
    void accept(){
        acceptPersonal();
        acceptProfessional();
        acceptAcademic();
    }

    void display(){
        cout << "\n\n========== EMPLOYEE BIO-DATA ==========" << endl;

        displayPersonal();
        displayProfessional();
        displayAcademic();

        cout << "=======================================" << endl;
    }
};

int main(){
    BioData employee;

    employee.accept();
    employee.display();

    return 0;
}