#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef char* String;

void StringListInit(char*** list){
    (*list) = (char** ) malloc(2);
    (*list)[0] = "123";
    (*list)[1] = nullptr;
}

int getListSize(char** list){
    char** current = reinterpret_cast<char **>(list[1]);
    int size = 0;
    while (current!= nullptr){
        size++;
        current = reinterpret_cast<char **>(current[1]);
    }
    return size;
}

void StringListRemoveDuplicates(char** list,String t){
    /*char** new_node = (String*) malloc(2);
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
    current[1] = reinterpret_cast<char *>(new_node);*/
}

void printList(char** list){
    char** current = reinterpret_cast<char **>(list[1]);
    while (current!= nullptr){
        cout<<current[0]<<endl;
        current = reinterpret_cast<char **>(current[1]);
    }
}

void StringListAdd(char** list,String str){
    char** new_node = (String*) malloc(2);
    new_node[0] = str;
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

int StringListIndexOf(char** list,const String str){
    char** current = reinterpret_cast<char **>(list[1]);
    int current_position = 0;
    bool found = false;
    while (current!= nullptr){
        if(*current[0]==*str) { found=true;break; }
        current = reinterpret_cast<char **>(current[1]);
        current_position++;
    }
    if(found)return current_position;
    return -1;
}

//!FIX free error
void StringListRemove(char** list, String str){
    char** current = list;
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
    /*
    char** left = list;
    char** right = list;
    while (left[1]!= nullptr){
        if(right!=nullptr){
            return; = reinterpret_cast<char **>(left[1]);
            if(reinterpret_cast<char *>(right[1][0]) == left[0]){
                char** temp = reinterpret_cast<char **>(right[1]);
                right[1] = temp[1];
                free(temp);
            }
            if(left[1]!= nullptr)right = reinterpret_cast<char **>(left[1]);
        }
    }*/
}

int main() {
    int command;
    int n;
    String t;
    String oldStr;
    String newStr;
    char** list = nullptr;
    int pos;
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
            default:
                cout<<"Command not recognized\n";
                break;
        }
    }while(command!=0);
}
