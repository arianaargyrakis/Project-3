#include <iostream>
#include "Car.h"

int main() {
    PriorityQueue q;
    //get file
    //for loop
        Car car; //use to make car objects for each car in the data
        //read data for one car
            //use car.car_attributes.push_back(string);
        // use car.determineSize(height, length, width); to get size
        // use q.push(car); after reading all info for one car

    //get user's input
    //use q.updatePriority(input, 0); after each question/input (update index by +1 for each input)
    string gasPowered;
    string cityMPG;
    string highwayMPG;
    string transmissionType;
    string horsepower;
    string torque;
    string driveTrain;
    string size;
    cout << "Please input your automobile preferences to find makes and models that suit your needs below." << endl;
    cout << endl;
    cout << "Gas (1) / Electric (2)" << endl;
    cin >> gasPowered;
    cout << endl;
    cout << "Small Size (1) / Medium Size (2) / Large Size (3)" << endl;
    cin >> size;
    cout << endl;
    if (gasPowered == "1")
    {
        cout << "Automatic Transmission (1) / Manual Transmission (2):" << endl;
        cin >> transmissionType;
        cout << endl;
        cout << "Minimum City MPG (int): " << endl;
        cin >> cityMPG;
        cout << endl;
        cout << "Minimum Highway MPG (int): " << endl;
        cin >> highwayMPG;
        cout << endl;
    }
    cout << "Minimum Horsepower (int): " << endl;
    cin >> horsepower;
    cout << endl;
    cout << "Torque in lb-ft (int): " << endl;
    cin >> torque;
    cout << endl;
    cout << "Rear Wheel Drive (1) / All Wheel Drive (2)" << endl;
    cin >> driveTrain;
    cout << endl;

    vector<string> idealCar;

    if (gasPowered == "1")
    {
        idealCar.push_back("Gasoline");
    }
    else
    {
        idealCar.push_back("Electricity");
    }
    if (gasPowered == "1")
    {
        idealCar.push_back(cityMPG);
        idealCar.push_back(highwayMPG);
        if (transmissionType == "1")
        {
            idealCar.push_back("Automatic transmission");
        }
        else
        {
            idealCar.push_back("Manual transmission");
        }
    }
    idealCar.push_back(horsepower);
    idealCar.push_back(torque);
    if (driveTrain == "1")
    {
        idealCar.push_back("Rear-wheel drive");
    }
    else
    {
        idealCar.push_back("All-wheel drive");
    }
    if (size == "1")
    {
        idealCar.push_back("small");
    }
    else if (size == "2")
    {
        idealCar.push_back("medium");
    }
    else
    {
        idealCar.push_back("large");
    }

    //for (int i = 0; i < idealCar.size(); i++) //fuel type, city MPG, highway MPG, transmission type, horsepower, torque, drivetrain, size
    //{
    // cout << idealCar[i] << endl;
    // use updatePriority here
    //}

    Car priorityCar = q.top();
    //print stuff using priorityCar
    cout << "Car: " << priorityCar.car_attributes[10] << endl;
    cout << "Size: " << priorityCar.car_attributes[0] << endl;
    cout << "Volume: " << priorityCar.car_attributes[16] << endl;
    cout << "Driveline: " << priorityCar.car_attributes[1] << endl;
    cout << "Engine Type: " << priorityCar.car_attributes[2] << endl;
    if(priorityCar.car_attributes[3] == "TRUE")
    {
        cout << "Has Hybrid Engine: " << "Yes" << endl;
    }
    else
    {
        cout << "Has Hybrid Engine: " << "No" << endl;
    }
    cout << "Number of Forward Gears: " << priorityCar.car_attributes[4] << endl;
    cout << "Transmission: " << priorityCar.car_attributes[9] << endl;
    cout << "City mpg: " << priorityCar.car_attributes[6] << endl;
    cout << "Fuel Type: " << priorityCar.car_attributes[7] << endl;
    cout << "Highway mpg: " << priorityCar.car_attributes[8] << endl;
    cout << "HorsePower: " << priorityCar.car_attributes[14] << endl;
    cout << "Torque: " << priorityCar.car_attributes[15] << endl;
    cout << "RPM: " << priorityCar.car_attributes[17] << endl;
    cout << "Time using Priority Queue: " /*<< need to implement Clock*/ << endl;

    return 0;
}
