
//1283

//You are given an array of integers nums and an integer K, your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer K.
//Each result of the division is rounded to the nearest integer greater than or equal to that element. 


    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
        int n = nums.size();
        
        int greatest = *max_element(nums.begin(), nums.end());
        //possible candidates are 1 to max element
        int l = 1, r = greatest, ans = 0;   
        
        while(l<=r)
        {
            int mid = (l+r)/2, sum = 0;
            
            //calculating the sum for each candidate
            
            for(int i = 0; i<n; i++)
            {
                if(nums[i]%mid == 0)
                    sum = sum + nums[i]/mid;
                else
                    sum = sum + (nums[i]/mid) + 1;
            }
            
            //condition for binary search
            if(sum<=K)      
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
            
        }
        
        return ans;
        
    }


