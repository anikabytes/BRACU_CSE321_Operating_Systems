#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct order{
	int quantity;
	float price;
};

int main(){

	struct order paratha;
	printf("Quantity of Paratha: ");
	scanf("%d",&paratha.quantity);
	printf("Unit Price: ");
	scanf("%f",&paratha.price);
	
	struct order vegetables;
	printf("Quantity of Vegetables: ");
	scanf("%d",&vegetables.quantity);
	printf("Unit Price: ");
	scanf("%f",&vegetables.price);

	struct order mineral_water;
	printf("Quantity of Mineral Water: ");
	scanf("%d",&mineral_water.quantity);
	printf("Unit Price: ");
	scanf("%f",&mineral_water.price);
	
	int num_of_people;
	printf("Number of People: ");
	scanf("%d",&num_of_people);
	
	float total;
	total = ((paratha.quantity*paratha.price)+(vegetables.quantity*vegetables.price)+(mineral_water.quantity*mineral_water.price))/num_of_people;
	printf("Individual people will pay: %.2f tk\n",total);


}
