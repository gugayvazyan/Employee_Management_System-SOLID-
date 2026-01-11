#include "Developer.h"

Developer::Developer(std::string _name, int _pcount) : Employee(_name), pcount(_pcount) {}
void Developer::printInfo() {
    std::cout << "| Name: " << getName() << " | Id:" << getId() << " | Post: Developer | Projects: " <<  getProjects() << " | Salary amount: " << Calculate() << " |" << std::endl; 
}
int Developer::getProjects() { return pcount; }

int Developer::Calculate() { 
    return 1500000 + (getProjects() * 100000);
}
void Developer::clean() { pcount = 0; }
void Developer::addProj() { ++pcount; }