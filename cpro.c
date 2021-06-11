#include<stdio.h>
#include<stdlib.h>

void bf_menu();
void lunch_menu();
void dinner_menu();

//void repeat_bf();

void display();

void main_repeat();

void bf_order();

int i;
int item_arr[100];

void main(){
    int ch;
    for(;;){
        display();
        printf("Enter the option to choose\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: bf_menu();
                    break;
            
            case 2: lunch_menu();
                    break;

            case 3: dinner_menu();
                    break;

            case 4: exit(0);
                    break;

            default: main_repeat(); 
        }

    }
}

void bf_menu(){
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

    printf("Enter breakfast option\n");

    bf_order();
}

void bf_order(){
    int bf_item_num; 
    int quantity;
    int choice;

    scanf("%d",&bf_item_num);

    printf("Enter the quantity\n");
    scanf("%d",&quantity);

    if(bf_item_num>0 && bf_item_num<8){
        for(i=0;i<quantity;i++){
            item_arr[i]=bf_item_num;
        }
    }       
    /*for(i=0;i<15;i++){
           printf("%d",item_arr[i]);
        }*/
    else{
        printf("Enter a valid option\n");
        bf_menu();
    }

    printf("Do you want to continue ordering breakfast\n");
    printf("[1]Yes, [2]No\n");
    scanf("%d",choice);

}

// void repeat_bf(){
//     int loc;


//     if(loc!=0){
//             for(loc=i+1;loc<quantity;loc++){
//                 item_arr[loc]=bf_item_num;
//             }
//         }
// }


void lunch_menu(){
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

void dinner_menu(){
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

void display(){
    printf("                Welcome to C Restaurant.          \n ");
    printf("             +============================+          \n\n");
    printf("  ~~ Please select the meal that you would like to purchase. ~~ \n\n");
    printf("\t\t      1)  Breakfast\n");
    printf("\t\t      2)  Lunch\n");
    printf("\t\t      3)  Dinner\n");
    printf("\t\t      4)  Exit\n");
}

void main_repeat(){
    int ch;
    for(;;){
        display();
        printf("Enter the option to choose\n");
        scanf("%d",&ch);

        switch(ch){
            case 1: bf_menu();
                    break;
            
            case 2: lunch_menu();
                    break;

            case 3: dinner_menu();
                    break;

            case 4: exit(0);
                    break;
            default: main_repeat(); 
        }

    }
}
