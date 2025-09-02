#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <vector>
// #include "Menus.h"
#include "Pizza.h"

class Menus;

class Observer{
    public:
        virtual void update(Menus* subject,std::string message) = 0; // allows a single observer to listen to multiple menus without double output. Done by specifying which subject is sending the update
        virtual ~Observer() = default;
        void setSubject(Menus* s);
        Menus* getSubject()const{return subject;}
        void clearHistory(){
            observerStates.clear();
        }
    protected:
        std::vector<std::vector<Pizza *>> observerStates;
        Menus *subject = nullptr;
};

#endif