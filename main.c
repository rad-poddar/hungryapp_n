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

void search_category(category cat[])
{
    int type,index;
    outlet *ptr;
    category select;
    printf("enter the category of food outlet you wish to view \n1-restaurant \n2-cafe\n3-pub?");
    scanf("%d",&type);
    index=type-1;
    select=cat[index];
    printf("what food category do you wish to view?\n 1-southindian \n 2-northindian
           
           traverse_outlet(ptr);
           }


int main()
{
    category cat[3];
    initialize(cat);
    
    return 0;
}

void initialize(category cat[])
{
    int i=0;
    for(i=0;i<3;i++)
    {
        cat[i].chinese=NULL;
        cat[i].continental=NULL;
        cat[i].north_indian=NULL;
        cat[i].south_indian=NULL;
    }
}

int distance(int first,int second)
{
    x1=
    d=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    return d;
}



