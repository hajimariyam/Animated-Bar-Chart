/*
		CS 251 - Data Structures
		Project 3 - Animated Bar Chart
		Author: Mariyam Haji
		NetID: mhaji7
    	System: Visual Studio Code with Ubuntu (WSL 2) on Windows 10 

		barchart.h - BarChart class
		Purpose: Implement the BarChart class to store one entire frame of the animation inside a 
            non-dynamic low-level C array of Bar objects. Memory on the heap is allocated for the 
            array based on the n value passed in as a parameter in the parameterized constructor. 
            If a Bar is attempted to be added beyond capacity n, it will be ignored. The graph()
            public function graphs the frame.
*/


#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"       // used by graders, do not remove
#include "bar.h"
using namespace std;


// Constants used for bar chart animation
const string BOX = "\u29C8";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


// Color codes for light mode terminals
const string RED("\033[1;36m");
const string PURPLE("\033[1;32m");
const string BLUE("\033[1;33m");
const string CYAN("\033[1;31m");
const string GREEN("\033[1;35m");
const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

// Color codes for darker mode terminals
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};


// BarChart
class BarChart 
{
    private:
        // Private member variables for the abstraction    
        Bar* bars;          // pointer to non-dynamic C-style array containing a list of Bars
        int capacity;       // total # of locations available
        int size;           // # of elements stored in array
        string frame;       // determines which group of records (data column #1)

    public:
        // Public member functions for a BarChart object

        // default constructor:
        BarChart() {
            bars = nullptr;
            capacity = 0;
            size = 0;
            frame = "";
        }

        // parameterized constructor:
        //      @param n Number of Bar objects to allocate memory for
        BarChart(int n) {
            bars = new Bar[n];
            capacity = n;
            size = 0;
            frame = "";
        }

        // copy constructor:
        //      called automatically to create a BarChart that contains a copy of an existing
        //      BarChart (@param other), usually when passing BarChart as a parameter-by-value
        BarChart(const BarChart& other) 
        {
            // allocate this BarChart with same attributes as the other
            this->bars = new Bar[other.size];
            this->size = other.size;
            this->capacity = other.capacity;
            this->frame = other.frame;
            
            // make a copy of each element from the other BarChart into this one
            for (int i = 0; i < other.size; ++i) {
                this->bars[i] = other.bars[i];
            }
        }

        // copy operator=
        //      called when assigning one BarChart as another, i.e. this = other;
        BarChart& operator=(const BarChart& other) 
        {
            // special case: both BarCharts are the same
            if (this == &other) {
                return *this;
            }

            // *this* BarChart exists (unlike in copy constructor) so free associated memory
            delete[] bars;

            // allocate this BarChart with same attributes as the other
            this->bars = new Bar[other.size];
            this->size = other.size;
            this->capacity = other.capacity;
            this->frame = other.frame;

            // make a copy of each element from the other BarChart into this one
            for (int i = 0; i < other.size; ++i) {
                this->bars[i] = other.bars[i];
            }

            return *this;
        }

        // clear:
        //      called by user to free the array and reset all private variables to default values
        void clear() 
        {
            delete[] bars;
            bars = nullptr;
            capacity = 0;
            size = 0;
            frame = "";
        }

        // destructor:
        //      called automatically by C++ to free the memory associated by the BarChart 
        //      when the object goes out of scope
        virtual ~BarChart() 
        {
            if (bars != nullptr) {
                delete[] bars;
            }
        }

        // mutator and accessor functions:
        void setFrame(string frame) {
            this->frame = frame;
        }

        string getFrame() {
            return frame; 
        }

        int getSize() {
            return size; 
        }

        // addBar:
        //      add a Bar at the end of the BarChart:
        //      @params read-in values from corresponding columns in a row of data
        //      @return true if successful
        //      @return false if BarChart object is full
        bool addBar(string name, int value, string category) 
        {
            Bar newBar (name, value, category);
            if (capacity > size) {
                bars[size] = newBar;
                size++;
                return true;
            }
        
            return false;
        }

        // operator[]
        //      allows read (access) or write (modify) of ith Bar object in BarChart
        //      @return Bar element at ith index in BarChart (in insertion order)
        Bar& operator[](int i) 
        {
            // i is out of bounds
            if (i < 0 || i >= size) {
                throw out_of_range("BarChart: i out of bounds");
            }

            return bars[i];
        }

        // dump:
        //      for debugging, print out the BarChart object in text in descending order by value
        //      @param output Any stream (cout, filestream, stringstream)
        void dump(ostream &output) 
        {
            output << "frame: " << frame << endl;

            // sort in descending order by value of each Bar (uses overloaded comparison operators)
            sort(bars, bars+size, greater<Bar>());

            for (int i = 0; i < size; ++i) {
                output << bars[i].getName() << " " 
                       << bars[i].getValue() << " " 
                       << bars[i].getCategory() << endl;
            }
        }
        
        // graph:
        //      graph bars to display a single BarChart in the animation 
        //      @param output Any stream (cout, filestream, stringstream)
        //      @param colorMap Maps category -> color to determine color
        //      @param top Number of bars to graph for each frame (top 10? top 12?)
        void graph(ostream &output, map<string, string> &colorMap, int top) 
        {
            // sort in descending order by value of each Bar (uses overloaded comparison operators)
            sort(bars, bars+size, greater<Bar>());
            
            int lenMax = 60;  // max # of BOXs to print
            int lenBar = 0;
            string color = "";

            // if needed, reset number of bars to graph
            if (top > size || top < 0) {
                top = size;
            }

            // for each bar to graph..
            for (int x = 0; x < top; x++) 
            {
                Bar thisBar = bars[x];

                // if colorMap is empty or the category is not found in it
                if (colorMap.size() == 0 || colorMap.find(thisBar.getCategory()) == colorMap.end()) {
                    color = BLACK; 
                } 
                else {
                    color = colorMap[thisBar.getCategory()];
                }

                // print top Bar with lenMax BOXs and remaining bars proportional to it
                // calculate as float then set as integer for flooring
                lenBar = ((thisBar.getValue() + 0.0) / bars[0].getValue()) * lenMax;
                string barBoxes = "";
                for (int i = 0; i < lenBar; i++) {
                    barBoxes += BOX;
                }

                output << color << barBoxes << ' ' << thisBar.getName() << ' ' << thisBar.getValue() << endl;
            }
        }
};

