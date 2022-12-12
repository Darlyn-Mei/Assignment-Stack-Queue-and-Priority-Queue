#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  Node *next, *prev;
} *front, *rear;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value; 
  newNode->next = newNode->prev = NULL;   
  return newNode;       
}

void pushQueue(int value){
    Node *temp = createNode(value); // create the new node
    if (!front)                      // if there's no front a.k.a. we have an empty LL
    {
        front = rear = temp; // rear will be the new front and the new rear
    }
    else
    {
        rear->next = temp; // current rear will point to the newly created node
        temp->prev = rear; // the new node will point to the current rear
        rear = temp;       // the new node will be the last node in the LL (new rear)
    }
}

void removeFront()
{
  if (!front)
  { // if linked is empty
    return;
  }
  else if (!front->prev) // if only 1 node, front has no node below it
  {
    free(front);  // free allocated memory
    front = NULL; // set the value to NULL
  }
  else // if there are more than 1 node,
  {
    Node *newFront = front->prev;        // the new front candidate will be below the current front
    front->prev = newFront->next = NULL; // isolate the current front
    free(front);                       // free the allocated memory
    front = newFront;                    // the new front will replace the deleted front
  }
}

void readQueue(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printQueue()
{
  for (Node *temp = rear; temp != NULL; temp = temp->next)
  {
    readQueue(temp);
    puts("|");
    puts("|");
    puts("v");
  }
  puts("NULL");
}

int main(){
    pushQueue(5);
    pushQueue(10);
    pushQueue(20);
    pushQueue(9);

    printQueue();

    removeFront();

    printQueue();

    return 0;
}