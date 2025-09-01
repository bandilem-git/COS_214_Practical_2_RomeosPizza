#include "Observer.h"
#include "Menus.h"

void Observer::setSubject(Menus* s){
    // if (subject && subject != s)
    // { // deregistering from old subject
    //     subject->removeObserver(this);
    // }

    subject = s;
} // to be used by subject when we addObserver