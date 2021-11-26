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

