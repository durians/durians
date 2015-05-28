#数据结构





##线性结构

* 向量
* 列表
* 栈
* 队列 
* 串


##树结构

* 动机
		
		1.树可以表示层次关系
			表达式
			文件系统
			URL
			... ...
		
		2.树能兼顾高效的操作
			查找
			插入、删除
				
* 树存储

		1.父亲
		typedef struct PTNode
		{
			int data;
			int parent;
		}PTNode;
		
		typedef struct PTree
		{
			PTNode nodes[MAX_TREE_SIZE];
			int r;		//根的位置
			int n;		//结点数
		}PTree;
		
		适合找parent操作，eg: 并查集
		
		2.孩子
		
		
		3.父亲＋孩子
		
		4.长子＋兄弟
			树通过长子兄弟方式可转成二叉树
		
	
* 二叉树存储

		1.顺序存储
		适合：完全二叉树、满二叉树存储.一般二叉树,浪费空间。
		特点：结点i父亲为i/2,左孩子2i，右孩子2i+1
		
		2.链式存储
		typedef struct BiTNode
		{
			struct vnode* left;
			struct vnode* right;
			int data;
			//...
		}BiTNode,*BiTree;

		
* 遍历

	[习题1][树1]－[树的层次遍历][树1AC] 
	
	[习题2][树2]－[树的先序中序：求后序][树2AC]
			[同类题][THU2-3]
	
	[习题3][PA2-3]－[树的先序后序：求真二叉树中序][PA2-3AC]
	
		先序遍历 PreOrderTraversal
		中序遍历 InOrderTraversal
		后序遍历 PostOrderTraversal
		可以递归实现
		
		也可以非递归而用栈实现
		入栈顺序为先序，岀栈顺序为中序
		
		层次遍历 LevelOrderTraversal
		用队列实现
		
* 二叉搜索树（BST，Binary Search Tree）
[习题1][树5]－[建完全二叉搜索树][树5AC]
[习题2][树4]－[二叉搜索序列][树4AC]

		BST定义：
		1. 左子树 < 根结点
		2. 右子树 > 根结点
		3. 左、右子树都是BST树

* 平衡二叉树（AVL）		
[习题][树3]－[Root of AVL Tree][树3AC]

		由于BST可能高度过深退化成单链，引入平衡限制：
		1. 是BST树
		2. 且左右子树高度差绝对值不超过1，|Hl- Hr| <= 1

		平衡调整策略：
		LL、LR、RR、RL
		
* 堆
	
	* [堆实现优先队列][heap.c]
	* [堆排序][heapsort.c]
	* [习题1][树6]－[建最小堆][树6AC]
	* [习题2][poj 2431]－[最大堆运用][2431AC]  
	* [习题3][poj 3253]－[最小堆运用][3253AC]
	* [习题4][PA4-1]－[任务调度][PA4-1AC]

	1. 优先队列（Priority Queue）定义 
			
			push  按优先级序列插入
			pop   删除优先级最高的元素
			top   查看优先级最高的元素
			
			C++ STL里有priority_queue
		
	2. 堆的定义
		
			  大堆：k[i] >= k[2*i]  k[i] >= k[2*i+1]
			  小堆：k[i] <= k[2*i]  k[i] <= k[2*i+1]
			  i = 1,2,...,n/2
			  
			  逻辑结构：完全二叉树结构
			  存储结构：顺序存储
			  
			  操作：
			  pushHeap  按优先级序列插入
			  popHeap   删除优先级最高的元素
			  topHeap   查看优先级最高的元素
	
	3. 堆实现优先队列
					
			操作系统按优先级调度算法(大堆)
			Huffman编码算法（小堆）
			
		
* ￼￼哈夫曼树（Huffman Tree）
[习题][树8]－[Huffman Codes][树8AC]

		1.定义：
		带权路径（WPL，Weighted Path Length of Tree）最小的树，
		即最优二叉树
		
		typedef struct BiTNode
		{
			int weight;
			struct BiTNode* left, right;
		} BiTNode,*BiTree, *HuffmanTree;
		
		2.构建方法：
		找权值最小的两个子二叉树合并, 如何找最小的两个呢？堆！
		
		
		3.哈夫曼编码，不等长编码二义性避免
		前缀码，任何字符的编码都不是另一字符编码的前缀。
		
* 并查集
[习题][树7]－[并查集练习][树7AC]

		1.存储：
		集合，森林结构，树根Root带表一个集合。双亲表示法，数组存储。
		
		typedef struct MFSet
		{
			//parent
			// > 0  代表父结点
			// = 0  代表空集
			// < 0  代表根结点，负数表示该集合的元素个数
			int parent;
			int data;
		} MFSet[N];
		
		＃并
		只需把一个集合的parent设为另一集合的Root即可
		
		# 查: 查找某个元素所在的集合（根结点Root）		

