    //
// Created by Chidi on 4/9/2017.
//
#include <iostream>
#include <string>
#include "libSet.h"
#include "libMemb.h"

using namespace std;

    libSet:: libSet(){}
    libSet:: libSet(string itle, string urpose, libMemb oot)
    : title(itle), purpose(urpose), root(oot){}
        /*libSet::title = itle;
        libSet::purpose = urpose;
        libSet:: root = oot;*/

        string libSet:: getTitle(){
            return title;
        }
        /*mutator for title*/
        void libSet:: setTitle(string newTitle){
            title = newTitle;
        }
        /* accessor for purpose*/
        string libSet:: getPurpose(){
            return purpose;
        }
        /*mutator for purpose*/
        void libSet:: setPurpose(string newPurpose){
            purpose = newPurpose;
        }
        /*add child to tally of children*/
        void libSet:: addKids(){
            //search and if parent belongs, add tally
            //kids+=1;
        }
        void libSet:: setTotMemb(int newMemb){
            totalMembers= newMemb;
        }
        int libSet:: getTotMemb(){
            return totalMembers;
        }
        /* Calculuate and set total number of levels */
        void libSet:: calcLevel(){

        }
        /* Returns the root */
        libMemb libSet:: getRoot(){
            return root;
        }
        /*Enact default features of root*/
        void libSet:: rootDefaults(){
            root.setLevel(0);
        }


        /*determine whether there are children*/
        bool libSet:: haveKids(){

        }
        /*return list of kids as string*/
        //string returnKids(){

        //}
        /* create sibling */
        void libSet:: createSibling(string newName, string parName, libMemb olderSib){
        //string parName = libMemb::getParent();
        int curLev = olderSib.getLevel();

            libMemb sibling;
            sibling.setTitle(parName+"_"+newName);
            sibling.setName(newName);
            sibling.setParent(parName);
            sibling.setLevel(curLev);

            //sets item number of new child
            if(olderSib.getSiblings() < 1){
                sibling.setItemNum(1);
                sibling.setSiblings(0);
            }
            else{
                //set to siblings+1 and adds sibling to counter
                sibling.setItemNum(olderSib.getSiblings()+1);
                sibling.setSiblings(olderSib.getSiblings()+1);
            }

            //places in set of members
            setTotMemb(getTotMemb()+1);
            int placer = getTotMemb();

            fullSet[placer] = sibling;
        }
        //create children
        void libSet:: createChild(string newName, string parName, libMemb newParent){
            //string parName = libMemb::getParent();
            int curLev = newParent.getLevel();

            libMemb child;
            child.setTitle(parName+"_"+newName);
            child.setName(newName);
            child.setParent(parName);
            child.setLevel(curLev+1);

            //sets item number of new child
            if(newParent.getSiblings() < 1){
                child.setItemNum(1);
            }
            else{
                //set to siblings+1
                child.setItemNum(newParent.getSiblings()+1);
            }
            /*formerly counted number of children*/
            //libMemb::addKid();

            //places in set of members
            setTotMemb(getTotMemb()+1);
            int placer = getTotMemb();

            fullSet[placer] = child;
            totalLevels++;
        }

        //searches for item based on parent?
        //prints a string of children
        string libSet:: returnChildren(string parentStr){
            cout<< "Members of " + parentStr +":" <<endl;

            for(int ct=0; ct>= getTotMemb(); ct++){
                if(fullSet[ct].getParent() == parentStr){
                    cout<< fullSet[ct].getTitle() << endl;
                    cout<< "Children: "+ fullSet[ct].getKid() << endl;
                }
            }
        }
        //the array is supposed to be a const, not sure how to set size
        string libSet:: levelSearch(int levelToSearch) {
            int levSize = 0;
            libMemb levelMembers[levSize];

            for (int ct = 0; ct <= totalMembers; ct++) {
                int levlHold = fullSet[ct].getLevel();

                if(levlHold = levelToSearch){
                    if(fullSet[ct].getTitle() != levelMembers[ct-1].getTitle()){
                        levSize++;
                        levelMembers[ct] = fullSet[ct];
                    }
                }
                if(ct = totalMembers){
                    for(int cntr =0; cntr <= sizeof(levelMembers); cntr++){
                        cout << levelMembers[cntr].getTitle() << endl;
                    }
                }

            }

        }
        //print the entire list, number of children and special notes
        string libSet:: returnList(){
            int lev;
            libMemb hold;
            string printMembers[totalMembers];

            cout<< getTitle()<< endl;
            while (lev <= totalLevels){
                //fill with titles of one level
                for(int ct = 0; ct <= totalLevels; ct++){
                    printMembers[ct] = libSet::levelSearch(ct);

                }
                cout << "Members of Level " <<lev<< ":"<< endl;
                //print members of level
                for(int cotr= 0; cotr <= sizeof(printMembers); cotr++){
                    cout << printMembers[cotr];
                }

                lev++;
            }
        }


        //finds item based on its title
        libMemb libSet:: searchTitl(string afa) {
            int found =0;
            bool rn= true;
            while(rn != false){
            for(int ct= 0; ct <= totalMembers; ct++){
                if(fullSet[ct].getName() == afa){
                    found++;
                    return fullSet[ct];
                    }
                if(ct == totalMembers){
                    rn= false;
                    }
                }
            }
            if(found ==0){
                cout<< "Item not found. Enter new search item";
                cin >> afa;

            }
        }
        //returns item based on its parent
        libMemb libSet:: searchParNT(string mumDad) {
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
        string libSet:: membersOfParent(libSet daSet, string targetParent){
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
