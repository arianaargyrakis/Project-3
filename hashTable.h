//
// Created by andre on 11/22/2023.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#endif //HASHTABLE_HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <forward_list>
#include <list>
#include "Car.h"
using namespace std;

class hashTable{
    Car arr[100];
public:
    void insert(Car c, int priority){
        arr[priority] = c;
    }

    Car search(int priority){
        return arr[priority];
    }

};