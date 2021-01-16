class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i] > 0)
            {
                st.push(i);
            }
            else{
                while(!st.empty())
                {
                    if(abs(asteroids[st.top()]) == abs(asteroids[i]))
                    {
                        asteroids[st.top()] = 1001;
                        asteroids[i] = 1001;
                        st.pop();
                        break;
                    }
                    else if(abs(asteroids[st.top()]) > abs(asteroids[i]))
                    {
                        asteroids[i] = 1001;
                        break;
                    }
                    else{
                        asteroids[st.top()] = 1001;
                        st.pop();
                    }
                }
            }
        }
        for(int i=0;i<asteroids.size();i++)
        {
            if(asteroids[i] != 1001)
            {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};
