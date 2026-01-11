#pragma once
#include "Employee.h"
#include "ISalaried.h"

class Developer : public Employee, public ISalaried {
public: 
    Developer(std::string _name, int _pcount);
    void printInfo();
    void addProj();
    int Calculate();
    int getProjects();
    void clean();
private:
    int pcount;
};
