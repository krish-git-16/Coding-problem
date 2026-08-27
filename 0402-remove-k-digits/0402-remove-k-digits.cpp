class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        int n=num.size();
        if(k>=num.size())
        return "0";
        for(int i=0;i<n;i++)
        {
            while(!st.empty()&&num[st.top()]>num[i]&&k>0)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }
        string ans="";
        while(!st.empty())
        {
            ans.push_back(num[st.top()]);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(k>0)
        {
            ans.pop_back();
            k--;
        }
        int i = 0;

        while(i < ans.size() && ans[i] == '0')
            i++;

        ans = ans.substr(i);

        if(ans.empty())
            return "0";
        return ans;
    }
};