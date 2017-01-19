#ifndef RESISTOR_H
#define RESISTOR_H

#include <string>
#include <iostream>

using namespace std;

class Resistor {
private:
    double resistance; // resistance (in Ohms)
    string name; // C++ string holding the label
    int endpointNodeIDs[2]; // IDs of nodes it attaches to
    Resistor* next;

public:
    Resistor(string name_, double resistance_, int endpoints_[2]);
    // endpoints_ holds the node indices to which this resistor connects
    string getName() const; // returns the name
    double getResistance() const; // returns the resistance

    //int* getEndpoints () const;

    void setResistance(double resistance_);
    int getOtherEndpoint(int endpoint);
    Resistor* getNext();
    void setNext(Resistor* setNextR);
    // you *may* create either of the below to print your resistor
    void print();
    friend ostream& operator<<(ostream&, const Resistor&);
};

ostream& operator<<(ostream&, const Resistor&);

#endif	/* RESISTOR_H */

