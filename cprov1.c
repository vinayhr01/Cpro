#include<stdio.h>
#include<stdlib.h>

struct node{
    int item_num;
    int quantity;
    struct node *link;
};
typedef struct node *order;

order getnode(){
    order p;

    p=(order)malloc(sizeof(order));

    if(p==NULL){
        printf("Insufficient memory\n");
        exit(0);
    }
    return p;
}

void bf_menu(order root);
void lunch_menu(order root);
void dinner_menu(order root);

order bf_order(order root);
order lunch_order(order root);
order dinner_order(order root);

void display_bf_order(order root);
void display();

void main(){
    int ch;
    order root=NULL;

    for(;;){
        display();
        printf("Enter the option to choose\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: bf_menu(root);
                    break;
            
            case 2: lunch_menu(root);
                    break;

            case 3: dinner_menu(root);
                    break;

            case 4: exit(0);
                    break;

            default: break;
        }

    }
}

void display(){
    printf("                Welcome to C Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("  ~~ Please select the meal that you would like to purchase. ~~ \n\n");
    printf("\t\t      1)  Breakfast\n");
    printf("\t\t      2)  Lunch\n");
    printf("\t\t      3)  Dinner\n");
    printf("\t\t      4)  Exit\n");
}

void bf_menu(order root){
    for(;;){
        int ch;
        int choice;

        printf("                Welcome to C Restaurant.          \n ");
        printf("             +============================+          \n\n");
        printf("                  $  Breakfast Menu  $ \n\n");
        printf("  ~~ Please select the food that you would like to purchase with its serial number. ~~ \n\n");
        printf("\t\t   1) Toast - Rs 30.00\n");
        printf("\t\t   2) Idli-Vada - Rs 35.00\n");
        printf("\t\t   3) Dosa - Rs 40.00\n");
        printf("\t\t   4) UPMA - Rs 20.00\n");
        printf("\t\t   5) Milk- Rs 15.00\n");
        printf("\t\t   6) Tea - Rs 20.00\n");
        printf("\t\t   7) Coffee - Rs 30.00\n");

        printf("Enter an option\n1]To order\n2]Display order\n3]Display Main Menu\n4]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=bf_order(root);
                    break;
            case 2: display_bf_order(root);
                    break;

            case 3: display();
                    printf("Enter the option to choose\n");
                    scanf("%d",&choice);

                    switch(choice){
                        case 1: bf_menu(root);
                                break;
                        
                        case 2: lunch_menu(root);
                                break;

                        case 3: dinner_menu(root);
                                break;

                        case 4: exit(0);
                                break;
                    }
                    break;

            case 4: exit(0);
        }
    }
}

order bf_order(order root){
    order temp;
    order last;
    int item_num;
    int quantity;

    printf("Enter the item number to order\n");
    scanf("%d",&item_num);

    printf("Enter the quantity to order\n");
    scanf("%d",&quantity);

    temp=getnode();

    temp->item_num=item_num;
    temp->quantity=quantity;
    temp->link=NULL;

    if(root==NULL){
        return temp;
    }

    if(root->link==NULL){
        root->link=temp;
        return root;
    }

    last=root;

    while(last->link!=NULL){
        last=last->link;
    }
    last->link=temp;
    return root;
}

void display_bf_order(order root){
    order temp;

    temp=root;

    while(temp!=NULL){
        printf("Item num- %d\nQuantity- %d\n",(temp->item_num),(temp->quantity));
        temp=temp->link;
    }
}

void lunch_menu(order root){
    printf("                Welcome to C Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                   $  Lunch Menu  $ \n\n");
    printf("  ~~ Please select the food that you would like to purchase. ~~ \n\n");
    printf("\t\t   0) Veg Biryani - Rs 80.00\n");
    printf("\t\t   1) Special Meal- Rs 120.00\n");
    printf("\t\t   2) Roti - Rs 20.00\n");
    printf("\t\t   3) Dal tadka - Rs 120.00\n");
    printf("\t\t   4) Paneer Tikka - Rs 150.00\n");
    printf("\t\t   5) Veg Mix - Rs 160.00\n");
    printf("\t\t   6) Ice cream - Rs 30.00\n");
}

void dinner_menu(order root){
    printf("                Welcome to C Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("                    $  Dinner Menu  $ \n\n");
    printf("  ~~ Please select the food that you would like to purchase. ~~ \n\n");
    printf("\t\t   0) Fried Rice - Rs 65.00\n");
    printf("\t\t   1) Spegatti- Rs 50.00\n");
    printf("\t\t   2) Burger - Rs 70.00\n");
    printf("\t\t   3) Pasta - Rs 80.00\n");
    printf("\t\t   4) Noodles - Rs 65.00\n");
    printf("\t\t   5) Paratha - Rs 110.00\n");
    printf("\t\t   6) Fruit Salad - Rs 50.00\n");
}
