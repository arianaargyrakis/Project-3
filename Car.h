#ifndef PROJECT_3_CAR_H
#define PROJECT_3_CAR_H

#endif //PROJECT_3_CAR_H

#pragma once
#include <vector>
#include <string>
using namespace std;

struct Car {
    //not sure if we'll use classification, make, model_year, or year, but I put them for now
//    0 string size;
//    1 string driveline;
//    2 string engine_type;
//    3 string hybrid; (bool)
//    4 string num_of_forward_gears; (int)
//    5 string transmission;
//    6 string city_mpg; (int)
//    7 string fuel_type;
//    8 string highway_mpg; (int)
//    9 string classification;
//    10 string ID;
//    11 string make;
//    12 string model_year;
//    13 string year;
//    14 string horsepower; (int)
//    15 string torque; (int)
//    16 string rpm; (int)
//    17 string priority; (int)
    vector<string> car_attributes; //push back the above attributes into the vector in this exact order (if necessary type conversions happen elsewhere)

    void determineSize(int height, int length, int width) {
        //gets the size for the size variable in the car class
        int dimensions = height * length * width;

        if(dimensions < 1000000) {
            this->car_attributes.emplace_back("small");
        }
        else if(dimensions > 7500000) {
            this->car_attributes.emplace_back("large");
        }
        else {
            this->car_attributes.emplace_back("medium");
        }

    }
};

class PriorityQueue {
public:
    vector<Car> priority_vect; //vector of Cars, basically a vector of vectors

    Car top() {
        //returns the car with the highest priority(the ideal car)
        Car max = priority_vect.at(0);

        for(int i = 1; i < priority_vect.size(); i++) {
            if(stoi(priority_vect.at(i).car_attributes.at(17)) > stoi(max.car_attributes.at(17))) {
                max = priority_vect.at(i);
            }
        }
        return max;
    }

    void push(Car& c) {
        priority_vect.push_back(c);
    }

    void updatePriority(string input, int index) {
        //updates the priority variable in car class
        //input is what the user inputs, index is the index for the specific variable being checked in car_attributes
        for(int i = 0; i < priority_vect.size(); i++) {
            size_t found = priority_vect.at(i).car_attributes.at(index).find(input);
            if(found != string::npos) {
                int p = stoi(priority_vect.at(i).car_attributes.at(17));
                p += 1;
                priority_vect.at(i).car_attributes.at(17) = to_string(p);
            }
        }
    }
};
