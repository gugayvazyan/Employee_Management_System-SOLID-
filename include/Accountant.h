#pragma once 
#include "Employee.h"
#include "ISalaried.h"


class Accountant: public Employee, public ISalaried {
public:
    Accountant(std::string _name, int _rcount); 
    void printInfo();
    int Calculate();
    void clean();
    void addRep();
    int getReport();

private:
    int rcount;

};