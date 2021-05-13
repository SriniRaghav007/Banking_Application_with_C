#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bank_details
{
	long acc_no;
	int upip;
	char name[100];
	long isfc;//10 digit code for unique identification of bank branch
	int balance;
	int upi;
};
int j=2;
struct bank_details b[100];
void display(int);
void Create_new_account();
void Cash_withdrawl();
void balance_information(int);
void logout();
void refresh();
void upi(int);
void changepass();
void encrpyption();
void main()
{
	FILE *fp,*ftemp;
	int i,s,pass;
	fp=fopen("bankdetails.txt","r");
	for(i=0;i<j;i++)
	{
		fscanf(fp,"%d",&b[i].upi);
		fscanf(fp,"%d",&b[i].upip);
		fscanf(fp,"%ld",&b[i].isfc);
		fscanf(fp,"%ld",&b[i].acc_no);
		fscanf(fp,"%s",b[i].name);
		fscanf(fp,"%d",&b[i].balance);
	}
	fclose(fp);
	/*for(i=0;i<j;i++)
	{
	}*/
	printf("-----------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("Welcome to Net banking mechanism\n");
	sin:
	printf("Please enter UPI ID \n");
	scanf("%d",&s);
	for(i=0;i<j;j++)
	{
		if(s==b[i].upi)
		{	
			printf("Please Enter the password\n");
			scanf("%d",&pass);
			if(pass==b[i].upip)
			{
				printf("\nWelcome %s \n\n",b[i].name);
				display(i);	
			}
			else
			{
				printf("Invalid credentials\n");
				exit(1);
				
			}
		}
		else if(i==j-1)
		{
			system("cls");
			goto sin;
		}
	}
}
void display(int a)
{	
	printf("IFSC CODE :%ld\n",b[a].isfc);
	switch(b[a].isfc)
	{
		case 100001:printf("Bengaluru East Branch\n");
			break;
		case 100002:printf("Bengaluru West Branch\n");
			break;
		case 100003:printf("Bengaluru North Branch\n");
			break;
		case 100004:printf("Bengaluru South Branch\n");
			break;
		default:printf("check program\n");
			exit(1);
	}
    int k;
	for(;;)
	{
    		printf("\n\nPlease enter one of the options\n");
    		printf("\n1. Create a new account \n");
    		printf("2. UPI money transfer \n");
    		printf("3. Cash withdrawl \n");
    		printf("4. Balance inquiry and other details \n");
    		printf("5. Change password\n");
    		printf("6. Log out \n");
    		scanf("%d",&k);
		switch(k)
				{
					case 1:printf("Please enter the your details\n");
						//scanf("%d",&mm);
						break;
					case 2:upi(a);
						break;
					case 3:printf(" cash withdrawal\n");
						break;
					case 4:balance_information(a);
						break;
					case 5:printf("Enter your old password\n");
						break;
					case 6:logout();	
						break;
					default:printf("invalid choice\n");
						system("cls");
				}
	}
}
void upi(int l)
{
	long r;
	int bc,m,amt;
	raw:
	printf("Please enter the account no to tranfer money\n");
	scanf("%ld",&r);
	for(m=0;m<j;m++)
	{
		if(b[m].acc_no==r)
		{
			man:printf("Enter the amount to be transferred\n");
			scanf("%d",&amt);
			if(amt>b[l].balance)
			{
				printf("Insufficient Balance\n");
				goto man;
			}
			else
			{
				b[l].balance=b[l].balance-amt;
				b[m].balance=b[m].balance+amt;
				printf("Amount Transferred\n");
				printf("Do you want to go back?(type 1)(any other key for logout)\n");//wordings
				scanf("%d",&bc);
				if(bc==1)
				{
					system("cls");
					display(l);
				}
				else
					logout();
			}
		}
		else
		{
			printf("Account doesnt exist\n");
			/*printf("You were automatically logged out\n");
			logout();*/
			goto raw;
		}		
	}
}
void logout()
{
	printf("Thank You for using Net banking mechanism\n");
	exit(1);
}			
void balance_information(int y)
{
	int bck;
		printf("UPI ID:%d\n",b[y].upi);
		printf("IFSC CODE:%ld\n",b[y].isfc);
		printf("ACCOUNT NUMBBER:%ld\n",b[y].acc_no);
		printf("NAME:%s\n",b[y].name);
		printf("ACCOUNT BALANCE:%d\n",b[y].balance);
		printf("Do you want to go back?(type 1)(any other key for logout)\n");//wordings
				scanf("%d",&bck);
				if(bck==1)
				{
					system("cls");
					display(y);
				}
				else
					logout();


}
