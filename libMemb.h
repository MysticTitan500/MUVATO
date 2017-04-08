#ifndef MAVUTO_LIBMEMB_H
#define MAVUTO_LIBMEMB_H
#endif //MAVUTO_LIBMEMB_H
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
    static string title;
    static int level;
    static string parentName;
    static int kids = 0;
    static int itemNum;
    static int siblings;

public:
    static int getKid(){
        return kids;
    }
    //mutator for kids
    static void addKid(){
        kids+=1;
    }
    //acessor for parentName
    static string getParent(){
        return parentName;
    }
    void setParent(string stParent){
        parentName = stParent;
    }
    //mutator for title
    string setTitle(string newTitle){
        title = newTitle;
        return title;
    }
    //accessor for title
    static string getTitle(){
        return title;
    }
    //get the current level of the member
    static int getLevel(){
        return level;
    }
    void setLevel(int newLevel){
        level = newLevel;
    }
    static int getItemNum(){
        return itemNum;
    }
    void setItemNum(int newitemNum){
        itemNum = newitemNum;
    }
    static int getSiblings(){
        return siblings;
    }
    void setSiblings(int newSib){
        siblings = newSib;
    }
    //create default member
    libMemb(string title, int itemNum);
    libMemb(){
        //Methods
            //determines if member has children
        bool haveKids(){
            int childCt = getKid();
            if(childCt < 1){
                return false;
            }
            else{
                return true;
            }
        }
            //determines if member has siblings
        bool hasSiblings(){
            int sibCt = getSiblings();
            if(sibCt < 1){
                return false;
            }
            else{
                return true;
            }
        }
            //create sibling
        void createSibling(string newName){
            string parName = getParent();
            int curLev = getLevel();

            libMemb child;
            child.setTitle(parName+"_"+newName);
            child.setParent(parName);
            child.setLevel(curLev);

            //sets item number of new child
            if(hasSiblings()== false){
                child.setItemNum(1);
                child.setSiblings(0);
            }
            else{
                //set to siblings+1 and adds sibling to counter
                child.setItemNum(getSiblings()+1);
                child.setSiblings(getSiblings()+1);
            }


            addKid();
        }
            //create children
        void createChild(string newName){
            string parName = getParent();
            int curLev = getLevel();

            libMemb child;
            child.setTitle(parName+"_"+newName);
            child.setParent(parName);
            child.setLevel(curLev+1);

            //sets item number of new child
            if(hasSiblings()== false){
                child.setItemNum(1);
            }
            else{
                //set to siblings+1
                child.setItemNum(getSiblings()+1);
            }

                addKid();
        }
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
    }


};



