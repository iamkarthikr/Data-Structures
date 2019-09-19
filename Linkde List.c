#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
  char name[29];
  int numpl;
  int id;
  struct node *next;
}*h,*t,*t1,*w,*q;
int i,n,ch,ps,x,k;
k=0;

int main()
{
  //struct node *h,*t,*t1,*w,*q;
	h=NULL;  
  printf("/*CAR DATA USING LINKED LIST */ ");
  while(1)
 { 
    printf("\n1)View Details of all cars \n");
    printf("2)Enter a new car detail\n");
    printf("3)Delete the details of a car\n");
    printf("4)Edit the details of a car\n");
    printf("5)Exit\n");
    printf("ENTER YOUR CHOICE ");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:    
        view();
        break;
      case 2:
        insert();
        break;
      case 3:
        delete();
        break;
      case 4:
        modify();
        break;
      case 5:
        exit(0);
        break;     
    }  
  }  
}
void view()
{
  if(h==NULL)
  {
    printf("NO RECORDS ARE AVAILABLE \n");
  }
  w=h;
  while(w!=NULL)
  {
    printf("\nCar ID is             :");
    printf("%d",w->id);
    printf("\nCar name is           :");
    printf("%s",w->name);
    printf("\nCar number-plate is   :");
    printf("%d",w->numpl);
    w=w->next;
  }        
}
void insert()
{
  printf("ENTER THE NEW RECORD\n");
  if(h==NULL)
  {
    h=t=(struct node *)malloc(sizeof(struct node));
    printf("Enter the ID of the Car            :");
    scanf("%d",&t->id);
    printf("Enter the name of the car          :");
    scanf("%s",&t->name);
    printf("Enter the number-plate of the car  :");
    scanf("%d",&t->numpl);
    t->next=NULL;     
  }
  else
  {
    t1=(struct node *)malloc(sizeof(struct node));
    printf("Enter the ID of the Car              :");
    scanf("%d",&t1->id);
    printf("Enter the name of the car            :");
    scanf("%s",&t1->name); 
    printf("Enter the number-plate of the car    :");
    scanf("%d",&t1->numpl);
    t1->next=t->next;
    t->next=t1;
    t=t1;
  }
}
void delete()
{
  printf("ENTER THE ID OF THE CAR WHOS DETAIL IS TO BE DELTED  :");
  scanf("%d",&ps);
  t=h;
  while(t->id!=ps-1)
  {
    t=t->next;
  }
  t1=t->next;
  t->next=t1->next;
  free(t1);
}
void modify()
{
  printf("ENTER THE ID WHOSE DATA YOU WANT TO MODIFIY :");
  scanf("%d",&ps);
  t=h;
  while(t->id!=ps)
  {
    t=t->next;
  }
  printf("Enter the new car id                    :");
  scanf("%d",&t->id); 
  printf("Enter the new name of the car           :");
  scanf("%s",&t->name);
  printf("Enter the new plate_number of the car   :");
  scanf("%d",&t->numpl);
}
