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


