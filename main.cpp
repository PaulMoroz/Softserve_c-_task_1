#include <iostream>
#include <stdlib.h>
#include "list.h"
using namespace std;
typedef char* String;


int main() {
    int command;
    int n;
    String t;
    String oldStr;
    String newStr;
    char** list = nullptr;
    StringListInit(&list);
    do{
        cout<<"Enter 1 to add string\n";
        cout<<"Enter 2 to remove string\n";
        cout<<"Enter 3 to get number of items in the list\n";
        cout<<"Enter 4 to get the index position of the first exact match of specified string\n";
        cout<<"Enter 5 to print list\n";
        cout<<"Enter 6 to replace string in list\n";
        cout<<"Enter 7 to sort list\n";
        cout<<"Enter 8 to remove duplicates from list\n";
        cout<<"Enter 0 to exit\n";
        cin>>command;
        switch (command) {
            case 1:
                cout<<"Enter length of string to add\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string: ";
                cin>>t;
                StringListAdd(list,t);
                break;
            case 2:
                cout<<"Enter length of string to delete\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string: ";
                cin>>t;
                StringListRemove(list,t);
                break;
            case 3:
                cout<<"Size of list: "<<getListSize(list)<<endl;
                break;
            case 4:
                cout<<"Enter size of string\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string\n";
                cin>>t;
                cout<<StringListIndexOf(list,t)<<endl;
                break;
            case 5:
                printList(list);
                break;
            case 6:
                cout<<"Enter length of old string\n";
                cin>>n;
                oldStr = (String) malloc(n + 1);
                cout<<"Enter string: ";
                cin>>oldStr;
                cout<<"Enter length of new string\n";
                cin>>n;
                newStr = (String) malloc(n + 1);
                cout<<"Enter string: ";
                cin>>newStr;
                StringListReplaceInStrings(list,oldStr,newStr);
                break;
            case 7:
                StringListSort(list);
                break;
            case 8:
                StringListRemoveDuplicates(list);
                break;
            case 0:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Command not recognized\n";
                break;
        }
    }while(command!=0);
    StringListDestroy(&list);
}
