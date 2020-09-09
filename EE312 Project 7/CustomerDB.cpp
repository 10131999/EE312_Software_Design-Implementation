/*
 * Name:
 * EID:
 * Project 7, CRM part 2
 * EE 312, Fall 2019
 */
#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here

    if(isMember(name) == true){
        int i = 0;
        while (i < capacity){
            if (data[i].name == name){
                return data[i]; //could be wrong ask about return by reference
            }
            i++;
        }
    }else{
        if(length == capacity){
            //resize the array and reallocate space
            capacity = capacity * 2;
            Customer* new_data = new Customer[capacity];
            int x = 0;
            while (x < length){
                new_data[x] = data[x];
                x ++;
            }
            new_data[x].name = name;
            new_data[x].bottles = 0;
            new_data[x].diapers = 0;
            new_data[x].rattles = 0;
            delete[] data;//delete(data); try this
            data = new_data;
            return data[x];

        }else{
            // add new customer to the data base and return by reference
            data[length].name = name;
            data[length].bottles = 0;
            data[length].rattles = 0;
            data[length].diapers = 0;
            length ++;
            return data[length-1];
        }
    }


}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    int i = 0;
    while (length > i){
        if (data[i].name == name){ //might work properly now
            return true;
        }
        i ++;
    }
    return false;
}
