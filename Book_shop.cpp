#include <iostream>
#include <string>
using namespace std;

class Publication{
public:
    string *title, *author, *publisher;
    float *price;

    Publication(string t, string a, string p, float pr){
        title = new string;
        author = new string;
        publisher = new string;
        price = new float;

        *title = t;
        *author = a;
        *publisher = p;
        *price = pr;
    }

    ~Publication(){
        delete title;
        delete author;
        delete publisher;
        delete price;
    }

    void display(){
        cout << "------ Books Details ------" << endl;
        cout << "Title  : " << *title << endl;
        cout << "Author  : " << *author << endl;
        cout << "Publisher  : " << *publisher << endl;
        cout << "Price   : " << *price << endl;
    }
};


class books : public Publication{
private:
    int *stocks;

public:

    books(string t, string a, string p, float pr, int s): Publication(t, a, p, pr){
        stocks = new int;
        *stocks = s;
    }

    ~books(){
        delete stocks;
    }

    bool search(string t, string a){
        if (*title == t && *author == a)
            return true;
        else
            return false;
    }

    void purchase(){
        int copies;

        cout << "-----> Book is available." << endl;

        cout << "Enter number of copies required: ";
        cin >> copies;

        if (copies <= *stocks){
            cout << "Total Cost : "
                 << copies * (*price) << endl;

            *stocks = *stocks - copies;

            cout << "Remaining Stock : "
                 << *stocks << endl;
        }
        else{
            cout << "Required copies not in stock" << endl;
            cout << "Available copies: "
                 << *stocks << endl;
        }
    }
};


int main(){
    books b1("C++", "Bjarne", "Pearson", 500, 10);
    books b2("Python", "Guido", "McGraw", 450, 5);
    books b3("Java", "James", "Oracle", 600, 8);

    b1.display();

    cout << "--------------------------" << endl;

    b2.display();

    cout << "--------------------------" << endl;

    b3.display();

    cout << "--------------------------" << endl;

    string title, author;

    cout << "========== BOOK SHOP ==========" << endl;

    cout << "Enter Book Title: ";
    cin >> title;

    cout << "Enter Author Name: ";
    cin >> author;

    if (b1.search(title, author) == true)
        b1.purchase();

    else if (b2.search(title, author) == true)
        b2.purchase();

    else if (b3.search(title, author) == true)
        b3.purchase();

    else
        cout << "\nBook is not available." << endl;

    return 0;
}