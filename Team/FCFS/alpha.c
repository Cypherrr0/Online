#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    FILE *dict;
    dict = fopen("E:\\dict.txt","r");
    char FCFS[20];
    char SSTF[20];
    char SCAN[20];
    char what[20];
    char UnknownSTRA[20];
    char STRATEGY[20];
    strcpy(FCFS,"FCFS");
    strcpy(SSTF,"SSTF");
    strcpy(SCAN,"SCAN");
	if((dict==NULL))
	{
		printf("FAILED!");
		exit(0);
	}
    char temp;
    int mark;
    int num_TOTAL=5,num_DISTANCE=2;
    while(temp=fgetc(dict),temp!=EOF)
    {
        if(temp=='T')
        {
            while(fgetc(dict)!='=')
            {
                mark=0;
            }
            fscanf(dict,"%d",&num_TOTAL);

        }
        else if(temp=='D')
        {
            while(fgetc(dict)!='=')
            {
                mark=0;
            }
            fscanf(dict,"%d",&num_DISTANCE);

        }
        else if(temp=='S')
        {
            while(fgetc(dict)!='=')
            {
                mark=0;
            }
            fscanf(dict,"%s",UnknownSTRA);
            if(strcmp(FCFS,UnknownSTRA)==0)
            {
                strcpy(STRATEGY,FCFS);
            }
            else if(strcmp(SSTF,UnknownSTRA)==0)
            {
                strcpy(STRATEGY,SSTF);
            }
            else if(strcmp(SCAN,UnknownSTRA)==0)
            {
                strcpy(STRATEGY,SCAN);
            }

        }
        else
        {
            while(temp=fgetc(dict),temp!='\n')
            {
                mark=0;
            }
        }
    }
    printf("TOTAL_STATION:%d\n",num_TOTAL);
    printf("DISTANCE:%d\n",num_DISTANCE);
    printf("STRATEGY:%s\n",STRATEGY);
	fclose(dict);
}