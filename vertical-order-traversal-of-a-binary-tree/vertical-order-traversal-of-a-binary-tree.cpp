//this pair is for storing TreeNode and vertical level
typedef std::pair<TreeNode*,int> tPair;

class Solution {
    std::map<int,vector<int>> verticalOrderMap_;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> retVec;
        
        //Queue for iterating values by BFS
        std::queue<tPair> tQueue;
        
        tQueue.push(make_pair(root,0));
        
        while(!tQueue.empty())
        {
            int size = tQueue.size();
            
            // We are creating additional map so that if 2 values are at same horizontal level and vertical level
            // we always put the values in ascending order, hence we use a set here.
            //Create a map where level is the key and values are present in set so that they are ordered
            std::map<int,set<int>> tMap;
            
            while(size)
            {
                tPair data = tQueue.front();

                tMap[data.second].insert(data.first->val);
                
                tQueue.pop();
                size--;
                
                if(data.first->left)
                    tQueue.push(make_pair(data.first->left,data.second - 1));
                
                if(data.first->right)
                    tQueue.push(make_pair(data.first->right,data.second + 1));
            }
            
            for(auto it=tMap.begin();it!=tMap.end();it++)
            {
                // convert the set into vector
                auto v1 = getVectorFromSet(it->second);
                
                // get the existing vector till now
                auto& vec = verticalOrderMap_[it->first];
                
                //append v1 to the existing vector
                vec.insert(vec.end(),v1.begin(),v1.end());
            }
        }
        
        for(auto itMap = verticalOrderMap_.begin();itMap!=verticalOrderMap_.end();itMap++)
            retVec.push_back(itMap->second);
        return retVec;
    }
    
    vector<int> getVectorFromSet(const set<int>& i)
    {
        vector<int> ret;
        for(auto it=i.begin();it!=i.end();it++)
            ret.push_back(*it);
        return ret;
    }
};