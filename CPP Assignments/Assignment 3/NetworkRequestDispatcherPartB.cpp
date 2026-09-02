//============================================================================
// Name        : NetworkRequestDispatcherPartB.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <utility>
using namespace std;

using Header = pair<string, string>;
using HeaderList = vector<Header>;

using Port = unsigned int;
using IPAddress = string;

typedef unsigned long long RequestId;

void printHeaders(const HeaderList& headers){
    for (const Header& header : headers){
        cout << left
             << setw(20) << header.first
             << " : "
             << header.second
             << endl;
    }
}

int main() {

	HeaderList headers =
	{
	    {"Content-Type", "application/json"},
	    {"Authorization", "Bearer eyJhbGci..."},
	    {"Accept-Language", "en-US"}
	};

	Port serverPort = 8000;
	RequestId requestId= 1748293847;

	cout << "Request ID : " << requestId << endl;
	cout << "Server Port : " << serverPort << endl;

	cout << "" << endl;

	cout << "Headers: " << endl;
	printHeaders(headers);
	return 0;
}
