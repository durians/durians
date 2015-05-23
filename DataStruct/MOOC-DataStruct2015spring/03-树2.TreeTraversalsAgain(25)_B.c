#include <stdio.h>

int preOrder[];
int inOrder[];
int postOrder[];

//  先序遍历：DL......R......
//  中序遍历：...L...D...R...
//  后序遍历：......L......RD
void slove(int preI, int inI, int postI, int n)
{
    if(n == 0) return ;
    if(n == 1){postOrder[postI] = preOrder[preI]; return;}
    
    //root
    int root = postOrder[postI + n - 1] = preOrder[preI];
    
    int i = inI;
    while(inOrder[i] != root)
        i++;                            
    
    //L  pre:preI+1        in:inI   post:postI            len:i-inI  
    //R  pre:preI+1+i-inI  in:i+1   post:postI + i - inI  len:n - i + inI - 1
    slove(preI+1, inI, postI, i-inI);
    slove(preI+1+i-inI, i + 1, postI + i - inI, n - i + inI - 1);
     
     
}