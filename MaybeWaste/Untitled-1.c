#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main()
{
    FILE *dict;
    dict = fopen("E:\\dict.dic","r");
	if((dict==NULL))
	{
		printf("FAILED!");
		exit(0);
	}
    char total_station[20];
    char strategy[20];
    char distance[20];
    char FCFS[20];
    char SSTF[20];
    char SCAN[20];
    strcpy(total_station,"total_station");
    strcpy(strategy,"strategy");
    strcpy(distance,"distance");
    strcpy(FCFS,"FCFS");
    strcpy(SSTF,"SSTF");
    strcpy(SCAN,"SCAN");
    char Unknown1[20];
    char Unknown2[10];
    int num_TOTAL=0;
    int num_DISTANCE=0;
	int mark1=0,mark2=0,mark3=0;
    for(int i=0;i<3;i++)
    {
        fscanf(dict,"%[^=]",Unknown1);
        if(strcmp(total_station,Unknown1)==0)
        {
            getchar();
            scanf("%d",&num_TOTAL);
			printf("%d",num_TOTAL);
			mark1=1;
        }
        else if(strcmp(strategy,Unknown1)==0)
        {
            getchar();
            scanf("%s",Unknown2);
            if(strcmp(FCFS,Unknown2))
            {
                printf("FCFS");
            }
            else if(strcmp(SSTF,Unknown2))
            {
                printf("SSTF");
            }
            else if(strcmp(SCAN,Unknown2))
            {
                printf("SCAN");
            }
			mark2=1;
        }
        else if(strcmp(distance,Unknown1))
        {
            getchar();
            scanf("%d",&num_DISTANCE);
			printf("%d",num_DISTANCE);
			mark3=1;
        }
		else
		{
			printf("XXX");
		}
    }
	if(mark1==0)
	{
		num_TOTAL=5;
	}
	if(mark2==0)
	{
		printf("FCFS");
	}
	if(mark3==0)
	{
		num_DISTANCE=2;
	}
	fclose(dict);
}