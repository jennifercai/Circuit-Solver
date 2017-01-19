#include "Node.h"
#include <iostream>

using namespace std;

//default constructor, sets initial values to 0

Node::Node(int idNum) {
    id = idNum;
    bool set = false;
    resistors = 0;
    voltage = 0;
    vChanged = 0;
    rList = new ResistorList();
    next = NULL;
}

Node::~Node() {
    delete rList;
}

//adds a resistor, increments the resistor count numRes

void Node::addResistor(Resistor* res) {
    rList->insertResistor(res);
    resistors = resistors + 1;
}

void Node::resetRList() {
    rList = new ResistorList();
}
//prints out node with formatting

void Node::print() {
    cout << "Connections at node " << id << ": " << resistors << " resistor(s)" << endl;
}

int Node::getID() {
    return id;
}

void Node::deleteResistor() {
    resistors = resistors - 1;
}

double Node::getVoltage() {
    return voltage;
}

ResistorList* Node::getRList() {
    return rList;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node* setNextN) {
    next = setNextN;
}

void Node::setVoltage(double sVoltage) {
    voltage = sVoltage;
}

void Node::changeVoltage(double sVoltage) {
    vChanged = voltage - sVoltage;
    if (vChanged < 0) {
        vChanged = 0 - vChanged;
    }
    voltage = sVoltage;
}

double Node::getVChanged() {
    return vChanged;
}

void Node::setSet(bool isSet) {
    set = isSet;
}

bool Node::getSet() {
    return set;
}