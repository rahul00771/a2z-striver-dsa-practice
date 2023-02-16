
/*Given an unsorted array Arr[] of N integers and an integer X, find floor and ceiling of X in Arr[0..N-1].

Floor of X is the largest element which is smaller than or equal to X. Floor of X doesn’t exist if X is smaller than smallest element of Arr[].

Ceil of X is the smallest element which is greater than or equal to X. Ceil of X doesn’t exist if X is greater than greatest element of Arr[].*/

//O(n)


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    
    
    int flr = -1, cl = INT_MAX;
    
    for(int i = 0; i<n; i++)
    {
        if(arr[i]<=x)
            flr = max(flr, arr[i]);
        if(arr[i]>=x)
            cl = min(cl, arr[i]);
            
    }
    
    if(cl == INT_MAX)
        return {flr, -1};
    else
        return {flr, cl};

}