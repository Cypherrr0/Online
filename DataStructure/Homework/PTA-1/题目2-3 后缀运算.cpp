#include<stdio.h>
int main()
{
	char mark[100];
	char postfix[100];
	char mid;
	int i=0;
	int j=0;
	int m=0;
	for(m=0;m<200;m++)
	{
		scanf("%c",&mid);
		if(mid=='0'||mid=='1'||mid=='2'||mid=='3'||mid=='4'||mid=='5'||mid=='6'||mid=='7'||mid=='8'||mid=='9')
		{
			postfix[i]=mid;
			i++;
		}
		else if(mid=='+'||mid=='-')
		{
			while(j>0&&mark[j-1]!='(')
			{
				postfix[i]=mark[j-1];
				mark[j]='0';
				j--;
				i++;
			}
			mark[j]=mid;
			j++;
		}
		else if(mid=='*'||mid=='/')
		{
			while(j>0&&(mark[j-1]=='*'||mark[j-1]=='/'))
			{
				postfix[i]=mark[j-1];
				mark[j]='0';
				j--;
				i++;
			}
			mark[j]=mid;
			j++;
		}
		else if(mid=='(')
		{
			mark[j]=mid;
			j++;
		}
		else if(mid==')')
		{
			while(j>0&&mark[j-1]!='(')
			{
				postfix[i]=mark[j-1];
				j--;
				mark[j]='0';
				i++;
			}
			if(mark[j-1]=='(')
			{
				j--;
				mark[j]='0';
			}
		}
		mid='P';
	}
	while(j>0)
	{
		postfix[i]=mark[j-1];
		j--;
		mark[j]='0';
		i++;
	}
	
	int k;
	float operation[100];
	int x=0;
	float A,B;
	for(k=0;k<=i;k++)
	{
		if(postfix[k]=='0'||postfix[k]=='1'||postfix[k]=='2'||postfix[k]=='3'||postfix[k]=='4'||postfix[k]=='5'||postfix[k]=='6'||postfix[k]=='7'||postfix[k]=='8'||postfix[k]=='9')
		{
			operation[x]=postfix[k]-'0';
			x++;
		}
		else
		{
			A=operation[x-2];
			B=operation[x-1];
			x--;
			x--;
			if(postfix[k]=='+')
			{
				operation[x]=A+B;
			}
			else if(postfix[k]=='-')
			{
				operation[x]=A-B;
			}
			else if(postfix[k]=='*')
			{
				operation[x]=A*B;
			}
			else if(postfix[k]=='/')
			{
				operation[x]=A/B;
			}
			x++;
		}
	}
	
	printf("%.2f\n",operation[0]);
	

	for(k=0;k<=i;k++)
	{
		printf("%c ",postfix[k]);
	}
	return 0;
}
