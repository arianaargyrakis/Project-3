#ifndef PROJECT_3_CAR_H
#define PROJECT_3_CAR_H

#endif //PROJECT_3_CAR_H

#pragma once
#include <vector>
#include <string>
using namespace std;

struct Car {
    //not sure if we'll use classification, make, model_year, or year, but I put them for now
    string size;
    string driveline;
    string engine_type;
    bool hybrid;
    int num_of_forward_gears;
    string transmission;
    int city_mpg;
    string fuel_type;
    int highway_mpg;
    string classification;
    string ID;
    string make;
    string model_year;
    string year;
    int horsepower;
    int torque;
    int priority;

    string determineSize(int height, int length, int width) {
        //gets the size for the size variable in the car class
        //to be implemented
    }
};

class PriorityQueue {
public:
    vector<Car> priority_vect;

    Car top() {
        //returns the car with the highest priority(the ideal car)
        //to be implemented
    }

    void updatePriority(Car& c) {
        //updates the priority variable in car class
        //to be implemented
    }
};
