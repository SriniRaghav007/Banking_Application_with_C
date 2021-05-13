#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void usercreate(char username[30],char password[30]);

int main()
{
	char username[30] , password[30];
	printf("Enter Username: ");
	scanf("%s",&username);
	printf("Enter password: ");
	scanf("%s",&password);
	usercreate(username,password);
}

void usercreate(char username[30] ,char password[30])
{
	FILE *fp;
	fp=fopen("data.txt","a");
	fputs(username,fp);
	fputs(" ",fp);
	fputs(password,fp);
	printf("Account successfully created");
}
