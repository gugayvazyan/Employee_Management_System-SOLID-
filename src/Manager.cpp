#include "Manager.h"

Manager::Manager(std::string _name, int _dcount) : Employee(_name), dcount(_dcount) {}

void Manager::printInfo() {
    std::cout << "| Name: " << getName() << " | Id:" << getId() << " | Post: Manager | Decisions : " <<  getDec() << " | Salary amount: " << Calculate() << " |" << std::endl; 
}

int Manager::Calculate() {
    return 1000000 + (dcount * 100000);
}

void Manager::clean() { dcount = 0; }
void Manager::addDec() { ++dcount; }
int Manager::getDec() { return dcount; }
 