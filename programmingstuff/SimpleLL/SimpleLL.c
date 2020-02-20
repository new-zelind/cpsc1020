// A simple C program to introduce
// a linked list
#include "SimpleLL.h"
#include <stdlib.h>

/*This function is used to print the value of the data for each node in a linked
 *list. Using a while loop the code will traverse through the list printing each
 *nodes data value as it goes through each node in the list.
 *Parameters: none
 *Return:  void*/
void printList()
{
  node_t* temp = head;
  if(head == NULL)
  {
    printf("List is empty!\n");
  }
  else
  {
    while (temp != NULL)
    {
      printf(" %d ", temp->data);
      temp = temp->next;
    }
  }
  printf("\n");
}
/******************************************************************************/

/*This functions adds a node to the end of the linked lists.  If the head is
 *NULL then this means the list is empty. If it is it points the head to the
 *newly created node.
 *It first will dynamically allocate the memory and initialize the data
 *for the new node. Create a temporary node and set it equal to where head is
 *pointing.
 *Parameters: int num - after the new node is created we need to give the data
 *portion of the node a value.  Num is that value.
 *return:  there is not return value */
void append(int num)
{

  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  newNode->data = num;
  newNode->next = NULL;
  node_t* temp = head;
  //the list is empty
  if(head == NULL)
  {
    head = newNode;
  }
  else
  {

    //while I am not at the end of the list
    while(temp->next != NULL)
    {
      temp = temp->next;
    }

    temp->next = newNode;
  }
}
/******************************************************************************/

/*This function will add a node to the front of the list. First it will allocate
 *memory for the new node, returning the address of the allocated memory to a
 *local variable. Next it will set the values of the data and next pointer for
 *the new node.
 *Parameters: int num - this represents the value of the data portion of the
 *struct.
 *Return:  There is no returtn value. */
void addFront(int num)
{
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  newNode->data = num;
  newNode->next = head;
  head = newNode;
}
/******************************************************************************/

/* Function to delete the entire linked list It first creates two local variables
 * current that will point to the same node as head.
 * Parameters: none
 * Return: There is no return value*/
void deleteList()
{
   node_t* current = head;
   node_t* next = NULL;
   if(head==NULL)
   {
     printf("List is already empty\n");
     //exit(0);
   }
   while (current != NULL)
   {
       next = current->next;
       free(current);
       current = next;
   }

   /* deref h to affect the real head back
      in the caller. */
   head = NULL;
}

/******************************************************************************/
/*Function removes an element with a specific value from the lists
 *Parameter: int num represents the value of the nodes data that will be removed
 *return: void
 */

 void removeNode(int num)
 {
   int found=0;
   node_t* current = head;
   node_t* nextNode = NULL;
   if(head==NULL){
       printf("List is empty!\n");
       return;
   }
   if(current->data == num){
       head = current->next;
       free(current);
       return;
   }
   current = current -> next;
   nextNode = current -> next;
   while(nextNode->next!=NULL){
       nextNode=current->next;
       if(nextNode->data==num){
           current->next=nextNode->next;
           free(nextNode);
           nextNode = current->next;
           found = 1;
       }
       current=nextNode;
   }
   if(found==0){
       printf("%i was not found in the list.\n", num);
   }
 }

/******************************************************************************/
/*Function removes all occurances of an node with a specific value
 *Parameter: int num represents the value of the nodes data that will be removed
 *return: void
 */
 void removeAllOcc(int num)
 {
   node_t *current = head;
   node_t *nextNode = NULL;
   node_t *duplicate;

   //Check to see if either the current node or next node point to null.
   while((current != NULL)&&(current->next!=NULL)){
       nextNode=current;
       while(nextNode->next!=NULL){
           if(current->data == nextNode->data){
               //If the data in the head of the current node equals that of the next node,
               //The duplicate number equals the data contained in the head of the next member
               //of the linked list. Then, free the old duplicate data. Move one node along the
               //linked list.
               duplicate=nextNode->next;
               free(duplicate);
               nextNode->next=nextNode->next->next;
           }
           else{
               //Otherwise, move to the next node in the list.
               nextNode=nextNode->next;
           }
       }
       current=current->next;
   }
 }
