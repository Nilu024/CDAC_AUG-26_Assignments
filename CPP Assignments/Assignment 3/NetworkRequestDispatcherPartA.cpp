//============================================================================
// Name        : NetworkRequestDispatcherPartA.cpp
// Author      : Nilesh Desale
// Description : HTTP Status Code Dispatcher using enum class
//============================================================================

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum class HttpStatus
{
    OK = 200,
    Created = 201,
    BadRequest = 400,
    Unauthorized = 401,
    NotFound = 404,
    ServerError = 500
};

void handleResponse(HttpStatus status, const string& endpoint)
{
    cout << setw(25) << endpoint;

    switch (static_cast<int>(status))
    {
        case 200:
            cout << setw(5) << 200
                 << setw(18) << "OK"
                 << "Request successful" << endl;
            break;

        case 201:
            cout << setw(5) << 201
                 << setw(18) << "Created"
                 << "New record created" << endl;
            break;

        case 400:
            cout << setw(5) << 400
                 << setw(18) << "Bad Request"
                 << "Invalid request" << endl;
            break;

        case 401:
            cout << setw(5) << 401
                 << setw(18) << "Unauthorized"
                 << "Authentication required" << endl;
            break;

        case 404:
            cout << setw(5) << 404
                 << setw(18) << "Not Found"
                 << "Endpoint does not exist" << endl;
            break;

        case 500:
            cout << setw(5) << 500
                 << setw(18) << "Server Error"
                 << "Internal server error - retry later" << endl;
            break;

        default:
            cout << setw(5) << "???"
                 << setw(18) << "Unknown"
                 << "Unknown HTTP status" << endl;
    }
}

int main()
{
    cout << left
         << setw(25) << "Endpoint"
         << setw(5)  << "Code"
         << setw(18) << "Status"
         << "Message" << endl;

    cout << string(75, '-') << endl;

    handleResponse(HttpStatus::OK,
                   "GET /api/users");

    handleResponse(HttpStatus::Created,
                   "POST /api/users");

    handleResponse(HttpStatus::Unauthorized,
                   "POST /api/login");

    handleResponse(HttpStatus::NotFound,
                   "GET /api/products/99");

    handleResponse(HttpStatus::ServerError,
                   "POST /api/order");

    return 0;
}
