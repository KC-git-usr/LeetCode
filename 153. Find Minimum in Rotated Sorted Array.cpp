/*
Binary search for the location where a[mid] is the min value

[3,4,5,1,2]
 L       R

nums[mid] >= nums[left]
    search right portion;
else
    search left portion;

*/

class Solution {
public:
    int findMin(vector<int>& nums) {

        int left = 0, right = nums.size()-1;
        int mid = (left+right)/2;
        int result = nums[0];

        while(left<=right) { //this sub-portion is already sorted, so left most value is the smallest

            if(nums[left] < nums[right]) {
                result = std::min(result, nums[left]);
                break;
            }

            mid = (left+right)/2;
            result = std::min(result, nums[mid]);

            if(nums[mid] >= nums[left])
                left = mid + 1;

            else
                right = mid - 1;

        }

        return result;
    }
};