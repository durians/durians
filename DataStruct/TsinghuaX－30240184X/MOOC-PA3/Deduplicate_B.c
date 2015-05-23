#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _node
{
    char value[41];
    struct _node *next;
    int outed;
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
    
    while(p && (0 != strcmp(p->value, str)) )
        p = p->next;
    
    return p;
}

void hashAdd(struct _node *s)
{
    unsigned int key = hashCode(s->value) % M;
    s->next = h[key].next;
    h[key].next = s;
}

int main(int argc, char *argv[])
{
    char str[41] = {0};
    int n;
    struct _node *find, *s;
    
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%s", str);
        
        find = hashFind(str);
        if (find && !find->outed) {
            find->outed = 1;
            printf("%s\n", str);
        }else if(!find){
            s = (struct _node*)malloc(sizeof(struct _node));
            strcpy(s->value, str);
            s->outed = 0;
            hashAdd(s);
        }
    }
    
    return 0;
}