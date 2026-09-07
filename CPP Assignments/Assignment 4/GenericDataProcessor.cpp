//============================================================================
// Name        : GenericDataProcessor.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <stdexcept>
#include <iomanip>

using namespace std;


// ============================================================
// PART A
// ABSTRACT CLASS : DataProcessor
// ============================================================

class DataProcessor {
public:

    // Pure virtual functions
    virtual void loadData(const string& source) = 0;

    virtual void processData() = 0;

    virtual void exportResult(const string& destination) = 0;

    virtual string processorType() const = 0;

    virtual int recordCount() const = 0;


    // Non-pure virtual function
    virtual void printSummary() const
    {
        cout << "Processor Type : "
             << processorType() << endl;

        cout << "Record Count   : "
             << recordCount() << endl;
    }


    // Virtual destructor
    virtual ~DataProcessor() = default;
};


// ============================================================
// CSVProcessor
// ============================================================

class CSVProcessor : public DataProcessor {
private:

    vector<string> records;

public:

    // Load CSV data
    void loadData(const string& source) override
    {
        cout << "[CSV] Loading data from: "
             << source << endl;

        // Hard-coded 5 sample rows
        records.clear();

        records.push_back("id,name,city");
        records.push_back("101,ramesh,pune");
        records.push_back("102,suresh,mumbai");
        records.push_back("103,amit,nashik");
        records.push_back("104,rahul,nagpur");
    }


    // Convert records to uppercase
    void processData() override
    {
        for (string& record : records)
        {
            for (char& ch : record)
            {
                ch = static_cast<char>(
                    toupper(static_cast<unsigned char>(ch))
                );
            }
        }

        cout << "[CSV] Data processed successfully."
             << endl;
    }


    // Export processed records
    void exportResult(const string& destination) override
    {
        cout << endl;

        cout << "[CSV EXPORT -> "
             << destination
             << "]"
             << endl;

        for (const string& record : records)
        {
            cout << record << endl;
        }
    }


    // Return processor type
    string processorType() const override
    {
        return "CSV Processor";
    }


    // Return number of records
    int recordCount() const override
    {
        return static_cast<int>(records.size());
    }
};


// ============================================================
// SensorStreamProcessor
// ============================================================

class SensorStreamProcessor : public DataProcessor {
private:

    vector<double> readings;

    double mean;
    double minimum;
    double maximum;

public:

    SensorStreamProcessor()
        : mean(0.0),
          minimum(0.0),
          maximum(0.0)
    {
    }


    // Load sensor readings
    void loadData(const string& source) override
    {
        cout << "[Sensor] Loading data from: "
             << source << endl;

        readings.clear();

        // 8 hard-coded sensor readings
        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(24.6);
        readings.push_back(22.9);
        readings.push_back(26.3);
        readings.push_back(23.7);
        readings.push_back(24.2);
    }


    // Calculate mean, minimum and maximum
    void processData() override
    {
        if (readings.empty())
        {
            mean = 0.0;
            minimum = 0.0;
            maximum = 0.0;
            return;
        }


        double sum = 0.0;

        minimum = readings[0];
        maximum = readings[0];


        for (double value : readings)
        {
            sum += value;

            if (value < minimum)
            {
                minimum = value;
            }

            if (value > maximum)
            {
                maximum = value;
            }
        }


        mean = sum / readings.size();


        cout << "[Sensor] Data processed successfully."
             << endl;
    }


    // Export statistical summary
    void exportResult(const string& destination) override
    {
        cout << endl;

        cout << "[SENSOR EXPORT -> "
             << destination
             << "]"
             << endl;

        cout << fixed << setprecision(2);

        cout << "Mean : "
             << mean << endl;

        cout << "Min  : "
             << minimum << endl;

        cout << "Max  : "
             << maximum << endl;
    }


    // Return processor type
    string processorType() const override
    {
        return "Sensor Stream Processor";
    }


    // Return number of readings
    int recordCount() const override
    {
        return static_cast<int>(readings.size());
    }


    // Bonus getter
    double getMean() const
    {
        return mean;
    }
};


// ============================================================
// PART B
// TEMPLATE CLASS : DataBuffer<T>
//
// Circular / Ring Buffer
//
// Template definitions are kept in the same file because
// the compiler needs the complete template definition when
// generating code for specific types such as int, double,
// and string.
// ============================================================

template <typename T>
class DataBuffer {
private:

    T* data;

    int capacity;

    // Index of oldest element
    int head;

    // Index where next element is written
    int tail;

    // Current number of elements
    int count;


public:

    // Constructor
    DataBuffer(int capacity)
        : capacity(capacity),
          head(0),
          tail(0),
          count(0)
    {
        if (capacity <= 0)
        {
            throw invalid_argument(
                "Capacity must be greater than zero"
            );
        }

        data = new T[capacity];
    }


    // Destructor
    ~DataBuffer()
    {
        delete[] data;
    }


    // ========================================================
    // PUSH
    // Add element
    // If full, overwrite oldest element
    // ========================================================

    void push(const T& value)
    {
        data[tail] = value;


        // If buffer is full
        if (count == capacity)
        {
            // Oldest element is overwritten.
            // Move head to next oldest element.
            head = (head + 1) % capacity;
        }
        else
        {
            count++;
        }


        // Move tail circularly
        tail = (tail + 1) % capacity;
    }


