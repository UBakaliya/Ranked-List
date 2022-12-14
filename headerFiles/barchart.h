/*
    File: barchart.h
    Code Implementer: Uvaish Bakaliya
    Date: 10-12-2022
    Code written In: Visual Studio code(VSC)
    -----------------------------------------------
    barchart.h is where we implement the function that are going to be use full
    in 'barchartanimate.h' file line 'addBar()'.
*/

#include "bar.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");

// Color codes for darker mode terminals
const string CYAN("\033[1;36m");
const string GREEN("\033[1;32m");
const string GOLD("\033[1;33m");
const string RED("\033[1;31m");
const string PURPLE("\033[1;35m");
const string BLUE("\033[1;34m");
const string WHITE("\033[1;37m");
const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

// BarChart
class BarChart
{
private:
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // Bars.  As a result, you must also keep track of the number of elements
    // stored (size) and the capacity of the array (capacity).  This is not a
    // dynamic array, so it does not expand.
    Bar *bars; // pointer to a C-style array
    int capacity;
    int size;
    string frame;

public:
    //----------------
    // for testing
    Bar *getBars() { return this->bars; }
    // for testing
    int getCapacity() { return this->capacity; }
    //----------------
    BarChart()
    {
        this->bars = nullptr;
        this->capacity = 0;
        this->size = 0;
    }

    // Parameter passed in determines memory allocated for bars.
    BarChart(int n)
    {
        this->bars = new Bar[n]; // allocated memory on heap for the bars
        this->capacity = n;
        this->size = 0;
    }

    // Called automatically by C++ to create an BarChart that contains
    // a copy of an existing BarChart.  Example: this occurs when passing
    // BarChart as a parameter by value.
    BarChart(const BarChart &other)
    {
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
    }

    // Called when you assign one BarChart into another, i.e. this = other;
    BarChart &operator=(const BarChart &other)
    {
        // if we assign into it self
        if (this == &other)
            return *this;

        delete[] bars;
        // assign the data size and capacity and the bars to original bars
        this->bars = new Bar[other.capacity];
        this->size = other.size;
        this->capacity = other.capacity;
        // copy the data from the bars other and assign them to original bars
        for (int i = 0; i < other.size; ++i)
            this->bars[i] = other.bars[i];
        return *this;
    }

    // frees memory and resets all private member variables to default values.
    void clear()
    {
        delete[] bars;
        bars = nullptr;
        this->capacity = 0;
        this->size = 0;
    }
    // Called automatically by C++ to free the memory associated by the
    // BarChart.
    virtual ~BarChart() { clear(); }

    void setFrame(string frame)
    {
        this->frame = frame;
    }

    // Returns the frame of the BarChart oboject.
    string getFrame() { return this->frame; }

    // adds a Bar to the BarChart.
    bool addBar(string name, int value, string category)
    {
        // if the there is no room to add:
        if (this->size >= this->capacity)
            return false;
        // if there is a room to add then add the value at the
        // current index
        Bar b(name, value, category);
        this->bars[size] = b;
        this->size++;
        return true;
    }

    // Returns the size (number of bars) of the BarChart object.
    int getSize() { return this->size; }

    // This gives public access to Bars stored in the Barchart.
    Bar &operator[](int i)
    {
        // check if the bars use likes to get is a valid index
        if (i < 0 || i >= this->size)
            throw out_of_range("BarChart: i out of bounds");
        // if valid then:
        return this->bars[i];
    }

    // Used for printing the BarChart object.
    void dump(ostream &output)
    {
        // print the frame and from the the ouput
        output << "frame: " << getFrame() << endl;
        sort(this->bars, this->bars + this->capacity, greater<Bar>()); // sort the bars by values

        // display the bars in the range of the capacity
        for (int i = 0; i < capacity; i++)
        {
            output << this->bars[i].getName() << " " << this->bars[i].getValue()
                   << " " << this->bars[i].getCategory() << endl;
        }
    }

    // Used for printing out the bar.
    void graph(ostream &output, map<string, string> &colorMap, int top)
    {
        int lenMax = 60, counter = 0;
        sort(this->bars, this->bars + this->capacity, greater<Bar>()); // sort the bars by values
        string barStr, line;
        // get the first value that is going to be a the greatest
        float calculatedBar = (this->bars[0].getValue());

        // // run till the counter is not same as top(max number)
        for (int i = 0; i < this->size; i++)
        {
            // if the top is reached to given value the break
            if (counter == top)
                break;
            // find the Category in a map
            if (colorMap.find(this->bars[i].getCategory()) != colorMap.end())
            {
                int barToPrint = (this->bars[i].getValue() / calculatedBar) * lenMax; // calculate the bars that
                                                                                      // needs to be added to are going to be drownd
                // add the box to 'barstr'
                for (int i = 0; i < barToPrint; i++)
                    barStr += BOX;
                // if the color map has any values that are Black then
                // assign it to WHITE color:
                if (colorMap[this->bars[i].getCategory()] == "")
                    colorMap[this->bars[i].getCategory()] = WHITE;

                // print the bar with the colors
                output << colorMap[this->bars[i].getCategory()] << barStr << ' '
                       << this->bars[i].getName() << ' ' << bars[i].getValue() << endl;
                counter++;
                barStr.clear(); // clear the boxes so it can add the new once
            }
        }
    }
};
