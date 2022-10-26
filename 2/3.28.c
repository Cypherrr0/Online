#include<stdio.h>
#include<stdlib.h>
main()
{
    FILE *fp=fopen("D:\\CollegeStuff\\c","r+");
    if(fp==NULL)
    {
        printf("Failed to open\n");
        exit(1);
        fseek(fp,2,SEEK_END);
        fwrite("ddd",1,3,fp);
        fclose(fp);
        return 0;
    }
}