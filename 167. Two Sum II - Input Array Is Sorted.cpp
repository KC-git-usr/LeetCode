class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int ptr1 = 0, ptr2 = numbers.size() - 1;
        int sum1;

        while(ptr1 < ptr2) {
            sum1 = numbers[ptr1] + numbers[ptr2];
            if(sum1 == target)
                break;
            if(sum1 > target)
                ptr2--;
            else
                ptr1++;
        }
        return {ptr1 + 1, ptr2 + 1};
    }
};