//============================================================================
// Name        : LogBufferProperCopySemantics.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

class LogBuffer{

private:
	char* buffer;
	int capacity;
	int size;
	static int instanceCount;

public:
	// Constructor — allocates char buffer of given capacity on heap
	LogBuffer(int capacity);

	// Copy Constructor — must perform a DEEP copy
	LogBuffer(const LogBuffer& other);

	// Copy Assignment Operator — must handle self-assignment, release old memory,deep copy
	LogBuffer& operator=(const LogBuffer& other);

	// Destructor — frees the buffer, decrements instanceCount
	~LogBuffer();

	void append(const char* msg); // Appends msg to buffer (up to capacity)

	void print() const; // Prints current buffer contents

	 	 void clear(); // Resets size to 0

	// Returns current live object count
	static int getInstanceCount();
};

int LogBuffer::instanceCount = 0;

LogBuffer::LogBuffer(int capacity){
    this->capacity = capacity;
    this->size = 0;

    buffer = new char[capacity + 1];

    buffer[0] = '\0';

    instanceCount++;

    cout << "[LogBuffer Created] capacity=" << capacity << endl;
}

LogBuffer::LogBuffer(const LogBuffer& other){

	capacity = other.capacity;
	size = other.size;

	buffer = new char[capacity +1];

	memcpy(buffer, other.buffer, size+1);

	instanceCount++;

	cout << "[LogBuffer Deep Copied] capacity = " << capacity << endl;
}

LogBuffer& LogBuffer::operator=(const LogBuffer& other){
	if(this == &other){

		cout << "[Self-assignment detected — no operation]" << endl;

		return *this;
	}

	delete[] buffer;

	capacity = other.capacity;
	size = other.size;

	buffer = new char[capacity + 1];

	memcpy(buffer, other.buffer, size+1);

	cout << "[LogBuffer Assigned]" << endl;

	return *this;
}

LogBuffer::~LogBuffer(){

	delete[] buffer;

	instanceCount++;

	cout << "[LogBuffer Destroyed]" << endl;
}

void LogBuffer::append(const char* msg){

	int msglength = strlen(msg);

	int available = capacity - size;

	int copyLength = min(msglength, available);

	memcpy(buffer+ size, msg, copyLength);

	size += copyLength;

	buffer[size] = '\0';

}

void LogBuffer::print() const {
	cout << buffer << endl;
}

void LogBuffer::clear(){

	size = 0;
	buffer[0] = '\0';

}

int LogBuffer::getInstanceCount(){
    return instanceCount;
}

int main() {

	// Objective 1 : Basic usage
	 LogBuffer log1(256);
	 log1.append("Server started on port 8080");
	 log1.append(" | Request received from 192.168.1.10");
	 log1.print();

	 cout << "" << endl;

	 // Objective 2 : Deep copy via copy constructor
	 LogBuffer log2 = log1; // copy constructor
	 log2.append(" | Cached response sent");
	 cout << "log1 : "; log1.print(); // must NOT contain log2's append
	 cout << "log2 : "; log2.print();
	 cout << "" << endl;

	 // Objective 3 : Copy assignment operator
	 LogBuffer log3(128);
	 log3 = log1; // copy assignment
	 log3.print();
	 cout << "" << endl;

	 // Objective 4 : Self-assignment guard
	 log1 = log1; // must not crash or corrupt data
	 log1.print();
	 cout << "" << endl;

	 // Objective 5 : Static member
	 cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;


	return 0;
}
