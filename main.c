#include <stdio.h>

#define CAPACITY 3
#include<stdlib.h>
void insert(int element);
void delete();
void display();

int queue[CAPACITY];
int front = 0;
int rear = 0;


int main()
{
 int ch, ele;
  while(1)
  {

   printf("press 1 for insert operation\n");
   printf("press 2 for delete operation\n");
   printf("press 3 for traverse or display the stack\n");
   printf("press 4 for quit\n");



 printf("enter the choice to perform operation\n");
 scanf("%d", &ch);

  switch(ch)
  {
   case 1: printf("enter the element to insert inside the queue\n");
     scanf("%d", &ele);

     insert(ele);
     break;

   case 2: delete();
     break;


   case 3: display();
     break;

   case 4: exit(0);

   default: printf("you entered wrong choice\n");

  }

  }
 return 0;
}




void insert(int element)
{
 if(rear == CAPACITY)
 {
  printf("QUEUE IS FULL\n");
 }
 else
 {
  queue[rear] = element;
  rear++;

  printf(" %d  is inserted in the queue\n", element);
 }
}


void delete()
{
 int i, ele;

 if(front == rear)
 {
  printf("QUEUE IS EMPTY\n");
 }
 else
 {
  ele = queue[front];

  printf("%d   is deleted\n", ele);

  for(i = 0; i < rear-1; i++)
   queue[i] = queue[i+1];
   rear -- ;
 }
}


void display()
{
 int i;

 if(front == rear)
 {
  printf("QUEUE IS EMPTY\n");
 }
 else
 {
  printf("items are in the queue\n");
  for(i =front; i < rear; i++)
  {
   printf("%d   ", queue[i]);
  }
  printf("\n");
 }
}
