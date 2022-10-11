/*  bar.h implements the Bar class by aggregating related information (name, value, and category) 
    for use in a bar chart. For example, a bar drawn in a bar chart would represent:
        name = Beijing, value = 672, and category = East Asia

    The class implements both a default and a parameterized constructor, a destructor, and 
    getters for each private member variable. The class also overloads four comparison operators 
    that compare any two Bar objects by their value. These operators can be used to sort a list
    of Bar objects and achieve a bar graph that is plotted in sorted, descending order.

    CS 251 - Data Structures 
    Project 3 - Animated Bar Chart

    Author: Mariyam Haji 
    NetID: mhaji7
    System: Visual Studio Code on Windows 10 
*/


#include <iostream>
#include <string>
#include "myrandom.h"       // used in graders, do not remove
using namespace std;


// Bar
class Bar 
{
    private:
        // Private member variables for a Bar object
        string name;
        int value;
        string category;

    public:
        // Public member functions for a Bar object
        
        // Default constructor
        Bar() {
            name = "";
            value = 0;
            category = "";
        }

        // Parameterized constructor
        Bar(string name, int value, string category) {
            this->name = name;
            this->value = value;
            this->category = category;
        }

        // Destructor
        virtual ~Bar() {
            // EMPTY: no memory allocation on the heap for Bar class
        }

        // Accessor functions for each private data member
        string getName() {
            return name;
        }

        int getValue() {
            return value;
        }

        string getCategory() {            
            return category;
        }

        // Operators to allow comparing of two Bar objects based on the their value
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

