/* 
 * File:   Rparser.cpp
 * Author: caiwei7
 *
 * Created on September 30, 2016, 9:40 PM
 * Edited  on October 18, 2016, 1:00 PM
 */
#include "Rparser.h"
#include "NodeList.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

/*Error functions prints error messages*/
void invalidCommand() {
    cout << "Error: invalid command" << endl;
}

void invalidArgument() {
    cout << "Error: invalid argument" << endl;
}

void negativeResistance() {
    cout << "Error: negative resistance" << endl;
}

void cannotBeAll() {
    cout << "Error: resistor name cannot be the keyword \"all\"" << endl;
}

void sameNode(int nodeID) {
    cout << "Error: both terminals of resistor connect to node " << nodeID
            << endl;
}

void tooMany() {
    cout << "Error: too many arguments" << endl;
}

void tooFew() {
    cout << "Error: too few arguments" << endl;
}

void resistorDoesNotExist(string name) {
    cout << "Error: resistor " << name << " not found" << endl;
}

void resistorAlreadyExists(string name) {
    cout << "Error: resistor " << name << " already exists" << endl;
}

void noNodesSet() {
    cout << "Error: no nodes have their voltage set" << endl;
}

void nodeIDNotFound(int nodeID) {
    cout << "Error: node " << nodeID << " not found" << endl;
}


/*takes out one string from the stringstream, if it fails, there are too few
  arguments, used as a helper function for other check functions*/
bool getString(stringstream& myStream, string& name) {
    myStream >> name;
    if (myStream.fail()) {
        tooFew();
        return false;
    }
    return true;
}


/*Check functions checks individual inputs for validity. If valid, returns true.
  If not valid, uses error functions to print error messages and return false.*/

/*checks the resistance to see if there is input, that it is valid, and not
  negative*/
bool checkResistance(stringstream& myStream, double& resistance) {
    string resistanceString;
    if (!getString(myStream, resistanceString)) {
        return false;
    }

    stringstream resistanceStream(resistanceString);

    resistanceStream >> resistance;
    if (resistanceStream.fail()) {
        invalidArgument();
        return false;
    }

    resistanceStream >> resistanceString;
    if (!resistanceStream.fail()) {
        invalidArgument();
        return false;
    }

    if (resistance < 0) {
        negativeResistance();
        return false;
    }

    return true;
}

bool checkVoltage(stringstream& myStream, double& voltage) {
    string voltageString;
    if (!getString(myStream, voltageString)) {
        return false;
    }

    stringstream voltageStream(voltageString);

    voltageStream >> voltage;
    if (voltageStream.fail()) {
        invalidArgument();
        return false;
    }

    voltageStream >> voltageString;
    if (!voltageStream.fail()) {
        invalidArgument();
        return false;
    }
    return true;
}

/*checks that there is input, and that it is not the keyword all*/
bool checkNotAll(stringstream& myStream, string& name) {
    if (!getString(myStream, name)) {
        return false;
    }
    if (name == "all") {
        cannotBeAll();
        return false;
    }
    return true;
}

/*checks the nodeID to see if there is input, that it is valid*/
bool checkNodeID(stringstream& myStream, int& nodeID) {
    string nodeIDString;
    if (!getString(myStream, nodeIDString)) {
        return false;
    }

    stringstream nodeIDStream(nodeIDString);

    nodeIDStream >> nodeID;

    if (nodeIDStream.fail()) {
        invalidArgument();
        return false;
    }

    nodeIDStream >> nodeIDString;
    if (!nodeIDStream.fail()) {
        invalidArgument();
        return false;
    }

    return true;
}

/*checks if there are too many inputs*/
bool checkTooMany(stringstream& myStream) {
    string temp;
    myStream >> temp;
    if (!myStream.fail()) {
        tooMany();
        return false;
    }
    return true;
}

/*checks that two nodeIDs are not the same value*/
bool checkSameNode(int nodeID1, int nodeID2) {
    if (nodeID1 == nodeID2) {
        sameNode(nodeID1);
        return false;
    }
    return true;
}

/*checks that the resistor name does not exist in the resistor array*/
bool checkResistorNotExists(NodeList* nList, string name) {
    if (nList -> resistorExists(name) != NULL) {
        resistorAlreadyExists(name);
        return false;
    }
    return true;
}

/*checks that the resistor name does exist in the resistor array*/
bool checkResistorNameExists(NodeList* nList, double& oldResistance, string name) {
    if (nList -> resistorExists(name) != NULL) {
        oldResistance = nList-> resistorExists(name) -> getResistance();
        return true;
    }
    resistorDoesNotExist(name);
    return false;
}

bool foundNodeID(NodeList* nList, int nodeID) {
    if (nList ->findNode(nodeID) != NULL)
        return true;
    nodeIDNotFound(nodeID);
    return false;
}

/*Success functions print out successful output*/

void insertRSuccess(string name, double resistance, int nodeID1, int nodeID2) {
    cout << "Inserted: resistor " << name << " " << fixed << setprecision(2) << resistance << " Ohms " << nodeID1 << " -> " << nodeID2 << endl;
}

