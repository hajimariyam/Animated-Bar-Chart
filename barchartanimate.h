// barchartanimate.h
// TO DO:  add header comment here.  Also add function header comments below.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include "unistd.h"
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;

//
// BarChartAnimate
//
class BarChartAnimate 
{
    private:
        //
        // Private member variables for the abstraction.
        // This implementation uses a low-level C array, bars, to store a list of
        // BarCharts.  As a result, you must also keep track of the number of
        // elements stored (size) and the capacity of the array (capacity).
        // This IS dynamic array, so it must expand automatically, as needed.
        //
        BarChart* barcharts;  // pointer to a C-style array
        int size;
        int capacity;
        map<string, string> colorMap;
        string title;
        string xlabel;
        string source;

    public:
        // a parameterized constructor:
        // Like the ourvector, the barcharts C-array should be constructed here
        // with a capacity of 4.
        BarChartAnimate(string title, string xlabel, string source) 
        {
            barcharts = new BarChart[4];
            capacity = 4;
            size = 0;
            
            this->title = title;
            this->xlabel = xlabel;
            this->source = source;
        }

        //
        // destructor:
        //
        // Called automatically by C++ to free the memory associated
        // by BarChartAnimate.
        //
        virtual ~BarChartAnimate() 
        {
            if (barcharts != nullptr) {
                delete[] barcharts;
            }
        }

        // addFrame:
        // adds a new BarChart to the BarChartAnimate object from the file stream.
        // if the barcharts has run out of space, double the capacity (see
        // ourvector.h for how to double the capacity).
        // See application.cpp and handout for pre and post conditions.
        void addFrame(ifstream &file) 
        {
            string tempString, thisRecord;
            string year, name, country, value, category;
            int numRecords = 0, colorIndex = 0;

            getline (file, tempString);      // blank line
            getline (file, tempString);      // total records in group

            if (tempString != "") {
                numRecords = stoi(tempString);
            }
            else {
                numRecords = 0;
            }

            BarChart dataChart(numRecords);

            for (int i = 0; i < numRecords; i++) 
            {
                getline (file, thisRecord);
                stringstream myStringStream (thisRecord);

                getline (myStringStream, year, ',');
                getline (myStringStream, name, ',');
                getline (myStringStream, country, ',');
                getline (myStringStream, value, ',');
                getline (myStringStream, category, ',');

                dataChart.setFrame(year);
                dataChart.addBar(name, stoi(value), category);

                if (colorMap.find(category) == colorMap.end()) {
                    colorMap.emplace(category, COLORS[colorIndex]);
                    
                    colorIndex++;
                    if (colorIndex == COLORS.size()) {
                        colorIndex = 0;
                    }
                }
            }

            if (size == capacity)
            {
                int newCapacity = capacity * 2;
                BarChart* newBarcharts = new BarChart[newCapacity];
            
                for (int thisChart = 0; thisChart < size; ++thisChart) {
                    newBarcharts[thisChart] = barcharts[thisChart];
                }

                delete[] barcharts;
                barcharts = newBarcharts;
                capacity = newCapacity;
            }
        
            // there's room, add to the end of the array:
            barcharts[size] = dataChart;
            size++;
        }

        // animate:
        // this function plays each frame stored in barcharts.  In order to see the
        // animation in the terminal, you must pause between each frame.  To do so,
        // type:  usleep(3 * microsecond);
        // Additionally, in order for each frame to print in the same spot in the
        // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
        // in between each frame.
        void animate(ostream &output, int top, int endIter) 
        {
            unsigned int microsecond = 50000;

            if (endIter == -1) {
                endIter = size;
            }

            for (int thisFrame = 0; thisFrame < endIter - 1; thisFrame++) {
                // usleep(3 * microsecond);
                output << CLEARCONSOLE;
                output << BLACK << title << "\n" << source << endl;
                barcharts[thisFrame].graph (output, colorMap, top);
                output << BLACK << xlabel << "\nFrame: " << barcharts[thisFrame].getFrame() << endl; 
            }
            
            // top determines the number of top bars graphed
            // endIter determines how many iterations of the animation are graphed, -1 if all

        }

        //
        // Public member function.
        // Returns the size of the BarChartAnimate object.
        //
        int getSize()
        {
            return size;
        }

        //
        // Public member function.
        // Returns BarChart element in BarChartAnimate.
        // This gives public access to BarChart stored in the BarChartAnimate.
        // If i is out of bounds, throw an out_of_range error message:
        // "BarChartAnimate: i out of bounds"
        //
        BarChart& operator[](int i)
        {
            if (i < 0 || i >= size) {
                throw out_of_range("BarChartAnimate: i out of bounds");
            }

            return barcharts[i];
        }
};
