// Jayesh Gore A-37 S-2 31/08/2026
#include <iostream>
using namespace std;

class Vehicle
{
private:
    string vehicleNo;
    string vehicleName;
    float distance;
    float fuel;
    
public:

    void accept()
    {
        cout << "Enter Vehicle Number: ";
        cin >> vehicleNo;

        cout << "Enter Vehicle Name: ";
        cin >> vehicleName;

        cout << "Enter Distance Travelled (km): ";
        cin >> distance;

        cout << "Enter Fuel Consumed (litres): ";
        cin >> fuel;

    }
    
    float calculateEfficiency()
    {
        return distance / fuel;
    }
    

    void display()
    {
        cout << "\nVehicle Number: " << vehicleNo;
        cout << "\nVehicle Name: " << vehicleName;
        cout << "\nDistance Travelled: " << distance << " km";
        cout << "\nFuel Consumed: " << fuel << " litres";
        cout << "\nFuel Efficiency: " << calculateEfficiency() << " km/l";
    }

    void update()
    {
        float newDistance, newFuel;

        cout << "\nEnter additional distance travelled: ";
        cin >> newDistance;

        cout << "Enter additional fuel consumed: ";
        cin >> newFuel;

        distance = distance + newDistance;
        fuel = fuel + newFuel;

        cout << "Vehicle details updated successfully.\n";
    }

    void maintenance()
    {
        if (distance  >= 10000)
            cout << "\nVehicle requires maintenance.";
        else
            cout << "\nVehicle does not require maintenance.";
    }

        
};

int main()
{
    Vehicle v1, v2;

    cout << "Enter details of Vehicle 1\n";
    v1.accept();

    cout << "\nEnter details of Vehicle 2\n";
    v2.accept();

    cout << "\n\n--- Vehicle 1 Details ---";
    v1.display();
    v1.maintenance();

    cout << "\n\n--- Vehicle 2 Details ---";
    v2.display();
    v2.maintenance();

    cout << "\n\n--- Updating Vehicle 1 ---\n";
    v1.update();

    cout << "\n--- Updated Vehicle 1 Details ---";
    v1.display();

    cout << "\n\n--- Comparing Fuel Efficiency ---";

    if (v1.calculateEfficiency() > v2.calculateEfficiency())
            cout << "\n" << "vehicle 1 has better fuel efficiency.";
    else if (v1.calculateEfficiency() < v2.calculateEfficiency())
            cout << "\n" << "vehicle 2 has better fuel efficiency.";
    else
            cout << "\nBoth vehicles have the same fuel efficiency.";
    
    return 0;
}