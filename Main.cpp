/* 
 * File:   Main.cpp
 * Author: caiwei7
 *
 * Created on October 18, 2016, 2:44 PM
 */

#include "Resistor.h"
#include "Node.h"
#include "Rparser.h"
#include "NodeList.h"
#include <sstream>

#define MIN_ITERATION_CHANGE 0.0001

using namespace std;

//helper functions for solve

bool hasChanged(NodeList* nList) {
    Node* next = nList->getHead();
    while (next != NULL) {
        if (next->getVChanged() > MIN_ITERATION_CHANGE) {
            return true;
        }
        next = next->getNext();
    }
    return false;
}

void solveCircuit(NodeList* nList) {
    do {
        Node* next = nList->getHead();
        while (next != NULL) {
            if (next ->getSet() == false) {
                double first = 0;
                double second = 0;
                int nodeID = 0;
                Resistor* res = next->getRList()->getHead();
                while (res != NULL) {
                    first = first + 1.0 / res->getResistance();
                    second = second + nList ->findNode(res->getOtherEndpoint(next->getID())) ->getVoltage() / res->getResistance();
                    res = res->getNext();
                }
                next->changeVoltage(second / first);
            }
            next = next->getNext();
        }
    } while (hasChanged(nList));
}

//the main function will run

int main(int argc, char** argv) {

    NodeList* nList = new NodeList();

    string inputLine;
    cout << "> ";
    getline(cin, inputLine);
    //reads input until eof
    while (!cin.eof()) {
        string command;
        //converting the input to stringstream
        stringstream myStream(inputLine);
        myStream >> command;


        if (command == "setV") {
            int nodeID;
            double voltage;
            if (setV(myStream, nodeID, voltage, nList)) {
                nList->findNode(nodeID)->setVoltage(voltage);
                nList->findNode(nodeID)->setSet(true);
            }
        } else if (command == "unsetV") {
            int nodeID;
            if (unsetV(myStream, nodeID, nList)) {
                nList->findNode(nodeID)->setVoltage(0);
                nList->findNode(nodeID)->setSet(false);
            }
        } else if (command == "solve") {
            if (solve(nList)) {
                solveCircuit(nList);
                printSolve(nList);
            }
        } else if (command == "insertR") {

            string name;
            double resistance;
            int nodes[2];

            if (insertR(myStream, name, resistance, nodes[0], nodes[1], nList)) {
                Node* insertN = nList -> findInsertNode(nodes[0]);
                Resistor* res = new Resistor(name, resistance, nodes);
                insertN ->addResistor(res);
                insertN = nList->findInsertNode(nodes[1]);
                Resistor* res2 = new Resistor(name, resistance, nodes);
                insertN -> addResistor(res2);
            }
        } else if (command == "modifyR") {
            string name;
            double resistance;
            if (modifyR(myStream, name, resistance, nList)) {
                nList -> changeResistance(name, resistance);
            }
        }

        else if (command == "printR") {

            printR(myStream, nList);

        } else if (command == "printNode") {
            printNode(myStream, nList);
        } else if (command == "deleteR") {
            string name;
            if (deleteR(myStream, name, nList)) {
                if (name == "all") {
                    nList->deleteAllResistors();
                } else {
                    nList->deleteResistor(name);
                }
            }

        } else {
            invalidCommand();
        }

        //clears stream
        myStream.clear();
        cout << "> ";
        //next line
        getline(cin, inputLine);
    }



    delete nList;

    return 0;
}
