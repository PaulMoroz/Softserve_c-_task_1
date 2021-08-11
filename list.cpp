//
// Created by нободи on 04.08.2021.
//

#include "list.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
void StringListInit(char*** list){
    char* default_val = "123";
    (*list) = (char** ) malloc(2);
    (*list)[0] = default_val;
    (*list)[1] = nullptr;
}

void StringListDestroy(char*** list){
    if(list==nullptr) {
        //cout<<"List is null\n";
        return;
    }
    char** curr = (*list);
    while (curr!= nullptr){
        char** temp = curr;
        curr = reinterpret_cast<char **>(curr[1]);
        free(temp);
    }
}


int getListSize(char** list){
    if(list==nullptr) {
        //cout<<"List is null\n";
        return -1;
    }
    char** current = reinterpret_cast<char **>(list[1]);
    int size = 0;
    while (current!= nullptr){
        size++;
        current = reinterpret_cast<char **>(current[1]);
    }
    return size;
}

void printList(char** list){
    if(list==nullptr) {
        //cout<<"List is null\n";
        return;
    }
    char** current = reinterpret_cast<char **>(list[1]);
    while (current!= nullptr){
        cout<<current[0]<<endl;
        current = reinterpret_cast<char **>(current[1]);
    }
}

void StringListAdd(char** list,String str){
    if(list==nullptr) {
        //cout<<"List is null\n";
        return;
    }
    char** new_node = (String*) malloc(2);
    new_node[0] = str;
    new_node[1] = nullptr;
    char** current = list;
    while (current[1]!= nullptr){
        current = reinterpret_cast<char **>(current[1]);
    }
    current[1] = reinterpret_cast<char *>(new_node);
}

int StringListIndexOf(char** list,const String str){
    if(list==nullptr) {
        //cout<<"List is null\n";
        return -1;
    }
    char** current = reinterpret_cast<char **>(list[1]);
    int current_position = 0;
    bool found = false;
    while (current!= nullptr){
        if(*current[0]==*str) {
            found=true;
            break;
        }
        current = reinterpret_cast<char **>(current[1]);
        current_position++;
    }
    if(found) {
        return current_position;
    }
    return -1;
}

void StringListRemove(char** list, String str){
    char** current = list;
    if(list==nullptr) {

        //cout<<"List is null\n";
        return;
    }
    while (current[1]!= nullptr){
        char** temp = reinterpret_cast<char **>(current[1]);
        if(temp!=nullptr  && *(temp)[0]==*str){
            current[1] = temp[1];
            free(temp);
        }else{
            current = reinterpret_cast<char **>(current[1]);
        }
    }
}

void StringListReplaceInStrings(char** list, char* before, char* after){
    if(list==nullptr) {

        //cout<<"List is null\n";
        return;
    }
    char** current = reinterpret_cast<char **>(list[1]);
    while (current!= nullptr){
        if(*current[0]==*before){
            char* t = current[0];
            current[0] = after;
            free(t);
        }
        current = reinterpret_cast<char **>(current[1]);
    }
}

void StringListSort(char** list){
    if(list==nullptr) {

        //cout<<"List is null\n";
        return;
    }
    int n = getListSize(list);
    char**  left = reinterpret_cast<char **>(list[1]);
    char** right;
    for(int i=0;i<n;i++){
        right = reinterpret_cast<char **>(left[1]);
        for(int j=i + 1;j<n;j++){
            if(*left[0] > *right[0]) {
                char* t = left[0];
                left[0] = right[0];
                right[0] = t;
            }
            right = reinterpret_cast<char **>(right[1]);
        }
        left = reinterpret_cast<char **>(left[1]);
    }
}

void StringListRemoveDuplicates(char** list){

    char** left = reinterpret_cast<char **>(list[1]);
    char** right;
    while (left[1]!= nullptr){
        right = left;
        while (right!= nullptr){
            char** temp = reinterpret_cast<char **>(right[1]);
            if(temp!= nullptr && *temp[0] == *left[0]){
                right[1] = temp[1];
                free(temp);
            }else {
                right = reinterpret_cast<char **>(right[1]);
            }
        }
        if(left[1]!= nullptr)left = reinterpret_cast<char **>(left[1]);
    }
}
