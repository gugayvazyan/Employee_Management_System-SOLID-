#pragma once

#include "Employee.h"
#include <vector>
#include <memory>
#include <iostream>

class PayrollService;

class EmployeeRepository {
public:
    void addEmpl(std::shared_ptr<Employee> emp);
    void delEmpl(int id);
    void listEmpl();

private:
    std::vector<std::shared_ptr<Employee>> database;

    friend class PayrollService;
};