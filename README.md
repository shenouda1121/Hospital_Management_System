🏥 Hospital Management System (C++) :-

This repository contains a console-based Hospital Management System developed in C++ using file handling techniques.
The system allows efficient management of patient records including insertion, searching, updating, deletion, and persistent storage without using a database.
___________________________________________________________________________________________________________________________________________________________________________________________________________________
✨ Key Features :-

1️⃣ Patient Record Management :-

Add new patient records

Display all stored patients

Search patients by Patient ID

Update existing patient information

Delete patient records
___________________________________________________________________________________________________________________________________________________________________________________________________________________
2️⃣ File-Based Storage System :-

Patient data is stored persistently using text files

No database required

Uses record packing and unpacking
___________________________________________________________________________________________________________________________________________________________________________________________________________________
📄 Data Format :-

ID|Name|Age|Disease|Address|Phone#


Each patient record is stored on a separate line inside:

patients.txt
___________________________________________________________________________________________________________________________________________________________________________________________________________________
3️⃣ Menu-Driven Interface :-

Simple and user-friendly console menu

Easy navigation between operations

Suitable for beginners and students
___________________________________________________________________________________________________________________________________________________________________________________________________________________
🛠️ Technical Implementation :-

Language: C++

Concepts Used:

Object-Oriented Programming (OOP)

Classes & Encapsulation

File Handling (fstream)

Sequential File Access

String Processing

CRUD Operations:
Create, Read, Update, Delete
___________________________________________________________________________________________________________________________________________________________________________________________________________________
📂 Project Structure :-

Hospital_Management_System/

│

├── hospital.cpp                 # Main source code

├── patients.txt                 # Patient records (generated at runtime)

├── temp.txt                     # Temporary file for update/delete operations

├── .gitignore

└── README.md
___________________________________________________________________________________________________________________________________________________________________________________________________________________
🚀 How to Run

🔹 Compile
g++ hospital.cpp -o hospital

🔹 Run
./hospital
___________________________________________________________________________________________________________________________________________________________________________________________________________________
📌 Sample Patient Record :-

101|Ahmed|35|Diabetes|Cairo|01012345678#
___________________________________________________________________________________________________________________________________________________________________________________________________________________
🎯 Project Purpose :-

This project is designed for:

Computer Science & IT students

Learning file organization concepts

Practicing C++ OOP in a real-world scenario

Understanding how simple management systems work internally
___________________________________________________________________________________________________________________________________________________________________________________________________________________
🔮 Future Enhancements :-

Input validation

Support for spaces using getline

Binary file implementation

Indexing for faster search

GUI-based version

Database integration
___________________________________________________________________________________________________________________________________________________________________________________________________________________
📜 License :-

This project is licensed under the MIT License – free to use, modify, and distribute.
