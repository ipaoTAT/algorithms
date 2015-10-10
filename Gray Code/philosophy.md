＃解决思路
1. 基于二叉树的回溯法
本题的解决方案为典型的回溯法。首先想到的回溯法是深度优先搜索（DFS）。
考虑格雷码对应的二叉树如图：
					Root
					／   \
				   0       1
				/    \   /    \
			   0    1  1     0
该树有个特点，就是左子树的左子树为0，右子树为1；而右子树恰好相反。可以在DFS递归中使用标识标记当前访问的是左子树还是右子树，来决定下一个该入栈的是谁。
代码如下：
```C++
void generate(vector<char> &res, int n, char cur, bool left)
{
    res.push_back(cur);
    if(res.size() == n)
    {
	print_vector(res);
    }else{

    char first = '0';
   	char second = '1';
   	if(!left)
   	{
   	    first = '1';
   	    second = '0';
   	}
   	generate(res, n, first, true);
   	generate(res, n, second, false);
   }
   //回溯退栈
   res.pop_back();
}

int graycode(int n)
{
    vector<char> res;
    generate(res, n, '0', true);
    generate(res, n, '1', false);
}
```

2. 经典回溯法
