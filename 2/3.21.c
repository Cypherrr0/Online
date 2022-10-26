#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct data{
    int userid;
    int movieid;
}DATA[10000];

void FINDMovies(int movieid);
void PrintResults();

void FINDMovies(int movieid)
{
    char id[100];
    char waste1[100];
    char title[100];
    char waste2[100];
    char genre[100];
    char known[0][100]='Action';
    known[1][100]='Adventure';
    known[2][100]='Animation';
    known[3][100]='Children';
    known[4][100]='Comedy';
    known[5][100]='Crime';
    known[6][100]='Documentary';
    known[7][100]='Drama';
    known[8][100]='Fantasy';
    known[9][100]='Film-Noir';
    known[10][100]='Horror';
    known[11][100]='IMAX';
    known[12][100]='Musical';
    known[13][100]='Mystery';
    known[14][100]='Romance';
    known[15][100]='Sci-Fi';
    known[16][100]='Thriller';
    known[17][100]='War';
    known[18][100]='Western';
    int judge;

    int Action; 
    int Adventure;
    int Animation;
    int Children;
    int Comedy;
    int Crime;
    int Documentary;
    int Drama;
    int Fantasy;
    int Film;   //Film-Noir
    int Horror;
    int IMAX;
    int Musical;
    int Mystery;
    int Romance;
    int Sci;
    int Thriller;
    int War;
    int Western;

    char WASTE[100000];
    FILE *movie;
    movie=fopen("D:\\CollegeStuff\\c\\ml-latest-small\\movies.csv","r");
    int count=0;
    while(!feof(movie)&&count<movieid-1)
    {
        fscanf(movie, "%s",WASTE);
        count++;
    }
    fscanf(movie,"%[^,]%s,%c,%[^,]%s,%c",id,waste1,title,waste2);
    fscanf(movie, "%[^|]%s",genre);
    fscanf(movie, "%c",WASTE);
    while(1)
    {
        for(int i=0;i<19;i++)
        {
            judge=strcmp(known[i],genre);
            {
                if(judge==0)
                {
                    if(i==0)
                    {
                        Action++;
                    }
                    else if(i==1)
                    {
                        Adventure++;
                    }
                    else if(i==2)
                    {
                        Animation++;
                    }
                    else if(i==3)
                    {
                        Children++;
                    }
                    else if(i==4)
                    {
                        Comedy++;
                    }
                    else if(i==5)
                    {
                        Crime++;
                    }
                    else if(i==6)
                    {
                        Documentary++;
                    }
                    else if(i==7)
                    {
                        Drama++;
                    }
                    else if(i==8)
                    {
                        Fantasy++;
                    }
                    else if(i==9)
                    {
                        Film++;
                    }
                    else if(i==10)
                    {
                        Horror++;
                    }
                    else if(i==11)
                    {
                        IMAX++;
                    }
                    else if(i==12)
                    {
                        Musical++;
                    }
                    else if(i==13)
                    {
                        Mystery++;
                    }
                    else if(i==14)
                    {
                        Romance++;
                    }
                    else if(i==15)
                    {
                        Sci++;
                    }
                    else if(i==16)
                    {
                        Thriller++;
                    }
                    else if(i==17)
                    {
                        War++;
                    }
                    else if(i==18)
                    {
                        Western++;
                    }
                }
            }
        }
        if((fscanf(movie,"%[^|]%s",genre)))
        {
            fscanf(movie,"%c",WASTE);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    int line=1,usercount=1;
    int count=0;
    int temp1=0,temp2=0;
    char W;
    FILE *user;
    user=fopen("D:\\CollegeStuff\\c\\ml-latest-small\\ratings","r");
    if(!user)
    {
        printf("ERROR");
        return 1;
    }
    while(!feof(user))
    {
        fscanf(user,"%d,%d,%d",&count,&temp1,&temp2,&);
        if(count==usercount)
        {
            if(temp2>3)
            {
                temp1=DATA[usercount].movieid;
                FINDMovies(DATA[usercount].movieid);
            }
        }
        else
        {
            usercount++;
            DATA[usercount].userid=count;
            if(temp2>3)
            {

            }
        }
    }
}