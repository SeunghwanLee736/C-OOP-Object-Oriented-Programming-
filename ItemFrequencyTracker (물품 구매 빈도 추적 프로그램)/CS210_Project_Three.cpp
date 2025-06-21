#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

// Class for encapsulate item frequency tracking
class ItemTracker {
private:
    map<string, int> itemFrequency;

public:
    // Constructor -> loads data from file and builds map
    ItemTracker(const string& filename) {
        ifstream inFile(filename);
        if (!inFile) {
            cerr << "Error: Unable to open input file.\n";
            exit(1);
        }

        string item;
        while (inFile >> item) {
            itemFrequency[item]++;
        }

        inFile.close();
        WriteFrequencyData("frequency.dat");
    }

    // Returns frequency of a specific item
    int GetFrequency(const string& item) const {
        auto it = itemFrequency.find(item);
        if (it != itemFrequency.end()) {
            return it->second;
        }
        return 0;
    }

    // Outputs all item frequencies
    void PrintAllFrequencies() const {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Outputs a histogram of all item frequencies
    void PrintHistogram() const {
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }

    // Writes frequencies to a backup file
    void WriteFrequencyData(const string& outputFilename) const {
        ofstream outFile(outputFilename);
        if (!outFile) {
            cerr << "Error: Unable to open output file.\n";
            exit(1);
        }

        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }

        outFile.close();
    }
};

// Displays the menu
void DisplayMenu() {
    cout << "\n==== Corner Grocer Menu ====\n";
    cout << "1. Search for an item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    int choice;
    string item;

    while (true) {
        DisplayMenu();
        cin >> choice;

        // Input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter item to search for: ";
            cin >> item;
            cout << item << " was purchased " << tracker.GetFrequency(item) << " times.\n";
            break;
        case 2:
            tracker.PrintAllFrequencies();
            break;
        case 3:
            tracker.PrintHistogram();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice. Please select between 1 and 4.\n";
        }
    }
}
