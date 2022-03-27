class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1]))
            {
                int leftlen=0;
                int j=i;
                while(j > 0 && arr[j] > arr[j-1])
                {
                    j--;
                    leftlen++;
                }
                int k=i;
                int rightlen = 0 ;
                while(k < n-1 && arr[k]> arr[k+1])
                {
                    rightlen++;
                    k++;
                }
                ans = max(ans, rightlen+leftlen+1);
            }
        }
        return ans;
    }
};