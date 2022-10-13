// TO DO:  add header comment here.  Also add function header comments below.
/*  barchart.h implements the BarChart class ...

    CS 251 - Data Structures 
    Project 3 - Animated Bar Chart

    Author: Mariyam Haji 
    NetID: mhaji7
    System: Visual Studio Code on Windows 10 
*/


#include <iostream>
#include <algorithm>
#include <map>
#include "myrandom.h"       // used in graders, do not remove
#include "bar.h"
using namespace std;

// Constants used for bar chart animation.  You will primarily
// use these in barchartanimate.h, but you might find some useful here.
// const string BOX = "\u29C8";
const string BOX = "X";
const string CLEARCONSOLE = "\033[2J";
const string RESET("\033[0m");


// Color codes for light mode terminals
// const string RED("\033[1;36m");
// const string PURPLE("\033[1;32m");
// const string BLUE("\033[1;33m");
// const string CYAN("\033[1;31m");
// const string GREEN("\033[1;35m");
// const string GOLD("\033[1;34m");
const string BLACK("\033[1;37m");
// const vector<string> COLORS = {RED, PURPLE, BLUE, CYAN, GREEN, GOLD, BLACK};

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
        /*  This implementation uses a low-level C array, bars, to store a list of Bars and 
            keeps track of the number of elements stored (size) and the capacity of the array 
            (capacity). This is not a dynamic array, so it does not expand. */

        // Private member variables for the abstraction    
        Bar* bars;       // pointer to a C-style array
        int capacity;
        int size;
        string frame;

    public:
        // Public member functions

        // default constructor:
        BarChart() {
            bars = nullptr;
            capacity = 0;
            size = 0;
            frame = "";
        }

        // parameterized constructor:
        // Parameter passed in determines memory allocated for bars.
        BarChart(int n) {
            
            // Allocate memory for 10 bars
            bars = new Bar[n];
            // Initialize capacity to 10 and all other private member variables to default values.
            capacity = n;
            size = 0;
            frame = "";
            
        }

        // Copy constructor
        //
        // Called automatically by C++ to create an BarChart that contains
        // a copy of an existing BarChart.  Example: this occurs when passing
        // BarChart as a parameter by value.
        //
        BarChart(const BarChart& other) {
            
            // TO DO:  Write this constructor.
            this->bars = new Bar[other.size];       // size that exists
            this->size = other.size;
            this->capacity = other.capacity;
            this->frame = other.frame;
            
            for (int i = 0; i < other.size; ++i)
            {
                this->bars[i] = other.bars[i];
            }

        }

        //
        // copy operator=
        //
        // Called when you assign one BarChart into another, i.e. this = other;
        //
        BarChart& operator=(const BarChart& other) {
            
            if (this == &other) {
                return *this;
            }

            delete[] bars;

            this->bars = new Bar[other.size];
            this->size = other.size;
            this->capacity = other.capacity;
            this->frame = other.frame;

            for (int i = 0; i < other.size; ++i) {
                this->bars[i] = other.bars[i];
            }

            return *this;
        }

        // clear
        // frees memory and resets all private member variables to default values.
        void clear() {
            
            // TO DO:  Write this operator.
            delete[] bars;
            bars = nullptr;
            capacity = 0;
            size = 0;
            frame = "";
            
        }

        //
        // destructor:
        //
        // Called automatically by C++ to free the memory associated by the
        // BarChart.
        //
        virtual ~BarChart() {

            // TO DO:  Write this destructor.
            if (bars != nullptr) {
                delete[] bars;
            }   
        }

        // setFrame
        void setFrame(string frame) {
            this->frame = frame;
        }

        // getFrame()
        // Returns the frame of the BarChart oboject.
        string getFrame() {
            return frame; 
        }

        // addBar
        // adds a Bar to the BarChart.
        // returns true if successful
        // returns false if there is not room
        bool addBar(string name, int value, string category) {
            
            Bar newBar (name, value, category);
            if (capacity > size) {
                bars[size] = newBar;
                size++;
                return true;
            }
            
            return false;
        }

        // getSize()
        // Returns the size (number of bars) of the BarChart object.
        int getSize() {
            return size; 
        }

        // operator[]
        // Returns Bar element in BarChart.
        // This gives public access to Bars stored in the Barchart.
        // If i is out of bounds, throw an out_of_range error message:
        // "BarChart: i out of bounds"
        Bar& operator[](int i) 
        {
            if (i < 0 || i >= size) {
                throw out_of_range("BarChart: i out of bounds");
            }

            return bars[i];
        }

        // dump
        // Used for printing the BarChart object.
        // Recommended for debugging purposes.  output is any stream (cout,
        // file stream, or string stream).
        // Format:
        // "frame: 1
        // aname 5 category1
        // bname 4 category2
        // cname 3 category3" <-newline here
        void dump(ostream &output) {
            output << "frame: " << frame << endl;

            sort(bars, bars+size, greater<Bar>());      // descending order

            for (int i = 0; i < size; ++i) {
                output << bars[i].getName() << " " 
                       << bars[i].getValue() << " " 
                       << bars[i].getCategory() << endl;
            }
        }

        // graph
        // Used for printing out the bar.
        // output is any stream (cout, file stream, string stream)
        // colorMap maps category -> color
        // top is number of bars you'd like plotted on each frame (top 10? top 12?)
        void graph(ostream &output, map<string, string> &colorMap, int top) 
        {
            sort(bars, bars+size, greater<Bar>());      // descending order
            
            int lenMax = 60;  // number of BOXs to print for first bar (max value)
            int lenBar = 0;
            string color, barBoxes;

            for (int x = 0; x < top; x++) 
            {
                Bar thisBar = bars[x];

                if (colorMap.size() == 0 || 
                    colorMap.find(thisBar.getCategory()) == colorMap.end()) 
                {
                    color = BLACK; 
                } 
                else {
                    color = colorMap[thisBar.getCategory()];
                }

                lenBar = (thisBar.getValue() / bars[0].getValue()) * lenMax;     // also works for first bar to avoid more if-s
                for (int i = 0; i < lenBar; i++) {
                    barBoxes += BOX;
                }

                output << color << barBoxes << ' ' << thisBar.getName() << ' ' << thisBar.getValue() << endl;
            }
        }
};