    // ========================================================
    // POP
    // Remove and return oldest element
    // ========================================================

    T pop()
    {
        if (isEmpty())
        {
            throw underflow_error(
                "Buffer is empty"
            );
        }


        T value = data[head];


        // Move head forward
        head = (head + 1) % capacity;


        // One element removed
        count--;


        return value;
    }


    // ========================================================
    // PEEK
    // View oldest element without removing
    // ========================================================

    T peek() const
    {
        if (isEmpty())
        {
            throw underflow_error(
                "Buffer is empty"
            );
        }

        return data[head];
    }


    // ========================================================
    // isEmpty
    // ========================================================

    bool isEmpty() const
    {
        return count == 0;
    }


    // ========================================================
    // isFull
    // ========================================================

    bool isFull() const
    {
        return count == capacity;
    }


    // ========================================================
    // size
    // ========================================================

    int size() const
    {
        return count;
    }


    // ========================================================
    // FRIEND << OPERATOR
    // ========================================================

    template <typename U>
    friend ostream& operator<<(
        ostream& out,
        const DataBuffer<U>& buf
    );
};


// ============================================================
// DataBuffer << operator
// Prints elements from oldest to newest
// ============================================================

template <typename U>
ostream& operator<<(
    ostream& out,
    const DataBuffer<U>& buf
)
{
    out << "[";


    for (int i = 0; i < buf.count; i++)
    {
        int index =
            (buf.head + i) % buf.capacity;


        out << buf.data[index];


        if (i < buf.count - 1)
        {
            out << ", ";
        }
    }


    out << "]";


    return out;
}


// ============================================================
// MAIN
// ============================================================

int main()
{
    // ========================================================
    // PART A
    // Abstract Data Processor
    // ========================================================

    cout << "=============================================="
         << endl;

    cout << "        PART A - DATA PROCESSORS"
         << endl;

    cout << "=============================================="
         << endl;


    // Cannot instantiate abstract class
    //
    // DataProcessor dp;
    // ERROR: DataProcessor is an abstract class
    //
    // This line is intentionally commented out.


    // Abstract pointer array/vector
    vector<DataProcessor*> pipeline;


    pipeline.push_back(
        new CSVProcessor()
    );

    pipeline.push_back(
        new SensorStreamProcessor()
    );


    // Process every processor polymorphically
    for (auto* p : pipeline)
    {
        cout << endl;

        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }


    // ========================================================
    // BONUS
    // dynamic_cast Safety Check
    // ========================================================

    cout << endl;

    cout << "=============================================="
         << endl;

    cout << "        BONUS - dynamic_cast CHECK"
         << endl;

    cout << "=============================================="
         << endl;


    for (auto* p : pipeline)
    {
        if (auto* csv =
                dynamic_cast<CSVProcessor*>(p))
        {
            cout << "Found CSV Processor with "
                 << csv->recordCount()
                 << " records."
                 << endl;
        }
        else if (auto* sensor =
                     dynamic_cast<SensorStreamProcessor*>(p))
        {
            cout << "Found Sensor Processor - Mean: "
                 << fixed << setprecision(2)
                 << sensor->getMean()
                 << endl;
        }
    }


    // ========================================================
    // PART B
    // INTEGER BUFFER
    // ========================================================

    cout << endl;

    cout << "=============================================="
         << endl;

    cout << "        PART B - DATA BUFFER"
         << endl;

    cout << "=============================================="
         << endl;


    DataBuffer<int> tickBuffer(5);


    for (int i = 1; i <= 7; i++)
    {
        tickBuffer.push(i * 10);
    }


    cout << "Tick Buffer: "
         << tickBuffer
         << endl;


    // ========================================================
    // DOUBLE BUFFER
    // ========================================================

    DataBuffer<double> tempBuffer(4);


    tempBuffer.push(36.6);
    tempBuffer.push(37.1);
    tempBuffer.push(38.2);
    tempBuffer.push(36.9);


    cout << "Before pop: "
         << tempBuffer
         << endl;


    cout << "Popped: "
         << tempBuffer.pop()
         << endl;


    cout << "After pop: "
         << tempBuffer
         << endl;


    // ========================================================
    // STRING BUFFER
    // ========================================================

    DataBuffer<string> logBuffer(3);


    logBuffer.push(
        "INFO: Server started"
    );

    logBuffer.push(
        "WARN: High memory usage"
    );

    logBuffer.push(
        "ERROR: DB connection timeout"
    );

    logBuffer.push(
        "INFO: Retry successful"
    );


    cout << "Log Buffer: "
         << logBuffer
         << endl;


    // ========================================================
    // TEST PEEK
    // ========================================================

    cout << endl;

    cout << "Oldest log: "
         << logBuffer.peek()
         << endl;


    // ========================================================
    // TEST STATUS
    // ========================================================

    cout << "Log Buffer Size: "
         << logBuffer.size()
         << endl;

    cout << "Log Buffer Empty: "
         << (logBuffer.isEmpty() ? "Yes" : "No")
         << endl;

    cout << "Log Buffer Full: "
         << (logBuffer.isFull() ? "Yes" : "No")
         << endl;


    // ========================================================
    // CLEANUP PIPELINE
    // ========================================================

    for (auto* p : pipeline)
    {
        delete p;
    }

    pipeline.clear();


    cout << endl;

    cout << "Program completed successfully."
         << endl;


    return 0;
}
