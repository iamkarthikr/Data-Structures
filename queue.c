#include <stdio.h>
#include <stdlib.h>
struct node
{
    int id;
    char name[40];
    char problem[20];
    struct node *next;
}*front,*rear,*temp,*front1;
int frontelement();
void enq();
void deq();
void empty();
void display();
void create();
void queuesize();
int count = 0;
int no, ch, e,id;
char name[40],problem[20];
void main()
{
    printf("/*HOSPITAL QUEUE */");
    create();
    while (1)
    {
        printf("\n1)Add patient");
        printf("\n2)Remove patient");
        printf("\n3)Patient in the front");
        printf("\n4)Check if Queue is Empty?");
        printf("\n5)Exit");
        printf("\n6)Display all patient in Queue");
        printf("\n7)Queue size");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            enq();
            break;
        case 2:
            deq();
            break;
        case 3:
            e=frontelement();
            if (e != 0)
                printf("Front element : %d", e);
            else
                printf("\n No front element in Queue as queue is empty");
            break;
        case 4:
            empty();
            break;
        case 5:
            exit(0);
        case 6:
            display();
            break;
        case 7:
            queuesize();
            break;
        default:
            printf("Wrong choice, Please enter correct choice  ");
            break;
        }
    }
}
void create()
{
    front=rear=NULL;
}
void queuesize()
{
    printf("\nQueue size : %d", count);
}
void enq()
{

    if (rear==NULL)
    {
        rear=(struct node *)malloc(1*sizeof(struct node));
        rear->next=NULL;
        printf("Enter Patient id : ");
    	scanf("%d",&rear->id); 
   		printf("Enter Patient name :");
    	scanf("%s",&rear->name);
    	printf("Enter Patient problem :");
    	scanf("%s",&rear->problem);
        front=rear;
    }
    else
    {
        temp=(struct node *)malloc(1*sizeof(struct node));
    	printf("Enter Patient id : ");
    	scanf("%d",&temp->id); 
    	printf("Enter Patient name :");
    	scanf("%s",&temp->name);
    	printf("Enter Patient problem :");
    	scanf("%s",&temp->problem);
        rear->next=temp;
    	temp->next=NULL;
        rear=temp;
    }
    count++;
}
void display()
{
    front1=front;
    if ((front1==NULL)&&(rear==NULL))
    {
        printf("QUEUE IS EMPTY");
        return;
    }
    else
    {
        printf("display all Patients\n");
        while(front1!=NULL)
        {
            printf("%d\n",front1->id);
            printf("%s\n",front1->name);
            printf("%s\n",front1->problem);
            front1=front1->next;
        }
    }      
}
void deq()
{
    front1=front;
    if (front1==NULL)
    {
        printf("\n ERROR: Trying to display elements from empty queue");
        return;
    }
    else
        if (front1->next!=NULL)
        {
            front1=front1->next;
            printf("\n Dequed ID : %d",front->id);
            free(front);
            front=front1;
        }
        else
        {
            printf("\n Dequed ID : %d",front->id);
            free(front);
            front=NULL;
            rear=NULL;
        }
        count--;
}
int frontelement()
{
    if ((front != NULL) && (rear != NULL))
    {
        return(front->id);
    }   
    else
    {
        return 0;
    }       
}
void empty()
{
     if ((front == NULL) && (rear == NULL))
     {
        printf("\nQUEUE IS EMPTY");
     }      
    else
    {
       printf("QUEUE IS NOT EMPTY");
    }
}
