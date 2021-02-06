class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        int idx = 0;
        while(idx < path.length())
        {
            while(idx < path.length()-1 && path[idx+1] == '/')
            {
                idx++;
            }
            idx++;
            string directory;
            while(idx < path.length() && path[idx] != '/')
            {
                directory += path[idx];
                idx++;
            }
            if(directory == ".")
            {
                continue;
            }
            else if(directory == "..")
            {
                if(!paths.empty())
                {
                    paths.pop_back();
                }
            }
            else if(!directory.empty()){
                paths.push_back(directory);
            }
        }
        string ans = "/";
        for(int i=0;i<paths.size();i++)
        {
            ans += paths[i];
            if(i < paths.size()-1)
            {
                ans += '/';
            }
        }
        return ans;
    }
};