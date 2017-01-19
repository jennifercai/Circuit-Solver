/* 
 * File:   Rparser.h
 * Author: caiwei7
 *
 * Created on October 18, 2016, 10:21 PM
 */

#ifndef RPARSER_H
#define	RPARSER_H

#include <string>
#include "NodeList.h"

using namespace std;

void invalidCommand();

void invalidArgument();

void negativeResistance();

void cannotBeAll();

void sameNode(int nodeID);

void tooMany();

void tooFew();

void zeroOrNegative();

void resistorDoesNotExist(string name);

void resistorAlreadyExists(string name);

void nodeIDNotFound(int nodeID);




bool getString(stringstream& myStream, string& name);

bool checkResistance(stringstream& myStream, double& resistance);

bool checkVoltage(stringstream& myStream, double& voltage);

bool checkNotAll(stringstream& myStream, string& name);

bool checkNodeID(stringstream& myStream, int& nodeID, int maxNodeNumber);

bool checkTooMany(stringstream& myStream);

bool checkSameNode(int nodeID1, int nodeID2);

bool checkResistorNotExists(NodeList* nList, string name);

bool checkResistorNameExists(NodeList* nList, double& oldResistance, string name);

bool foundNodeID(NodeList* nList, int nodeID);




void insertRSuccess(string name, double resistance, int nodeID1, int nodeID2);

void modifyRSuccess(string name, double oldResistance, double resistance);

void printRNameSuccess(NodeList* nList, string name);

void printNodeAllSuccess(NodeList * nList);

void printNodeNodeIDSuccess(NodeList * nList, int nodeID);

void deleteRAllSuccess();

void deleteRNameSuccess(string name);

void printSolve(NodeList* nList);



bool solve(NodeList* nList);

bool setV(stringstream& myStream, int& nodeID, double& voltage, NodeList* nList);

bool unsetV(stringstream& myStream, int& nodeID, NodeList* nList);

bool insertR(stringstream& myStream, string& name, double& resistance,
        int& nodeID1, int& nodeID2, NodeList* nList);

bool modifyR(stringstream& myStream, string& name, double& resistance, NodeList* nList);

bool printR(stringstream& myStream, NodeList* nList);

bool printNode(stringstream& myStream, NodeList* nList);

bool deleteR(stringstream& myStream, string& name, NodeList* nList);


#endif	/* RPARSER_H */

