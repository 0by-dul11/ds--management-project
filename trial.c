#include<stdio.h>
#include<stdlib.h>
struct player{
    int jnum;
    char name[12];
    int age;
    char mob[11];
    char role[14];
    struct player *next;

};
typedef struct player plyr;
plyr *head, *temp;
int main (){
    int n, opt;
    printf("Enter the number of players : ");
    scanf("%d",&n);
    create(n);
    display();


    do{
        printf("\n\n\nChoose an option.\n");
        printf("1. Insert a new player.\n");
        printf("2. Delete a player.\n");
        printf("3. Search a player by Name.\n");
        printf("4. Display all  players Information.\n");
        printf("5. Update a players role.\n");
        printf("6. Delete the team.\n");
        printf("7. Exit from the task.\n");
        printf("Select your option: ");
        scanf("%d",&opt);

        switch (opt) {
            case 1:
                insert(n);
                display();
                break;
            case 2:
                delete(n);
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                display();
                break;
            case 5:
                update(n);
                display();
                break;
            case 6:
                delete_team();
                break;
            case 7:
                printf("Exit....\n");
                break;
            default :
                printf("Something wrong.");
                break;

        }

    }while(opt!=7);

    return 0;

}
void create(int n){

    plyr *newnode;
    head=(plyr*)malloc(sizeof(plyr));
    printf("Enter jersey number of player 1: ");
    scanf("%d",&head->jnum);
    printf("Enter name of player 1: ");
    scanf("%s",&head->name);
    printf("Enter age of player 1 : ");
    scanf("%d",&head->age);
    printf("Enter phone number of player 1 : ");
    scanf("%s",&head->mob);
     printf("Enter the role of player  1: ");
    scanf("%s",&head->role);
    head->next=NULL;
    temp=head;
   for(int i=2; i<=n; i++){
     newnode=(plyr*)malloc(sizeof(plyr));
    printf("Enter jersey number of player %d: ",i);
    scanf("%d",&newnode->jnum);
    printf("Enter name of player %d: ",i);
    scanf("%s",&newnode->name);
    printf("Enter age of player %d : ",i);
    scanf("%d",&newnode->age);
    printf("Enter phone number of player %d : ",i);
    scanf("%s",&newnode->mob);
     printf("Enter the role of player %d : ",i);
    scanf("%s",&newnode->role);
    newnode->next=NULL;
    temp->next=newnode;
    temp=temp->next;
   }



}
void display(){
    int i=1;
    temp=head;
    while(temp!=NULL){
        printf("\nInformation for player %d: \n",i);
        printf(" Jersey Number: %d\n Name: %s\n Age: %d\n Phone: %s\n Role: %s",temp->jnum, temp->name,temp->age,temp->mob,temp->role);
        temp=temp->next;
        i++;
    }
    printf("\n");

}
void insert_beg(){
    plyr *newnode;

     newnode=(plyr*)malloc(sizeof(plyr));
    printf("Enter jersey number of player : ");
    scanf("%d",&newnode->jnum);
    printf("Enter name of player : ");
    scanf("%s",&newnode->name);
    printf("Enter age of player  : ");
    scanf("%d",&newnode->age);
    printf("Enter phone number of player : ");
    scanf("%s",&newnode->mob);
     printf("Enter the role of player : ");
    scanf("%s",&newnode->role);
    newnode->next=head;
    head=newnode;

}
void insert_last(){
    plyr *newnode;
     newnode=(plyr*)malloc(sizeof(plyr));
    printf("Enter jersey number of player : ");
    scanf("%d",&newnode->jnum);
    printf("Enter name of player : ");
    scanf("%s",&newnode->name);
    printf("Enter age of player  : ");
    scanf("%d",&newnode->age);
    printf("Enter phone number of player : ");
    scanf("%s",&newnode->mob);
     printf("Enter the role of player  : ");
    scanf("%s",&newnode->role);
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newnode->next=NULL;
    temp->next=newnode;



}
void insert(int n){
    int pos;
    printf("Enter the position you want to insert: ");
    scanf("%d",&pos);
    if(pos==1){
        insert_beg();
    }
    else if(pos==n+1){
        insert_last();
    }
    else{
        plyr *prev, *current,*newnode;
        newnode=(plyr*)malloc(sizeof(plyr));
    printf("Enter jersey number of player : ");
    scanf("%d",&newnode->jnum);
    printf("Enter name of player: ");
    scanf("%s",&newnode->name);
    printf("Enter age of player: ");
    scanf("%d",&newnode->age);
    printf("Enter phone number of player: ");
    scanf("%s",&newnode->mob);
     printf("Enter the role of player: ");
    scanf("%s",&newnode->role);
    for(int i=1; i<pos; i++){
            prev=temp;
            current=temp->next;
            temp=temp->next;


    }
    prev->next=newnode;
    newnode->next=current;

    }


}
void delete_beg(){
    temp=head;
    head=temp->next;
    free(temp);
    temp=NULL;

}
void delete_last(){
    plyr *prev;
    temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;

}
void delete(int n){
    int pos;
    printf("Enter the position to delete a player: ");
    scanf("%d",&pos);
    if(pos==1){
        delete_beg();
    }
    else if(pos==n){
        delete_last();
    }
    else{
        plyr *prev, *current;
        temp=head;
        for(int i=1; i<pos; i++){
            prev=temp;
            current=temp->next;
            temp=temp->next;
        }
        prev->next=current->next;
        free(current);
    }


}
void search(){
    temp=head;
    char sname[12];
    int flag=0;
    printf("Enter a name to search: ");
    scanf("%s",&sname);
    while(temp!=NULL){
        if(sname==temp->name){
            flag=0;
            break;
        }
        else{
            flag++;
        }
        temp=temp->next;
    }
    if(flag==0){
        printf(" Jersey Number: %d\n Name: %s\n Age: %d\n Phone: %s\n Role: %s",temp->jnum, temp->name,temp->age,temp->mob,temp->role);
    }
    else{
        printf("Not Found.");
    }



}
void update_beg(){
    plyr *newnode;
    temp=head;
    newnode=(plyr*)malloc(sizeof(plyr));

    printf("Enter player role to update: ");
    scanf("%s", &newnode->role);
    strcpy(temp->role,newnode->role);
}
void update_last(){
    plyr *newnode;
    temp=head;
    newnode=(plyr*)malloc(sizeof(plyr));

    printf("Enter player role to update: ");
    scanf("%s",&newnode->role);
    while(temp->next!=NULL){
        temp=temp->next;
    }
    strcpy(temp->role,newnode->role);

}

void update(int n){
    int pos;
    printf("Enter the position to update: ");
    scanf("%d",&pos);
    if(pos==1){
        update_beg();
    }
    else if(pos==n){
        update_last();
    }
    else{
        plyr *newnode;
        temp=head;
        newnode=(plyr*)malloc(sizeof(plyr));

        printf("Enter player role to update: ");
        scanf("%s",&newnode->role);

        for(int i=1; i<pos; i++){
            temp=temp->next;
        }
        strcpy(temp->role,newnode->role);
    }

}
void delete_team(){
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        free(temp);
        head=temp;
    }
    printf("All players deleted : \n");
    printf("Start from beginning to form a new team.");
}
