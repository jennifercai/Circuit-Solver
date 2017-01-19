#include "NodeList.h"

#include <iostream>


using namespace std;

NodeList::NodeList() {
    head = NULL;
}

NodeList::~NodeList() {
    Node* nextN;
    while (head != NULL) {
        nextN = head;
        head = head -> getNext();
        delete nextN;
    }
}
// insert 5
// 2 4 6 8

void NodeList::insertNode(Node* insertN) {

    //insert front
    if (head == NULL) {
        head = insertN;
    } else {
        Node * nextN = head;
        Node * prevN = NULL;
        while (nextN != NULL && insertN->getID() > nextN -> getID()) {
            prevN = nextN;
            nextN = nextN -> getNext();
        }
        insertN -> setNext(nextN);
        if (prevN == NULL) {
            head = insertN;
        } else {
            prevN -> setNext(insertN);
        }
        /*while (nextN -> getNext() != NULL && insertN -> getID() > nextN -> getNext() -> getID()){
            nextN = nextN->getNext();
        }
        insertN -> setNext( nextN -> getNext());
        nextN -> setNext( insertN);*/
    }
}


//pointer to the node with the indicated node ID, NULL if DNE

Node* NodeList::findNode(int nodeID) {
    Node * nextN = head;
    while (nextN != NULL) {
        if (nextN -> getID() == nodeID) {
            return nextN;
        }
        nextN = nextN -> getNext();
    }
    return NULL;
}

//finds a nodeID, if it DNE, creates a new one

Node* NodeList::findInsertNode(int nodeID) {
    if (findNode(nodeID) == NULL) {
        Node* newNode = new Node(nodeID);
        insertNode(newNode);
        return newNode;
    }
    return findNode(nodeID);

}

//checks if resistor exists in any of the nodes

Resistor* NodeList::resistorExists(string rName) {
    Node* nextN = head;
    ResistorList* resL;
    while (nextN != NULL) {
        resL = nextN -> getRList();
        if (resL -> findResistor(rName) != NULL)
            return resL -> findResistor(rName);
        /* while (res!= NULL){
             if (res->getName() == rName){
                 return true;
             }
             res = res -> getNext();
         }*/
        nextN = nextN -> getNext();
    }
    return NULL;
}

//returns true if successful, otherwise false

bool NodeList::changeResistance(string rName, double newR) {

    if (resistorExists(rName)) {
        Node* nextN = head;
        Resistor* res;
        while (nextN != NULL) {
            res = nextN-> getRList() -> findResistor(rName);
            if (res != NULL) {
                res -> setResistance(newR);
            }
            nextN = nextN -> getNext();
        }
        return true;
    }
    return false;
}



void NodeList::deleteNode(Node* deleteN) {
    Node* nextN;
    if (head == deleteN) {
        nextN = deleteN;
        head = deleteN -> getNext();
        delete nextN;
    }
    else {
        nextN = head;
        while (nextN -> getNext() != NULL && nextN -> getNext() != deleteN) {
            nextN = nextN->getNext();
        }
        nextN -> setNext(deleteN -> getNext());
        delete deleteN;
    }
}



//returns true if successful, otherwise false

bool NodeList::deleteResistor(string rName) {

    if (resistorExists(rName)) {
        Node* nextN = head;
        ResistorList* resList;
        while (nextN != NULL) {
            resList = nextN -> getRList();
            if (resList -> findResistor(rName) != NULL) {
                nextN->deleteResistor();
                resList -> deleteResistor(resList -> findResistor(rName));
                if (resList->getHead()==NULL){
                    deleteNode (nextN);
                }
            }
            nextN = nextN -> getNext();
        }


        return true;
    }
    return false;
}
/*Node* next = nList ->getHead();
                    while (next != NULL) {
                        next->setVoltage(0);
                        next->setSet(false);
                        next = next->getNext();*/
void NodeList::deleteAllResistors() {
    Node* nextN;
    while (head != NULL) {
        nextN = head;
        head = head -> getNext();
        delete nextN;
    }
}

Node* NodeList::getHead() {
    return head;
}
