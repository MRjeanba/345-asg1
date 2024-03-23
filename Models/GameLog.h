//
// Created by Marilyne Nguyen on 2024-03-22.
//

#ifndef GAMELOG_H
#define GAMELOG_H
#include "Observable.h"


class GameLog: public Observer {
public:
    void update(const std::string& message) override;
};


#endif
