#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define rest 0
#define cafe 1
#define pub 2
#define asgard 0
#define narnia 1
#define wallstreet 2
#define diagonalley 3
#define pinkcity 4

#define south_indian 0
#define north_indian 1
#define continental 2
#define chinese 3


int X[5]={1,4,3,2,6};
int Y[5]={4,5,3,1,3};


typedef struct item
{
    char name[20];
    float price;
    struct item *next;
}item;

typedef struct agent
{
    char name[20];
    int id;
    char phone[10];
    int add_code;
    struct agent *next;
}agent;


agent *free_agents[5];
agent *alloc;

typedef struct spec{
    char name[20];
    struct spec *next;
}spec;

typedef struct user_tag
{
    int id;
    char name[20];
    char phone[10];
    int add_code;
    struct user_tag *next;
}user;

typedef struct outlet
{
    char name[20];
    int add_code;
    int seats;
    item *menu;
    spec *facilities;
    struct outlet *next;
    
}outlet;

typedef struct category
{
    outlet *type[4];
}category;

void initialize(category cat[]);
void addoutlet(category cat[]);

void traverse_outlet(outlet *o,int address)
{
    while (o!=NULL)
    {
        
    }
}
void search_category(category cat[],user *u)
{
    int t,index1,index2,i,address=-1;
    outlet *ptr;
    category select;
    printf("enter the category of food outlet you wish to view \n1-restaurant \n2-cafe\n3-pub\n4-all?");
    scanf("%d",&t);
    index1=t-1;
    printf("what food category do you wish to view?\n 1-southindian \n 2-northindian \n3-chinese \n4-continental\n5-all\n");
    scanf("%d",&t);
    printf("do you wish to see only nearby food outlets?[1/-1]");
    scanf("%d",&address);
    if (address!=(-1)) {
        address=u->add_code;
    }
    if(index1<3)
    {
            select=cat[index1];
            if(t<=4)
            {   ptr=select.type[t-1];
                traverse_outlet(ptr,address);
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    ptr=select.type[i];
                    traverse_outlet(ptr,address);
                }
            }
    }
    else
    {
        for (i=0; i<3; i++)
        {
            select=cat[i];
            if(t<=4)
            {   ptr=select.type[t-1];
                traverse_outlet(ptr,address);
            }
            else
            {
                for(i=0;i<4;i++)
                {
                    ptr=select.type[i];
                    traverse_outlet(ptr,address);
                }
            }
        }
    }
    
   
}


int main()
{
    category cat[3];
    initialize(cat);
    
    return 0;
}

void initialize(category cat[])
{
    int i=0,j=0;
    for(i=0;i<3;i++)
    {
        for (j=0; j<4; j++)
        {
            cat[i].type[i]=NULL;
        }
        
       
    }
}

int distance(int first,int second)
{
    int d;
    d=(X[first]-X[second])*(X[first]-X[second])+(Y[first]-Y[second])*(Y[first]-Y[second]);
    return d;
}



