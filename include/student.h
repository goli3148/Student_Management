#ifndef STUDENT_H
#define STUDENT_H
#include <string>
class Student{
    public:
        Student(std::string &name, int age, int id);
        std::string getName();
        int getAge();
        int getId();
        void setAge(int age);
        void setId(int id);
        void setName(std::string &name);
    private:
        std::string name;
        int age;
        int id;
};
#endif