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
	

	// barchartanimate.h public function tests
	

    return 0;
}


