class Solution {
public:
    bool sumGame(string num) {
        int q1=0,q2=0,sum1=0,sum2=0;
        for(int i=0;i<num.size()/2;i++)
        {
            if(num[i]=='?')
            {
                q1++;
            }
            else
            {
                sum1+=num[i]-'0';
            }
        }
        for(int i=num.size()/2;i<num.size();i++)
        {
            if(num[i]=='?')
            {
                q2++;
            }
            else
            {
                sum2+=num[i]-'0';
            }
        }
    
        if((q1+q2)%2)
        return 1;
        int qdiff = q1 - q2;
        int sdiff = sum1 - sum2;
        return sdiff != -9 * qdiff / 2;
    }
};