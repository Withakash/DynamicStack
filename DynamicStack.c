#include<stdio.h>
#include<conio.h>
typedef int item_type;

                             //Structure Declaration ......
                 //Node Struct
typedef struct node
 {
   struct node * pre;
   item_type info;
 } node;
                //Stack Struct
typedef struct
 {
  node * top;
 } stack;

void init(stack * sp);
void push(stack * sp,item_type item);
item_type pop(stack * sp);
item_type peek(stack * sp);
int size(int top);
 
               //init function
void init(stack * sp)
{
   sp->top = NULL;
}
              
                //create function for PUSH operation 
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

               //PUSH function ...
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

               //POP funtion ....
item_type pop(stack * sp)
{
  node * ptr;
  item_type item;
 
  if(sp->top==NULL)
  {
    puts("ERROR ! Stack is Underflow ");
    return 0;
  }

  ptr=sp->top;
  item=ptr->info;

  sp->top = sp->top->pre;
  free(ptr);
  return item;
}

              //PEEK function ...
item_type peek(stack * sp)
{
 if(sp->top==NULL)
 {
    puts("ERROR ! Stack is Underflow ");
    return 0;
 }
 return sp->top->info;
}

               //SIZE function
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
