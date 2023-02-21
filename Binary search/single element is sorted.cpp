

//540. Single element in a sorted array

/*You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.*/

//O(log n)

 int singleNonDuplicate(vector<int>& arr) {

        int n = arr.size();

        int l = 0, r = n-1;

        if(n==1)                //if it is the only element
            return arr[0];

        if(arr[0] != arr[1])
            return arr[0];                  //checking edge cases
        else if(arr[n-1] != arr[n-2])
            return arr[n-1];

        while(l<=r)
        {
            int mid = (l+r)/2;

            if((mid != 0) && (mid != n-1))      //staying inside the bounds
            {
                if((arr[mid] != arr[mid+1]) && (arr[mid] != arr[mid-1]))    //ele that occurs only once
                    return arr[mid];
                else if(arr[mid] == arr[mid+1])  //if ele found at mid and mid+1
                {
                    if((mid+1)%2 == 0)  //if mid+1 is even, there are odd num of ele on left of mid
                        r = mid - 1;
                    else                //if mid+1 is odd, there are even num of ele on left of mid, and odd num of ele on right
                        l = mid + 1;
                }
                else                            //if ele occurs at mid-1 and mid
                {
                    if((mid)%2 == 0)    //if mid is even, odd nums of ele on left side
                        r = mid - 1;
                    else                //if mid is odd, odd nums of ele on right side
                        l = mid + 1;
                }
            }
        }

        return -1;
        
    }