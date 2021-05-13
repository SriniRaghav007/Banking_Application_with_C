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
struct jcount
{
	int j;
};
//int j=2;
struct bank_details b[100];
struct jcount mm;
void caeser(char *encrypt,char *save);
void display(int);
void Create_new_account(int);
void bill(int);
void balance_information(int);
void logout();
void mystruct();
void upi(int);
void changepass(int);
void encrpyption();
void main()
{
	int is,s,pass,unit;
	mystruct(); //caeser here
	int choice;
	billboy:
	printf("Enter\n 1 for Pay Electricity bill\n 2 for Net banking\n");
	scanf("%d",&choice);
	switch(choice)
	{

		case 1:	
    	//Input unit consumed from user
    	printf("Enter total units consumed: ");
    	scanf("%d", &unit);
	bill(unit);
	break;
	case 2:
	/*for(i=0;i<j;i++)
	{
	}*/
	printf("-----------------------------------------------------------------------------------------------------------------------------\n\n");
	printf("Welcome to NetBanking mechanism\n");
	sin:
	printf("Please enter UPI ID \n");
	scanf("%d",&s);
	for(is=0;is<mm.j;is++)
	{
		if(s==b[is].upi)
		{	
			printf("Please Enter the password\n");
			scanf("%d",&pass);
			if(pass==b[is].upip)
			{
				printf("\nWelcome %s \n\n",b[is].name);
				display(is);	
			}
			else
			{
				printf("Invalid credentials\n");
				exit(1);
				
			}
		}
		else if(is==mm.j-1)
		{
			system("cls");
			goto sin;
		}
	}
	break;
	default:printf("Invalid choice\nPlease Try again\n");
	goto billboy;
	}
}
void display(int a)
{	
	printf("IFSC CODE :%ld\n",b[a].isfc);
	int bsdk;
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
    		printf("3. Request Debit card \n");
    		printf("4. Balance inquiry and other details \n");
    		printf("5. Change password\n");
    		printf("6. Log out \n");
    		scanf("%d",&k);
		switch(k)
				{
					case 1: Create_new_account(a);
						break;
					case 2:upi(a);
						break;
					case 3:printf(" Debit card requested\n");
						printf("Do you want to go back?(type 1)(any other key for logout)\n");//wordings
						scanf("%d",&bsdk);
						if(bsdk==1)
						{
						system("cls");
						display(a);
						}
					else
						logout();
						break;
					case 4:balance_information(a);
						break;
					case 5:changepass(a);
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
	int bc,m=0,amt;
	raw:

	printf("\nPlease enter the account no to tranfer money\n");
	scanf("%ld",&r);
	for(m=0;m<mm.j;m++)
	{
		if(r == b[m].acc_no)
		{
			man:
			printf("\nEnter the amount to be transferred\n");
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
				printf("Your Balance amount is %d\n",b[l].balance);
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
			
	}
	printf("account doesnt exist");
	goto raw;
}
void logout()
{
	int srg;
	FILE *fk,*fo;
	char *encrypt;
	char *save;
	encrypt="bankdetails.txt";
	save="data.txt";
	printf("Thank You for using Net Banking mechanism\n");
	fk=fopen("bankdetails.txt","w");
	fprintf(fk,"%d\n",mm.j);
	for(srg=0;srg<mm.j;srg++)
	{
		fprintf(fk,"%d\n",b[srg].upi);
		fprintf(fk,"%d\n",b[srg].upip);
		fprintf(fk,"%ld\n",b[srg].isfc);
		fprintf(fk,"%ld\n",b[srg].acc_no);
		fprintf(fk,"%s\n",b[srg].name);
		fprintf(fk,"%d\n",b[srg].balance);
	}
	fclose(fk);
	caeser(encrypt,save);
	remove("bankdetails.txt");
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
void changepass(int ll)
{	
	int newp,oldp,bcd;
	tan:
	printf("Enter your old upi  password\n");
	scanf("%d",&oldp);
	if(b[ll].upip==oldp)
	{
		printf("Enter your new UPI  password\n");
		scanf("%d",&newp);
		b[ll].upip=newp;
		printf("Password updated\n Please Logout to see changes\n");
	}
	else
	{
	printf("Incorrect password\n");
	goto tan;
	}
	printf("Do you want to go back?(type 1)(any other key for logout)\n");//wordings
				scanf("%d",&bcd);
				if(bcd==1)
				{
					system("cls");
					display(ll);
				}
				else
					logout();
}
void Create_new_account(int pq)
{	long bp,bp1,bp2;
		//printf("Previous Account Number :%ld",b[mm.j-1].acc_no);
		bp1=b[mm.j-1].acc_no;
		bp2=b[mm.j-1].upi;
		printf("Enter the details to create a new account\n");
	printf("Enter client name:");
		scanf("%s",b[mm.j].name);
	printf("\nEnter your 4 digit number password:");
		scanf("%d",&b[mm.j].upip);
	cos:
	printf("Chose your Branch:\n1-Bengaluru East Branch/n2-Bengaluru West Branch/n3-Bengaluru North Branch/n4-Bengaluru South Branch\n");
		scanf("%d",&bp);
	switch(bp)
	{
		case 1:printf("Bengaluru East Branch\n");
			b[mm.j].isfc=100001;
			break;
		case 2:printf("Bengaluru West Branch\n");
			b[mm.j].isfc=100002;
			break;
		case 3:printf("Bengaluru North Branch\n");
			b[mm.j].isfc=100003;
			break;
		case 4:printf("Bengaluru South Branch\n");
			b[mm.j].isfc=100004;
			break;
		default:printf("Invalid choice\n");
			goto cos;
	}
		b[mm.j].acc_no = bp1  + 1;
		b[mm.j].upi=bp2+1;

	printf("\nEnter balance you want to add to account:");
		scanf("%d",&b[mm.j].balance);
	printf("\nCONGRATULATIONS!....YOUR NEW ACCOUNT IS CREATED\n");
	int abd;
		printf(" YOUR NEW ACCOUNT DETAILS ARE\n");
		printf("UPI ID:%d\n",b[mm.j].upi);
		printf("UPI password:%d\n",b[mm.j].upip);
		printf("IFSC CODE:%ld\n",b[mm.j].isfc);
		printf("ACCOUNT NUMBBER:%ld\n",b[mm.j].acc_no);
		printf("NAME:%s\n",b[mm.j].name);
		printf("ACCOUNT BALANCE:%d\n",b[mm.j].balance);
		printf(" please logout to access your new account\n");
		mm.j=mm.j+1;
		printf("Do you want to go back?(type 1)(any other key for logout)\n");//wordings
				scanf("%d",&abd);
				if(abd==1)
				{
					system("cls");
					display(pq);
				}
				else
					logout();
}

void mystruct()
{
	FILE *fp;
	int i;
	char *decrypt;
	char *save;
	decrypt="data.txt";
	save="bankdetails.txt";
	caeser(decrypt,save);
	fp=fopen("bankdetails.txt","r");
	fscanf(fp,"%d",&mm.j);
	for(i=0;i<mm.j;i++)
	{
		fscanf(fp,"%d",&b[i].upi);
		fscanf(fp,"%d",&b[i].upip);
		fscanf(fp,"%ld",&b[i].isfc);
		fscanf(fp,"%ld",&b[i].acc_no);
		fscanf(fp,"%s",b[i].name);
		fscanf(fp,"%d",&b[i].balance);
	}
	fclose(fp);
}
void bill(int unit)
{
	float amt,total_amt,tax;
	int lol,t,t1,t2,t3;
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
	
	printf("\nDo you want to pay you bill amt through net banking?\n(1 for yes ,press any other key for exit)\n");
	scanf("%d",&lol);
	if(lol==1)
	{	sin1:
		printf("Please enter UPI ID \n");
		scanf("%d",&t1);
		for(t=0;t<mm.j;t++)
		{
			if(t1==b[t].upi)
			{	
				printf("Please Enter the password\n");
				scanf("%d",&t2);
				if(t2==b[t].upip)
				{
					printf("\nWelcome %s \n\n",b[t].name);
					printf("\nDO YOU WANT TO PAY BILL?(1-yes/any other key no and exit)\n");
					scanf("%d",&t3);
					if(t3==1)
					{	
						b[t].balance=b[t].balance-total_amt;
						printf("\nBILL PAID!\nTransaction complete.....\nThank you for using our electricity bil mechanism.... \n");
						logout();
					}
					else
						exit(1);	
	
				
				}
				else
				{
				printf("Invalid credentials\n");
				exit(1);
				
				}
			}
			else if(t==mm.j-1)
			{
			system("cls");
			goto sin1;
			}
		}
	}
	else
	exit(1);
}

void caeser(char *encrypt,char *save)
{
	FILE *fp1,*fp2;
	fp1=fopen(encrypt,"r");
	fp2=fopen(save,"w");
	int i=0,key=13;
	char ch="0";
	while (ch!=EOF || ch=='.')
	 {
		ch=getc(fp1);
		//printf("%c", ch);

			if(ch>='a' && ch<='z')
			{
				key=13;
				if(ch+key>'z')
				{
					ch=ch+key-'z'+'a'-1;
					//printf("%c", ch);
				}
				else
				{
					//printf("%c",ch+key);
					ch=ch+key;
				}
			}
			else
			{
				if(ch>='A' && ch<='Z')
                				{
					key=13;
					if(ch+key>'Z')
					{
						ch=ch+key-'Z'+'A'-1;
                                					//printf("%c",ch);  
					}
                        				else
					{
						ch=ch+key;
                                					//printf("%c",ch);  
					}
				}
				else
				{
					if(ch>='0' && ch<='9')
					{
						key=5;
						if(ch+key>'9')
						{	
							ch=ch+key-'9'+'0'-1;
							//printf("%c",ch);
						}
						else
						{
							ch=ch+key;
							//printf("%c",ch);
						}
					}
					else
					{	
						//printf("%c",ch);
					}
				}
			}
			if(ch==EOF)break;	
               			putc(ch,fp2);

	}	
	fclose(fp1);
	fclose(fp2); 	

}
	
	
	