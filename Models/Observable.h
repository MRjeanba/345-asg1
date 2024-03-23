/**
 * @file Observable.h
 * @brief Definition of the Observable class.
 */

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observer.h"

/**
 * @brief The Observable class represents an observable object that can be observed by multiple observers.
 */
class Observable {
protected:
    std::vector<Observer*> observers; /**< Vector to store pointers to the registered observers */
    bool isEnabled = true;

public:
    /**
     * @brief Registers an observer to start observing this observable object.
     * @param observer Pointer to the observer to register.
     */
    void registerObserver(Observer* observer) {
        observers.push_back(observer);
    }

    /**
     * @brief Unregisters an observer to stop observing this observable object.
     * @param observer Pointer to the observer to unregister.
     */
    void unregisterObserver(Observer* observer) {
        // Find and erase the observer from the vector
        auto it = std::find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    /**
     * @brief Notifies all registered observers that an update has occurred.
     */
    void notifyObservers(const std::string& message) {
        if(isEnabled)
        {
            for (Observer* observer : observers) {
                observer->update(message);
            }
        }
    }

    void setEnabled(bool enabled) {
        isEnabled = enabled;
    }

    /**
     * @brief Virtual method to be overridden by subclasses for specific update behavior.
     */
//    void update() override {}
    };

#endif
