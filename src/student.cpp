#include "student.h"

Student::Student(std::string &name, int age, int id):name(name), age(age), id(id) {}

std::string Student::getName(){
    return name;
}

int Student::getAge(){
    return age;
}

int Student::getId(){
    return id;
}

void Student::setAge(int age){
    this->age = age;
}

void Student::setName(std::string &name){
    this->name = name;
}

void Student::setId(int id){
    this->id = id;
}