#pragma once
#include "Employee.h"
#include "ISalaried.h"


class SalesPerson: public Employee, public ISalaried {
public:
    SalesPerson(std::string _name, int _scount); 
    void printInfo();
    int Calculate();
    void clean();
    void addSale();
    int getSale();
    
private:
    int scount;
};