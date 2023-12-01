#include <iostream>
#include "Car.h"

int main() {
    Car car; //use to make car objects for each car in the data
    PriorityQueue q;
    //read data
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
        idealCar.push_back("gas");
    }
    else
    {
        idealCar.push_back("electric");
    }
    if (gasPowered == "1")
    {
        idealCar.push_back(cityMPG);
        idealCar.push_back(highwayMPG);
        if (transmissionType == "1")
        {
            idealCar.push_back("automatic");
        }
        else
        {
            idealCar.push_back("manual");
        }
    }
    idealCar.push_back(horsepower);
    idealCar.push_back(torque);
    if (driveTrain == "1")
    {
        idealCar.push_back("rwd");
    }
    else
    {
        idealCar.push_back("awd");
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
    //}

    //Car ideal_car = q.top();
    //print stuff using ideal_car

    return 0;
}
