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

    Car ideal_car = q.top();
    //print stuff using ideal_car

    return 0;
}
