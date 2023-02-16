

//35. Search insert position

//To insert an element in correct position of a sorted array

//O(log n)


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();
        int l = 0, r = n-1, mid = l+(r-l)/2;
        int flr = INT_MIN, cl = INT_MAX;        //taking floor at -infnity and +infinity

        if(target <= nums[0])                   ///edge cases
            return 0;
        if(target > nums[n-1])
            return n;

        while(l<=r)
        {
            if(nums[mid] == target)
            {
                cl = mid;                   //bringing ceil and floor to mid if target found at mid
                flr = mid;
                break;                      //coming out of the loop if we found the pos
            }

            else if(target<nums[mid])
            {
                r = mid-1;
                cl = mid;              //shifting the ceil to mid, as ceil will not lye beyond that range
            }
            else
            {
                l = mid +1;
                flr = mid;          //shifting floor to the mid as floor will not lye beyond that range
            }

            mid = l + (r-l)/2;

        }

        return cl;                  //the ceiling position will be the correct insertion position for target
        
    }
};