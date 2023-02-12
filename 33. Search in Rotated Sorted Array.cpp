/*
[0,1,2,4,5,6,7]

[6,7,0,1,2,4,5]

[2,4,5,6,7,0,1] 4

[4,5,6,7,0,1,2], target = 0

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        int mid = (left+right)/2;

        while(left <= right) {

            if(nums[mid] == target) {
                return mid;
            }

            else if(nums[left] <= nums[mid]) {  //left sorted portion
                if (target > nums[mid] || target < nums[left])  //target doesn't lie in left sorted portion
                    left = mid + 1;
                else
                    right = mid - 1;
            }

            else {  //right sorted portion
                if(target < nums[mid] || target > nums[right])   //target in left portion
                    right = mid - 1;
                else
                    left = mid + 1;
            }

            mid = (left+right)/2;

        }

        return -1;

    }
};