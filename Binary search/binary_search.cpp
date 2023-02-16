

//704. Binary search

//given sorted array, if k is present return index else return -1

//O(log n)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size(), left = 0, right = n-1, mid = left+(right-left)/2;
        
        while(left<=right)
        {
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]<target)
                left = mid+1;
            else
                right = mid - 1;

            mid = left+(right-left)/2;
        }

        return -1;
    }
};