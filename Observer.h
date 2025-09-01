#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
#include "Menus.h"

class Menus;

class Observer{
    public:
        virtual void update(Menus* subject,std::string message) = 0; // allows a single observer to listen to multiple menus without double output
        virtual ~Observer() = default;
        void setSubject(Menus* s);
        Menus* getSubject()const{return subject;}
        const std::vector<std::vector<Pizza *>>& getStateHistory() const{
            return observerStates;
        }
        void clearHistory(){
            observerStates.clear();
        }
    protected:
        std::vector<std::vector<Pizza *>> observerStates;
        Menus *subject = nullptr;
};

#endif