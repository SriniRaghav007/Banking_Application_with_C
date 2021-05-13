#include <stdio.h>
#include <stdlib.h>
void caeser(FILE *encrypt,FILE *save);
int main(void)
{
	FILE *fp1,*fp2,*fp3;
	char ch="0",choice;
	int i=0,key=13;
 
	fp1 = fopen("pass2.txt", "r");
	fp2 = fopen("pass3.txt", "w");
	fp3=fopen("pass4.txt","w");
	caeser(fp1,fp2);
	printf("do you want toDecrypt");
	scanf("%c",choice);
	fclose(fp2);
	if(choice == 'Y' || choice=='y')
		fp2 = fopen("pass3.txt", "r");
		caeser(fp2,fp3);
		
}
void caeser(FILE *encrypt,FILE *save)
{
	int i=0,key=13;
	char ch=NULL;
	while (ch!=EOF)
	 {
		ch=getc(encrypt);
		//printf("%c", ch);

			if(ch>='a' && ch<='z')
			{
				key=13;
				if(ch+key>'z')
				{
					ch=ch+key-'z'+'a'-1;
					printf("%c", ch);
				}
				else
				{
					printf("%c",ch+key);
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
                                					printf("%c",ch);  
					}
                        				else
					{
						ch=ch+key;
                                					printf("%c",ch);  
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
							printf("%c",ch);
						}
						else
						{
							ch=ch+key;
							printf("%c",ch);
						}
					}
					else
					{	
						printf("%c",ch);
					}
				}
			}
			
               		putc(ch,save);
	
	}	
	fclose(encrypt);
	fclose(save); 	

}
