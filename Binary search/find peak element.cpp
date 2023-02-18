

//162. Find peak element

/*A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.*/

//O(log n)

int findPeakElement(vector<int>& arr) {
        
        int n = arr.size();

        if(n==1)             //if it is the only element, it is the peak
            return 0;

        if(arr[0]>arr[1])      //edge case
            return 0;

        else if(arr[n-2]<arr[n-1])  //edge case
            return n-1;

        int l = 0, r = n-1, mid = (r+l)/2;

        while(l<=r)
        {            

            if((arr[mid-1]<arr[mid]) && (arr[mid+1]<arr[mid]))  //condn for peak ele
                return mid;
            else if(arr[mid+1]>arr[mid])    
                l = mid;
            else if(arr[mid-1]>arr[mid])
                r = mid;

            mid = (r+l)/2;
        }

        return -1;

    }