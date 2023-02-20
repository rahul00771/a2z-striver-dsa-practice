

//153. Find minimum in rotated sorted array
//A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

//O(log n)

int findMin(vector<int>& arr) {
        
        int n = arr.size(), l = 0, r = n-1, ans = INT_MAX;

        while(l<=r)
        {
            int mid = (l+r)/2;

            if(arr[mid]>=arr[l])       //left side sorted, arr[l] becomes a candidate
            {
                ans = min(ans, arr[l]);
                l = mid + 1;
            }

            else if(arr[r]>=arr[mid])   //right side sorted, arr[mid] becomes candidate
            {
                ans = min(ans, arr[mid]);
                r = mid - 1;
            }
        }

        return ans;

    }