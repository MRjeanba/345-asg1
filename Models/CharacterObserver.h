/**
 * @file CharacterObserver.h
 * @brief Definition of the CharacterObserver class.
 */

#ifndef CHARACTEROBSERVER_H
#define CHARACTEROBSERVER_H

#include "Observer.h"
#include "fighter.h"

/**
 * @brief The CharacterObserver class represents an observer that monitors a fighter object.
 */
class CharacterObserver : public Observer {
private:
    fighter* character; /**< Pointer to the fighter object being observed */

public:
    /**
     * @brief Constructor for the CharacterObserver class.
     * @param character Pointer to the fighter object to observe.
     */
    CharacterObserver(fighter* character);

    /**
     * @brief Update method to be called when the observed fighter object's attributes are updated.
     */
    void update(const std::string& message);
};

#endif // CHARACTEROBSERVER_H
