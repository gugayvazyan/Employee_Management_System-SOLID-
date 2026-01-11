#pragma once
#include <iostream>

class ISalaried {
public:
    virtual int Calculate() = 0;
    virtual void clean() = 0;
    virtual ~ISalaried() = default;
};