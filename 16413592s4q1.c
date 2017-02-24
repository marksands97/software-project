#include <stdio.h>
int square_integers(int *square1, int *square2, int *square3, int *square4);

int main(void)
{
	int i, a, b, c, d, sum, product;

	/*Declaring the pointers*/
	int *first, *second, *third, *fourth;

	printf("Enter 4 integers:\n");

	/*Assigning the entered values to a variable*/
	scanf("%d %d %d %d", &a, &b, &c, &d);

	/*Assigning the address of the integers to the pointers*/
	first = &a;
	second = &b;
	third = &c;
	fourth = &d;

	sum = a+b+c+d;
	product = a*b*c*d;


	printf("\nEntered integers and memory addresses:\n\n%d Address: %d \n%d Address: %d\n%d Address: %d\n%d Address: %d\n\n", a, &first, b, &second, c, &third, d, &fourth);

	printf("Sum of integers: %d\n\n", sum);

	printf("Product of integers: %d", product);

	/*Calling the function to square the integers by pass by reference*/
	square_integers(&a, &b, &c, &d);


	return 0;
}

/*Creating the function*/
int square_integers(int *square1, int *square2, int *square3, int *square4)
{
	/*Squaring the variables*/

	*square1 = *square1 * *square1;
	*square2 = *square2 * *square2;
	*square3 = *square3 * *square3;
	*square4 = *square4 * *square4;

	printf("\n\nThe integers squared are: %d %d %d %d", *square1, *square2, *square3, *square4);

	return 0;

}