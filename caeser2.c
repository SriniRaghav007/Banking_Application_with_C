#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
void caeserEn();

int main()
{
	caeserEn();	
}

void caeserEn()
{
	int i=0,j=0,key=13;
	char message[30] , encry[30];
	FILE *fp;
	fp=fopen("pass2.txt","r");
	fgets(message,30,fp);
	while(message[i]!='\0')
	{
		if(message[i]>='a' && message[i]<='z')
		{
			if(message[i]+key>'z')
				encry[i]=message[i]+key-'z'+'a'-1;
			else

				encry[i]=message[i]+key;
		}
		else
		{
			if(message[i]>='A' && message[i]<='Z')
                			{
				if(message[i]+key>'Z')
					encry[i]=message[i]+key-'Z'+'A'-1;
                        			else
					encry[i]=message[i]+key;
			}
			else
			{
				if(message[i]>='0' && message[i]<='9')
				{
					if(message[i]+key>'9')
						encry[i]=message[i]+key-'9'+'0'-1;

					else
						encry[i]=message[i]+key;
				}
				else	
					encry[i]=message[i];
			}
                }

		i++;
	}
	printf("\n");
	i=0;
	while(encry[i]!='\0')
	{
		printf("%c",encry[i]);
		i++;
	}
}
