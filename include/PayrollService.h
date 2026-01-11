#pragma once
#include <memory>
#include <iostream>
#include "ISalaried.h"
#include "EmployeeRepository.h"

class EmployeeRepository;

class PayrollService {
public:
    void Pay(EmployeeRepository& data);
};