#include <iostream>
#include <string>
using namespace std;

class Product{
private:
    string name, ID;
    int quantity;
    double price;

public:
    Product(){
        cout<<"Enter Product ID: ";
        cin>>ID;
        cout<<"Enter Product Name: ";
        cin>>name;
        cout<<"Enter Product Quantity: ";
        cin>>quantity;
        cout<<"Enter Product Price: ";
        cin>>price;
    }

    Product(string n, string i, int q, double pr){
        name = n;
        ID = i;
        quantity = q;
        price = pr;
    }
    
    double cost(){
        return price*quantity;
    }
    void display()
    {
        cout << ID << "\t"
             << name << "\t\t"
             << price << "\t"
             << quantity << "\t"
             << cost() << endl;
    }
};
int main(){
    Product *P1 = new Product("Mobile","184",1,34000);
    Product *P2 = new Product();

    double total = P1->cost() + P2->cost();

    cout << "\n========== INVOICE ==========\n";
    cout << "ID\tName\t\tPrice\tQty\tCost\n";
    
    P1->display();
    P2->display();
 
    cout<<endl<<"Subtotal : "<<total<<endl;

    if (total >= 50000){
        cout<<"Discount is : "<<total * 10/100<<endl;
        cout<<"Total bill  : "<<total - (total * 10/100) <<endl ;
    }
    else if (total >= 25000){
        cout<<"Discount is : "<<total * 5/100<<endl;
        cout<<"Total bill  : "<<total - (total * 5/100) <<endl ;
    }
    else{
        cout<<"No Discount"<<endl;
        cout<<"Total bill : "<<total<<endl;
    }

    delete P1;
    delete P2;

    return 0;
}