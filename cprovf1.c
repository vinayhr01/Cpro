#include<stdio.h>
#include<stdlib.h>

int rate[21][2]={
    {0,30},{1,35},{2,40},{3,20},{4,15},{5,20},{6,30},{7,80},{8,120},{9,20},{10,120},{11,150},{12,160},{13,30},{14,65},
    {15,50},{16,70},{17,80},{18,65},{19,110},{20,50}
};

char food_item_list[][50]={"Toast","Idli Wada","Dosa","Upma","Milk","Tea","Coffee",
                      "Veg Biryani","Special Meal","Roti","Dal Tadka","Paneer Tikka","Veg Mix","Ice Cream",
                      "Fried Rice","Spegatti","Burger","Pasta","Noodles","Paratha","Fruit Salad"
};

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

void display_main_menu();
void bf_menu(order root);
void lunch_menu(order root);
void dinner_menu(order root);
void display_all_food_menu();

order food_order(order root);
order cancel_order(order root);

void display_food_order(order root,char food_item_list[][50]);

void display_bill(order root,int rate[][2],char food_item_list[][50]);

void main(){
    int ch;
    order root=NULL;

    for(;;){
        display_main_menu();
        printf("Enter the option to choose\n");
        scanf("%d",&ch);

        switch(ch){
            case 0: display_all_food_menu();
                    break;

            case 1: bf_menu(root);
                    break;
            
            case 2: lunch_menu(root);
                    break;

            case 3: dinner_menu(root);
                    break;

            case 4: display_bill(root,rate,food_item_list);
                    break;

            case 5: exit(0);

            default: break;
        }

    }
}

void display_all_food_menu(){
        printf("                  $  Breakfast Menu  $ \t\t");
        printf("\t\t\t\t\t                  $  Lunch Menu  $ \n\n");
        printf(" ~~ Please select the breakfast that you would like to purchase with serial number ~~ \t");
        printf(" ~~ Please select the lunch that you would like to purchase ~~ \n\n");
        printf("\t\t   1) Toast - Rs 30.00\t\t");
        printf("\t\t\t\t\t\t\t   8) Veg Biryani - Rs 80.00\n");
        printf("\t\t   2) Idli-Vada - Rs 35.00\t\t");
        printf("\t\t\t\t\t\t   9) Special Meal- Rs 120.00\n");
        printf("\t\t   3) Dosa - Rs 40.00\t\t");
        printf("\t\t\t\t\t\t\t   10) Roti - Rs 20.00\n");
        printf("\t\t   4) UPMA - Rs 20.00\t\t");
        printf("\t\t\t\t\t\t\t   11) Dal tadka - Rs 120.00\n");
        printf("\t\t   5) Milk- Rs 15.00\t\t");
        printf("\t\t\t\t\t\t\t   12) Paneer Tikka - Rs 150.00\n");
        printf("\t\t   6) Tea - Rs 20.00\t\t");
        printf("\t\t\t\t\t\t\t   13) Veg Mix - Rs 160.00\n");
        printf("\t\t   7) Coffee - Rs 30.00\t\t");
        printf("\t\t\t\t\t\t\t   14) Ice cream - Rs 30.00\n\n");

        printf("\t\t\t\t\t         $  Dinner Menu  $ \n\n");
        printf("\t\t\t\t\t\t ~~ Please select the food that you would like to purchase ~~ \n\n");
        printf("\t\t\t\t\t\t   15) Fried Rice - Rs 65.00\n");
        printf("\t\t\t\t\t\t   16) Spegatti- Rs 50.00\n");
        printf("\t\t\t\t\t\t   17) Burger - Rs 70.00\n");
        printf("\t\t\t\t\t\t   18) Pasta - Rs 80.00\n");
        printf("\t\t\t\t\t\t   19) Noodles - Rs 65.00\n");
        printf("\t\t\t\t\t\t   20) Paratha - Rs 110.00\n");
        printf("\t\t\t\t\t\t   21) Fruit Salad - Rs 50.00\n\n");       
}

