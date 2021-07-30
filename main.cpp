#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef char* String;

void initialiseList(){

}

int getListSize(){

}

void addString(String t){

}

void deleteString(String t){

}

int indexOfExactMatch(String t){

}

int main() {
    int command;
    int n;
    String t;
    do{
        cout<<"Enter 1 to add string\n";
        cout<<"Enter 2 to remove string\n";
        cout<<"Enter 3 to get number of items in the list\n";
        cout<<"Enter 4 to get the index position of the first exact match of specified string\n";
        cout<<"Enter 0 to exit\n";
        cin>>command;
        switch (command) {
            case 1:
                cout<<"Enter lenght of string to add\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string\n";
                gets(t);
                addString(t);
                break;
            case 2:
                cout<<"Enter string to remove\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string\n";
                gets(t);
                deleteString(t);
                break;
            case 3:
                cout<<"Size of list: "<<getListSize()<<endl;
                break;
            case 4:
                cout<<"Enter string to find first exact match\n";
                cout<<"Enter string to remove\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string\n";
                gets(t);
                indexOfExactMatch(t);
                break;
            default:
                cout<<"Command not recognized\n";
                break;
        }
    }while(command!=0);
}
