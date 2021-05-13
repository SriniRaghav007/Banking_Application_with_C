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
struct bank_details b[100];
void display(int);
void Create_new_account();
void Cash_withdrawl();
void balance_information();
void Log_out();
void refresh();
void upi();
void changepass();
void encrpyption();
void main()
{
	FILE *fp,*ftemp;
	int i=0;
	char ac_no[100],pass[50],str[100],str2[50],str3[100],s[100];
	printf("-------------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("Welcome to Net banking mechanism\n");
	printf("Please enter UPI ID \n");
	scanf("%s",s);
	fp=fopen("file3.txt","r");
	

	while(str)
	{
		fscanf(fp,"%s",str);
      		if(strcmp(str,s))
		{
			printf("Invalid UPI id\n");
		}
		else
		{
			fscanf(fp,"%s",str2);
			printf("Please Enter the password\n");
			scanf("%s",pass);
			if(strcmp(pass,str2))
			{
				printf("Invalid credentials\n");
				exit(1);
			}
			else
			{
				fscanf(fp,"%s",str3);
				strcpy(b[i].name,str3);
				printf("\nWelcome %s \n",b[i].name);
				display(i);
			}
		}

   	}
	fclose(fp);

}

void display(int a)
{	

	fscanf(fp,"%d",&b[a].ifsc;
	//accept isfc code from file
	switch(b[a].ifsc)
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
    int j;
	for(;;)
	{
    		printf("\n\nPlease enter one of the options\n");
    		printf("\n1. Create a new account \n");
    		printf("2. UPI money transfer \n");
    		printf("3. Cash withdrawl \n");
    		printf("4. Balance inquiry \n");
    		printf("5. Change password\n");
    		printf("6. Log out \n");
    		scanf("%d",&j);

				switch(j)
				{
					case 1:printf("Please enter the your details\n");
						//scanf("%d",&mm);
						break;
					case 2:printf("Please enter the account no to tranfer money\n");
						break;
					case 3:printf(" cash withdrawal\n");
						break;
					case 4:printf("Your balance is\n");
						break;
					case 5:printf("Enter your old password\n");
						break;
					case 6:printf("Logut\n");
						break;
					default:printf("invalid choice\n");
				}
	}
}

