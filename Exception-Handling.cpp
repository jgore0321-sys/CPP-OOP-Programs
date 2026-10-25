#include <iostream>
#include <string>
using namespace std;

class publication{
protected:
    string title;
    float price;
public:
    void input(){
        cout<<"Enter Title : ";
        cin>>title;

        cout<<"Enter Price : ";
        cin>>price;

        if(price < 0){
            throw price;
        }
    }

    void display(){
        cout<<"Title : "<<title<<endl;
        cout<<"Price : "<<price<<endl;
    }

    void zero(){
        title = "";
        price = 0;
    }
};
class book:public publication{
private:
    int pages;
public:
    void input(){
        publication::input();
        cout<<"Enter Number of pages : ";
        cin>>pages;

        if(pages < 0){
            throw pages;
        }
    }

    void dispaly(){
        publication::display();
        cout<<"Pages : "<<pages<<endl;
    }

    void zero(){
        publication::zero();
        pages = 0;
    }
};
class tape:public publication{
private:
    float time;
public:
   void input(){
        publication::input();
        cout<<"Enter time in minutes : ";
        cin>>time;

        if(time < 0){
            throw time;
        }
    }

    void dispaly(){
        publication::display();
        cout<<"Time in minutes : "<<time<<endl;
    }

    void zero(){
        publication::zero();
        time = 0;
    }
};

int main(){
    book b1;
    tape t1;
    try{
        cout<<"\nTaking Input.......\n";
        b1.input();
        cout<<endl;
        t1.input();
    }
    catch (float e) {
        cout << "Exception caught! Negative price or time.\n";
        b1.zero();
        t1.zero();
    }
    catch (int e) {
        cout << "Exception caught! Negative number of pages.\n";
        b1.zero();
        t1.zero();
    }
    
    cout << "\nBook: \n";
    b1.display();

    cout << "\nTape: \n";
    t1.display();

    return 0;
}