#include<stdio.h>
#include<conio.h>
typedef int item_type;
typedef struct node
 {
   struct node * pre;
   item_type info;
 } node;
typedef struct
 {
  node * top;
 } stack;
void init(stack * sp)
{
   sp->top = NULL;
}
node * create(item_type item)
{
  node * ptr = (node *)malloc(sizeof(node));
  if(ptr==NULL)
  {
   puts("Memory is full !");
   return NULL;
  }

  ptr->pre=NULL;
  ptr->info=item;

  return ptr;
}
void push(stack * sp,item_type item)
{
  node * ptr;
  ptr=create(item);
  if(ptr==NULL) return;

  if(sp->top==NULL)
  {
    sp->top=ptr;
  }
  else
  {
   ptr->pre=sp->top;
   sp->top=ptr;
  }
}
item_type pop(stack * sp)
{
  node * ptr;
  item_type item;

  ptr=sp->top;
  item=ptr->info;

  sp->top = sp->top->pre;
  free(ptr);
  return item;
}
item_type peek(stack * sp)
{
 return sp->top->info;
}
int size(stack * sp)
{
 node * ptr;
 int count=0;
 for(ptr=sp->top;ptr;ptr=ptr->pre)
 {
  count++;
 }
 return count;
}
void display(stack * sp)
{
 node * ptr;
 for(ptr=sp->top;ptr;ptr=ptr->pre)
 {
  printf("%d ",ptr->info);
 }
}