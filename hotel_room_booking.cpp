#include <iostream>
#include <string>
using namespace std;

class Hotel{
private:
    int arr[4][5];
    int floor, room;

public:
    Hotel(int m, int n){
        floor = m;
        room = n;
    
        for(int i=0; i<4; i++){
            for(int j=0; j<5; j++){
                arr[i][j] = 0;
            }
        }

    }

    void view(){
        for(int i=0; i<4; i++){
            for(int j=0; j<5; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    void booking(){
        cout<<"Enter Floor: ";
        cin>>floor;
        cout<<"Enter Room: ";
        cin>>room;

        if(floor<1 || floor>4 || room<1 || room>5){
            cout<<"Invalid Room or Floor."<<endl;
            return;
        }

        if(arr[floor-1][room-1]==0){
            arr[floor-1][room-1]=1;
            cout<<"Room Booked."<<endl;
        }
        else{
            cout<<"Room is already booked."<<endl;
        }
    }
};

int main(){
    Hotel h(4,5);
    int choice;
    
    while(true){
        cout<<"1. View the room"<<endl;
        cout<<"2. Book the room"<<endl;
        cout<<"3. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        if(choice == 1){
            h.view();
        }
        else if(choice == 2){
            h.booking();
            h.view();
        }
        else if(choice == 3){
            cout<<"Thank You ! "<<endl;
            break;
        }
        else{
            cout<<"Invalid Choice Input."<<endl;
        }
    }

    return 0;
}