//
// Created by Chidi on 4/5/2017.
//
#ifndef MAVUTO_LIBSET_H
#define MAVUTO_LIBSET_H

#endif //MAVUTO_LIBSET_H

#include <iostream>
#include <string>
#include "libMemb.h"

using namespace std;

class libSet
{
    //initialize variables
private:
    libMemb root;
    string title;
    string purpose;
    int kids= 0;
    int totalLevels;
    //accessor and mutator variables
public:
    /*accessor for title*/
    string getTitle(){
        return title;
    }
    /*mutator for title*/
    void setTitle(string newTitle){
        title = newTitle;
    }
    /* accessor for purpose*/
    string getPurpose(){
        return purpose;
    }
    /*mutator for purpose*/
    void setPurpose(string newPurpose){
        purpose = newPurpose;
    }
    /*add child to tally of children*/
    void addKids(){
        kids+=1;
    }
    /* Calculuate and set total number of levels */
    void calcLevel(){

    }
    //create default set
    libSet(string title, string purpose, libMemb root) {

    }

    libSet(){
        /*determine whether there are children*/
        bool haveKids(){

        }
        /*return list of kids as string*/
        string returnKids(){

        }
    }
};