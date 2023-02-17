
//Number of occurence

/*Given a sorted array Arr of size N and a number X, you need to find the number of occurrences of X in Arr.*/

//Find first_index and last_index and return last_index - first_index +1


//O(log n)


int count(int arr[], int n, int X) {
	    
	int l = 0, r = n-1, mid = (r+l)/2, first_index = 0, last_index = -1;
    
    
    
    //To find the first occurence index
    while(l<=r)
    {
        if(arr[mid] == X)
        {   
            first_index = mid;
            r = mid-1;              //to check first occurence, if mid == x, then reduce the array to left side and store the index
        }
        
        else if(X>arr[mid])
            l = mid+1;
        else
            r = mid-1;
            
        mid = (r+l)/2;
    }
    
    
    //To find the last occurence
    
    int l2 = 0, r2 = n-1, mid2 = (r2+l2)/2;
    
    while(l2<=r2)
    {
        if(arr[mid2] == X)
        {
            last_index = mid2;
            l2 = mid2+1;          //for the last occurence, if mid == x, then reduce the array to right half and store the index
        }
        
        else if(X>arr[mid2])
            l2 = mid2+1;
        else
            r2 = mid2-1;
            
        mid2 = (r2+l2)/2;
    }
    
    return last_index - first_index + 1;
    
	    
	}