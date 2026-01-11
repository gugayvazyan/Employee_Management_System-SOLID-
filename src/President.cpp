#include "President.h"

President::President(std::string _name) : Employee(_name) {}

void President::printInfo() {
    std::cout << "| Name: " << getName() << " | Id:" << getId() << " | Post: President | Salary amount: Infinity |" << std::endl; 
}