//conversion in doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
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


typedef struct likes
{
   char name[20];
   int frequency;
}likes;


typedef struct agent
{
    char name[20];
    int id;
    char address[50];
    char phone[10];
    int add_code;
    float commission;
    struct agent *next;
    
}agent;


typedef struct spec{
    char name[20];
    struct spec *next;
}spec;



typedef struct outlet
{
    char name[20];
    char address[20];
    int add_code;
    int seats;
    item *menu;
    spec *facilities;
    struct outlet *next;
    
}outlet;


typedef struct order
{
    int uid;  //user id
    outlet *selected_outlet;
    agent *selected_agent;
    item *food;
    int totalprice;
    struct order *next;
}order;

typedef struct user_tag
{
    int id;
    char name[20];
    char address[20];
    char phone[10];
    int add_code;
    likes *favourites;
    order *history;

    struct user_tag *next;
}user;

typedef struct category
{
    outlet *type[4];
}category;

/*------------------------------------------------------*/
agent *free_agents[5];
agent *alloc_agents;
user *signed_user;

static int user_id=1;
static int agent_id=1;

user *user_array[10];

order *live_order;

/*------------------------------------------------------*/
void initialize_user(user *user_array[]);
void initialize(category cat[]);
void addoutlet(category cat[]);
////////////////////////////void address_name(char c[],int address_code);
void traverse_outlet(outlet *o,int address);
void search_category(category cat[]);
void Sort_addresscodes(int arr[],int a);
void delivery(int user_id);
int address_code(char[]);
order* assign_agent(order *o);
outlet* search_outlet(char name[]);
void initialize_agents(void);
void signup_user(void);
void signup_agent(void);
void signin_user(void);
/*------------------------------------------------------*/



int main()
{
    category cat[3];
    initialize(cat);
    int choice;
    printf("ENTER 1 FOR USER ELSE 2 TO APPLY FOR AGENT\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        int t;
        printf("ENTER 1 FOR SIGNUP AND 2 FOR SIGNIN\n");
        scanf("%d",&t);
        if(t==1)
        { signup_user();}
        else
        { signin_user();}
    }
    else
    {
        signup_agent();
    }
    
    return 0;
}


/*------------------------------------------------------*/

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


/*------------------------------------------------------*/


int distance(int first,int second)
{
    int d;
    d=(X[first]-X[second])*(X[first]-X[second])+(Y[first]-Y[second])*(Y[first]-Y[second]);
    return d;
}


/*------------------------------------------------------*/


void traverse_outlet(outlet *o,int address)
{

    int d,i,j,flag;
    outlet *ptr;
    ptr=o;

    if (address!=-1)
    {

        item *menu_temp;            //printf facilities also
        while (ptr!=NULL)
        {
            printf("-----------------\nfood outlet name-%s\nNumber of seats-%daddress-%s\n------------\n",ptr->name,ptr->seats,ptr->address);
            menu_temp = ptr->menu;
            while(menu_temp!=NULL)
            {
               printf("%s %d",menu_temp->name,menu_temp->price);
               menu_temp = menu_temp->next;
            }
            printf("\n");
            ptr=ptr->next;
        }

    }
    else
    {
        item *menu_temp;                //print facilities also
        int a[5]={0,1,2,3,4};
        Sort_addresscodes(a, address);
        while (ptr!=NULL)
        {
            if (ptr->add_code==a[0]||ptr->add_code==a[1]||ptr->add_code==a[2])
            {
                printf("-----------------\nfood outlet name-%s\nNumber of seats-%daddress-%s\n------------\n",ptr->name,ptr->seats,ptr->address);
                 menu_temp = ptr->menu;
                 while(menu_temp!=NULL)
                 {
                         printf("%s %d",menu_temp->name,menu_temp->price);
                         menu_temp = menu_temp->next;
                 }
                 printf("\n");
            }
            ptr=ptr->next;
        }

    }
    
}


/*------------------------------------------------------*/


