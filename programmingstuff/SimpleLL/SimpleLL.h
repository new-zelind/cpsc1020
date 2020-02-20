#ifndef SIMPLELL_H
#define SIMPLELL_H

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
  int data;
  struct Node *next;
}node_t;

node_t* head;

void printList();
void append(int num);
void addFront(int num);
void deleteList();
void removeNode(int num);
void removeAllOcc(int num);


#endif
