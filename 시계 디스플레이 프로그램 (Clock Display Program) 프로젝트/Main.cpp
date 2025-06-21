//=========================================================
// Name: Seungwhan Lee
// CS 210 Project One - Chada Tech Clocks
// Date: 2025-05-24          
//=========================================================

#include <iostream>
#include <iomanip>

using namespace std;

// Time class for store and manipulate time
class Time {
private:
    int hour;
    int minute;
    int second;

public:
    Time() {
        hour = 0;
        minute = 0;
        second = 0;
    }

    void addHour() {
        hour = (hour + 1) % 24;
    }

    void addMinute() {
        minute++;
        if (minute >= 60) {
            minute = 0;
            addHour();
        }
    }

    void addSecond() {
        second++;
        if (second >= 60) {
            second = 0;
            addMinute();
        }
    }

    void display12HourClock() {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;
        string period = (hour >= 12) ? "PM" : "AM";

        cout << setw(25) << setfill('*') << "" << endl;
        cout << "*" << setfill(' ') << setw(6) << "" << "12-Hour Clock" << setw(7) << "" << "*\n";
        cout << "*     "
            << setw(2) << setfill('0') << displayHour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << " " << period << "     *\n";
        cout << setw(25) << setfill('*') << "" << endl;
    }

    void display24HourClock() {
        cout << setw(25) << setfill('*') << "" << endl;
        cout << "*" << setfill(' ') << setw(6) << "" << "24-Hour Clock" << setw(7) << "" << "*\n";
        cout << "*     "
            << setw(2) << setfill('0') << hour << ":"
            << setw(2) << setfill('0') << minute << ":"
            << setw(2) << setfill('0') << second << "         *\n";
        cout << setw(25) << setfill('*') << "" << endl;
    }
};

// Displays both clocks side by side
void displayClocks(Time time) {
    time.display12HourClock();
    time.display24HourClock();
    cout << endl;
}

// Displays the main menu
void displayMenu() {
    cout << "**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
}

// User menu selection
void runClockProgram() {
    Time clock;
    int choice = 0;

    do {
        displayClocks(clock);
        displayMenu();

        cout << "Enter your choice (1-4): ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // clear error flags
            cin.ignore(1000, '\n'); // discard invalid input
            cout << "Invalid input. Enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            cout << "Exiting program. Goodbye!\n";
            break;
        }

        cout << "\n";

    } while (choice != 4);
}

// Main function
int main() {
    runClockProgram();
    return 0;
}
