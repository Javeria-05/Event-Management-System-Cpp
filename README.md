# Event Management System (C++)
A console-based Event Management System developed in C++ using fundamental Data Structures like Binary Search Tree (BST), Queue, and Stack.
This system allows you to add events, register participants, view registration order, undo recent actions, and save data to files.

---

## Features
- Add events using Binary Search Tree (sorted by name)
- Register participants using a Queue (FIFO order)
- Undo last action using a Stack
- Save events and participants to text files
- Display events (in-order) and participant list
- File handling included (Events.txt, Participants.txt)

---

## File Output
- `Events.txt` → Contains in-order list of all events
- `Participants.txt` → Contains all registered participant names

---

## Data Structures Used
- **BST** → For storing and displaying events alphabetically  
- **Queue** → For participant registration order  
- **Stack** → To support undo functionality  

---

## How to Run

1. Make sure you have a C++ compiler (like g++, CodeBlocks, or Dev C++)
2. Save the code in a file (e.g., `main.cpp`)
3. Compile & run:
```bash
g++ main.cpp -o eventSystem
./eventSystem

---

## Sample Menu Output
====== Event Management Menu ======
1. Add Event
2. Register Participant
3. Display Events
4. Show Registration Order
5. Save Events to File
6. Undo Last Action (name only)
7. Save Participants to File
0. Exit

---

## Developer
Name: Javeria Irum
University: COMSATS University Islamabad
GitHub: Javeria-05

---

## Tags
C++ Event Management BST Queue Stack File Handling DSA Student Project Console App

