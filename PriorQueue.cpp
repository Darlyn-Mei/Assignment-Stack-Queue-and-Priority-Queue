#include <stdio.h>
#include <string.h>
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

void pushRear(int value)
{
    Node *newNode = createNode(value); // create the new node
    if (!front)                      // if there's no front a.k.a. we have an empty LL
    {
        front = rear = newNode; // rear will be the new front and the new rear
    }
    else
    {
        rear->prev = newNode; // current rear will point to the newly created node
        newNode->next = rear; // the new node will point to the current rear
        rear = newNode;       // the new node will be the last node in the LL (new rear)
    }
}

void pushQueue(int value1){
    Node *temp = createNode(value1); // create the new node
    if (!front || rear->value < value1)                      // if there's no front a.k.a. we have an empty LL
    {
        pushRear(value1);
    }
    else if (front->value > value1)
    {
        front->next = temp;
        temp->prev = front;
        front = temp;
    }
    else
    {
        Node *currentNode = rear->next;
        while (currentNode->value > value1)
        {
            currentNode = currentNode->next;
        }
        temp->next = currentNode;
        currentNode->prev->next = temp;
        temp->prev = currentNode->prev;
        currentNode->prev = temp;
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
    front = NULL; // set the value1 to NULL
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
  printf("Alamat node setelahnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

void printQueue()
{
  for (Node *temp1 = rear; temp1 != NULL; temp1 = temp1->next)
  {
    readQueue(temp1);
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