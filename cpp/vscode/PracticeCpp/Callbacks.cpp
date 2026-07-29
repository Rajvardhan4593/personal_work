#include <iostream>
#include <string>
#include <functional>
using namespace std;

/*
 * Callback functions are those functions which are passed as an argument in another function.
 * Callback functions can be of 3 type: Function Pointer, Class Member Function, Lambda Function.
 */

enum CalsiOperation
{
	//0,    1,      2     ,  3
	ADD,SUBSTRACT,MULTIPLY,DIVIDE
};

// 1. Member function example
class Calsi {
public:
	// Here I have defined a static member function which can be invoked directly in operate so that there will not be any requirement of current class typename
	static int add(int x, int y) {
		int result = x + y;
		cout << result << endl;
		return result;
	}

	// Here I haven't defined any static keyword so this function should be called with reference point of this class typename
	int substract(int x, int y) {
		int result = x - y;
		cout << result << endl;
		return result;
	}

	int divide(int x, int y) {
		int result = x / y;
		cout << result << endl;
		return result;
	}

	int multiply(int x, int y) {
		int result = x * y;
		cout << result << endl;
		return result;
	}

	int operate(int (*func)(int, int), int a, int b) {
		func(a, b); // This call is necessary to invoke the above function pointer
		cout << "Operation has been executed!" << endl;
		return 0;
	}

	void operate(int (Calsi::*func)(int, int), int a, int b) {
		int result = (this->*func)(a, b); // This call is necessary to invoke the above function pointer
		cout << "Operation has been executed!" << endl;
	}

	void getResult(CalsiOperation operationType, int a, int b) {
		if (operationType == ADD)            operate(add, a, b);
		else if (operationType == SUBSTRACT) operate(&Calsi::substract, a, b);
		else if (operationType == MULTIPLY)  operate(&Calsi::multiply, a, b);
		else if (operationType == DIVIDE)    operate(&Calsi::divide, a, b);
		else cout << "Specified operation is not supported!" << endl;
	}

};

// 2. Directly through function pointers example.
void work(std::string str) {
	cout << "Executing Work!" << endl;
	cout << str << endl;
}

int executeWork(void (*func)(std::string)) {
	func("This string will be printed in work()");
	cout << "After execution of work executing certain validations for it!" << endl;
	return 0;
}

// 3. Using lambda function pointers.
string printString(std::function<string(string)> callback, string name) {
	return callback(name); // Invoking the function
}

int main() {
	// Class member function as callback
	Calsi* obj = new Calsi();
	obj->getResult(CalsiOperation::ADD, 1, 2);
	obj->getResult(CalsiOperation::SUBSTRACT, 5, 2);
	obj->getResult(CalsiOperation::MULTIPLY, 9, 5);
	obj->getResult(CalsiOperation::DIVIDE, 90, 2);
	
	// Direct member function as callback
	if (executeWork(work)) {
		cout << "Failed to execute certain work, please check!" << endl;
	}

	// Defining a lambda function
	string message = printString(
		[](string name)
		{
			return "Hello " + name;
		},
		"Raj"
	);
	cout << message << endl;

	return 0;
}