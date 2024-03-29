//Leetcode explore solutions

//Notes
//Sorting algos
//  https://dev.to/koladev/8-must-know-sorting-algorithms-5ja

//Q. Given an array nums of integers, return how many of them contain an even number of digits.

#include <string>

class Solution 
{
    public:
        int findNumbers(vector<int>& nums) 
        {
            int c = 0;
            string s;
            for(int i=0; i<nums.size();i++)
            {
                s = to_string(nums[i]);
                if( (s.length())%2==0 )
                    c++;
            }
            return c;
        }
};


//Q. Sort into a new array | 1 pass 2 pointer

vector<int> sortedArray(vector<int>& A)
{
	vector<int> result(A.size());
	int l=0, r=(A.size()-1);
	for(int i=(A.size()-1); i>=0;i--)
	{
		result[i] = (A[l]>A[r])?A[l++]:A[r--];
	}
}


class Solution {
public:
    void duplicateZeros(vector<int>& arr) 
    {
        vector<int> result(arr.size());
        for(int i=0,k=0; k<arr.size(); i++,k++)
        {
            result[k]=arr[i];
            if(arr[i]==0 && k!=(arr.size()-1))
            {
                result[++k]=arr[i];
            }
        }
        arr = result;
    }
};


//delete repeated elements


#include <iostream>

using namespace std;

int main()
{
    int A[] = {0, 0, 1, 1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < n; i++)
        cout<<A[i]<<' ';
    int count = 0;
    for(int i = 1; i < n; i++)
    {
        if(A[i] == A[i-1]) 
            count++;
        else 
            A[i-count] = A[i];
    }
    cout<<'\n'<<(n-count)<<'\n';
    for (int i = 0; i < n; i++) {
        cout<<A[i]<<' ';
    }
    return 0;
}


//2D vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cout<<"Hello World\n";
    
    char s1[] = "ABC";
    int l1 = sizeof(s1)/sizeof(s1[0]);
    char s2[] = "ABCBABC";
    int l2 = sizeof(s2)/sizeof(s2[0]);
    
    std::vector<std::vector<int>> v;
    std::vector<int> temp;

    for (int i = 0; i < l1-1; i++) 
    {
        for (int j = 0; j < l2-1; j++)
            if(s1[i]==s2[j])
                temp.push_back(j);
        v.push_back(temp);
        temp.clear();
    }
    
    for (auto i : v) 
    {
        for (auto j : i)
            cout<<j<<" ";
        cout<<endl;
    }
    
    
    return 0;
}


//singly linked-list
//determine if cycle exists
public boolean hasCycle(ListNode head) 
{
    if(head==null) 
        return false;
    ListNode walker = head;
    ListNode runner = head;
    while(runner.next!=null && runner.next.next!=null) 
    {
        walker = walker.next;
        runner = runner.next.next;                  //important technique
        if(walker==runner) return true;
    }
    return false;
}

//BST
//Pre-order traversal
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* root, vector<int> &nodes)  //note the &
    {
        if(root==nullptr)
            return;                                     //note the empty return
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
public:
     
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int> nodes;
        preorder(root, nodes);
        return nodes;
    }
};


//BFS
//Level-order
vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> result;
    if(!root)
        return result;

    queue<TreeNode*> s;
    vector<int> level;
    queue<TreeNode*> nodes;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* n = s.front();
        s.pop();
        level.push_back(n->val);
        if(n->left)
            nodes.push(n->left);
        if(n->right)
            nodes.push(n->right);

        if(s.empty())
        {
            s.swap(nodes);
            result.push_back(level);
            level.clear();
        }
    }
    
    return result;
}