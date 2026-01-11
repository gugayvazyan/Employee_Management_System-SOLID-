#include "Accountant.h"

Accountant::Accountant(std::string _name, int _rcount) : Employee(_name), rcount(_rcount) {}
void Accountant::printInfo() {
    std::cout << "| Name: " << getName() << " | Id:" << getId() << " | Post: Accountant | Reports: " <<  getReport() << " | Salary amount: " << Calculate() << " |" << std::endl; 
}
int Accountant::Calculate() {
    return 400000 + (getReport() * 30000);
};
void Accountant::clean() { rcount = 0; };
void Accountant::addRep() { ++rcount; }
int Accountant::getReport() { return rcount; }