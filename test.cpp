
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
    FILE *fp1;//�ļ�ָ��
    char str[20];
	/* 
	*以只读方式打开文件
	*read.txt格式为 ：用户名 密码 （中间有一空格）无限循环
	*/
    if ((fp1=fopen("G:\\�������\\ʵ��һ\\read.txt","r"))==NULL)
    {	
        printf("cannot open file\n");
        return 0;
     }
	while(!feof(fp1))//�ļ����������ط�0ֵ���ļ�δ����������0ֵ
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
