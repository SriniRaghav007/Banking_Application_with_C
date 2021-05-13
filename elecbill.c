#include<stdio.h>
void bill(int);
int main()
{
	int unit;
    	//Input unit consumed from user
    	printf("Enter total units consumed: ");
    	scanf("%d", &unit);
	bill(unit);
}

void bill(int unit)
{
	float amt,total_amt,tax;
    	// Calculate electricity bill according to given conditions 
    	if(unit <= 30)
    	{
    	    amt = unit * 3.75;
    	}
    	else if(unit <= 70)
    	{
       		amt = 112 + ((unit-30) * 5.2);
    	}
    	else if(unit <= 100)
    	{
    	    amt = 364 + ((unit-70) * 6.75);
    	}
    	else if(unit <= 150)
    	{
    	    amt = 675 + ((unit-100) * 7.8);
    	}

    	else
    	{
    	    amt = 1100 + ((unit-250) * 10);
    	}

    /*
     * Calculate total electricity bill
     * after adding tax
     */
    	tax = amt * 0.09;
    	total_amt  = amt + tax+ 240; //240 is fixed amount

    	printf("Amount Due = Rs. %.2f\n", total_amt);
}
