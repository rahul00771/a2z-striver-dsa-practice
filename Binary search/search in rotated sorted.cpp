

//33. Search in rotated sorrted array

/*Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.*/

//O(log n)

int search(vector<int>& arr, int key) {

        int n = arr.size(), l = 0, r = n-1;

        while(l<=r)
        {
            int mid = (l+r)/2;
            
            if(arr[mid] == key)
                return mid;
            else if((arr[mid]>arr[l]) && (key<arr[mid]) && (key>=arr[l]))
                r = mid - 1;        //if key lies on left sorted
            else if((arr[r]>arr[mid]) && (key<=arr[r]) && (key>arr[mid]))
                l = mid + 1;        //if key lies on right sorted 
            else if((arr[r]<arr[mid]) && ((key<arr[l]) || (key>arr[mid])))
                l = mid + 1;        //if key lies on right unsorted
            else
                r = mid - 1;        //if key lies on left unsorted
        }
        
        return -1;

    }
