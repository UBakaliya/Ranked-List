/*
    File: barchartanimate.h
    Code Implementer: Uvaish Bakaliya
    Date: 10-12-2022
    Code written In: Visual Studio code(VSC)
    -----------------------------------------------
    barchartanimate.h file is used for adding frames into c style class array
    and animating in this file as well
*/

#pragma once
#include "barchart.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unistd.h>
#include <vector>

using namespace std;

// BarChartAnimate using all the 'h' files
class BarChartAnimate
{
private:
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    BarChart *barCharts; // pointer to a C-style array (add frames into this)
    int size;
    int capacity;

    map<string, string> colorMap; // to store the colors

    string title, xlabel, source, year, name, country,
        value, category, strNumBar, line; // for the header of the file

    int idx = 0; // for color assigning purposes

public:
    // for testing prepuces
    string getTitle() { return title; }

    string getXlable() { return xlabel; }

    string getSource() { return source; }

    int getCapacity() { return capacity; }

    // a parameterized constructor:
    // with a capacity of 4. other with default this->values
    BarChartAnimate(string title, string xlabel, string source)
    {
        this->barCharts = nullptr;
        this->size = 0;
        this->capacity = 4;
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
    }

    // destructor:
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    virtual ~BarChartAnimate()
    {
        delete[] barCharts;
        this->barCharts = nullptr; // reset to a new, empty vector with capacity of 4:
        this->size = 0;
        this->capacity = 4;
    }

    // resize is size of the *barChart array
    void resize()
    {
        // if the size same or more then capacity:
        if (this->size >= this->capacity)
        {
            // create a new temp array double the size of the previous array
            BarChart *tmpBarCharts = new BarChart[this->capacity * 2];
            // copy all the elements from the origianal barCharts array
            // and assign those to tmpBartChart array
            for (int i = 0; i < this->capacity; ++i)
            {
                tmpBarCharts[i] = this->barCharts[i];
                tmpBarCharts[i].setFrame(this->barCharts[i].getFrame()); // copy the frame
            }
            delete[] this->barCharts;
            // assign the tmpBarCharts to barCharts
            this->barCharts = tmpBarCharts;
            this->capacity *= 2; // double the capacity
        }
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barCharts has run out of space, double the capacity
    void addFrame(ifstream &file)
    {
        int numBar = 0; // to get the range to add the bars in
        // allocate the memory for the barChart only first time:
        if (this->size == 0)
            this->barCharts = new BarChart[this->capacity];

        getline(file, strNumBar, '\n'); // get the space
        getline(file, strNumBar, '\n'); // and after get the number that size of the frame
        // if the strNumBar is not an space then:
        if (strNumBar != "")
            numBar = stoi(strNumBar);

        // if the numBar is a valid number more then 0 then:
        if (numBar != 0)
        {
            BarChart barChart(numBar); // allocate memory on the for the number of the
                                       // bars that are going to be in a frame
            // loop throw the frame and find get the bars:
            for (int i = 0; i < numBar; i++)
            {
                // grab the line and split it tile(end line -category):
                getline(file, this->line, '\n');
                stringstream ss(this->line);
                getline(ss, year, ',');
                getline(ss, this->name, ',');
                getline(ss, this->country, ',');
                getline(ss, this->value, ',');
                getline(ss, category, '\n');

                // assign colors to category in colorMap & add the current Bar
                if (colorMap.find(this->category) == colorMap.end())
                {
                    // assign the category with colors in colorMap and increment the map indx
                    colorMap.emplace(this->category, COLORS[idx++]);
                    if (idx == COLORS.size())
                        idx = 0;
                }
                barChart.addBar(this->name, stoi(this->value), this->category);
                barChart.setFrame(this->year);
            }
            resize(); // double the size if the reached the capacity

            this->barCharts[this->size].setFrame(barChart.getFrame());
            this->barCharts[this->size] = barChart;
            this->size++;
        };
    }

    bool animateFoundedFarms(ostream &output, int top, int endIter, string frame)
    {
        unsigned int microsecond = 50000;
        bool init = false;
        for (int i = 0; i < endIter; i++)
        {
            if (this->barCharts[i].getFrame() == frame)
            {
                if (!init)
                {
                    init = true;
                    return true;
                }
                usleep(3 * microsecond);
                output << WHITE << getTitle() << "\n"
                       << getSource() << endl;
                barCharts[i].graph(output, colorMap, top);
                output << RESET;
                output << WHITE << getXlable() << endl;
                output << "Frame: " << barCharts[i].getFrame() << endl;
                init = true;
            }
        }
        return false;
    }

    // this function plays each frame stored in barCharts.
    void animate(ostream &output, int top, int endIter)
    {
        // if the endIter is -1 (end of the list the display all of the frames)
        if (endIter == -1)
            endIter = getSize();
        unsigned int microsecond = 50000;
        // loop till the 'endIter' size
        for (int i = 0; i < endIter; i++)
        {
            output << CLEARCONSOLE;  // clear the console after displaying the frame
            usleep(3 * microsecond); // and display slowly
            // display the first headers(white color):
            output << WHITE << getTitle() << "\n"
                   << getSource() << endl;
            // graph them and color them:
            this->barCharts[i].graph(output, colorMap, top);
            output << WHITE << getXlable()
                   << "\nFrame: " << this->barCharts[i].getFrame() << endl;
            output << RESET; // reset
        }
    }

    // Returns the size of the BarChartAnimate object.
    int getSize() { return this->size; }

    // Returns BarChart element in BarChartAnimate.
    BarChart &operator[](int i)
    {
        // check if the bars use likes to get is a valid index
        if (i < 0 || i >= this->size)
            throw out_of_range("BarChart: i out of bounds");
        // if valid then:
        return this->barCharts[i];
    }
};
