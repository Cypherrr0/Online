#include<stdio.h>
#include<stdlib.h>

int xxx;
int fuck(int gg);

int fuck(int gg)
{
    for(int i = 0; i <3;i++)
    {
        gg++;
    }
    for(int i = 0; i <3;i++)
    {
        gg--;
    }
    return gg;
}
int main()
{
    char a,aa[5];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int i;
    int x;
    scanf("%d",&x);
    x=fuck(x);
    FILE*dict;
    dict = fopen("dict.dic","rb");
    memset(aa,0,5);
    memset(bb,0,5);
    memset(cc,0,5);
    memset(dd,0,5);
    memset(ee,0,5);
    memset(hh,0,5);
    memset(gg,0,5);
    while(--x)
    {
        fread(&a,sizeof(a),1,dict);
        fread(&b,sizeof(b),1,dict);
        fread(&c,sizeof(c),1,dict);
        fread(&d,sizeof(d),1,dict);
        fread(&e,sizeof(e),1,dict);
        fread(&g,sizeof(g),1,dict);
        fread(&h,sizeof(h),1,dict);
        fread(aa,sizeof(a),5,dict);
        fread(bb,sizeof(b),5,dict);
        fread(cc,sizeof(c),5,dict);
        fread(dd,sizeof(d),5,dict);
        fread(ee,sizeof(e),5,dict);
        fread(gg,sizeof(g),5,dict);
        fread(hh,sizeof(h),5,dict);
        memset(aa,0,5);
    }
    fread(&a,sizeof(a),1,dict);
    fread(&b,sizeof(b),1,dict);
    fread(&c,sizeof(c),1,dict);
    fread(&d,sizeof(d),1,dict);
    fread(&e,sizeof(e),1,dict);
    fread(&g,sizeof(g),1,dict);
    fread(&h,sizeof(h),1,dict);
    fread(aa,sizeof(a),5,dict);
    fread(bb,sizeof(b),5,dict);
    fread(cc,sizeof(c),5,dict);
    fread(dd,sizeof(d),5,dict);
    fread(ee,sizeof(e),5,dict);
    fread(gg,sizeof(g),5,dict);
    fread(hh,sizeof(h),5,dict);
    printf("%c\n",a);
    printf("%hd\n",b);
    printf("%d\n",c);
    printf("%ld\n",d);
    printf("%lld\n",e);
    printf("%f\n",g);
    printf("%lf\n",h);
    printf("%s\n",aa);
    printf("%hd ",bb[0]);
    printf("%hd ",bb[1]);
    printf("%hd ",bb[2]);
    printf("%hd ",bb[3]);
    printf("%hd ",bb[4]);
    printf("%d ",cc[0]);
    printf("%d ",cc[1]);
    printf("%d ",cc[2]);
    printf("%d ",cc[3]);
    printf("%d ",cc[4]);
    printf("%ld ",dd[0]);
    printf("%ld ",dd[1]);
    printf("%ld ",dd[2]);
    printf("%ld ",dd[3]);
    printf("%ld ",dd[4]);
    printf("%lld ",ee[0]);
    printf("%lld ",ee[1]);
    printf("%lld ",ee[2]);
    printf("%lld ",ee[3]);
    printf("%lld ",ee[4]);
    printf("%f ",gg[0]);
    printf("%f ",gg[1]);
    printf("%f ",gg[2]);
    printf("%f ",gg[3]);
    printf("%f ",gg[4]);
    printf("%lf ",hh[0]);
    printf("%lf ",hh[1]);
    printf("%lf ",hh[2]);
    printf("%lf ",hh[3]);
    printf("%lf ",hh[4]);
    fclose(dict);
}