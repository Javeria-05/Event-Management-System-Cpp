#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

struct Event {
    string eventName;
    string eventDate;
    Event* left;
    Event* right;
};

Event* createEvent(string name, string date) {
    Event* newEvent = new Event;
    newEvent->eventName = name;
    newEvent->eventDate = date;
    newEvent->left = newEvent->right = nullptr;
    return newEvent;
}

Event* insertEvent(Event* root, string name, string date) {
    if (root == nullptr)
        return createEvent(name, date);
    if (name < root->eventName)
        root->left = insertEvent(root->left, name, date);
    else
        root->right = insertEvent(root->right, name, date);
    return root;
}

void inOrder(Event* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << "Event: " << root->eventName << ", Date: " << root->eventDate << endl;
        inOrder(root->right);
    }
}

void saveEventsToFile(Event* root, ofstream &file) {
    if (root != nullptr) {
        saveEventsToFile(root->left, file);
        file << "Event: " << root->eventName << ", Date: " << root->eventDate << endl;
        saveEventsToFile(root->right, file);
    }
}

void deleteTree(Event* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

void saveParticipantsToFile(queue<string> q, ofstream &file) {
    while (!q.empty()) {
        file << q.front() << endl;
        q.pop();
    }
}

int main() {
    Event* root = nullptr;
    stack<string> actionStack;
    queue<string> participantQueue;

    int choice;
    do {
        cout << "\n====== Event Management Menu ======\n";
        cout << "1. Add Event\n";
        cout << "2. Register Participant\n";
        cout << "3. Display Events\n";
        cout << "4. Show Registration Order\n";
        cout << "5. Save Events to File\n";
        cout << "6. Undo Last Action (name only)\n";
        cout << "7. Save Participants to File\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        cin.ignore(); // flush newline

        if (choice == 1) {
            string name, date;
            cout << "Enter Event Name: ";
            getline(cin, name);
            cout << "Enter Event Date (e.g. 2025-08-01): ";
            getline(cin, date);
            root = insertEvent(root, name, date);
            actionStack.push("Added Event: " + name);
            cout << "Event added successfully.\n";
        }
        else if (choice == 2) {
            string participant;
            cout << "Enter Participant Name: ";
            getline(cin, participant);
            participantQueue.push(participant);
            actionStack.push("Registered Participant: " + participant);
            cout << "Participant registered successfully.\n";
        }
        else if (choice == 3) {
            cout << "\n--- Events List (In-Order) ---\n";
            inOrder(root);
        }
        else if (choice == 4) {
            cout << "\n--- Participant Registration Order ---\n";
            queue<string> tempQueue = participantQueue;
            while (!tempQueue.empty()) {
                cout << tempQueue.front() << endl;
                tempQueue.pop();
            }
        }
        else if (choice == 5) {
            ofstream file("Events.txt");
            if (file.is_open()) {
                saveEventsToFile(root, file);
                file.close();
                cout << "Events saved to 'Events.txt'.\n";
            } else {
                cout << "Unable to open file.\n";
            }
        }
        else if (choice == 6) {
            if (!actionStack.empty()) {
                cout << "Undo: " << actionStack.top() << endl;
                actionStack.pop();
            } else {
                cout << "Nothing to undo.\n";
            }
        }
        else if (choice == 7) {
            ofstream file("Participants.txt");
            if (file.is_open()) {
                saveParticipantsToFile(participantQueue, file);
                file.close();
                cout << "Participants saved to 'Participants.txt'.\n";
            } else {
                cout << "Unable to open file.\n";
            }
        }
        else if (choice == 0) {
            cout << "Exiting program. Bye!\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    deleteTree(root);
    return 0;
}