##图































**自我要求**

> * 理解各基础数据结构
> 
> ![Abstrac Data Type](res/ADT.png)
> 
> * 分别用C、C++语言实现各数据结构
> 
>   实现的算法、代码中犯过的错
> 
> * 使用各数据结构完成一定量的OJ题	
> 



**参考**

> 严蔚敏教材
> 
> [清华大学 邓俊辉 TsinghuaX: 30240184X 数据结构(2015春)]
> 
> [浙江大学 陈越、何钦铭 数据结构] － [PAT作业]
> 
> [在线演示]，[C++示例]，[清华大学OJ]，[PAT OJ]



**感受**
>
> * C没有&，表达起来真麻烦，每次都用指针，真是受够了。C++用& 代码就简洁多了。
> 
> * 我习惯的C命名规范:
> 	
> 		1.结构体使用帕斯卡命名法
> 		2.而函数、变量使用骆驼命名法
> 
> 		#### 清华大学校长留给毕业生的五句话
















##OJ

静态链表：
[Reversing Linked List](MOOC-DataStruct2015spring/02-线性结构2.ReversingLinkedList.c)

双链表：
[祖玛(Zuma)](TsinghuaX－30240184X/MOOC-PA1/Zuma.c)

排序＋二分查找：
[范围查询(Range)](TsinghuaX－30240184X/MOOC-PA1/range_A.c)

排序＋求逆序数
[灯塔(LightHouse)](TsinghuaX－30240184X/MOOC-PA1/LightHouse.c)

栈的次序
[列车调度(Train)](TsinghuaX－30240184X/MOOC-PA2/Train.c)
[Pop Sequence](MOOC-DataStruct2015spring/02-线性结构3.PopSequence.c.c)


[树1]:http://www.patest.cn/contests/mooc-ds2015spring/03-树1
[树1AC]:MOOC-DataStruct2015spring/03-树1.ListLeaves(25).c

[树2]:http://www.patest.cn/contests/mooc-ds2015spring/03-树2
[树2AC]:MOOC-DataStruct2015spring/03-树2.TreeTraversalsAgain(25).c

[树3]:http://www.patest.cn/contests/mooc-ds2015spring/04-树3
[树3AC]:MOOC-DataStruct2015spring/04-树3.RootofAVLTree(25).c

[树4]:http://www.patest.cn/contests/mooc-ds2015spring/04-树4
[树4AC]:MOOC-DataStruct2015spring/04-树4.SearchinaBinarySearchTree(25).c

[树5]:http://www.patest.cn/contests/mooc-ds2015spring/04-树5
[树5AC]:MOOC-DataStruct2015spring/04-树5.CompleteBinarySearchTree(30).c

[树6]:http://www.patest.cn/contests/mooc-ds2015spring/05-树6 
[树6AC]:MOOC-DataStruct2015spring/05-树6.Path-in-a-Heap(25).c

[树7]:http://www.patest.cn/contests/mooc-ds2015spring/05-树7
[树7AC]:MOOC-DataStruct2015spring/05-树7.FileTransfer(25).c

[树8]:http://www.patest.cn/contests/mooc-ds2015spring/05-树8
[树8AC]:MOOC-DataStruct2015spring/05-树8.HuffmanCodes(30).c

[PA2-3]:http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=405
[PA2-3AC]:TsinghuaX－30240184X/MOOC-PA2/ProperRebuild.c
[THU2-3]:http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=388	

[poj 2431]:http://poj.org/problem?id=2431
[2431AC]:../OnlineJudge/POJ/poj2431Expedition.c

[poj 3253]:http://poj.org/problem?id=3253
[3253AC]:../OnlineJudge/POJ/poj3253FenceRepair.c

[PA4-1]:http://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=409
[PA4-1AC]:TsinghuaX－30240184X/MOOC-PA4/任务调度(Schedule).c

[heap.c]:MOOC-DataStruct2015spring/heap.c
[heapsort.c]:MOOC-DataStruct2015spring/heapsort.c




[浙江大学 陈越、何钦铭 数据结构]:http://mooc.study.163.com/course/ZJU-1000033001#/info

[PAT作业]:http://mooc.study.163.com/learn/ZJU-1000033001#/learn/custom?id=1000052001

[清华大学 邓俊辉 TsinghuaX: 30240184X 数据结构(2015春)]:http://www.xuetangx.com/courses/TsinghuaX/30240184_2015X/2015_T1/courseware/293594d41a0a459a88e4b4a5c855e723/

[清华大学OJ]:http://dsa.cs.tsinghua.edu.cn/oj/foyer.shtml

[在线演示]:http://dsa.cs.tsinghua.edu.cn/~deng/ds/demo/

[C++示例]:http://dsa.cs.tsinghua.edu.cn/~deng/ds/src_link/index.htm

[PAT OJ]:http://www.patest.cn





