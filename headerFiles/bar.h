/*
    File: bar.h
    Code Implementer: Uvaish Bakaliya
    Project 3(CS251): Animated Bar Chart (Fall 2022)
    Date: 10-12-2022
    Code written In: Visual Studio code(VSC)
    -----------------------------------------------
    This is bar.h file where we set and get the data from the object of the
    class.
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

// Bar that is going to be used in 'barchart.h'
class Bar
{
private:
    // Private member variables for a Bar object
    string name, category;
    int value;

public:
    // default constructor:
    Bar()
    {
        this->name = "";
        this->value = 0;
        this->category = "";
    }

    // a second constructor:
    // Parameter passed in constructor Bar object.
    Bar(string name, int value, string category)
    {
        // the private variables will take the values of the passed in arguments in the constructor
        this->name = name;
        this->value = value;
        this->category = category;
    }
    // getName:
    string getName() { return this->name; }

    // getValue:
    int getValue() { return this->value; }

    string getCategory() { return this->category; }

    // objects.  Comparison should be based on the Bar's value.  For example:
    bool operator<(const Bar &other) const { return (this->value < other.value); }
    bool operator<=(const Bar &other) const { return (this->value <= other.value); }
    bool operator>(const Bar &other) const { return (this->value > other.value); }
    bool operator>=(const Bar &other) const { return (this->value >= other.value); }
};