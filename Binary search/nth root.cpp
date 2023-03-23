

//To find the nth root
// given n and m find nth root of m in nlogm

	
	int NthRoot(int n, int m)
	{
	    
	    if(m == 1)
	        return 1;                          //edge case for m == 1
	    
	    int upper = m/n, lower = 0, check = m/n;
	    
	    
	     while(check>0)         
	     {
	         if(pow(check, n) == m)
	            return check;
	            
	         else if(pow(check, n)>m)
	         {
	             upper = check;             //upper bounf for answer range
	             check = check/n;           //binary condition
	         }
	         else                           //finding the lower bound for answer range
	         {
	             lower = check;
	             break;
	         }
	            
	     }
	     
	     for(int i = lower; i<= upper; i++)     //searching in the range lower to upper
	     {
	         if(pow(i, n) == m)
	            return i;
	     }
	     
	     return -1;         //if the answer is not integer
	     
	     
    }