//
// Created by Chidi on 4/5/2017.
//
#ifndef MAVUTO_LIBSET_H
#define MAVUTO_LIBSET_H


//http://p2p.wrox.com/c-programming/92954-c-class-example-separate-header-implementation-file.html


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
    int totalMembers;
    //accessor and mutator methods

public:
    libMemb fullSet[1000];
    /*accessor for title*/
    string getTitle();
    /*mutator for title*/
    void setTitle(string newTitle);
    /* accessor for purpose*/
    string getPurpose();
    /*mutator for purpose*/
    void setPurpose(string newPurpose);
    /*add child to tally of children*/
    void addKids();
    void setTotMemb(int newMemb);
    int getTotMemb();
    /* Calculuate and set total number of levels */
    void calcLevel();
    /*Enact default features of root*/
    void rootDefaults();

    //create  set
    libSet();
    libSet(string title, string purpose, libMemb root);

        /*determine whether there are children*/
        bool haveKids();
        /*return list of kids as string*/
        //string returnKids(){

        //}
        /* create sibling */
        void createSibling(string newName, string parName, libMemb olderSib);
        //create children
        void createChild(string newName, string parName, libMemb newParent);

        //searches for item based on parent?
        //prints a string of children
        string returnChildren(string parentStr);
        //print the entire list, number of children and special notes
        string returnList();


    //finds item based on its title
    libMemb searchTitl(string afa);
    //returns item based on its parent
    libMemb searchParNT(string mumDad) ;
    string membersOfParent(libSet daSet, string targetParent);

    string levelSearch(int levelToSearch);
    //returns root
    libMemb getRoot();
};
#endif //MAVUTO_LIBSET_H