void display_main_menu(){
    printf("                Welcome to C Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("  ~~ Please select the meal that you would like to purchase. ~~ \n\n");
    printf("\t\t      0)  Complete food menu\n");
    printf("\t\t      1)  Breakfast\n");
    printf("\t\t      2)  Lunch\n");
    printf("\t\t      3)  Dinner\n");
    printf("\t\t      4)  Bill\n");   
    printf("\t\t      5)  Exit\n");
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

        printf("Enter an option in\n1]To order\n2]To cancel order\n3]Display order\n4]Display Main Menu\n5]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=food_order(root);
                    break;

            case 2: root=cancel_order(root);
                    break;

            case 3: display_food_order(root,food_item_list);
                    break;

            case 4: display_main_menu();
                    printf("Enter the menu option to choose\n");
                    scanf("%d",&choice);

                    switch(choice){
                        case 0: display_all_food_menu();
                                break;

                        case 1: bf_menu(root);
                                break;
                        
                        case 2: lunch_menu(root);
                                break;

                        case 3: dinner_menu(root);
                                break;

                        case 4: display_bill(root,rate,food_item_list);
                                break;

                        case 5: exit(0);
                                break;
                    }
                    break;

            case 5: exit(0);
        }
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
        printf("\t\t   8) Veg Biryani - Rs 80.00\n");
        printf("\t\t   9) Special Meal- Rs 120.00\n");
        printf("\t\t   10) Roti - Rs 20.00\n");
        printf("\t\t   11) Dal tadka - Rs 120.00\n");
        printf("\t\t   12) Paneer Tikka - Rs 150.00\n");
        printf("\t\t   13) Veg Mix - Rs 160.00\n");
        printf("\t\t   14) Ice cream - Rs 30.00\n");

        printf("Enter an option in\n1]To order\n2]To cancel order\n3]Display order\n4]Display Main Menu\n5]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=food_order(root);
                    break;

            case 2: root=cancel_order(root);
                    break;

            case 3: display_food_order(root,food_item_list);
                    break;

            case 4: display_main_menu();
                    printf("Enter the menu option to choose\n");
                    scanf("%d",&choice);

                    switch(choice){
                        case 0: display_all_food_menu();
                                break;

                        case 1: bf_menu(root);
                                break;
                        
                        case 2: lunch_menu(root);
                                break;

                        case 3: dinner_menu(root);
                                break;

                        case 4: display_bill(root,rate,food_item_list);
                                break;

                        case 5: exit(0);
                    }
                    break;

            case 5: exit(0);
        }
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
        printf("\t\t   15) Fried Rice - Rs 65.00\n");
        printf("\t\t   16) Spegatti- Rs 50.00\n");
        printf("\t\t   17) Burger - Rs 70.00\n");
        printf("\t\t   18) Pasta - Rs 80.00\n");
        printf("\t\t   19) Noodles - Rs 65.00\n");
        printf("\t\t   20) Paratha - Rs 110.00\n");
        printf("\t\t   21) Fruit Salad - Rs 50.00\n");

        printf("Enter an option in\n1]To order\n2]Display order\n3]Display Main Menu\n4]Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1: root=food_order(root);
                    break;

            case 2: root=cancel_order(root);
                    break;

            case 3: display_food_order(root,food_item_list);
                    break;

            case 4: display_main_menu();
                    printf("Enter the food menu option to choose\n");
                    scanf("%d",&choice);

                    switch(choice){
                        case 0: display_all_food_menu();
                                break;

                        case 1: bf_menu(root);
                                break;
                        
                        case 2: lunch_menu(root);
                                break;

                        case 3: dinner_menu(root);
                                break;

                        case 4: display_bill(root,rate,food_item_list);
                                break;

                        case 5: exit(0);
                    }
                    break;

            case 5: exit(0);
        }
    }
}

