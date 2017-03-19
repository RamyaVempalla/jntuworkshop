#include<stdio.h>
#include<conio.h>
#include<alloc.h>
int l=0;
void create();
void insert();
void deletion();
void display();
struct node
{
int data;
struct node*flink;
struct node*blink;
}*start=NULL,*ptr;
void main()
{
int ch;
clrscr();
do
  {
  printf("\n1 create\n2 insert\n3 delete\n4 display\n5 exit\n");
  scanf("%i",&ch);
  switch(ch)
  {
  case 1: create();
	  break;
  case 2: insert();
	  break;
  case 3: deletion();
	  break;
  case 4: display();
	  break;
  case 5: exit(0);
	  break;
  }
  }while(1);
}
void create()
{
struct node *newnode,*ptr;
char ch;
do
  {
  newnode=(struct node*)malloc(sizeof(struct node));
  l++;
  printf("\nenter data");
  scanf("%i",&newnode->data);
  newnode->flink=NULL;
  newnode->blink=NULL;
  if(start==NULL)
  {
    start=newnode;
    ptr=newnode;
  }
  else
  {
    ptr->flink=newnode;
    newnode->blink=ptr;
    newnode->flink=start;
    ptr=newnode;
  }
  printf("press y to continue");
  ch=getch();
  }while(ch=='y');

}
void insert()
{
struct node*newnode,*ptr,*ptr1;
int i=1,pos;
if(l<=0)
 {
 printf("no list is created");
 }
else
{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter data");
   scanf("%i",&newnode->data);
   newnode->flink=NULL;
   newnode->blink=NULL;
   printf("entr pos");
   scanf("%i",&pos);
   if(pos>0&&pos<=l+1)
   {
     if(pos==1)
     {
     ptr=start;
     ptr1=start;
     ptr1=ptr1->flink;
     do
     {
     ptr=ptr->flink;
     }while(ptr->flink!=start);
     newnode->flink=start;
     start=newnode;
     ptr1->blink=newnode;
     ptr->flink=start;
     l++;
     }
     else if (pos==l+1)
     {
      ptr=start;
     do
     {
     ptr=ptr->flink;
     }while(ptr->flink!=start);

     ptr->flink=newnode;
     newnode->blink=ptr;
     newnode->flink=start;
     l++;

     }
     else
     {
       ptr1=start;
       while(i!=pos)
       {
	  ptr=ptr1;
	  ptr1=ptr->flink;
	  i++;
       }
       newnode->flink=ptr1;
       newnode->blink=ptr;
       ptr1->blink=newnode;
       ptr->flink=newnode;
       l++;
     }
   }
}
}
void deletion()
{
struct node *ptr, *ptr1;
int i=1,pos;
if(l<=0)
{
printf("no list is created");
}
else
 {
 printf("enter pos");
 scanf("%i",&pos);
 if(pos>0&&pos<=l+1)
  {
  if(pos==1)
   {
    ptr=start;
   do
   {
   ptr=ptr->flink;
   }while(ptr->flink!=start);

   ptr1=start;
   start=ptr1->flink;
   free(ptr1);
    ptr->flink=start;
   l--;

   }
  else if(pos==l)
   {
   ptr1=start;
   while(ptr1->flink!=start)
   {
    ptr=ptr1;
    ptr1=ptr->flink;
   }
   ptr->flink=start;
   free(ptr1);
   l--;
   }
   else
   {
     ptr1=start;
     while(i!=pos)
     {
      ptr=ptr1;
      ptr1=ptr->flink;
      i++;
     }
     ptr->flink=ptr1->flink;
     free(ptr1);
     l--;
   }
  }
 }
}

void display()
{
struct node*ptr,*temp;
int i=1,pos;
printf("enter pos from where to start");
scanf("%i",&pos);
ptr=start;
while(i!=pos)
{
ptr=ptr->flink;
i++;
}

temp=ptr;
do
{
printf("%4i",ptr->data);
ptr=ptr->flink;
}while(ptr!=temp);
}






