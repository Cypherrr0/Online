#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void Task1(FILE*dict);
void Task2(FILE*dict);
void Task3(FILE*dict);

void Task1(FILE*dict)
{
    int capital=0,lowercase=0,digit=0,others=0;
    char c;
    c=fgetc(dict);
    while(!feof(dict)) 
    {
        if(c>=97&&c<=122)
        {
            lowercase++;
        }
        else if(c>=65&&c<=90)
        {
            capital++;
        }
        else if(c>=48&&c<=57)
        {
            digit++;
        }
        else
        {
            others++;
        }
        c=fgetc(dict);
    }
    printf("Task1:\n");
    printf("capital: %d\n",capital);
    printf("lowercase: %d\n",lowercase);
    printf("digit: %d\n",digit);
    printf("others: %d\n",others);
}

void Task2(FILE*dict)
{
    int num=0,max=0,min=0,len=0;
    char c[100];
    while(fgets(c,100,dict))
    {
        len=strlen(c);
        if(num==0)
        {
            max=len;
            min=len;
        }
        if(max<len)
        {
            max=len;
        }
        if(min>len)
        {
            min=len;
        }
        num++;
    }

    printf("Task2:\n");
    printf("line: %d\n",num);
    printf("%d characters in max line.\n",max-1);
    printf("%d characters in min line.",min-1);

}

void Task3(FILE*dict)
{
    int capital[50]={0};
    int lowercase[50]={0};
    char c;
    c=fgetc(dict);
    while(!feof(dict)) 
    {
        if(c>=97&&c<=122)
        {
            lowercase[c-97]++;
        }
        else if(c>=65&&c<=90)
        {
            capital[c-65]++;
        }
        c=fgetc(dict);
    }
    int cap[27],low[27];
    for(int i=0;i<26;i++)
    {
        cap[i]=i+65;
        low[i]=i+97;
    }
    printf("Task3:\n");
    printf("CAPITAL:\n");
    for(int i=0;i<26;i++)
    {
        printf("%c:%d\n",cap[i],capital[i]);
    }
    printf("LOWERCASE:\n");
    for(int i=0;i<26;i++)
    {
        printf("%c:%d\n",low[i],lowercase[i]);
    }
}

int main()
{
    FILE*dict;
    dict = fopen("dict.dic","r");
    int n=0;
    if(dict == NULL)
    {
        printf("Error\n");
    }
    else
    {
        scanf("%d",&n);
        if(n==1)
        {
            Task1(dict);
        }
        else if(n==2)
        {
            Task2(dict);
        }
        else if(n==3)
        {
            Task3(dict);
        }
    }
    fclose(dict);
}
//D:\\CollegeStuff\\c\