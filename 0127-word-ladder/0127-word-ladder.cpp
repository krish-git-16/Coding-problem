class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,pair<string,int>>>q;
        int n=wordList.size();
        vector<bool>visited(n,0);
        vector<int>dist(n,INT_MAX);
        bool found = false;
        for(auto &word : wordList)
        {
            if(word == endWord)
            {
                found = true;
                break;
            }
        }
        if(!found) return 0;
        for(int i=0;i<n;i++)
        {
            int diff=0;
            for(int j=0;j<beginWord.size();j++)
            {
                
                if(wordList[i][j]!=beginWord[j])
                {
                    diff++;
                }
            }
            if(diff==1)
            {
                dist[i]=2;
                q.push({2,{wordList[i],i}});                
            }
        }
        while(!q.empty())
        {
            int steps=q.front().first;
            string  w=q.front().second.first;
            int index=q.front().second.second;
            q.pop();
            visited[index]=1;
            if(w==endWord)
            return steps;
            for(int i=0;i<n;i++)
            {
                int diff=0;
                if(visited[i])
                continue;
                for(int j=0;j<beginWord.size();j++)
                {
                    
                    if(wordList[i][j]!=w[j])
                    {
                        diff++;
                    }
                }
                if(diff==1)
                {
                    if(steps+1<dist[i])
                    {
                        dist[i]=steps+1;
                        q.push({steps+1,{wordList[i],i}});
                    }                    
                }
            }
        }
        return 0;
    }
};