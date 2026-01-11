#include "Employee.h"

Employee::Employee(std::string _name) : id(), name(_name) { 
    id = ++Counter::id;
}

int Employee::getId() { return id; }
std::string Employee::getName() { return name; }