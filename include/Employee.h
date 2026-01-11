#pragma once
#include <iostream>
#include <string>

class Counter {
    inline static int id = 0;
    friend class Employee;
};

class Employee {
public:
    int getId();
    std::string getName(); 
    virtual void printInfo () = 0;
    virtual ~Employee() = default;
protected:
    Employee(std::string _name);
    int id;
    std::string name;
};