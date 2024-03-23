#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
using std::string;

class Observer {
public:
    virtual void update(const std::string& message) = 0;
};

#endif
