
#include<stdio.h>
#include<string.h>
 
int recog_pwd(char name[20],char pwd[20]);
int main()
{
	int isok;
	char *name = "asd";
	char *pwd = "123";
	if((recog_pwd(name,pwd))==1)
	{
		printf("user and pwd right\n");
	}else printf("user not exist or password is wrong\n");
 
}
int recog_pwd(char name[20],char pwd[20])
{
	int s;
    FILE *fp1;//ÎÄ¼şÖ¸Õë
    char str[20];
	/* 
	*ä»¥åªè¯»æ–¹å¼æ‰“å¼€æ–‡ä»¶
	*read.txtæ ¼å¼ä¸º ï¼šç”¨æˆ·å å¯†ç  ï¼ˆä¸­é—´æœ‰ä¸€ç©ºæ ¼ï¼‰æ— é™å¾ªç¯
	*/
    if ((fp1=fopen("G:\\Èí¼ş¹¤³Ì\\ÊµÑéÒ»\\read.txt","r"))==NULL)
    {	
        printf("cannot open file\n");
        return 0;
     }
	while(!feof(fp1))//ÎÄ¼ş½áÊø£º·µ»Ø·Ç0Öµ£»ÎÄ¼şÎ´½áÊø£º·µ»Ø0Öµ
	{
		fscanf(fp1,"%s",str);
		
		if(strcmp(str,name)==0)
		{
			printf("the name :%s is ok\n",name);
			printf("%s",name);
			fscanf(fp1,"%s",str);
			if(strcmp(str,pwd)==0)
			{
				printf("the pwd :%s is ok\n",pwd);
				return 1;
			}else
			{
				printf("the pwd :%s is wrong\n",pwd);
				fclose(fp1);
				return 0;
			}
				
		}
	fscanf(fp1,"%s",str);
		
	}
	fclose(fp1);
    return 0;
 
}
