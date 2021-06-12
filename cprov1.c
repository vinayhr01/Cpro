#include<stdio.h>
#include<stdlib.h>

struct node{
    int item_num;
    int quantity;
    struct node *link;
};
typedef struct node *order;

order getnode(){
    order allocate;

    allocate=(order)malloc(sizeof(order));

    if(allocate==NULL){
        printf("Insufficient memory\n");
        exit(0);
    }
    return allocate;
}

void bf_menu(order root);
void lunch_menu(order root);
void dinner_menu(order root);

order bf_order(order root);
order lunch_order(order root);
order dinner_order(order root);

void display_bf_order(order root);
void display_lunch_order(order root);
void display_dinner_order(order root);

void display_main_menu();

void main(){
    int ch;
    order root=NULL;

    for(;;){
        display_main_menu();
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

void display_main_menu(){
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

        printf("Enter an option in\n1]To order\n2]Display order\n3]Display Main Menu\n4]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=bf_order(root);
                    break;
            case 2: display_bf_order(root);
                    break;

            case 3: display_main_menu();
                    printf("Enter the menu option to choose\n");
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

    printf("Enter the breakfast item number to order\n");
    scanf("%d",&item_num);

    printf("Enter the quantity of breakfast to order\n");
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

    if(root==NULL){
        printf("You haven't ordered anything\n");
    }
    temp=root;

    while(temp!=NULL){
        printf("Breakfast item num- %d\tBreakfast Quantity- %d\n",(temp->item_num),(temp->quantity));
        temp=temp->link;
    }
}

void lunch_menu(order root){
    for(;;){
        int ch;
        int choice;

        printf("                Welcome to C Restaurant.          \n ");
        printf("             +============================+          \n\n");
        printf("                   $  Lunch Menu  $ \n\n");
        printf("  ~~ Please select the food that you would like to purchase. ~~ \n\n");
        printf("\t\t   1) Veg Biryani - Rs 80.00\n");
        printf("\t\t   2) Special Meal- Rs 120.00\n");
        printf("\t\t   3) Roti - Rs 20.00\n");
        printf("\t\t   4) Dal tadka - Rs 120.00\n");
        printf("\t\t   5) Paneer Tikka - Rs 150.00\n");
        printf("\t\t   6) Veg Mix - Rs 160.00\n");
        printf("\t\t   7) Ice cream - Rs 30.00\n");

        printf("Enter an option in\n1]To order\n2]Display order\n3]Display Main Menu\n4]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=lunch_order(root);
                    break;
            case 2: display_lunch_order(root);
                    break;

            case 3: display_main_menu();
                    printf("Enter the menu option to choose\n");
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

order lunch_order(order root){
    order temp;
    order last;
    int item_num;
    int quantity;

    printf("Enter the lunch item number to order\n");
    scanf("%d",&item_num);

    printf("Enter the quantity of lunch to order\n");
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

void display_lunch_order(order root){
    order temp;

    if(root==NULL){
        printf("You haven't ordered anything\n");
    }

    temp=root;

    while(temp!=NULL){
        printf("Lunch item num- %d\tLunch Quantity- %d\n",(temp->item_num),(temp->quantity));
        temp=temp->link;
    }
}

void dinner_menu(order root){
    for(;;){
        int ch;
        int choice;

        printf("                Welcome to C Restaurant.          \n ");
        printf("             +============================+          \n\n");
        printf("                    $  Dinner Menu  $ \n\n");
        printf("  ~~ Please select the food that you would like to purchase. ~~ \n\n");
        printf("\t\t   1) Fried Rice - Rs 65.00\n");
        printf("\t\t   2) Spegatti- Rs 50.00\n");
        printf("\t\t   3) Burger - Rs 70.00\n");
        printf("\t\t   4) Pasta - Rs 80.00\n");
        printf("\t\t   5) Noodles - Rs 65.00\n");
        printf("\t\t   6) Paratha - Rs 110.00\n");
        printf("\t\t   7) Fruit Salad - Rs 50.00\n");

        printf("Enter an option in\n1]To order\n2]Display order\n3]Display Main Menu\n4]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=dinner_order(root);
                    break;
            case 2: display_dinner_order(root);
                    break;

            case 3: display_main_menu();
                    printf("Enter the food menu option to choose\n");
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

order dinner_order(order root){
    order temp;
    order last;
    int item_num;
    int quantity;

    printf("Enter the dinner item number to order\n");
    scanf("%d",&item_num);

    printf("Enter the quantity of dinner to order\n");
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

void display_dinner_order(order root){
    order temp;

    if(root==NULL){
        printf("You haven't ordered anything\n");
    }

    temp=root;

    while(temp!=NULL){
        printf("Dinner item num- %d\tDinner Quantity- %d\n",(temp->item_num),(temp->quantity));
        temp=temp->link;
    }
}
