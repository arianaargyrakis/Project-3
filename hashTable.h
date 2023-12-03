#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#endif //HASHTABLE_HASHTABLE_H

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Car.h"
using namespace std;

class hashTable{
    vector<list<Car>> hashT;
    int capacity = 5;
    int size = 0;
    double maxLoadFactor = 0.5;
public:
    hashTable(){
        hashT.resize(capacity);
    }

    int hashFunction(int priority){
        return priority % capacity;
    }

    void resizeAndRehash(int newCapacity){
        vector<list<Car>> newHashT(newCapacity);
        for (auto v : hashT){
            for (auto w : v){
                int newIndex = hashFunction(w.getPriority());
                newHashT[newIndex].push_back(w);
            }
        }
        hashT = newHashT;
        capacity = newCapacity;
    }

    void insert(Car c, int priority){
        if ((double(size) / capacity) >= maxLoadFactor){
            resizeAndRehash(capacity * 2);
        }
        int index = hashFunction(priority);
        if (hashT[index].empty()){
            size++;
        }
        hashT[index].push_back(c);
    }

    string search(int priority){
        int index = hashFunction(priority);
        list<Car> bucket = hashT[index];

        for(auto v : bucket){
            if (v.getPriority() == priority){
                return v.getMake();
            }
        }
        return "null";
    }
};
