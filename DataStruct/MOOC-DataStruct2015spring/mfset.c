//
//  mfset.c
//
//  数据类型：
//  结构（关系）：
//      集合（双亲树表示）
//      parent[N];
//  操作：
//      initial(&S) //构造n个集合，每个集合仅含单个元素
//      find(S,v)   //查询v所属的集合
//      merge(&S,vi,vj)
//
//
//  Created by durians on 15/5/31.
//
//
#define N   1000

//集合
//parent[N]
//  －1  初始值,树的根结点，表示即集合i
//   0   表示空集合
//   >0  表示i属于集合parent[i]
//   <0  表示i是根，集合i有－parent[i]个元素
int parent[N];

void initial()
{
    int i;
    for(i = 0; i < N; i++)
        parent[i] = -1;
}

int find(int v)
{
    if(parent[v] > 0)//压缩路径
        return parent[v] = find(parent[v]);
    else//parent[v] < 0, v为根结点,即集合v
        return v;
}


void merge(int vi, int vj)
{
    int si = find(vi);
    int sj = find(vj);
    
    if(parent[si] <= parent[sj])
    {
        //sj < si
        //si = si U sj
        parent[si] += parent[sj];
        parent[sj] = si;
    }
    else
    {
        parent[sj] += parent[si];
        parent[si] = sj;
    }
}





