#include"dstack1.c"
void main()
{
 stack stk;
 int choice,x;
 item_type item;
 init(&stk);
 while(1)
 {
  clrscr();
  puts(">>>>> MENU <<<<<");
  puts("1. PUSH");
  puts("2. POP");
  puts("3. PEEK");
  puts("4. SIZE");
  puts("5. DISPLAY");
  puts("6. EXIT");
  puts("ENTER YOUR CHOICE : ");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:
    puts("Enter item :");
    scanf("%d",&item);
    push(&stk,item);
    break;
   case 2:
    printf("%d is deleted",pop(&stk));
    break;
   case 3:
    printf("%d is top item",peek(&stk));
    break;
   case 4:
    printf("%d item present",size(&stk));
    break;
   case 5:
    display(&stk);
    break;
   case 6:
    exit(1);
   default:
    puts("Invalid Choice !!");
    break;
  }
  getch();
 }

}