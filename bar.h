/*
		CS 251 - Data Structures
		Project 3 - Animated Bar Chart
		Author: Mariyam Haji
		NetID: mhaji7
    	System: Visual Studio Code with Ubuntu (WSL 2) on Windows 10 

		bar.h - Bar class
		Purpose: Implement the Bar class by aggregating related information 
            (name, value, category) for use in a BarChart object.
*/


#include <iostream>
#include <string>
#include "myrandom.h"       // used by graders, do not remove
using namespace std;


// Bar
class Bar 
{
    private:
        // Private member variables for the abstraction
        string name;            // data column #2
        int value;              // data column #4
        string category;        // data column #5

    public:
        // Public member functions for a Bar object
        
        // default constructor:
        Bar() {
            name = "";
            value = 0;
            category = "";
        }

        // parameterized constructor:
        //      @params read-in values from corresponding columns in a row of data
        Bar (string name, int value, string category) {
            this->name = name;
            this->value = value;
            this->category = category;
        }

        // destructor:
        virtual ~Bar() {
            // EMPTY: no memory allocation on the heap for Bar class
        }

        // accessor functions for each private data member:
        string getName() {
            return name;
        }

        int getValue() {
            return value;
        }

        string getCategory() {            
            return category;
        }

        // overloaded comparison operators:
        //      compare any two Bar objects by their value and sort a list of Bar objects
        //      to achieve a bar graph that is plotted in sorted, descending order
        
        bool operator<(const Bar &other) const {
            return (this->value < other.value);
        }

        bool operator<=(const Bar &other) const {
            return (this->value <= other.value);
        }

        bool operator>(const Bar &other) const {
            return (this->value > other.value);
        }

        bool operator>=(const Bar &other) const {
            return (this->value >= other.value);
        }
};

