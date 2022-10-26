#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *dict;
    dict = fopen("dict.dic","rb");
    int n;
    scanf("%d",&n);

    int a;
    char b[10];
    char c[10];
    char d[50];

    int waste1;
    char waste2[10];
    char waste3[10];
    char waste4[50];

    int x=n-1;

    for(int i=0; i<x; i++)
    {
        fscanf(dict,"%d",&waste1);
        fscanf(dict,"%s",waste2);
        fscanf(dict,"%s",waste3);
        fscanf(dict,"%s",waste4);
    }
    
        fscanf(dict,"%d",&a);
        fscanf(dict,"%s",b);
        fscanf(dict,"%s",c);
        fscanf(dict,"%s",d);
    
    printf("%d\n",a);
    printf("%s\n",b);
    printf("%s\n",c);
    printf("%s\n",d);
    fclose(dict);
}
//D:\\CollegeStuff\\dict.dic