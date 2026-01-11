#include "SalesPerson.h"



SalesPerson::SalesPerson(std::string _name, int _scount) : Employee(_name), scount(_scount) {}

void SalesPerson::printInfo() {
    std::cout << "| Name: " << getName() << " | Id:" << getId() << " | Post: SalesPerson | Sales : " <<  getSale() << " | Salary amount: " << Calculate() << " |" << std::endl; 
}

int SalesPerson::Calculate() {
    return 600000 + (scount * 75000); 
}

void SalesPerson::clean() { scount = 0; }
void SalesPerson::addSale() { ++scount; }
int SalesPerson::getSale() { return scount; }