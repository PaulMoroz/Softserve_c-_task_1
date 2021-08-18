
#ifndef SOFTSERFE_COURSE_TASK_1_LIST_H
#define SOFTSERFE_COURSE_TASK_1_LIST_H
typedef char* String;
void StringListRemoveDuplicates(char** list);
void StringListSort(char** list);
void StringListReplaceInStrings(char** list, char* before, char* after);
void StringListRemove(char** list, String str);
int StringListIndexOf(char** list, String str);
void StringListAdd(char** list, String str);
void printList(char** list);
int getListSize(char** list);
void StringListInit(char*** list);
void StringListDestroy(char*** list);
#endif //SOFTSERFE_COURSE_TASK_1_LIST_H
