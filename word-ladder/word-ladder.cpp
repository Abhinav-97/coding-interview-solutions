class Solution {
public:
    string alphabets = "abcdefghijklmnopqrstuvwxyz";
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> wordDict;
        unordered_map<string, bool> visited;
        for(int i=0;i<wordList.size();i++)
        {
            wordDict[wordList[i]] = true;
        }
        queue<pair<string,int>> q;
        q.push({beginWord, 1});
        int ans = INT_MAX;
        visited[beginWord] = true;
        while(!q.empty())
        {
            int cost = q.front().second;
            string word = q.front().first;
            q.pop();
            if(word == endWord)
            {
                ans = min(ans, cost);
                continue;
            }
            for(int i=0;i<word.size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(word[i] != alphabets[j])
                    {
                        string newWord = word;
                        
                        newWord[i] = alphabets[j];
                        if(visited.find(newWord) == visited.end() && wordDict.find(newWord) != wordDict.end())
                        {
                            visited[newWord] = true;
                            q.push({newWord, cost+1});
                        }
                    }
                }
            }
        }
        if(ans == INT_MAX)
        {
            return 0;
        }
        return ans;
    }
    
};
