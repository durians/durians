//http://www.patest.cn/contests/mooc-ds2015spring

#include<stdio.h>
typedef struct _node
{
  int addr;
  int data;
  int next;
}Node;

Node L[100001];
Node sL[100001];

int main()
{
  int firstaddr, N, K;
  
  scanf("%d %d %d",&firstaddr, &N, &K);
  
  int i, j, s, len;
  int addr, data, next;
  
  for( i = 0; i < N; i++)
  {
    scanf("%d %d %d",&addr, &data, &next);
    L[addr].addr = addr;
    L[addr].data = data;
    L[addr].next = next;
  }
  
  for( len = 0, addr = firstaddr; addr !=-1; addr = L[addr].next)
    len++;
  
  addr = firstaddr;  
  if( len < K)
  {
    for(s = 0; s < len; s++)
      {
        sL[s].addr = addr;
        sL[s].data = L[addr].data;
        sL[s].next = -1;
            
        addr = L[addr].next;
      }
  }
  else 
  {
    for(i = 0; i + K <= len; i += K)
      {
        for(j = 1; j <= K; j++)
        {
          
          s = i + K - j;
          sL[s].addr = addr;
          sL[s].data = L[addr].data;
          sL[s].next = -1;
          
          addr = L[addr].next;
        }
      }
      for(s = i; s < len; s++)
      {
        sL[s].addr = addr;
        sL[s].data = L[addr].data;
        sL[s].next = -1;
            
        addr = L[addr].next;
      }
  }
  
  
  
  for(i = 0; i < len - 1; i++)
  {
    sL[i].next = sL[i+1].addr;
  }
  
  for(i = 0; i < len - 1; i++)
  {
    printf("%05d %d %05d\n", sL[i].addr, sL[i].data, sL[i].next);
  }
  printf("%05d %d %d\n", sL[i].addr, sL[i].data, -1);
  
  
  
  return 0;
}