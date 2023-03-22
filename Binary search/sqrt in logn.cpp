
//To find square root using log n time

    //first checking with x/2, and then setting a range, i.e upper and lower bounds of sqrt(x), then find in range of lower and upper

    long long int floorSqrt(long long int x) 
    {
        long long int lower = 1, upper = x/2, check = x/2;
               
        
        while(check>0)          
        {
            if(check*check == x)        //if sqrt, return the number
                return check;
                
            else if(check*check > x)    //if greater, then reduce the range(upper limit)
            {
                upper = check;
                check = check/2;
            }
            else if(check*check < x)    //if smaller, then increade the lower bound
            {
                lower = check;
                break;
            }
        }
        
        
        for(long long int i = lower; i<=upper + 1; i++)     //search from lower to upper bound
        {
            if(i*i == x)
                return i;
            else if(i*i > x)        //for non perfect square numbers
                return i-1;
        }
        
        
    }

