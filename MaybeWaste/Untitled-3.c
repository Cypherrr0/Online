#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXN 20


bool palindrome( char *s );


int main()
{
    char s[MAXN];

    scanf("%s", s);
    if ( palindrome(s)==true )
        printf("Yes\n");
    else
        printf("No\n");
    printf("%s\n", s);
    system("pause");
    return 0;
}
bool palindrome( char *s )
{
	int length=strlen(s);
	int i;
	for(i=0;i<length;i++)
	{
		if(s[i]==s[length-1])
		{
			length--;
		}
		else
		{
			return false;
		}
	}
	if(length==i+1)
	{
		return true;
	}
}