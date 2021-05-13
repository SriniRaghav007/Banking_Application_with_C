#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
void caeseren();

/*
int main()
{
	int key,choice;
	char *filename,keychoice;

	for(;;)
	{
		printf("\n \n \n \n");
		printf("---------------------------------------------------------------------------------\n\n");
		printf("Welcome to the Caeser Cipher Encrypter/Decrypter\n");
		printf("Choose any of the following options\n 1.Encrypt\n 2.Decrypt\n 3.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1 :printf("Enter your filename\n");
				scanf("%s",filename);
				printf("Enter your key\n");
                                scanf("%d",&key);
				caeser(filename,key);
				break;

			case 2 : printf("Enter your filename\n");
                                scanf("%s",filename);
				printf("Do you know the key?(Y/N)\n");
				scanf(" %c",&keychoice);
				if(keychoice=='Y')
				{
                                	printf("Enter your key\n");
                                	scanf("%d",&key);
					printf("All possible combinations are:\n");
                                	caeser(filename,key);
				}
				else
				{
					printf("All possible combinations are:\n");
					for(int i=0;i<27;i++)
						caeser(filename,i);
                                	break;
				}
				break;
			case 3 : exit(1);
				break;
			default : 	system("clear");
					printf("Wrong input\n");
		}
	}
}
*/

int main()
{
	caeseren(3);
}
void caeseren(int nooflines)
{
	int i=0,j=0;
	int key=13;
	char message[30];
	FILE *fp;
	fp=fopen("file3.txt","r");
	for(j=0;j<nooflines;j++)
	{
	
	fgets(message,100,fp);
	while(message[i]!='\0')
	{
		if(message[i]>='a' && message[i]<='z')
		{
			if(message[i]+key>'z')
				printf("%c",message[i]+key-'z'+'a'-1);
			else
				printf("%c",message[i]+key);
		}
		else
		{
			if(message[i]>='A' && message[i]<='Z')
                			{
				if(message[i]+key>'Z')	
					printf("%c",message[i]+key-'Z'+'A'-1);
                        			else
                                				printf("%c",message[i]+key);
			}
			else
			{
				if(message[i]>='0' && message[i]<='9')
				{
					if(message[i]+key>'9')
						printf("%c",message[i]+key-'9'+'0'-1);
					else
						printf("%c",message[i]+key);
				}
				else
					printf("%c",message[i]);
			}
                		}
		i++;
	}
	
	}
	fclose(fp);
}

void caeserde()
{
	int i=0;
	int key=13;
	char message[30];
	FILE *fp;
	fp=fopen("file3.txt","r");
	fgets(message,30,fp);
	while(message[i]!='\0')
	{
		if(message[i]>='a' && message[i]<='z')
		{
			if(message[i]+key>'z')
				printf("%c",message[i]+key-'z'+'a'-1);
			else
				printf("%c",message[i]+key);
		}
		else
		{
			if(message[i]>='A' && message[i]<='Z')
                	{
				if(message[i]+key>'Z')
                                	printf("%c",message[i]+key-'Z'+'A'-1);
                        	else
                                	printf("%c",message[i]+key);
			}
			else
			{
				if(message[i]>='0' && message[i]<='9')
				{
					if(message[i]+key>'9')
						printf("%c",message[i]+key-'9'+'0'-1);
					else
						printf("%c",message[i]+key);
				}
				else
					printf("%c",message[i]);
			}
                }

		i++;
	}
	printf("\n");
}
