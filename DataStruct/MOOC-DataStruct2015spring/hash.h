//
//  hash.h
//  
//
//  Created by durians on 15/5/26.
//
//

#ifndef ____hash__
#define ____hash__

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

#endif /* defined(____hash__) */
