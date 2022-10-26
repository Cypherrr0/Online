#include<stdio.h>
int main()
{
    char c;
    int num;
    scanf("%d", &num);
    while(getchar() != '\n');  //来清除scanf缓存中的垃圾数据
    int i=0;//count表示A分别在几个位置 的数量
    for(i=0;i<num;i++)
    {
        int pos=0,count[3]={0,0,0};//,count[3]={0,0,0}不能放上面
        while((c=getchar())!='\n')
        {
            if(c=='A') count[pos]++;
            else if(c=='P'&&pos==0) pos=1;
            else if(c=='T'&&pos==1) pos=2;
            else break;
        }        
        if(c=='\n'&&pos==2&&count[1]&&count[2]==count[1]*count[0])
            printf("YES\n");        //也可以用puts("YES");自带换行符
        else  
            printf("NO\n");        //也可以用puts("YES");自带换行符
        if(c!='\n')
            while(getchar()!='\n');   //来清除getchar缓存中的垃圾数据
    }    
    return 0;
}