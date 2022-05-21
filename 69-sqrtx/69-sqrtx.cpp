class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x==1)
        {
            return x;
        }
        int left = 0;
        int right = x;
        while(left < right)
        {
            long long int mid = (right+left)/2;
            if(mid*mid == x)
            {
                return mid;
            }
            else if(mid*mid > x)
            {
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        if(left*left > x)
        {
            return left-1;
        }
        return left;
    }
};