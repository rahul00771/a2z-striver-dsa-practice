

//4.Median of two sorted arrays(Hard)

//given two sorted arrays, return the median of the merged sorted array

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        

        //apply binary search on the smaller array
        //taking nums1 as the smaller array
        if(nums2.size()<nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        //size of the arrays
        int n1 = nums1.size(), n2 = nums2.size();

        //condn parameters for BS on nums1
        int low = 0, high = n1;

        //BS on nums1
        while(low<=high)
        {
            //position of partition(not index)
            int cut1 = (low + high)/ 2 , cut2 = (n1 + n2 + 1)/2 - cut1;

            //if partition is made at 0th position, make l = INT_MIN
            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            
            //if partition is made at 0th position, make r = INT_MAX
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2? INT_MAX : nums2[cut2];


            //condition for valid partition
            if(l1<=r2 && l2<=r1)
            {   
                //if even number of elements
                if((n1+n2)%2 == 0)
                    return ( max(l1, l2) + min(r1, r2))/2.0;
                //if odd number of elements
                else
                    return (max(l1, l2));
            }

            //if our partitioning is not correct, move to left side(reducing elements from nums1)
            else if(l1>r2)
                high = cut1 - 1;
            //wrong partition, moving to left side(taking more elements form nums1)
            else
                low = cut1 + 1;
                
        }

        return 0.00;
    }