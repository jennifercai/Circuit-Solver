/* 
 * File:   Node.h
 * Author: JC and VB
 * Author: TSA
 *
 * Updated on August 24, 2016, 01:40 PM
 * Created on October 6, 2013, 12:58 PM
 */

#ifndef NODE_H
#define NODE_H

#include "ResistorList.h"

class Node {
private:

    int id;
    bool set;
    int resistors;
    double voltage;
    double vChanged;
    ResistorList* rList;
    Node* next;

public:
    Node(int idNum); //implement this
    ~Node();
    // Updates resIDArray to make the resistor in position rIndex in
    // the resistor array connected to this node.
    void addResistor(Resistor* res);
    void resetRList();
    // prints the whole node
    // nodeIndex is the position of this node in the node array.
    void print();

    int getID();
    double getVoltage();
    ResistorList* getRList();
    Node* getNext();
    void setNext(Node* setNextN);
    double getVChanged();
    void deleteResistor();
    void setVoltage(double sVoltage);
    void changeVoltage(double sVoltage);
    void unsetVoltage();
    void setSet(bool isSet);
    bool getSet();
};

#endif	/* NODE_H */