void search_category(category cat[])
{
    int t,index1,i,address=-1;
    outlet *ptr;
    category select;

    printf("enter the category of food outlet you wish to view \n1-restaurant  \n2-cafe \n3-pub  \n4-all?");
    scanf("%d",&t);

    index1=t-1;

    printf("what food category do you wish to view? \n 1-southindian  \n 2-northindian  \n3-chinese  \n4-continental \n5-all \n");
    scanf("%d",&t);


    printf("do you wish to see only nearby food outlets?[1/-1]");
    scanf("%d",&address);

    if (address!=(-1)) 
    {
        address = signed_user->add_code;
    }

    if(index1<3)
    {
         select=cat[index1];

         if(t<=4)
         {  
            ptr=select.type[t-1];
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
              {    
                  ptr=select.type[t-1];
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

/*-------------------------------------------*/

void Sort_addresscodes(int arr[],int a)
{

    int i, key, j;
    for (i = 1; i < 5; i++)
    {
        key = arr[i];
        j = i-1;
        while (j >= 0 && distance(arr[j],a) >distance(key, a))
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }

}


/*_________________________________________________*/


void place_order()
{

    int choice,i;
    char name[50]; 

    order *new_order;
    new_order = (order*)malloc(sizeof(order));

    printf("if you want to see our outlets enter 1 else 0\n");
    scanf("%d",&choice);
    if(choice==1)
    {
       search_category();
    }

    printf("enter the name of restaurant");
    scanf("%s",name);
    
    new_order->uid = signed_user->id;
    new_order->selected_outlet = search_outlet(name);
    new_order->totalprice=0;

    item *new_menu,*nptr,*ptr;
    new_menu = NULL;

    printf("enter the no. of items that you want to order\n");
    scanf("%d",&choice);

    printf("enter the names of item to order\n");
    int found;

    for(i=0;i<choice;i++)
    {
         nptr = (item*)malloc(sizeof(item));
         scanf("%s",name); 
         ptr = (new_order->selected_outlet)->menu;
         found=0;
         while(ptr!=NULL && found==0)
         {
             if(strcmp(ptr->name,name)==0)
             { 
                new_order->totalprice += ptr->price;
                found=1; 
                strcpy(nptr->name,ptr->name);
                nptr->price = ptr->price;
                nptr->next = new_menu;
                new_menu = nptr;
             }
             else
             { 
                 ptr = ptr->next;
             }
         }
         
    }


    new_order->food = new_menu;
    new_order = assign_agent(new_order);;

    new_order->next = live_order;
    live_order = new_order;

}


order* assign_agent(order *o)
{

    int a[5]={0,1,2,3,4};
    int i,found=0;
    agent *selected_agent;

    Sort_addresscodes(a,(o->selected_outlet)->add_code);
    
    for (i=0; i<5&&found==0; i++)
    {
        if (free_agents[i]!=NULL)
        {
            selected_agent=free_agents[i];
            found=1;
            free_agents[i]=selected_agent->next;
            selected_agent->next=alloc_agent;
            alloc_agent=selected_agent;
            
        }
    }

    o->selected_agent=selected_agent;
    o->next=live_order;
    live_order=o;
    return o;
}

/*---------------------------------------*/


outlet* search_outlet(char name[])
{
   int t,j,found=0;
   outlet *search,*ptr;
   category select;

   for(t=0;t<3 && found==0;t++) 
   {
      
      select = cat[t];
      for(j=0;j<4 && found==0;j++)
      {

          ptr = select.type[j];
          while(ptr!=NULL && found==0);
          {
             if(strcmp(ptr->name,name)==0)
             {
                search = ptr;
                found=1;
             }
             else
             { 
                ptr = ptr->next; 
             }
          }
      
      }

   }

   return search;
     
}


void initialize_user(user *user_array[])
{
    int i;
    for(i=0;i<10;i++)
    {  user_array[i] = NULL; }
    
}


void delivery()
{
    int uid,found=0,id;
    order *ptr,*prev,*old;

    agent *tobefreed;
    ptr=live_order;
    prev=NULL;
    uid=signed_user->id;

    while (ptr!=NULL && found==0)
    {
        id=ptr->uid;
        if (id==user_id)
        {
            found=1;
            if(prev!=NULL)
            {
                prev->next = ptr->next;
            }
            else
            {
                live_order = ptr->next;
            }
            old=ptr;
            ptr = ptr->next;
        }
        else
        {
          prev=ptr;
          ptr=ptr->next;
        }
    }
    if (found==1)
    {
         old->next = signed_user->history;
         signed_user->history = old;

         tobefreed=old->selected_agent;
         tobefreed->add_code = signed_user->add_code;
         tobefreed->commission += (0.1) * old->totalprice;

         item *menu_;
         likes *temp;
         menu_ = old->menu;
         while(menu_!=NULL)
         {
            temp = signed_user->favourites;
            int flag=0;
            while(temp!=NULL && flag==0)
            {
               if(strcmp(temp->name,menu_->name)==0)
               {
                   temp->frequency +=1; flag=1;
               }
               else
               {
                 temp = temp->next;
               }
            }
            if(flag==0)
            {
                temp = (likes*)malloc(sizeof(likes));
                temp->frequency = 1;
                strcpy(temp->name,menu_->name);
                temp->next = signed_user->favourites;
                signed_user->favourites = temp;
            }
            menu_ = menu_->next;
         }

         tobefreed->next=free_agents[signed_user->add_code];
         free_agents[signed_user->add_code]=tobefreed;
    }
    else
    {
        printf("NO LIVE ORDER FROM THIS ID");
    }
    
}


void cancel()
{
    int uid,id,found=0;
    order *ptr,*prev,*old;
    agent *tobefreed;

    ptr=live_order;
    prev=NULL;
    uid=signed_user->id;

    while (ptr!=NULL && found==0)
    {
        id=ptr->uid;
        if (id==user_id)
        {
            found=1;
            if(prev!=NULL)
            {
                prev->next = ptr->next;
            }
            else
            {
                live_order = ptr->next;
            }
            old=ptr;
            ptr = ptr->next;
        }
        else
        {
            prev=ptr;
            ptr=ptr->next;
        }
    }

    if (found==1)
    {
        tobefreed=old->selected_agent;
        tobefreed->next=free_agents[signed_user->add_code];
        tobefreed->add_code = signed_user->add_code;
        free_agents[signed_user->add_code]=tobefreed;
        free(old);
        printf("YOUR ORDER HAS BEEN CANCELLED SUCCESSFULLY\n");
    }
    else
    {
        printf("NO LIVE ORDER FROM THIS ID");
    }
    
}

 int address_code(char str[])
 {
     char s;
     int a;
     s=str[0];
     switch (s)
     {
         case 'a':
             a=0;
             break;
         case 'n':
             a=1;
             break;
         case 'w':
             a=2;
             break;
         case 'd':
             a=3;
             break;
         case 'p':
             a=4;
             break;
            
         default:
             break;
      }
      return a;
 }


void initialize_agents()
{
    int i;
    for (i=0; i<5; i++)
    {
        free_agents[i]=NULL;
    }
    alloc_agents=NULL;
}


void signup_agent()
{
    
    agent *temp;
    temp = (agent*)malloc(sizeof(agent));

    printf("enter your name\n");
    scanf("%s",temp->name);

    printf("enter your address");
    scanf("%s",temp->address);

    temp->add_code = address_code(temp->address);
    printf("enter your contact\n");
    scanf("%s",temp->phone);

    temp->id = agent_id;
    agent_id++;
    temp->commission = 0;
    temp->next = free_agents[temp->add_code];
    free_agents[temp->add_code] = temp;
}


void signup_user( )
{
    user *temp;
    temp = (user*)malloc(sizeof(user));

    printf("enter your name\n");
    scanf("%s",temp->name);

    printf("enter your address\n");
    scanf("%s",temp->address);
    temp->add_code = address_code(temp->address);

    printf("enter your contact no.\n");
    scanf("%s",temp->phone);

    temp->history = NULL;
    temp->favourites = NULL;

    temp->id = user_id;
    user_id++;
    temp->next = user_array[temp->id % 10];
    user_array[temp->id % 10] =temp;

    printf("you signed up successfully !!! use %d as your future id\n",temp->id);
}


void signin_user()
{
     int t,flag=0;
     printf("enter your user id\n");
     scanf("%d",&t);
     user *search;
     search = user_array[t%10];

     while(search!=NULL && flag==0)
      {
          if(search->add_code==t)
          {
              flag=1;
              signed_user = search;
          }
          else
          {
              search = search->next;   
          }
      }

      if(flag==0)
      {
         printf("NO USER FOUND WITH GIVEN ID !!!\n PLEASE SIGN UP FIRST\n");
      }
      else
      {
        printf("WELCOME!! %s\n",signed_user->name);  
      }

}
