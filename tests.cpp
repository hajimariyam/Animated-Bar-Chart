#include <iostream>
#include "barchartanimate.h"
using namespace std;


/* bar.h - Test each Public Member Function in Bar class */


// Test Default Constructor and Getter Functions for Bar class

bool test1BarDefaultConstructor() {
	Bar b1;
    if (b1.getName() != "") {
    	cout << "test1BarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b1.getValue() != 0) {
    	cout << "test1BarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b1.getCategory() != "") {
    	cout << "test1BarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "test1BarDefaultConstructor: all passed!" << endl;
    return true;
}

bool test2BarDefaultConstructor() {
	Bar b2;
    if (b2.getName() != "") {
    	cout << "test2BarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b2.getValue() != 0) {
    	cout << "test2BarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b2.getCategory() != "") {
    	cout << "test2BarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "test2BarDefaultConstructor: all passed!" << endl;
    return true;
}


// Test Parameterized Constructor and Getter Functions for Bar class

// typical inputs
bool test1BarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "test1BarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "test1BarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "test1BarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "test1BarParamConstructor: all passed!" << endl;
    return true;
}

// 1-letter string for name, 0 for value
bool test2BarParamConstructor() {
	Bar b("C", 0, "US");
    if (b.getName() != "C") {
    	cout << "test2BarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "test2BarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "test2BarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "test2BarParamConstructor: all passed!" << endl;
    return true;
}

// 2-word strings for name and category, -1 for value
bool test3BarParamConstructor() {
	Bar b("Los Angeles", -1, "United States");
    if (b.getName() != "Los Angeles") {
    	cout << "test3BarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != -1) {
    	cout << "test3BarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "United States") {
    	cout << "test3BarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "test3BarParamConstructor: all passed!" << endl;
    return true;
}


// Test < and > Comparison Operators for Bar class

// typical inputs
bool test1BarLessThanGreaterThan() {
	Bar b1("Chicago", 13, "US");
	Bar b2("Chicago", 25, "US");
    if (b1 < b2 && b2 > b1) {
		cout << "test1BarLessThanGreaterThan: all passed!" << endl;
		return true;
	}
	else if (!(b1 < b2)) {
		cout << "test1BarLessThanGreaterThan: < operator failed" << endl;
		return false;   
	}
	else if (!(b2 > b1)) {
		cout << "test1BarLessThanGreaterThan: > operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}

// negative values
bool test2BarLessThanGreaterThan() {
	Bar b1("Chicago", -1, "US");
	Bar b2("Chicago", 0, "US");
	if (b1 < b2 && b2 > b1) {
		cout << "test2BarLessThanGreaterThan: all passed!" << endl;
		return true;
	}
	else if (!(b1 < b2)) {
		cout << "test2BarLessThanGreaterThan: < operator failed" << endl;
		return false;   
	}
	else if (!(b2 > b1)) {
		cout << "test2BarLessThanGreaterThan: > operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}

// equal values
bool test3BarLessThanGreaterThan() {
	Bar b1("Chicago", 9234324, "US");
	Bar b2("Chicago", 9234324, "US");
    if (b1 < b2) {
		cout << "test3BarLessThanGreaterThan: < operator failed" << endl;
    	return false;
	} else if (b1 > b2) {
		cout << "test3BarLessThanGreaterThan: > operator failed" << endl;
    	return false;
	}
    cout << "test3BarLessThanGreaterThan: all passed!" << endl;
    return true;
}

// float values (setting as int should floor)
bool test4BarLessThanGreaterThan() {
	Bar b1("Chicago", 2, "US");
	Bar b2("Chicago", 2.25, "US");
    if (b1 < b2) {
		cout << "test4BarLessThanGreaterThan: < operator failed" << endl;
    	return false;
    } else if (b1 > b2) {
		cout << "test4BarLessThanGreaterThan: > operator failed" << endl;
    	return false;
	}
    cout << "test4BarLessThanGreaterThan: all passed!" << endl;
    return true;
}


// Test <= and >= Comparison Operators for Bar class

// typical inputs
bool test1BarOrEqualToOperators() {
	Bar b1("Chicago", 13, "US");
	Bar b2("Chicago", 25, "US");
    if (b1 <= b2 && b2 >= b1) {
		cout << "test1BarOrEqualToOperators: all passed!" << endl;
		return true;
	}
	else if (!(b1 <= b2)) {
		cout << "test1BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b2 >= b1)) {
		cout << "test1BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}

// negative values
bool test2BarOrEqualToOperators() {
	Bar b1("Chicago", -1, "US");
	Bar b2("Chicago", 0, "US");
	if (b1 <= b2 && b2 >= b1) {
		cout << "test2BarOrEqualToOperators: all passed!" << endl;
		return true;
	}
	else if (!(b1 <= b2)) {
		cout << "test2BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b2 >= b1)) {
		cout << "test2BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}

// equal values
bool test3BarOrEqualToOperators() {
	Bar b1("Chicago", 9234324, "US");
	Bar b2("Chicago", 9234324, "US");
    if ( (b1 <= b2) && (b2 <= b1) && (b1 >= b2) && (b2 >= b1) ) {
		cout << "test3BarOrEqualToOperators: all passed!" << endl;
		return true;
	}
	else if (!(b1 <= b2)) {
		cout << "test3BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b2 <= b1)) {
		cout << "test3BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b1 >= b2)) {
		cout << "test3BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	else if (!(b2 >= b1)) {
		cout << "test3BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}

// float values (setting as int should floor)
bool test4BarOrEqualToOperators() {
	Bar b1("Chicago", 2, "US");
	Bar b2("Chicago", 2.25, "US");
    if ( (b1 <= b2) && (b2 <= b1) && (b1 >= b2) && (b2 >= b1) ) {
		cout << "test2BarOrEqualToOperators: all passed!" << endl;
		return true;
	}
	else if (!(b1 <= b2)) {
		cout << "test4BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b2 <= b1)) {
		cout << "test4BarOrEqualToOperators: <= operator failed" << endl;
		return false;   
	}
	else if (!(b1 >= b2)) {
		cout << "test2BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	else if (!(b2 >= b1)) {
		cout << "test4BarOrEqualToOperators: >= operator failed" << endl;
		return false;   
	}
	cout << "Error" << endl;
	return false;
}


/* barchart.h - Test each Public Member Function in BarChart class */


// Test Default Constructor and Getter Functions for BarChart class 

bool test1BarChartDefaultConstructor() {
	BarChart bc1;
    if (bc1.getFrame() != "") {
    	cout << "test1BarChartDefaultConstructor: getFrame failed" << endl;
    	return false;
    } else if (bc1.getSize() != 0) {
    	cout << "test1BarChartDefaultConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test1BarChartDefaultConstructor: all passed!" << endl;
    return true;
}

bool test2BarChartDefaultConstructor() {
	BarChart bc2;
    if (bc2.getFrame() != "") {
    	cout << "test2BarChartDefaultConstructor: getFrame failed" << endl;
    	return false;
    } else if (bc2.getSize() != 0) {
    	cout << "test2BarChartDefaultConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test2BarChartDefaultConstructor: all passed!" << endl;
    return true;
}


// Test Parameterized Constructor and Getter Functions for BarChart class 

// typical input
bool test1BarChartParamConstructor() {
	BarChart bc(1);
    if (bc.getFrame() != "") {
    	cout << "test1BarChartParamConstructor: getFrame failed" << endl;
    	return false;
    } else if (bc.getSize() != 0) {
    	cout << "test1BarChartParamConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test1BarChartParamConstructor: all passed!" << endl;
    return true;
}

// negative input, should reset to 0
bool test2BarChartParamConstructor() {
	BarChart bc(-1);
    if (bc.getFrame() != "") {
    	cout << "test2BarChartParamConstructor: getFrame failed" << endl;
    	return false;
    } else if (bc.getSize() != 0) {
    	cout << "test2BarChartParamConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test2BarChartParamConstructor: all passed!" << endl;
    return true;
}


// Test Copy Constructor and Getter Functions for BarChart class 

// typical input
bool test1BarChartCopyConstructor() {
	BarChart bc(10);
	BarChart bcCopy(bc);

    if (bcCopy.getFrame() != bc.getFrame()) {
    	cout << "test1BarChartCopyConstructor: getFrame failed" << endl;
    	return false;
    } else if (bcCopy.getSize() != bc.getSize()) {
    	cout << "test1BarChartCopyConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test1BarChartCopyConstructor: all passed!" << endl;
    return true;
}

// negative input, should reset to 0
bool test2BarChartCopyConstructor() {
	BarChart bc(-1);
	BarChart bcCopy(bc);

    if (bcCopy.getFrame() != bc.getFrame()) {
    	cout << "test2BarChartCopyConstructor: getFrame failed" << endl;
    	return false;
    } else if (bcCopy.getSize() != bc.getSize()) {
    	cout << "test2BarChartCopyConstructor: getSize failed" << endl;
    	return false;
    }
    cout << "test2BarChartCopyConstructor: all passed!" << endl;
    return true;
}


// Test Copy Operator= for BarChart class using Getter Functions, addBar(), and dump()  

bool test1BarChartCopyOperator() {
	BarChart bc1(10);
	bc1.addBar ("Chicago", 2, "US");
	if (bc1.getSize() != 1) {
		cout << "test1BarChartCopyOperator: bc1.getSize failed" << endl;
		return false;
	}

	BarChart bc2;
	if (bc2.getSize() != 0) {
		cout << "test1BarChartCopyOperator: bc2.getSize failed" << endl;
		return false;
	}

	bc2 = bc1;
	if (bc2.getSize() != bc1.getSize()) {
		cout << "test1BarChartCopyOperator: getSize failed" << endl;
		return false;
	}

	cout << "test1BarChartCopyOperator: all passed!" << endl;
	return true;
}

bool test2BarChartCopyOperator() {
	BarChart bc1(10);
	BarChart bc2;
	
	bc1.addBar ("Chicago", 2, "US");
	bc2 = bc1;
	
	bc1.dump(cout);
	bc2.dump(cout);

	cout << "test2BarChartCopyOperator: all passed!" << endl;
	return true;
}


// Test setFrame(), clear(), addBar(), dump() for BarChart class

bool test1BarChartSetAndClear() {
	BarChart bc;

	bc.setFrame("2022");
	if (bc.getFrame() != "2022") {
		cout << "test1BarChartSetAndClear: setFrame/getFrame failed" << endl;
		return false;
	}

	bc.clear();
	if (bc.getFrame() != "") {
		cout << "test1BarChartSetAndClear: clear/getFrame failed" << endl;
		return false;
	}

	cout << "test1BarChartSetAndClear: all passed!" << endl;
	return true;
}

bool test2BarChartSetAndClear() {
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar ("Chicago", 1020, "US");
	bc.addBar ("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	
	bc.dump(cout);
	if (bc.getFrame() != "1950") {
		cout << "test2BarChartSetAndClear: setFrame/getFrame failed" << endl;
		return false;
	}
	if (bc.getSize() != 3) {
		cout << "test2BarChartSetAndClear: getSize failed" << endl;
		return false;
	}
	
	bc.clear();
	bc.dump(cout);
	if (bc.getFrame() != "") {
		cout << "test2BarChartSetAndClear: clear/getFrame failed" << endl;
		return false;
	}
	if (bc.getSize() != 0) {
		cout << "test2BarChartSetAndClear: getSize failed" << endl;
		return false;
	}

	cout << "test2BarChartSetAndClear: all passed!" << endl;
	return true;
}


// Test [] for BarChart class
bool testBarChartAccess() {
	BarChart bc(3);
	bc.setFrame("1950");
	
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");

	for (int i = 0; i < bc.getSize(); i++) {
		cout << bc[i].getName() << " ";
		cout << bc[i].getValue() << " ";
		cout << bc[i].getCategory();
		cout << endl;
	}

	return true;
}


// Test graph() for BarChart class

bool test1BarChartGraph() {
	BarChart bc(3);
	bc.setFrame("1950");
	
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");

	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;
	colorMap["US"] = red;
	colorMap["France"] = blue;
	
	bc.graph(cout, colorMap, 3);	// top = size

	cout << "test1BarChartGraph: all passed!" << endl;
	return true;
}

bool test2BarChartGraph() {
	BarChart bc(3);
	bc.setFrame("1950");
	
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");

	string red("\033[1;36m");
	string blue("\033[1;33m");
	map<string, string> colorMap;
	colorMap["US"] = red;
	// no color for "France" - sets to BLACK
	
	bc.graph(cout, colorMap, 10);	// top > size
	bc.graph(cout, colorMap, -1);	// top < 0

	cout << "test2BarChartGraph: all passed!" << endl;
	return true;
}


/* barchartanimate.h - Test each Public Member Function in BarChartAnimate class */


// Test Parameterized Constructor, getSize(), and Operator[] for BarChartAnimate class 

bool test1BarChartAnimParamConstructor() {
	BarChartAnimate bca("The most populous cities in the world from 1500 to 2018",
					   "Population (thousands)",
					   "Sources: SEDAC; United Nations; Demographia" );
    if (bca.getSize() != 0) {
    	cout << "test1BarChartAnimParamConstructor: getSize failed" << endl;
    	return false;
    }

	// should throw out_of_range error, commented after testing to avoid aborting run_tests
	// bca[1].dump(cout);

    cout << "test1BarChartAnimParamConstructor: all passed!" << endl;
    return true;
} 

bool test2BarChartAnimParamConstructor() {
	// should throw error, commented after testing to avoid aborting run_tests
	// BarChartAnimate bca (0,0,0);
    
    cout << "test2BarChartAnimParamConstructor: all passed!" << endl;
    return true;
} 


// Test addFrame() for BarChartAnimate class

bool test1BarChartAnimAddFrame() {
	ifstream inFile("cities.txt");
	string title, xlabel, source;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}

	// checking edge case since last line == "" and cannot be stoi'd
	try {
		bca[bca.getSize()-1].dump(cout);
		cout << "test1BarChartAnimAddFrame: all passed!" << endl;
		return true;
	}
	catch (exception& e) {		// aborts anyway
		cout << "test1BarChartAnimAddFrame: last chart dump failed" << endl;
    	return false;
	}
}

// check if memory doubles
bool test2BarChartAnimAddFrame() {
	ifstream inFile("cities.txt");
	string title, xlabel, source;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);	// should double capacity for this

	if (bca.getSize() != 5) {
		cout << "test2BarChartAnimAddFrame: capacity doubling failed" << endl;
    	return false;
	}

	cout << "test2BarChartAnimAddFrame: all passed!" << endl;
	return true;
}


// Test animate() for BarChartAnimate class
// 		(testing endIter argument; top argument is tested in graph())

// endIter > size
bool test1BarChartAnimAnimate() {
	ifstream inFile("cities.txt");
	string title, xlabel, source;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);

	if (bca.getSize() != 3) {
		cout << "test1BarChartAnimAnimate: getSize failed" << endl;
    	return false;
	}

	// endIter = 5 but size = 3, should reset to endIter = size
	// bca.animate(cout, 10, 5);

	return true;
}

// endIter = -1
bool test2BarChartAnimAnimate() {
	ifstream inFile("cities.txt");
	string title, xlabel, source;
	getline(inFile, title);
	getline(inFile, xlabel);
	getline(inFile, source);

	BarChartAnimate bca(title, xlabel, source);
	
	bca.addFrame(inFile);
	bca.addFrame(inFile);
	bca.addFrame(inFile);

	if (bca.getSize() != 3) {
		cout << "test1BarChartAnimAnimate: getSize failed" << endl;
    	return false;
	}

	// endIter = -1, should display all frames
	// bca.animate(cout, 10, -1);

	return true;
}


int main() 
{
	// bar.h public function tests
	test1BarDefaultConstructor();
	test2BarDefaultConstructor();
	test1BarParamConstructor();
	test2BarParamConstructor();
	test3BarParamConstructor();
	test1BarLessThanGreaterThan();
	test2BarLessThanGreaterThan();
	test3BarLessThanGreaterThan();
	test4BarLessThanGreaterThan();
	test1BarOrEqualToOperators();
	test2BarOrEqualToOperators();
	test3BarOrEqualToOperators();
	test4BarOrEqualToOperators();
	
	// barchart.h public function tests
	test1BarChartDefaultConstructor();
	test2BarChartDefaultConstructor();
	test1BarChartParamConstructor();
	test2BarChartParamConstructor();
	test1BarChartCopyConstructor();
	test2BarChartCopyConstructor();
	test1BarChartCopyOperator();
	test2BarChartCopyOperator();
	test1BarChartSetAndClear();
	test2BarChartSetAndClear();
	testBarChartAccess();
	test1BarChartGraph();
	test2BarChartGraph();

	// barchartanimate.h public function tests
	test1BarChartAnimParamConstructor();
	test2BarChartAnimParamConstructor();
	test1BarChartAnimAddFrame();
	test2BarChartAnimAddFrame();
	test1BarChartAnimAnimate();
	test2BarChartAnimAnimate();

    return 0;
}
