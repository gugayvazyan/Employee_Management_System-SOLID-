#include "EmployeeRepository.h"

void EmployeeRepository::addEmpl(std::shared_ptr<Employee> emp) {
    database.push_back(emp);
}
void EmployeeRepository::delEmpl(int id) {
    for(size_t i = 0; i < database.size(); ++i) {
        if (database[i]->getId() == id) {
            database.erase(database.begin() + i);
            std::cout << "Successfully deleted." << std::endl;
            return;
        }
        std::cout << "ID not found." << std::endl;
    }
}

void EmployeeRepository::listEmpl(){
    for(auto& emp : database)
        emp->printInfo();
}




