#include <stdio.h>
#include <stdlib.h>
#define LEN 3 //no of items in food_arr

typedef struct items {
    int quantity;
    int price;
} items_t; //structure is type define as items_t

int main() {
    int bill = 0;
    items_t food_arr[LEN]; //array of items_t named food_arr
    char fnames[LEN][30] = {"Paratha","Vegetables","Mineral Water"}; //array with dimension 3 and each string in array length on 29 including \0
   
    for (int i=0; i<LEN; i++) {
        printf("Quantity Of %s: ", fnames[i]); 
        scanf("%d", &food_arr[i].quantity); //takes input of food items and stores in food_arr
        printf("Unit Price: ");
        scanf("%d", &food_arr[i].price);
        bill = bill + food_arr[i].quantity*food_arr[i].price; //bill is updated by adding the product of quantity and price for each item
    }
    int nop = 0;
    printf("Number of People: ");
    scanf("%d", &nop); //inputs number of people and added to nop

    if (0 < nop) {
        float ind_payment = bill/nop; //if nop is greater than 0 it calcualtes the individual pay
        printf("Individual people will pay: %.2f tk\n",ind_payment);
    }
    return 0;
}