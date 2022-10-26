#include<stdio.h>
#define START 0
#define GET1 1
#define GET0 2
#define END 3

main()
{
    char signal;
    int vehicles,seconds,interval,longest;
    int state;
	
    state=START;
    vehicles=0; seconds=0;longest=0;
    printf("input signals,'#'to end:\n");
    while(state!=END){
    signal=getchar();
        switch(state){
        case START:/*若当前状态是初始状态，则只是简单的对时钟数或者车辆数加1*/
            switch(signal){
    case '1': vehicles++;
            state=GET1; /*状态迁移到1*/
        break;
    case '0':
        seconds++;
        state=GET0;
        break;		
    case '#':
        state=END;	 	
        break;	 		  
    }				    
        break;
        case GET1:/*若当前状态是q1，即上一个信号是'1'*/
        switch(signal){
        case '1': /*当前读入信号是'1'，则只是简单将车辆加1*/ 
        vehicles++;
        break;
        case '0': /*前信号是'0'，则要开始计数两个1之间的时钟间隔interval*/ 
        seconds++;
        interval=1;/*开始计数interval*/
        state=GET0;
        break;	
        case '#':
        state=END;	 	
        break;	 		  
    }		
            break;
    case GET0:	/*若当前状态是q2，即上一个信号是'0'*/
        switch(signal){
            case '0': /*当前读入信号是'0',则需要判断是否要将interval加1*/ 
    seconds++;
    if(interval>0)  /*interval>0,表示状态是从状态1转移到状态2的， 	                         所以interval需要继续加1*/
            interval++;
            break;
            case '1': /*当前读入信号是'1',需要判断是否要处理最长时间间隔*/ 
            vehicles++;
                if (interval>0)/*interval>0,表示状态是从状态q1转移到状态q2的，所以		在状态迁移回q1之前需要处理最大时间间隔*/
        if(interval>longest)
            longest=interval;
        interval=0;
        state=GET1;
        break;	
        case '#':state=END;	 break;
    }
    

        }/*switch*/         
    }/*while*/
    
    printf("%d vehicles passed in %d seconds\n",vehicles,seconds);
    printf("the longest gap was %d  seconds\n",longest);

    return 0; 	 

}


