/* 
 * File:   NodeLIst.h
 * Author: caiwei7
 *
 * Created on November 8, 2016, 9:33 PM
 */

#ifndef NODELIST_H
#define	NODELIST_H


#include <string>
#include "Node.h"
#include "ResistorList.h"
#include "Resistor.h"

class NodeList {
private:

    Node* head;

public:
    NodeList();
    ~NodeList();

    void insertNode(Node* insertN);

    //pointer to the node with the indicated node ID, NULL if DNE
    Node* findNode(int nodeID);

    //finds a nodeID, if it DNE, creates a new one
    Node* findInsertNode(int nodeID);

    //checks if resistor exists in any of the nodes
    Resistor* resistorExists(string rName);

    //returns true if successful, otherwise false
    bool changeResistance(string rName, double newR);

    //returns true if successful, otherwise false
    bool deleteResistor(string rName);

    void deleteAllResistors();

    void deleteNode(Node* deleteN);
    
    Node* getHead();

};






#endif	/* NODELIST_H */

