//
// Created by Chidi on 4/9/2017.
//
#include <iostream>
#include <string>
#include "libMemb.h"

using namespace std;

//create default member
    libMemb:: libMemb()
    {}
    libMemb:: libMemb(string tile, int iemNum)
    : title(tile), itemNum(iemNum)
    {}

            int libMemb:: getKid(){
                return kids;
            }
            //mutator for kids
            void libMemb:: addKid(){
                kids+=1;
            }
            //acessor for parentName
            string libMemb:: getParent(){
                return parentName;
            }
            void libMemb:: setParent(string stParent){
                parentName = stParent;
            }
            //mutator for title
            string libMemb:: setTitle(string newTitle){
                title = newTitle;
                return title;
            }
            //accessor for title
            string libMemb:: getTitle(){
                return title;
            }
            string libMemb:: setName(string newName){
                name = newName;
                return name;
            }
            string libMemb:: getName(){
                return name;
            }
            //get the current level of the member
            int libMemb:: getLevel(){
                return level;
            }
            void libMemb:: setLevel(int newLevel){
                level = newLevel;
            }
            int libMemb:: getItemNum(){
                return itemNum;
            }
            void libMemb:: setItemNum(int newitemNum){
                itemNum = newitemNum;
            }
            int libMemb:: getSiblings(){
                return siblings;
            }
             void libMemb:: setSiblings(int newSib){
                siblings = newSib;
            }
        //determines if member has siblings
        bool libMemb:: hasSiblings(){
            int sibCt = getSiblings();
            if(sibCt < 1){
                return false;
            }
            else{
                return true;
            }
        }
        //create sibling
        void libMemb:: createSibling(string newName){
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
        void libMemb :: createChild(string newName){
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