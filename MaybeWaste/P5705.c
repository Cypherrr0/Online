#include<stdio.h>
#include<string.h>
int main()
{
    char a[1000];
    scanf("%s",&a);
    getchar();
    int b=strlen(a);
    for(int i=b-1; i>=0; i--)
    {
        printf("%c",a[i]);
    }
}