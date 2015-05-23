//http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=393



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    char name[10];
    struct _node *next;
    int count;
}Hash;

#define M  (10000)
Hash h[M];

unsigned int hashCode(char s[])
{
    unsigned int h = 0, i;
    
    for( i = 0; i < strlen(s); i++)
    {
        h = (h << 5) | (h >> 27);
        h += (int)s[i];
    }
    return h;
}

struct _node *hashFind(char *str)
{
    unsigned int key = hashCode(str) % M;
    struct _node *p = h[key].next;
    
    while(p && (0 != strcmp(p->name, str)) )
        p = p->next;
    
    return p;
}

void hashAdd(struct _node *s)
{
    unsigned int key = hashCode(s->name) % M;
    s->next = h[key].next;
    h[key].next = s;
}


int main(int argc, char *argv[])
{
    
    struct _node *s = NULL, *max = NULL;
    
    int n;
    char str[10] = {0};
    scanf("%d", &n);
    while(n--)
    {
        scanf("%s", str);
        s = hashFind(str);
        if(s)
        {
            s->count++;
        }
        else
        {
            s = (struct _node*)malloc(sizeof(struct _node));
            strncpy(s->name, str,10);
            s->count = 1;
            hashAdd(s);
        }
        if(!max || max->count < s->count)
            max = s;
    }
    printf("%s %d\n",max->name,max->count);
    
    return 0;
}