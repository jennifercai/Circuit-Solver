#include "ResistorList.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

ResistorList::ResistorList() {
    head = NULL;
}

ResistorList::~ResistorList() {
    Resistor* nextR;
    while (head != NULL) {
        nextR = head;
        head = head->getNext();
        delete nextR;
    }
}

//insert resistor at end of the list

void ResistorList::insertResistor(Resistor* insertR) {
    if (head == NULL) {
        head = insertR;
    } else {
        Resistor* nextR = head;
        while (nextR->getNext() != NULL) {
            nextR = nextR->getNext();
        }
        nextR->setNext(insertR);
    }
}

//returns pointer to the resistor with name

Resistor* ResistorList::findResistor(string name) {
    Resistor* nextR = head;
    while (nextR != NULL) {
        if (nextR->getName() == name) {
            return nextR;
        }
        nextR = nextR->getNext();
    }
    return NULL;
}

//deletes resistor given a pointer

void ResistorList::deleteResistor(Resistor* deleteR) {
    Resistor* nextR;
    if (head == deleteR) {
        nextR = deleteR;
        head = deleteR -> getNext();
        delete nextR;
    }
    else {
        nextR = head;
        while (nextR -> getNext() != NULL && nextR -> getNext() != deleteR) {
            nextR = nextR->getNext();
        }
        nextR -> setNext(deleteR -> getNext());
        delete deleteR;
    }
}

Resistor* ResistorList::getHead() {
    return head;
}
