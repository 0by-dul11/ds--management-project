#include<stdio.h>
#include<stdlib.h>
struct player{
    int jnum;
    char name[10];
    int age;
    char mob[11];
    char role[10];
    struct player *next;

};
typedef struct player plyr;
plyr *head, *temp;
int main(){
    int n, option;
    printf("Enter the number  of players: ");
    scanf("%d", &n);

 head=(plyr*)malloc(sizeof(plyr));
 printf("Enter the jersey number for player 1: ");
 scanf("%d",&head->jnum);
 printf("Enter the Name for player 1: ");
 scanf("%s",&head->name);
 printf("Enter the age for player 1: ");
 scanf("%d",&head->age);
 printf("Enter the phone number for player 1: ");
 scanf("%s",&head->mob);
 printf("Enter role for player 1: ");
 scanf("%s",&head->role);
  head->next=NULL;
create(n);
display();

}
 void display(){
     head=temp;
     while(temp!=NULL){
        printf("Jersey Number: %d, Name: %s, Age: %d, Mobile: %s, Role: %s\n",temp->jnum,temp->name,temp->age,temp->mob,temp->role);
        temp=temp->next;
     }
 }
 void create(int n){
     plyr *newplyr;
     temp=head;
     int i;
     for(i=2; i<=n; i++){
        newplyr=(plyr*)malloc(sizeof(plyr));
        printf("Enter jersey number for player %d:\n", i);
        scanf("%d",&temp->jnum);
        printf("Enter Name for player %d:\n", i);
        scanf("%s",&temp->name);
        printf("Enter age for player %d:\n", i);
        scanf("%d",&temp->age);
        printf("Enter phone number for player %d:\n", i);
        scanf("%s",&temp->mob);
        printf("Enter role for player %d:\n", i);
        scanf("%s",&temp->jnum);
        newplyr->next=NULL;
        temp->next=newplyr;
        temp=temp->next;

     }

 }
