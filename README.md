# C++ Module 00 - Introduction to C++

## Overview
This repository contains the implementations for Module 00 of the 42 School's C++ curriculum. This module focuses on introducing the basics of C++, including namespaces, classes, member functions, stdio streams, initialization lists, static, const, and other fundamental concepts.

## Status
Validated on 15/01/2024. Grade: 100%.

## General Information
- **Compiler used:** `c++`
- **Compilation flags:** `-Wall -Wextra -Werror -std=c++98`
- **Standard:** C++98 for compliance and simplicity, per the 42 School curriculum's requirements.

## Projects
This module is divided into three exercises, each emphasizing different aspects of C++ programming.

### Exercise 00: Megaphone
- **Directory:** `ex00/`
- **Files:** `Makefile`, `megaphone.cpp`
- **Description:** Create a program that converts input text to uppercase. If no input is provided, it outputs a loud and unbearable feedback noise message.
- **Key Concepts:** Basic I/O, command-line arguments, string manipulation.

### Exercise 01: My Awesome PhoneBook
- **Directory:** `ex01/`
- **Files:** `Makefile`, `Contact.hpp`, `Contact.cpp`, `PhoneBook.hpp`, `PhoneBook.cpp`, `main.cpp`
- **Description:** Implement a phonebook application that can store up to 8 contacts. The user can add new contacts, search, and view contact details.
- **Key Concepts:** Classes, member functions, arrays, basic data handling.

### Exercise 02: The Job Of Your Dreams
- **Directory:** `ex02/`
- **Files:** `Makefile`, `Account.hpp`, `Account.cpp`, `tests.cpp`
- **Objective:** Recreate the missing `Account.cpp` file for a banking application that simulates bank accounts with deposit and withdrawal functionalities.
- **Key Concepts:** Classes, member functions, static members, memory management, exception handling.

## Compilation and Usage
Each exercise directory contains a Makefile for easy compilation. To compile an exercise, navigate to its directory and run:

### Example

For `ex01`:
```sh
cd ex01 && make
./phonebook
```

## Detailed Exercise Descriptions

### Exercise 01: My Awesome PhoneBook
#### Description
Create a phonebook application that can store a maximum of 8 contacts. The program accepts three commands: `ADD`, `SEARCH`, and `EXIT`.

#### Commands
- **ADD:** Prompt the user to input the information of the new contact one field at a time. Once all fields are completed, add the contact to the phonebook.
- **SEARCH:** Display the saved contacts as a list of 4 columns: index, first name, last name, and nickname. Then, prompt the user for the index of the entry to display detailed information.
- **EXIT:** Quit the program and erase all contacts.

#### Example
```sh
$ ./phonebook
Choose your command: ADD, SEARCH, EXIT
> ADD
please enter contact firstname
John
please enter contact lastname
Doe
please enter contact nickname
Johnny
please enter contact's phone number
+123456789
please enter contact darkest secret
Afraid of spiders
Choose your command: ADD, SEARCH, EXIT
> SEARCH
     index|firstname |lastname  |nickname  
        0|      John|       Doe|    Johnny
Enter index to lookup: 
> 0
===============================================
Firstname: John
Lastname: Doe
Nickname: Johnny
Phone: +123456789
Darkest Secret: Afraid of spiders
===============================================
```
