
//875. Koko eating bananas

//given N piles of bananas, the ith pile has piles[i] bananas and H hours time until guards return (N <= H). Find the minimum (S) bananas to eat per hour such that Koko can eat all the bananas within H hours. Each hour, Koko chooses some pile of bananas and eats S bananas from that pile. If the pile has less than S bananas, then she consumes all of them, and wont eat any more bananas during that hour.

//O(nlogn)

int minEatingSpeed(vector<int>& piles, int h) {

        int greatest = piles[0];
        for(int i = 0; i<piles.size(); i++)         //finding the greatest ele
        {
            if(piles[i]>greatest)
                greatest = piles[i];
        }

        int l = 1, r = greatest, ans = 0;       

        while(l<=r)                         //for finding the min speed for eating banana
        {
            long long int hours = 0;        //hours for each mid we test
            int mid = (l+r)/2;              

            for(int i = 0; i<piles.size(); i++)     
            {
                if(piles[i]%mid == 0)       //if perfectly divisible simply add the no of hrs reqd
                    hours = hours + piles[i]/mid;
                else                     //if not divisible add no. of hrs and for remaining banana add 1 more hr
                    hours = hours + (piles[i]/mid) + 1;
            }

            if(hours<=h)  //if we found the speed(mid) which gives h hours, store it and try to find lesser speed
            {
                ans = mid;
                r = mid - 1;
            }
            else            //else increase the speed(mid)
                l = mid + 1;

        }

        return ans;

    }

