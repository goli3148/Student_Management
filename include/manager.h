#ifndef MANAGER_H
#define MANAGER_H
#include<vector>
#include<string>
#include "student.h"
class Manager{
    public:
        Manager(std::vector <Student> &students);
        Manager(Student &student);
        bool update(int id, std::string &name);
        bool update(int id, int age);
        bool update(int id, int newId, int avoid_overload);
        bool del(int id);
        bool add(int id, std::string &name, int age);
        int search(int id);
        void displayStudents();
    private:
        std::vector <Student> &students;
};
#endif