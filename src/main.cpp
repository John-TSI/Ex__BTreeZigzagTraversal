// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

#include<iostream>
#include"../inc/solution.hpp"


void PrintLevels(std::vector<std::vector<int>>&& levels)
{
	for(auto level : levels)
	{
		for(int i : level)
		{
			std::cout << i << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	TreeNode n7(7);
	TreeNode n6(5);
	TreeNode n5(3);
	TreeNode n4(1);
	TreeNode n3(6,&n6,&n7);
	TreeNode n2(2,&n4,&n5);
	TreeNode root(4,&n2,&n3);  // {{4},{6,2},{1,3,5,7}}

/* 	TreeNode n5(7);
	TreeNode n4(15);
	TreeNode m3(20,&n4,&n5);
	TreeNode m2(9);
	TreeNode root(3,&m2,&m3); */  // {{3},{20,9},{15,7}}

	Solution sol;
	PrintLevels( sol.zigzagLevelOrder(&root) );
	return 0;
}

