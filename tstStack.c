#include <stdio.h>
#include <stdlib.h>

typedef struct MinStack{
    struct MinStack * nextNode;
    int value;    
} MinStack;


MinStack* minStackCreate() {
    MinStack * top = (MinStack *) malloc(sizeof(MinStack*));
    top = NULL;
    return top;
    
}

void minStackPush(MinStack* obj, int val) {
    MinStack * newTop = (MinStack *) malloc(sizeof(MinStack));
    newTop->nextNode = obj;
    newTop->value = val;
    obj = newTop;
  
}

void minStackPop(MinStack* obj) {
    if(obj!=NULL){
        obj = obj->nextNode;
    }
}

int minStackTop(MinStack* obj) {
    if(obj!=NULL){
        return obj->value;
    }
}

int minStackGetMin(MinStack* obj) {
    if(obj == NULL) return -1;
    MinStack* pNode=obj;
    int currVal= pNode->value ;
    while(pNode !=NULL){
        if(currVal > pNode->value){
            currVal = pNode->value;
        }
        pNode = pNode->nextNode;
    }
    return currVal;
}

void minStackFree(MinStack* obj) {
    MinStack* currNode;
    while(obj!=NULL){
        currNode = obj;
        obj= obj->nextNode;
        free(currNode);
    }

}


void main()
{

  MinStack* obj = minStackCreate();
  int val = 10;
  minStackPush(obj, val);

 int param_3 = minStackTop(obj);
  printf("param_3 = %d",param_3);
 
  int param_4 = minStackGetMin(obj);
  printf("param_4 = %d",param_4);
  
  minStackPop(obj);
 
  
 
  minStackFree(obj);   
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/