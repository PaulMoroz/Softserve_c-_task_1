#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef char* String;

int getListSize(char** list){
    char** current = list;
    int size = 0;
    while (current!= nullptr){
        size++;
        current = &current[1];
    }
    return size;
}

void addString(char**& list,String t){
    char** new_node = (String*) malloc(2);
    new_node[0] = t;
    new_node[1] = nullptr;
    if(list== nullptr){
        list = new_node;
        return;
    }
    char** current = list;
    while (current[1]!= nullptr){
        current = reinterpret_cast<char **>(current[1]);
    }
    current[1] = reinterpret_cast<char *>(new_node);
}

void printList(char** list){
    char** current = list;
    while (current!= nullptr){
        cout<<current[0]<<endl;
        current = reinterpret_cast<char **>(current[1]);
    }
}

int indexOfExactMatch(char** list,String t){
    char** current = list;
    int current_position = 0;
    bool found = false;
    while (current!= nullptr){
        if(*current[0]==*t) { found=true;break; }
        current = reinterpret_cast<char **>(current[1]);
        current_position++;
    }
    if(found)return current_position;
    return -1;
}

void deleteString(char**& list, int pos){
    if(pos >= getListSize(list))return;
    if(pos == 0){
        char** temp = list;
        list = reinterpret_cast<char **>(list[1]);
        free(temp);
        return;
    }
    int curr_pos = 0;
    char** current = list;
    while (curr_pos+1!=pos){
        current = reinterpret_cast<char **>(current[1]);
        curr_pos++;
    }
    char** temp = reinterpret_cast<char **>(current[1]);
    current[1] = temp[1];
    free(temp);
}



int main() {
    int command;
    int n;
    String t;
    char** list = nullptr;
    int pos;
    do{
        cout<<"Enter 1 to add string\n";
        cout<<"Enter 2 to remove string\n";
        cout<<"Enter 3 to get number of items in the list\n";
        cout<<"Enter 4 to get the index position of the first exact match of specified string\n";
        cout<<"Enter 5 to print list\n";
        cout<<"Enter 0 to exit\n";
        cin>>command;
        switch (command) {
            case 1:
                cout<<"Enter length of string to add\n";
                cin>>n;
                t = (String) malloc(n + 1);
                cout<<"Enter string: ";
                cin>>t;
                addString(list,t);
                break;
            case 2:
                cout<<"Enter index of string to remove(numbers from 0)\n";
                cin>>pos;
                deleteString(list,pos);
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
                cout<<indexOfExactMatch(list,t)<<endl;
                break;
            case 5:
                printList(list);
                break;
            default:
                cout<<"Command not recognized\n";
                break;
        }
    }while(command!=0);
}
