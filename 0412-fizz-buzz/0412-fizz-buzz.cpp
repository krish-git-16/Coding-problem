class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>ans;
        int rem;
        for(int i=1;i<=n;i++)
        {   
            string s;
            if(i%3==0&&i%5==0)
            s+="FizzBuzz";
            else if(i%5==0)
            s+="Buzz";
            else if(i%3==0)
            s+="Fizz";
            else
            { 
                int j=i;
                while(j)
                {
                    int r=j%10;
                    j/=10;
                    s+='0'+r;
                }
                reverse(s.begin(),s.end());
            }    
            ans.push_back(s);
        }
        return ans;
    }
};