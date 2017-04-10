#ifndef MAVUTO_LIBMEMB_H
#define MAVUTO_LIBMEMB_H

//#include "libSet.h"
#include <iostream>
#include <string>

//
// Created by Chidi on 4/5/2017.
//
using namespace std;

class libMemb
{
    //initialize variables
private:
    string title;
    string name;
    int level;
    string parentName;
    int kids;
    int itemNum;
    int siblings;

public:
//create default member
    libMemb();
    libMemb(string title, int itemNum);

    int getKid();
    //mutator for kids
    void addKid();
    //acessor for parentName
    string getParent();
    void setParent(string stParent);
    //mutator for title
    string setTitle(string newTitle);
    //accessor for title
    string getTitle();
    //mutator for name
    string setName(string newName);
    //accessor for name
    string getName();
    //get the current level of the member
    int getLevel();
    void setLevel(int newLevel);
    int getItemNum();
    void setItemNum(int newitemNum);
    int getSiblings();
    void setSiblings(int newSib);


        //Methods
            //determines if member has children
     /*   bool haveKids(){
            int childCt = getKid();
            if(childCt < 1){
                return false;
            }
            else{
                return true;
            }
        }  */
            //determines if member has siblings
        bool hasSiblings();
            //create sibling
        void createSibling(string newName);

            //create children
        void createChild(string newName);
        /*    //returns list of children as strings
        void returnKids(){
            int childCt = getKid();
            bool kidSol = haveKids();

            if(kidSol == false){
                cout<< "There are no children here.";
            }
            else{
                for(int ct = 0; ct <= childCt; ct++){

                }
            }
        }  */



};

#endif //MAVUTO_LIBMEMB_H

