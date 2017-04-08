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
    static string title;
    string purpose;
    int kids= 0;
    int totalLevels;
    static int totalMembers=1;
    //accessor and mutator methods

public:
    static libMemb fullSet[1000];
    /*accessor for title*/
    static string getTitle(){
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
        //search and if parent belongs, add tally
        //kids+=1;
    }
    static void setTotMemb(int newMemb){
        totalMembers= newMemb;
    }
    static int getTotMemb(){
        return totalMembers;
    }
    /* Calculuate and set total number of levels */
    void calcLevel(){

    }
    /*Enact default features of root*/
    void rootDefaults(){
        root.setLevel(0);
    }
    //create default set
    libSet(string title, string purpose, libMemb root);

    libSet();
        /*determine whether there are children*/
        bool haveKids(){

        }
        /*return list of kids as string*/
        //string returnKids(){

        //}
        /* create sibling */
        void createSibling(string newName, string parName){
            //string parName = libMemb::getParent();
            int curLev = libMemb::getLevel();

            libMemb sibling;
            sibling.setTitle(parName+"_"+newName);
            sibling.setParent(parName);
            sibling.setLevel(curLev);

            //sets item number of new child
            if(libMemb::getSiblings() < 1){
                sibling.setItemNum(1);
                sibling.setSiblings(0);
            }
            else{
                //set to siblings+1 and adds sibling to counter
                sibling.setItemNum(libMemb::getSiblings()+1);
                sibling.setSiblings(libMemb::getSiblings()+1);
            }

            //places in set of members
            setTotMemb(getTotMemb()+1);
            int placer = getTotMemb();

            fullSet[placer] = sibling;
        }
        //create children
        void createChild(string newName, string parName){
            //string parName = libMemb::getParent();
            int curLev = libMemb::getLevel();

            libMemb child;
            child.setTitle(parName+"_"+newName);
            child.setParent(parName);
            child.setLevel(curLev+1);

            //sets item number of new child
            if(libMemb::getSiblings() < 1){
                child.setItemNum(1);
            }
            else{
                //set to siblings+1
                child.setItemNum(libMemb::getSiblings()+1);
            }
            /*formerly counted number of children*/
            //libMemb::addKid();

            //places in set of members
            setTotMemb(getTotMemb()+1);
            int placer = getTotMemb();

            fullSet[placer] = child;
        }

        //searches for item based on parent?
        //prints a string of children
        string returnChildren(string parentStr){
            cout<< "Members of " + parentStr +":" <<endl;

            for(int ct=0; ct>= getTotMemb(); ct++){
                if(fullSet[ct].getParent() == parentStr){
                    cout<< fullSet[ct].getTitle() << endl;
                    cout<< "Children: "+ fullSet[ct].getKid() << endl;
                    endl;
                }
            }
        }
        //print the entire list, number of children and special notes
        string returnList(){
            cout<< getTitle()<< endl;
            //for loop to run through each level?

                //other for loop to run through each child?
        }
    //finds item based on its title
    libMemb searchTitl(string afa) {
        for(int rn =0; rn <3; rn++){
            for(int ct= 0; ct <= totalMembers; ct++){
                if(fullSet[ct].getTitle() == afa){
                    return fullSet[ct];
                }
                else{
                    cout<< "Item not found. Enter new search item";
                    cin >> afa;

                    rn = 0;
                }
            }
        }
    }
    //returns item based on its parent
    libMemb searchParNT(string mumDad) {
        for(int rn =0; rn <3; rn++){
            for(int ct= 0; ct <= totalMembers; ct++){
                if(fullSet[ct].getParent() == mumDad){
                    return fullSet[ct];
                }
                else{
                    cout<< "Item not found. Enter new search item";
                    cin >> mumDad;

                    rn = 0;
                }
            }
        }
    }
    string membersOfParent(libSet daSet, string targetParent){
        string validMembers[daSet.getTotMemb()];

        for(int ct= 0; ct <= daSet.getTotMemb(); ct++){
            if(daSet.fullSet[ct].getParent()== targetParent && daSet.fullSet[ct].getParent() != validMembers[ct-1]){
                validMembers[ct]= daSet.fullSet[ct].getTitle();
            }
            else{
                validMembers[ct] == "empty";
            }
        }

        for(int cotr= 0; cotr <= validMembers->size(); cotr++){
            if(validMembers[cotr]!= "empty"){
                cout << validMembers[cotr];
                return validMembers[cotr];
            }
        }
    }
};
