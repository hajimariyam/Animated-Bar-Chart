/*
		CS 251 - Data Structures
		Project 3 - Animated Bar Chart
		Author: Mariyam Haji
		NetID: mhaji7
    	System: Visual Studio Code with Ubuntu (WSL 2) on Windows 10 

		barchartanimate.h - BarChartAnimate class
		Purpose: Implement the BarChartAnimate class to store every frame of the animation inside a
            dynamic low-level C array of BarChart objects. Memory on the heap is allocated for the
            the array of, initially, 4 BarCharts. When the array is at capacity, it expands by doubling 
            in capacity to accomodate more frames. The animate() public function draws the animation.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h"       // used by graders, do not remove
#include "barchart.h"
using namespace std;


// BarChartAnimate
class BarChartAnimate 
{
    private:
        // Private member variables for the abstraction
        BarChart* barcharts;            // pointer to dynamic C-style array containing a list of BarCharts
        int capacity;                   // total # of locations available
        int size;                       // # of elements stored in array
        map<string, string> colorMap;   // determines what color to graph each bar 
        string title;                   // (3) variables for (3) data file header lines
        string xlabel;
        string source;

    public:
        // Public member functions for a BarChartAnimate object

        // parameterized constructor:
        //      initialize with 4 BarCharts, will double in addFrame() as needed
        //      @params read-in (3) header lines from data file
        BarChartAnimate(string title, string xlabel, string source) 
        {
            barcharts = new BarChart[4];
            capacity = 4;
            size = 0;
            
            this->title = title;
            this->xlabel = xlabel;
            this->source = source;
        }
        
        // destructor:
        //      called automatically by C++ to free the memory associated by the 
        //      BarChartAnimate when the object goes out of scope
        virtual ~BarChartAnimate() {
            if (barcharts != nullptr) {
                delete[] barcharts;
            }
        }

        // accessor for size of BarChartAnimate object
        int getSize() {
            return size;
        }

        // operator[]
        //      allows read (access) or write (modify) of ith BarChart object in BarChartAnimate
        //      @return BarChart element at ith index in BarChartAnimate (in insertion order)
        BarChart& operator[](int i) 
        {
            // i is out of bounds
            if (i < 0 || i >= size) {
                throw out_of_range("BarChartAnimate: i out of bounds");
            }

            return barcharts[i];
        }

        // addFrame:
        //      read a group of records from the file and build a BarChart object that is added
        //      to the BarChartAnimate barcharts array; if barcharts has run out of space, double the capacity.
        //      Pre-condition: @param file Guaranteed to be in specific format, where first getline() 
        //              in addFrame() is an empty line above each group of records or frame data
        //      Post condition: @param file Read to end of last record in the group of records
        void addFrame(ifstream &file) 
        {
            string tempString, thisRecord;
            string year, name, country, value, category;        // columns
            int numRecords = 0;
            unsigned int colorIndex = 0;

            getline (file, tempString);                         // blank line
            getline (file, tempString);                         // total # of records in group

            // if input is invalid, reset to 0, else convert to int
            if (tempString != "") {
                numRecords = stoi(tempString);
                if (numRecords < 0) {
                    numRecords = 0;
                }
            }
            else {
                numRecords = 0;
            }

            // stores a frame, or group of records
            BarChart dataChart(numRecords);

            // for each record in group..
            for (int i = 0; i < numRecords; i++) 
            {
                // get column values
                getline (file, thisRecord);
                stringstream myStringStream (thisRecord);

                getline (myStringStream, year, ',');
                getline (myStringStream, name, ',');
                getline (myStringStream, country, ',');
                getline (myStringStream, value, ',');
                getline (myStringStream, category, ',');

                dataChart.setFrame(year);

                // build Bar object for each record, or line
                dataChart.addBar(name, stoi(value), category);

                // build color map for this group
                if (colorMap.find(category) == colorMap.end()) 
                {
                    // if category is not in map, add and associate with next color
                    colorMap.emplace(category, COLORS[colorIndex]);
                    colorIndex++;

                    // if colors < # of categories in group of records, restart loop of colors
                    if (colorIndex == COLORS.size()) {
                        colorIndex = 0;
                    }
                }
            }

            // if capacity is full, double array size before adding BarChart object
            if (size == capacity)
            {
                int newCapacity = capacity * 2;
                BarChart* newBarcharts = new BarChart[newCapacity];
            
                // copy the elements from barcharts to the new array:
                for (int thisChart = 0; thisChart < size; ++thisChart) {
                    newBarcharts[thisChart] = barcharts[thisChart];
                }

                // delete barcharts and update private data members
                delete[] barcharts;
                barcharts = newBarcharts;
                capacity = newCapacity;
            }
        
            // BarChartAnimate barcharts array is not full, add BarChart object to end
            barcharts[size] = dataChart;
            size++;
        }

        // animate:
        //      Produce the final Bar Chart Animation by displaying each frame stored in barcharts 
        //      and pausing between each frame via usleep() for an animation effect
        //      **Creative Component is commented out, see header comment in application.cpp
        //      @param output Any stream (cout, filestream, stringstream)
        //      @param top Number of bars to graph for each frame (top 10? top 12?)
        //      @param endIter Number of iterations (frames) to graph for the animation, -1 for all
        void animate(ostream &output, int top, int endIter) 
        {
            // string tempInput;
            // int delayTime;

            // cout << "Enter a number greater than 0 (higher number, more delay) "
            //      << "by which you want to delay each frame: ";
            // cin >> tempInput;
            // try {
            //     delayTime = stoi(tempInput);
            //     if (delayTime <= 0) {
            //         delayTime = 3;
            //     }
            // }
            // catch (exception& e) {
            //     cout << "Invalid input for frame delay time, exiting program..." << '\n';
            //     exit(-1);
            // }

            unsigned int microsecond = 50000;

            if (endIter == -1 || endIter > size || endIter < -1) {
                endIter = size;
            }

            // for endIter amount of BarChart objects in BarchartAnimate barcharts array..
            for (int thisFrame = 0; thisFrame < endIter - 1; thisFrame++) 
            {
                // usleep (delayTime * microsecond);
                usleep (3 * microsecond);        // delay period
                output << CLEARCONSOLE;          // to print each frame at the same place
                output << BLACK << title << "\n" << source << endl;
                barcharts[thisFrame].graph (output, colorMap, top);
                output << BLACK << xlabel << "\nFrame: " << barcharts[thisFrame].getFrame() << endl; 
            }
        }
};
