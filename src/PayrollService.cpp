#include "PayrollService.h"


void PayrollService::Pay(EmployeeRepository& data){
    int total = 0;
    int count = 0;
    for(const auto& emp : data.database) {
        if(auto salaried = dynamic_cast<ISalaried*>(emp.get())) {
            total += salaried->Calculate();
            salaried->clean();
            ++count;
        }
    }
    std::cout << "| Payded: " << total << " | For " << count << " employers |" << std::endl;
}