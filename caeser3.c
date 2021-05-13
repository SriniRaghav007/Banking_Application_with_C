#include <stdio.h>
#include <stdlib.h>
void caeser(char *encrypt,char *save);
int main(void)
{
	char *file1;
	char *file2;
	char *file3;
	file1="bankdetails.txt";
	file2="data.txt";
	file3="bankdetails.txt";
	caeser(file1,file2);
	caeser(file2,file3);
		
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
			if(ch==EOF)break;	
               			putc(ch,fp2);

	}	
	fclose(fp1);
	fclose(fp2); 	

}
