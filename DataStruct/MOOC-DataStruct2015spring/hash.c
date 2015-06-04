//
//  hash.c
//  
//
//  Created by durians on 15/5/26.
//
//

#include <stdio.h>

#define HASH_SIZE   (1000)

typedef struct _strhash
{
    char *str;
}StrHash[HASH_SIZE];

int StrHashCode(char *str);
extern void StrHashAdd(char *str);
extern int StrHashRemove(char *str);
extern int StrHashSearch(char *str);
