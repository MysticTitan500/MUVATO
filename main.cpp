#include <iostream>
#include "libSet.h"
#include "libMemb.h"

using namespace std;

void addItem(libSet setInQuestion, string itemName){
    string titStr;
    cout << "Please enter the name of the category you are adding " +itemName+ " to: " << endl;
    cin >> titStr;

    string newPar = setInQuestion.searchTitl(titStr).getTitle();

    if(setInQuestion.searchTitl(titStr).getKid()< 1){
        setInQuestion.createChild(itemName, titStr);
        setInQuestion.searchTitl(titStr).addKid();

    }
    else{
        setInQuestion.createSibling(itemName, titStr);
        setInQuestion.searchTitl(titStr).addKid();
    }

    cout <<"Congratulations! "+itemName + "has been added!" << endl;
}

int main() {
    //create set and its name
    string setName;

    cout<< "Welcome, please enter the title of your set:"<< endl;
    cin>> setName;

    //name root of set
    libSet mainSet;
    mainSet.setTitle(setName);

    //prompt user to list number of categories(genre, company, etc.)
    int setNum;

    cout<< "How many catagories will "+ setName + " have?: "<<endl;
    cin >> setNum;
    //for loop based on number prompts user to name each one at a time, first will be child of root, subsequent will be siblings
    for(int cntr=1; cntr <= setNum; cntr++){
        string catName;

        if(cntr <= 1){
            cout<< "Please enter the name of the first catagory: " << endl;
            cin >> catName;

            mainSet.createChild(catName, setName);
        }
        else{
            cout<< "Please enter the name of the next catagory: "<< endl;
            cin >> catName;

            mainSet.createSibling(catName, setName);
        }

    }
    //congratulate on first list
    cout<< "Congratulations you've created your first list! Select one of the options below to continue." << endl;

    int option;
    //display options from here
    cout<< "1- Add items to current list" <<endl;
    cout<< "2- Search for item"<<endl;
    cout<< "3- View items from specific parent"<<endl;
    cout<< "4- Display entire list"<<endl;
    cout<< "5- Enter list purpose" <<  endl;
    cout<< "6- Export List to txt file"<<endl;

    cin >> option;

        if(option = 1){
            //call method adds items
            string newItem;

            cout << "Please enter the name of the new item: "<< endl;
            cin >> newItem;
            addItem(mainSet, newItem);
        }
    else if(option =2){
            //call method that searches for item based on name of item
            string itemToFind;
            cout<< "Please enter the name of the item you are looking for: " << endl;
            cin >> itemToFind;

            libMemb holderMemb = mainSet.searchTitl(itemToFind);

            cout << "Name: " + holderMemb.getTitle() << endl;
            cout << "Parent: " + holderMemb.getParent() << end;
            cout << "# of Children: " + holderMemb.getKid() << endl;


    }
    else if(option = 3){
            //call method that will prompt parent name to view its members
            string parNt;
            cout << "Enter the name of parent: "<< endl;
            cin >> parNt;

            mainSet.membersOfParent(mainSet, parNt);

    }
    else if(option = 4){
            //call method that prints whole list
    }
    else if(option = 5){
            string thePoint;
            cout << "What is the purpose or description of this list? " << endl;
            cin >> thePoint;

            mainSet.setPurpose(thePoint);
            cout << "Purpose set!";
        }
    else if(option = 6){
            //call method that prints list to file
    }
    else{
        cout<< "Invalid entry, please try again.";
        //set to start again
    }

    return 0;
}