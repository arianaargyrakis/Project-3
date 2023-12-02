#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <ctime>
#include "Car.h"

int main() {
    PriorityQueue q;
    clock_t timeQ; //clock for priority queue
    float totalTimeQ; //total time to do all priority queue related functions
    //read data
    ifstream csvFile;
    csvFile.open("cars.csv");
    string line = "";
    int firstLine = 1;
    timeQ = clock();
    while (getline(csvFile, line))
    {
        if (firstLine == 1)
        {
            firstLine++;
            string temp;
            stringstream inputString(line);
            getline(inputString, temp, ','); // this is to not read column headers
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');
            getline(inputString, temp, ',');

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
            getline(inputString, length, ',');
            getline(inputString, width, ',');
            newCar.determineSize(stoi(height), stoi(length), stoi(width));
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

    timeQ = clock() - timeQ;
    totalTimeQ = (float)timeQ/CLOCKS_PER_SEC;

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
    if (gasPowered != "3")
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

    vector<pair<string, int>> idealCar;

    if (gasPowered == "1")
    {
        idealCar.push_back({"Gasoline", 7});
    }
    else if (gasPowered == "2")
    {
        idealCar.push_back({"Diesel fuel", 7});
    }
    else if (gasPowered == "3")
    {
        idealCar.push_back({"Electricity", 7});
    }
    else if (gasPowered == "4")
    {
        idealCar.push_back({"Compressed natural gas", 7});
    }
    else
    {
        idealCar.push_back({"E85", 7});
    }
    if (gasPowered != "3")
    {
        idealCar.push_back({cityMPG, 6});
        idealCar.push_back({highwayMPG, 8});
        if (transmissionType == "1")
        {
            idealCar.push_back({"Automatic transmission", 9});
        }
        else
        {
            idealCar.push_back({"Manual transmission", 9});
        }
    }
    idealCar.push_back({horsepower, 14});
    idealCar.push_back({torque, 15});
    if (driveTrain == "1")
    {
        idealCar.push_back({"Rear-wheel drive", 1});
    }
    else if (driveTrain == "2")
    {
        idealCar.push_back({"All-wheel drive", 1});
    }
    else
    {
        idealCar.push_back({"Front-wheel drive", 1});
    }
    if (size == "1")
    {
        idealCar.push_back({"small", 0});
    }
    else if (size == "2")
    {
        idealCar.push_back({"medium", 0});
    }
    else
    {
        idealCar.push_back({"large", 0});
    }

    //preference order: fuel type, city MPG, highway MPG, transmission type, horsepower, torque, drivetrain, size
    timeQ = clock();
    for(int i = 0; i < idealCar.size(); i++)
    {
        q.updatePriority(idealCar[i].first, idealCar[i].second);
    }
    timeQ = clock() - timeQ;
    totalTimeQ += (float)timeQ/CLOCKS_PER_SEC;

    timeQ = clock();
    Car priorityCar = q.top();
    timeQ = clock() - timeQ;
    totalTimeQ += (float)timeQ/CLOCKS_PER_SEC;
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
    cout << "Time using Priority Queue: " << totalTimeQ << " seconds" <<endl;

    return 0;
}
