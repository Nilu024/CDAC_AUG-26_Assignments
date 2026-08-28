//============================================================================
// Name        : SignalProcessingPipeline.cpp
// Author      : Nilesh Desale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
#include <cmath>

using namespace std;

// 1. Compute RMS
double computeRMS(double* signal, int n)
{
    double sum = 0;
    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        sum += (*ptr) * (*ptr);
        ptr++;
    }

    return sqrt(sum / n);
}

// 2. Normalise
void normalise(double* signal, int n)
{
    double maxVal = 0;
    double* ptr = signal;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        if (fabs(*ptr) > maxVal)
        {
            maxVal = fabs(*ptr);
        }

        ptr++;
    }

    // Divide every element by max value
    ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr / maxVal;
        ptr++;
    }
}

// 3. Count zero crossings
int countZeroCrossings(double* signal, int n)
{
    int count = 0;
    double* ptr = signal;

    for (int i = 0; i < n - 1; i++)
    {
        if ((*ptr < 0 && *(ptr + 1) > 0) ||
            (*ptr > 0 && *(ptr + 1) < 0))
        {
            count++;
        }

        ptr++;
    }

    return count;
}

// 4. Apply gain
void applyGain(double* signal, int n, double gainFactor)
{
    double* ptr = signal;

    for (int i = 0; i < n; i++)
    {
        *ptr = *ptr * gainFactor;
        ptr++;
    }
}

// Main method
int main()
{
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};

    int n = sizeof(signal) / sizeof(signal[0]);

    cout << "Before processing:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    // Calculate RMS
    double rms = computeRMS(signal, n);

    // Count zero crossings
    int crossings = countZeroCrossings(signal, n);

    // Normalise signal
    normalise(signal, n);

    cout << "After normalise:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    // Apply gain
    applyGain(signal, n, 2.0);

    cout << "After applyGain:" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    cout << "RMS = " << rms << endl;
    cout << "Zero Crossings = " << crossings << endl;

    return 0;
}
