class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        stack<int>st; 
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>his(m,0);
        int ans=0,area=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                while(!st.empty())
                st.pop();
                if(matrix[i][j]=='1')
                {
                    his[j]++;
                }    
                else
                {
                    his[j]=0;
                }    
            }    
                vector<int>tempr(m);
                vector<int>templ(m);
                for(int k=0;k<m;k++)
                {
                    while(!st.empty()&&his[st.top()] >= his[k])
                    {
                        st.pop();
                    }
                    templ[k] = st.empty() ? -1 : st.top();
                    st.push(k);
                }
                while (!st.empty())
                st.pop();
                for(int k=m-1;k>=0;k--)
                {
                    while(!st.empty()&&his[st.top()] >= his[k])
                    {
                        st.pop();
                    }
                    tempr[k] = st.empty() ? m : st.top();
                    st.push(k);
                }
                for(int k=0;k<m;k++)
                {
                    area=his[k]*(tempr[k]-templ[k]-1);
                    ans=max(area,ans);
                }
        }    
        return ans;
    }
};