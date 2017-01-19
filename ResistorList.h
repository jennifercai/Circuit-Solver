/* 
 * File:   ResistorList.h
 * Author: caiwei7
 *
 * Created on November 8, 2016, 9:59 PM
 */

#ifndef RESISTORLIST_H
#define	RESISTORLIST_H


#include <string>
#include "Resistor.h"
class ResistorList {
private:

    Resistor* head;

public:
    ResistorList();
    ~ResistorList();

    //insert resistor at end of the list
    void insertResistor (Resistor* insertR);
    
    //returns pointer to the resistor with name
    Resistor* findResistor (string name);
    

    //deletes resistor given a pointer
    void deleteResistor (Resistor* deleteR);
    
    Resistor* getHead();

};



#endif	/* RESISTORLIST_H */

