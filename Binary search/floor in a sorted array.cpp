

//implement lower bound

//Given a sorted array arr[] of size N without duplicates, and given a value x.
//Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. Find the index of K(0-based indexing).

/*
Input:
N = 7, x = 5 
arr[] = {1,2,8,10,11,12,19}
Output: 1
Explanation: Largest Number less than 5 is
2 (i.e K = 2), whose index is 1(0-based 
indexing).
*/

class Solution{
  public:
    
    int findFloor(vector<long long> arr, long long n, long long X){
        
        long long left = 0, right = n-1, mid = (right + left)/2;
        
        if(arr[left] == X)         //if first element is X, return 0;
            return 0;
        if(X>arr[right])           //if X is greater than the greatest element, return last index
            return n-1;
        
        
        
        while(left<=right)          
        {
            if(arr[mid] == X)
                return mid;
                
            else if(X<arr[mid])
                right = mid - 1;
            
            else if(X>arr[mid])
                left = mid + 1;
                
            if((arr[mid-1]<X) && (arr[mid]>X))      //if mid-1 th element is less than X and mid th element is greater than X, return mid-1
                return mid-1;
                
            mid = (right + left)/2;
            
        }
        
       return -1;       
        
    }
};
