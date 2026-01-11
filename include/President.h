#pragma once 
#include "Employee.h"

class President : public Employee{
public:
    President(std::string _name); 
    void printInfo();
};