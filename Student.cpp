// Jayesh Bhairavnath Gore S-2 A-37 17/08/2026
#include <iostream>
#include <string>
using namespace std;
class Student{
private:
    string name, studentclass, dob, address, bloodgroup, 
    phoneNo, drivingLicense;
    char division;
    int rollNo;
    static int count;
public:
    Student(){
        cout<<"----- Default Constructor -----"<<endl;
        name = "Jayesh";
        studentclass = "SY_comp";
        dob = "DD/MM/YYYY";
        address = "Pune";
        bloodgroup = "A+";
        phoneNo = "9876543210";
        drivingLicense = "MH123456";
        division = 'A';
        rollNo = 37;
        count++;
        cout<<endl<<count<<endl;
    }
    Student(string n,string c,string d,string add,string bg,string pN,string dL, char div, int roll){
        cout<<"----- Parameterized Constructor -----"<<endl;
        name = n;
        studentclass = c;
        dob = d;
        address = add;
        bloodgroup = bg;
        phoneNo = pN;
        drivingLicense = dL;
        division = div;
        rollNo = roll;

        count++;
        cout<<endl<<count<<endl;
    }
    Student(const Student &s){
        cout<<"----- Copy Constructor -----"<<endl;
        name = s.name;
        studentclass = s.studentclass;
        dob = s.dob;
        address = s.address;
        bloodgroup = s.bloodgroup;
        phoneNo = s.phoneNo;
        drivingLicense = s.drivingLicense;
        division = s.division;
        rollNo = s.rollNo;
        count++;
        cout<<endl<<count<<endl;
    }
    void Display()
    {
        cout << "\n-------Student Information-------\n";
        cout << "Name is               : " << name << endl;
        cout << "student class is      : " << studentclass << endl;
        cout << "dob is                : " << dob << endl;
        cout << "address is            : " << address << endl;
        cout << "bloodgroup is         : " << bloodgroup << endl;
        cout << "phoneNo is            : " << phoneNo << endl;
        cout << "drivingLicense is     : " << drivingLicense << endl;
        cout << "division is           : " << division << endl;
        cout << "rollNo is             : " << rollNo << endl;
        cout << endl;
    }
    ~Student(){
        count--;
        cout<<"----- Destructor called for division: "<<division<<endl;
        cout<<"Count                         : "<<count<<endl;
     }
     static void Output(){
         cout<<"----- Total Student Objects: "<<count<<endl;
         cout<<endl;
     }
     friend class Database;
};
int Student::count =0;

class Database{
public:
    void show(const Student &a){
        cout<<"------ Friend Class ------"<<endl;
        cout<<"Roll No. : " <<a.rollNo<<endl;
        cout<<endl;
   }
};
int main(){
    Student s1;

    s1.Display();

    Student s2("jai", "SY_Comp", "DD/MM/YYYY", "Pune", "A+",
               "9876435120", "MH123456", 'A', 37);

    s2.Display();

    Student s3(s1);

    s3.Display();

    Student::Output();

    Database db;
    db.show(s2);

    return 0;
}