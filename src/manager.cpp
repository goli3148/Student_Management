#include <iostream>
#include <vector>
#include "manager.h"
#include "student.h"

Manager::Manager(std::vector <Student> &students):students(students){}
Manager::Manager(Student &student):students(*(new std::vector<Student>())) {
    students.push_back(student);  
}
int Manager::search(int id){
    for(int i=0; i<students.size(); i++){
        if (students[i].getId() == id){
            return i;
        }
    }
    return -1;
}
bool Manager::add(int id, std::string &name, int age){
    if (search(id) != -1) return false;
    students.push_back(Student(name, age, id));
    return true;
}
bool Manager::update(int id, std::string &name){
    int index = search(id);
    if (index == -1) return false;
    students[index].setName(name);
    return true;
}
bool Manager::update(int id, int age){
    int index = search(id);
    if (index == -1) return false;
    students[index].setAge(age);
    return true;
}
bool Manager::update(int id, int newId, int avoid_overload){
    int index = search(id);
    if (index == -1) return false;
    if (search(newId) != -1) return false;
    students[index].setId(newId);
    return true;
}
bool Manager::del(int id){
    int index = search(id);
    if (index == -1) return false;
    students.erase(students.begin()+index);
    return true;
}
void Manager::displayStudents() {
    if (students.empty()) {
        std::cout << "No students available!" << std::endl;
        return;
    }

    std::cout << "\nList of Students:\n";
    for (size_t i = 0; i < students.size(); ++i) {
        std::cout << "ID: " << students[i].getId()
                  << ", Name: " << students[i].getName()
                  << ", Age: " << students[i].getAge() << std::endl;
    }
}