class Solution {
public:
    string convert(string s, int numRows) {
        string s1;
        if(numRows==1)
        {
            return s;
        }
        for(int i=0;i<numRows;i++)
        {
            int index=i;
            int num=numRows-i-1;
            int num2=i;
            long long col=0;
            while(index<s.size())
            {
                if(col%2==0)
                { 
                    if(i!=numRows-1)
                    {
                        s1+=s[index];
                        index+=2*(num);
                    }    
                }    
                else
                {
                    if(i!=0)
                    {
                        s1+=s[index];
                        index+=2*(num2);
                    }    
                }
                col+=1;    
            }
        }
        return s1;
    }
};