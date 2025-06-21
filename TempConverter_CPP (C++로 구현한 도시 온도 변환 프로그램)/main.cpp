#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(int fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

int main() {
    ifstream inputFile("FahrenheitTemperature.txt");     // File for reading
    ofstream outputFile("CelsiusTemperature.txt");       // File for writing

    // Check if input file opened successfully
    if (!inputFile) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    // Check if output file opened successfully
    if (!outputFile) {
        cerr << "Error: Unable to create output file." << endl;
        return 1;
    }

    string city;
    int fahrenheit;

    // Read from the file until end
    while (inputFile >> city >> fahrenheit) {
        double celsius = fahrenheitToCelsius(fahrenheit);
        outputFile << city << " " << celsius << endl;
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Conversion complete. Data written to CelsiusTemperature.txt" << endl;

    return 0;
}