order food_order(order root){
    order temp;
    order last;
    int item_num;
    int quantity;

    printf("Enter the food item number to order\n");
    scanf("%d",&item_num);

    if(item_num<1 && item_num>21){
        printf("Enter right item number\n");
        return root;
    }

    printf("Enter the quantity of food items to order\n");
    scanf("%d",&quantity);

    if(quantity==0){
        printf("Enter a correct quantity number\n");
        return root;
    }

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

order cancel_order(order root){
    order temp,prev;
    int key,quantity;

    if(root==NULL){
        printf("Nothing to cancel, please place an order\n");
        return root;
    }

    printf("Enter the item number to cancel the order\n");
    scanf("%d",&key);

    printf("Enter the quantity of food item to cancel\n");
    scanf("%d",&quantity);

    if(root->link==NULL){
        if(key==root->item_num){
            if(quantity>root->quantity){
                printf("Enter correct quantity\n");
                return root;
            }

            printf("%d items are deleted with item number %d\n",quantity,(root->item_num));

            if(quantity<=root->quantity && quantity>0){
                while(quantity!=0){
                    root->quantity-=1;
                    quantity--;
                }
            }
            //printf("%d quantity in root is deleted",(root->quantity));
        }
        else if(key!=root->item_num){
            printf("Enter correct item number\n");
            return root;
        }
        if(key==root->item_num && root->quantity==0){
            printf("There is nothing to delete now, please order a food item\n");
            free(root);
            return NULL;
        }
        return root;
    }

    prev=NULL;
    temp=root;
    
    while(temp!=NULL){
        prev=temp;
        temp=temp->link;
        if(key==temp->item_num){
            if(quantity>temp->quantity){
                printf("Enter correct quantity\n");
                return root;
            }

            printf("%d items are deleted with item number %d\n",quantity,(temp->item_num));
            if(quantity<=temp->quantity && quantity>0){
                while(quantity!=0){
                    temp->quantity-=1;
                    quantity--;
                }
            }
            printf("%d quantity in temp is deleted",(temp->quantity));
            return root;

            if(temp->quantity==0){
                prev->link=temp->link;
                temp->link=NULL;
                free(temp);
                return root;
            }
        }
    }
}

void display_food_order(order root,char food_item_list[][50]){
    order temp;

    if(root==NULL){
        printf("You haven't ordered anything\n");
    }
    temp=root;

    printf("\t\t~~Item Name\t\tItem Number\t\tItem Quantity\n\n");

    while(temp!=NULL){
        printf("\t\t%s\t\t\t%d\t\t\t%d\n\n",food_item_list[(temp->item_num)-1],(temp->item_num),(temp->quantity));
        temp=temp->link;
    }
}

void display_bill(order root,int rate[][2],char food_item_list[][50]){
    int bill=0;
    order temp;
    float gst,cgst,sgst,total_bill;
    int choice;

    if(root==NULL){
        printf("You haven't ordered anything to display the bill\n");
        return;
    }

    printf("  +~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+          \n\n");
    printf("                      C RESTAURANT                   \n");
    printf("                    BILLING INFORMATION                \n");
    printf("\t ITEM NAME\t\t ITEM NUMBER \t Quantity \tPrice(in Rs./item)\t    Total Price\n\n");

    if(root->link==NULL){
        printf("\t%s\t\t     %d\t\t    %d\t\t\t%d\t\t     %d X %d = %d\n\n",(food_item_list[(root->item_num)-1]),(root->item_num),(root->quantity),(rate[(root->item_num)-1][1]),(root->quantity),(rate[(root->item_num)-1][1]),((root->quantity)*(rate[(root->item_num)-1][1])));
        bill=(root->quantity)*(rate[(root->item_num)-1][1]);
        printf("Total bill = %d\n",bill);
        return;
    }

    temp=root;

    while(temp!=NULL){
        printf("\t%s\t\t     %d\t\t    %d\t\t\t%d\t\t     %d X %d = %d\n\n",(food_item_list[(temp->item_num)-1]),(temp->item_num),(temp->quantity),(rate[(temp->item_num)-1][1]),(temp->quantity),(rate[(temp->item_num)-1][1]),((temp->quantity)*(rate[(temp->item_num)-1][1])));
        bill+=(temp->quantity)*(rate[(temp->item_num)-1][1]);
        temp=temp->link;
    }
    printf("\t  Total bill without gst = %d\n",bill);
    gst=bill*0.12;
    cgst=gst/2;
    sgst=cgst;
    total_bill=bill+gst+cgst+sgst;
    printf("\t  Total bill with gst = %0.2f\n\n",total_bill);

    display_main_menu();
    printf("Enter the food menu option to choose\n");
    scanf("%d",&choice);
    switch(choice){
        case 0: display_all_food_menu();
                break;

        case 1: bf_menu(root);
                break;
                        
        case 2: lunch_menu(root);
                break;

        case 3: dinner_menu(root);
                break;

        case 4: display_bill(root,rate,food_item_list);
                break;

        case 5: exit(0);
        }
}