void modifyRSuccess(string name, double oldResistance, double resistance) {
    cout << "Modified: resistor " << name << " from " << oldResistance << " Ohms to " << fixed << setprecision(2) << resistance << " Ohms" << endl;
}

void printRNameSuccess(NodeList* nList, string name) {
    cout << "Print:" << endl;
    nList->resistorExists(name)->print();
}

void printNodeAllSuccess(NodeList * nList) {
    cout << "Print:" << endl;
    Node* nextN = nList -> getHead();
    Resistor* nextR;
    while (nextN != NULL) {
        nextR = nextN -> getRList()->getHead();
        if (nextR != NULL) {
            nextN->print();
            while (nextR != NULL) {
                cout << "  ";
                nextR->print();
                nextR = nextR->getNext();
            }
        }
        nextN = nextN ->getNext();
    }
}

void printNodeNodeIDSuccess(NodeList * nList, int nodeID) {
    cout << "Print:" << endl;
    nList->findNode(nodeID)->print();
    Resistor* nextR = nList -> findNode(nodeID)->getRList()->getHead();
    while (nextR != NULL) {
        cout << "  ";
        nextR->print();
        nextR = nextR -> getNext();
    }
}

void deleteRAllSuccess() {
    cout << "Deleted: all resistors" << endl;
}

void deleteRNameSuccess(string name) {
    cout << "Deleted: resistor " << name << endl;
}

void setVSuccess(int nodeID, double voltage) {
    cout << "Set: node " << nodeID << " to " << voltage << " Volts" << endl;
}

void unsetVSuccess(int nodeID) {
    cout << "Unset: the solver will determine the voltage of node " << nodeID << endl;
}

void printSolve(NodeList* nList) {
    cout << "Solve:" << endl;
    Node* next = nList->getHead();
    while (next != NULL) {
        cout << "  Node " << next->getID() << ": ";
        cout << fixed << setprecision(2) << next->getVoltage() << " V" << endl;
        next = next->getNext();
    }
}

/*Command logic functions use check functions to check validity of statements,
 if statements are valid, will use success functions to print output*/

bool solve(NodeList* nList) {
    Node* next = nList->getHead();
    while (next != NULL) {
        if (next->getSet()) {
            return true;
        }
        next = next->getNext();
    }
    noNodesSet();
    return false;
}

bool setV(stringstream& myStream, int& nodeID, double& voltage, NodeList* nList) {
    if (checkNodeID(myStream, nodeID) && foundNodeID(nList, nodeID) && checkVoltage(myStream, voltage) && checkTooMany(myStream)) {
        setVSuccess(nodeID, voltage);
        return true;
    }
    return false;
}

bool unsetV(stringstream& myStream, int& nodeID, NodeList* nList) {
    if (checkNodeID(myStream, nodeID) && foundNodeID(nList, nodeID) && checkTooMany(myStream)) {
        unsetVSuccess(nodeID);
        return true;
    }
    return false;
}

bool insertR(stringstream& myStream, string& name, double& resistance,
        int& nodeID1, int& nodeID2, NodeList* nList) {

    if (checkNotAll(myStream, name) && checkResistance(myStream, resistance)
            && checkNodeID(myStream, nodeID1)
            && checkNodeID(myStream, nodeID2)
            && checkResistorNotExists(nList, name)
            && checkSameNode(nodeID1, nodeID2) && checkTooMany(myStream)) {
        insertRSuccess(name, resistance, nodeID1, nodeID2);
        return true;
    }
    return false;
}

bool modifyR(stringstream& myStream, string& name, double& resistance, NodeList* nList) {
    double oldResistance;
    if (checkNotAll(myStream, name)
            && checkResistorNameExists(nList, oldResistance, name)
            && checkResistance(myStream, resistance) && checkTooMany(myStream)) {
        modifyRSuccess(name, oldResistance, resistance);
        return true;
    }
    return false;
}

bool printR(stringstream& myStream, NodeList* nList) {

    string name;
    double dummyDouble;
    if (getString(myStream, name) && checkTooMany(myStream) && checkResistorNameExists(nList, dummyDouble, name)) {
        printRNameSuccess(nList, name);
        return true;
    }
    return false;
}

bool printNode(stringstream& myStream, NodeList* nList) {
    string nodeID;
    int nodeID1;

    if (getString(myStream, nodeID)) {

        if (nodeID == "all") {
            if (checkTooMany(myStream)) {
                printNodeAllSuccess(nList);
                return true;
            }
        }
        stringstream nodeConversion(nodeID);
        if (checkNodeID(nodeConversion, nodeID1) && checkTooMany(myStream)) {
            printNodeNodeIDSuccess(nList, nodeID1);
            return true;
        }
    }
    return false;
}

bool deleteR(stringstream& myStream, string& name, NodeList* nList) {
    if (getString(myStream, name) && checkTooMany(myStream)) {
        if (name == "all") {
            deleteRAllSuccess();
            return true;
        } else {
            double dummyDouble;
            if (checkResistorNameExists(nList, dummyDouble, name)) {
                deleteRNameSuccess(name);
                return true;
            }
        }
    }
    return false;
}

