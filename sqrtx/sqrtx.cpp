class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while(left <= right)
        {
            long long int mid = left + (right-left)/2;
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
        return left-1;
    }
};
