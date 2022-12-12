#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  Node *next, *prev;
} *top;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value; 
  newNode->next = newNode->prev = NULL;   
  return newNode;       
}

void pushStack(int value)
{
  Node *newNode = createNode(value); 
  if (!top)                      
  {
    top = newNode;
  }
  else
  {                      
    top->next = newNode; 
    newNode->prev = top; 
    top = newNode;       
  }
}

void removeStack()
{
  if (!top)
  { // if linked is empty
    return;
  }
  else if (!top->prev) // if only 1 node, top has no node below it
  {
    free(top);  // free allocated memory
    top = NULL; // set the value to NULL
  }
  else // if there are more than 1 node,
  {
    Node *newTop = top->prev;        // the new top candidate will be below the current top
    top->prev = newTop->next = NULL; // isolate the current top
    free(top);                       // free the allocated memory
    top = newTop;                    // the new top will replace the deleted top
  }
}

void readStack(){
  Node *currentNode = top;
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sekarang: %p\n", currentNode);
}

int main(){
    pushStack(10);
    pushStack(30);
    pushStack(20);
    readStack();

    removeStack();

    readStack();

  return 0;
}