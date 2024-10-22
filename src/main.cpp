#include <iostream>
#include <vector>
#include "student.h"
#include "manager.h"

void displayMenu() {
    std::cout << "\n==== Student Management System ====" << std::endl;
    std::cout << "1. Add Student" << std::endl;
    std::cout << "2. Update Student" << std::endl;
    std::cout << "3. Delete Student" << std::endl;
    std::cout << "4. Display All Students" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void displayUpdateMenu() {
    std::cout << "\n==== Update Student ====" << std::endl;
    std::cout << "1. Update Name" << std::endl;
    std::cout << "2. Update Age" << std::endl;
    std::cout << "3. Update ID" << std::endl;
    std::cout << "Choose an update option: ";
}

int main() {
    std::vector<Student> studentList;
    Manager manager(studentList);

    int option;
    do {
        displayMenu();
        std::cin >> option;

        if (option == 1) {
            // Add student
            int id, age;
            std::string name;
            std::cout << "Enter student ID: ";
            std::cin >> id;
            std::cout << "Enter student name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter student age: ";
            std::cin >> age;

            if (manager.add(id, name, age)) {
                std::cout << "Student added successfully!" << std::endl;
            } else {
                std::cout << "A student with this ID already exists!" << std::endl;
            }

        } else if (option == 2) {
            // Update student
            int id, updateOption;
            std::cout << "Enter student ID to update: ";
            std::cin >> id;

            if (manager.search(id) == -1) {
                std::cout << "Student not found!" << std::endl;
                continue;
            }

            displayUpdateMenu();
            std::cin >> updateOption;

            if (updateOption == 1) {
                // Update name
                std::string newName;
                std::cout << "Enter new name: ";
                std::cin.ignore();
                std::getline(std::cin, newName);

                if (manager.update(id, newName)) {
                    std::cout << "Student name updated successfully!" << std::endl;
                } else {
                    std::cout << "Failed to update student name!" << std::endl;
                }

            } else if (updateOption == 2) {
                // Update age
                int newAge;
                std::cout << "Enter new age: ";
                std::cin >> newAge;

                if (manager.update(id, newAge)) {
                    std::cout << "Student age updated successfully!" << std::endl;
                } else {
                    std::cout << "Failed to update student age!" << std::endl;
                }

            } else if (updateOption == 3) {
                // Update ID
                int newId;
                std::cout << "Enter new ID: ";
                std::cin >> newId;

                if (manager.update(id, newId, 1)) {
                    std::cout << "Student ID updated successfully!" << std::endl;
                } else {
                    std::cout << "Failed to update student ID!" << std::endl;
                }

            } else {
                std::cout << "Invalid update option!" << std::endl;
            }

        } else if (option == 3) {
            // Delete student
            int id;
            std::cout << "Enter student ID to delete: ";
            std::cin >> id;

            if (manager.del(id)) {
                std::cout << "Student deleted successfully!" << std::endl;
            } else {
                std::cout << "Student not found!" << std::endl;
            }

        } else if (option == 4) {
            // Display all students
            manager.displayStudents();

        } else if (option == 5) {
            std::cout << "Exiting the system." << std::endl;

        } else {
            std::cout << "Invalid option! Please try again." << std::endl;
        }

    } while (option != 5);

    return 0;
}
