#pragma once
#include "ISalaried.h"
#include "Employee.h"

class Manager: public Employee, public ISalaried {
public:


    Manager(std::string _name, int _dcount); 
    void printInfo();
    int Calculate();
    void clean();
    int getDec();
    void addDec();
private:
    int dcount;
};