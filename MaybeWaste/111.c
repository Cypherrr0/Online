#include<stdio.h>
#include<math.h>
int main()
{
	int a=0,b=0,count=0,sum=0,mark=3;
	scanf("%d%d",&a,&b);
	for(int i=a;i<=b;i++)
	{
		sum+=i;
		count++;
		if(i>=0)
		{
			printf("    %d",i);
		}
		else
		{
			printf("   %d",i);
			mark--;
		}
		if(count%5==0)
		{
			printf("\n");
			mark=3;
		}
        else if(i==b)
        {
            printf("\n");
        }
	}
	printf("Sum = %d",sum);
}

