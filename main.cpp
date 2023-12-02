#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Car.h"

int main() {

    Car car; //use to make car objects for each car in the data
    PriorityQueue q;
    //read data
    // use car.determineSize(height, length, width); to get size
    // use q.push(car); after reading all info for one car
    ifstream csvFile;
    csvFile.open("cars.csv");
    string line = "";
    int firstLine = 1;
    while (getline(csvFile, line))
    {
        if (firstLine == 1)
        {
            firstLine++;
        }
        else
        {
            Car newCar;
            string height;
            string length;
            string width;
            string driveline;
            string engineType;
            string hybrid;
            string numGears;
            string transmissionName;
            string MPGcity;
            string fuel;
            string MPGhighway;
            string transmissionType;
            string ID;
            string make;
            string modelYear;
            string year;
            string horsepower;
            string torque;
            string size;
            string rpm;

            stringstream inputString(line);

            getline(inputString, height, ',');
            newCar.car_attributes.push_back(height);
            getline(inputString, length, ',');
            newCar.car_attributes.push_back(length);
            getline(inputString, width, ',');
            newCar.car_attributes.push_back(height);
            getline(inputString, driveline, ',');
            newCar.car_attributes.push_back(driveline);
            getline(inputString, engineType, ',');
            newCar.car_attributes.push_back(engineType);
            getline(inputString, hybrid, ',');
            newCar.car_attributes.push_back(hybrid);
            getline(inputString, numGears, ',');
            newCar.car_attributes.push_back(numGears);
            getline(inputString, transmissionName, ',');
            newCar.car_attributes.push_back(transmissionName);
            getline(inputString, MPGcity, ',');
            newCar.car_attributes.push_back(MPGcity);
            getline(inputString, fuel, ',');
            newCar.car_attributes.push_back(fuel);
            getline(inputString, MPGhighway, ',');
            newCar.car_attributes.push_back(MPGhighway);
            getline(inputString, transmissionType, ',');
            newCar.car_attributes.push_back(transmissionType);
            getline(inputString, ID, ',');
            newCar.car_attributes.push_back(ID);
            getline(inputString, make, ',');
            newCar.car_attributes.push_back(make);
            getline(inputString, modelYear, ',');
            newCar.car_attributes.push_back(modelYear);
            getline(inputString, year, ',');
            newCar.car_attributes.push_back(year);
            getline(inputString, horsepower, ',');
            newCar.car_attributes.push_back(horsepower);
            getline(inputString, torque, ',');
            newCar.car_attributes.push_back(torque);
            getline(inputString, size, ',');
            newCar.car_attributes.push_back(size);
            getline(inputString, rpm, ',');
            newCar.car_attributes.push_back(rpm);
            q.push(newCar);
        }

        line = "";
    }


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
    cout << "Gasoline (1) / Diesel (2) / Electricity (3) / Compressed Natural Gas (4) / E85 (5): " << endl;
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
    cout << "Rear Wheel Drive (1) / All Wheel Drive (2) / Front Wheel Drive (3)" << endl;
    cin >> driveTrain;
    cout << endl;

    vector<string> idealCar;

    if (gasPowered == "1")
    {
        idealCar.push_back("gas");
    }
    else if (gasPowered == "2")
    {
        idealCar.push_back("diesel");
    }
    else if (gasPowered == "3")
    {
        idealCar.push_back("electric");
    }
    else if (gasPowered == "natural gas")
    {
        idealCar.push_back("Diesel");
    }
    else
    {
        idealCar.push_back("E85");
    }
    if (gasPowered != "3")
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
    else if (driveTrain == "2")
    {
        idealCar.push_back("awd");
    }
    else
    {
        idealCar.push_back("fwd");
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

    //preference order: fuel type, city MPG, highway MPG, transmission type, horsepower, torque, drivetrain, size


    //Car ideal_car = q.top();
    //print stuff using ideal_car

    return 0;
}
