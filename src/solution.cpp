#include<queue>
#include<algorithm>
#include"../inc/solution.hpp"


std::vector<std::vector<int>> Solution::zigzagLevelOrder(TreeNode* root)
{
    std::vector<std::vector<int>> levels;
    std::vector<int> values;
    std::queue<TreeNode*> nodes;

    if(!root){ return levels; }  // handle empty tree
    nodes.push(root);

    bool leftToRight{true};  // boolean will be negated after each loop iteration
    while(!nodes.empty())
    {
        int nodesOnThisLevel = nodes.size();  // initially one, then recomputed each loop iteration based on number of queue pushes
        values.clear();  // this vector is repeatedly pushed onto the return variable 'levels', is reset each loop iteration

        for(int i{0}; i<nodesOnThisLevel; ++i)
        {
            values.push_back(nodes.front()->val);  // push the node's value onto 'values'
            if(nodes.front()->left){ nodes.push(nodes.front()->left); }  // push the node's children onto the queue
            if(nodes.front()->right){ nodes.push(nodes.front()->right); }
            nodes.pop();  // remove the node
        }
        if(!leftToRight){ std::reverse(values.begin(), values.end()); }  // reverse 'values' every other loop iteration
        levels.push_back(values);  // contains the values of nodes in a given level
        leftToRight = !leftToRight;  // negate the bool before next loop iteration
    }
    return levels;
}