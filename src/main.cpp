#include <iostream>
#include <memory>
#include <vector>

#include "Employee.h"
#include "ISalaried.h"
#include "EmployeeRepository.h"
#include "PayrollService.h"
#include "Developer.h"
#include "Manager.h"
#include "Accountant.h"
#include "SalesPerson.h"
#include "President.h"

int main() {
    EmployeeRepository repo;

    repo.addEmpl(std::make_shared<Developer>("Dev", 3));
    repo.addEmpl(std::make_shared<Manager>("Mgr", 2));
    repo.addEmpl(std::make_shared<Accountant>("Acc", 5));
    repo.addEmpl(std::make_shared<SalesPerson>("Sales", 7));
    repo.addEmpl(std::make_shared<President>("Gev"));


    repo.listEmpl();

    PayrollService ps;
    ps.Pay(repo);

    return 0;
}