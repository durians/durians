#include <stdio.h>
#include <stdlib.h>
typedef struct _student
{
    int number;
    int d;
    int c;
}Student;

Student stu[100000];
int N, L, H;

//是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。
//凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人  
//才德全尽(圣人) >  德胜才（君子） > 才德兼亡（愚人）德胜才> 才胜德（小人）>
int compare(const void *p, const void *q)
{
    struct _student *s1, *s2;
    s1 = (struct _student *)p;
    s2 = (struct _student *)q;
    
    //才德全尽 >H  德才总分从高到低排序
    if(s1->c >= H && s1->d >= H && 
       s2->c >= H && s2->d >= H)
    {
        if( (s2->c + s2->d) == (s1->c + s1->d) )
        {
            //总分相同时，按其德分降序排列
            //若德分也并列，则按准考证号的升序输出
            if( s2->d != s1->d ) return (s2->d - s1->d);
            else  return (s1->number - s2->number);
 
        }
        return (s2->c + s2->d) - (s1->c + s1->d) ;
    }
    else if (s1->c >= H && s1->d >= H) {
        return -1;
    }
    else if (s2->c >= H && s2->d >= H) {
        return 1;
    }
    //德胜才 德>=H>才>=L 也按总分排序
    else if ( s1->d >= H && H >s1->c && s1->c >=L &&  
              s2->d >= H && H >s2->c && s2->c >=L ) 
    {
        if( (s2->c + s2->d) == (s1->c + s1->d) )
        {
            //总分相同时，按其德分降序排列
            //若德分也并列，则按准考证号的升序输出
            if( s2->d != s1->d ) return (s2->d - s1->d);
            else  return (s1->number - s2->number);
 
        }
        return (s2->c + s2->d) - (s1->c + s1->d);
    }
    else if (s1->d >= H && H >s1->c && s1->c >=L) {
        return -1;
    }
    else if (s2->d >= H && H >s2->c && s2->c >=L) {
        return 1;
    }
    //才德兼亡 德胜才 H > 德 >＝才 >= L 按总分排序
    else if (H > s1->d && s1->d >= s1->c && s1->c >= L &&
             H > s2->d && s2->d >= s2->c && s2->c >= L )
    {
        if( (s2->c + s2->d) == (s1->c + s1->d) )
        {
            //总分相同时，按其德分降序排列
            //若德分也并列，则按准考证号的升序输出
            if( s2->d != s1->d ) return (s2->d - s1->d);
            else  return (s1->number - s2->number);
 
        }
        return (s2->c + s2->d) - (s1->c + s1->d);
    }
    else if (H > s1->d && s1->d >= s1->c && s1->c >= L) {
        return -1;
    }
    else if (H > s2->d && s2->d >= s2->c && s2->c >= L) {
        return 1;
    }
    //才胜德  才 >= H > 德 >= L || H > 才 >= 德 >=L
    /*else if( ( (s1->c >=H &&  s1->c > s1->d && s1->d >= L) || 
               (H > s1->c && s1->c >= s1->d && s1->d >=L)) &&
             ( (s2->c >=H &&  s2->c > s2->d && s2->d >= L) || 
               (H > s2->c && s2->c >= s2->d && s2->d >=L)) )*/
    else if(s1->c >= L && s1->d >= L &&
            s2->c >= L && s2->d >= L )        
    {
        if( (s2->c + s2->d) == (s1->c + s1->d) )
        {
            //总分相同时，按其德分降序排列
            //若德分也并列，则按准考证号的升序输出
            if( s2->d != s1->d ) return (s2->d - s1->d);
            else  return (s1->number - s2->number);
 
        }
        return (s2->c + s2->d) - (s1->c + s1->d);
    }
    else if (s1->c >= L && s1->d >= L) {
        return -1;
    }
    else if (s2->c >= L && s2->d >= L) {
        return 1;
    }
    else 
    {
        return 0;
    }
}
int main(int argc, char *argv[]) 
{
    int i, count = 0;
    scanf("%d %d %d",&N,&L,&H);
    
    for(i = 0; i < N; i++)
    {
        scanf("%d %d %d",&stu[i].number,&stu[i].d, &stu[i].c);
    }
    
    qsort(stu,N,sizeof(stu[0]), compare);
    
    
    for(i = 0; i < N; i++)
    {
        if( stu[i].d < L || stu[i].c < L) count++;
    }
    N = N - count;
    printf("%d\n",N);
    for(i = 0; i < N; i++)
    {
        if( stu[i].d < L || stu[i].c < L) count++;
        printf("%d %d %d\n",stu[i].number,stu[i].d,stu[i].c);
    }
    
}