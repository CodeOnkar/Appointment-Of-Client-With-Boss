

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to represent an appointment
struct Appointment {
    string name;
    string date;
    string time;
    bool isEmergency;
    int waitingTime; // in minutes
};

const int APPOINTMENT_DURATION = 30; // each appointment is 30 minutes

// Function to add a new appointment
void addAppointment(vector<Appointment>& appointments) {
    Appointment newAppointment;
    cout << "Enter name: ";
    cin >> newAppointment.name;
    cout << "Enter date: ";
    cin >> newAppointment.date;
    cout << "Enter time: ";
    cin >> newAppointment.time;
    cout << "Is it an emergency appointment? (1 for Yes, 0 for No): ";
    cin >> newAppointment.isEmergency;
    newAppointment.waitingTime = 0;
    appointments.push_back(newAppointment);
    cout << "Appointment added successfully!\n" << endl;
}

// Function to calculate waiting time for each appointment
void calculateWaitingTime(vector<Appointment>& appointments) {
    int currentWaitTime = 0;
    for (auto& appointment : appointments) {
        if (appointment.isEmergency) {
            appointment.waitingTime = 0;
        } else {
            appointment.waitingTime = currentWaitTime * APPOINTMENT_DURATION;
            currentWaitTime++;
        }
    }
}

// Function to display all appointments
void displayAppointments(const vector<Appointment>& appointments) {
    cout << endl << "Appointments:\n";
    for (const auto& appointment : appointments) {
        cout << "Name: " << appointment.name << ", Date: " << appointment.date << ", Time: " << appointment.time
             << ", Waiting Time: " << appointment.waitingTime << " minutes";
        if (appointment.isEmergency) {
            cout << " (Emergency)";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<Appointment> appointments;

    while (true) {
        cout << "1. Add Appointment\n";
        cout << "2. Display Appointments\n";
        cout << "3. Exit\n";
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addAppointment(appointments);
                calculateWaitingTime(appointments);
                break;
            case 2:
                // Sort appointments based on waiting time (higher priority to emergency)
                sort(appointments.begin(), appointments.end(),
                     [](const Appointment& a, const Appointment& b) {
                         if (a.isEmergency != b.isEmergency) {
                             return a.isEmergency;
                         } else {
                             return a.waitingTime < b.waitingTime;
                         }
                     });
                displayAppointments(appointments);
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}


