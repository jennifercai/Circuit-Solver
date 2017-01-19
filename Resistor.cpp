#include "Resistor.h"
#include <iomanip>

using namespace std;


//constructor, sets intial value

Resistor::Resistor(string name_, double resistance_, int endpoints_[2]) {
    name = name_;
    resistance = resistance_;
    endpointNodeIDs[0] = endpoints_[0];
    endpointNodeIDs[1] = endpoints_[1];
    next = NULL;
}

//returns private variable name

string Resistor::getName() const {
    return name;
}

//returns private variable resistance

double Resistor::getResistance() const {
    return resistance;
}

//sets private variable resistance

void Resistor::setResistance(double resistance_) {
    resistance = resistance_;
}

Resistor* Resistor::getNext() {
    return next;
}

void Resistor::setNext(Resistor* setNextR) {
    next = setNextR;
}

int Resistor::getOtherEndpoint(int endpoint) {
    if (endpointNodeIDs[0] == endpoint)
        return endpointNodeIDs[1];
    return endpointNodeIDs[0];
}

//prints out resistor with formatting

void Resistor::print() {
    cout.width(20);
    cout << left << name;
    cout << " ";
    cout.width(8);
    cout << right << fixed << setprecision(2) << resistance << " Ohms " << endpointNodeIDs[0] << " -> " << endpointNodeIDs[1] << endl;
}