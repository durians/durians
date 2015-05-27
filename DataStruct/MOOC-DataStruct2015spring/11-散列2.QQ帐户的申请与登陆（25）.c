//
//  11-散列2.c
//
//
//  Created by durians on 15/5/26.
//
//
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N (100000)
typedef struct _account{
    int account;
    char pwd[17];
    struct _account *next;
}Account;

Account *H[N] = {0};

void hashAdd(Account e)
{
    Account *p = (Account *)malloc(sizeof(Account));
    
    p->account = e.account;
    strcpy(p->pwd,e.pwd);
    p->next = H[e.account % N];
    H[e.account % N] = p;
}

int hashFind(Account e)
{
    for(Account *p = H[e.account % N];
        p!=NULL;
        p = p->next)
    {
        if(p->account == e.account)
        {
            if(0 == strcmp(p->pwd,e.pwd))
                return 1;
            else
                return -1;
        }
    }
    
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        char op;
        Account e;
        int status;
        
        while((op = getchar()) && op != 'L' && op != 'N');
        scanf("%d %s", &e.account, e.pwd),e.next = NULL;
        
        if(op == 'L')
        {
            if(0 == ( status = hashFind(e)) )
            {
                printf("ERROR: Not Exist\n");
            }
            else if(-1 == status)
            {
                printf("ERROR: Wrong PW\n");
            }
            else
            {
                printf("Login: OK\n");
            }
        }
        else // N
        {
            if(hashFind(e) > 0)
                printf("ERROR: Exist\n");
            else
            {
                printf("New: OK\n");
                hashAdd(e);
            }
        }
    }
}