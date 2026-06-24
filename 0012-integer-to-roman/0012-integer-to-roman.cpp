class Solution {
public:
    string intToRoman(int num) {
        string ans;
        int div,rem,mul=0,x;
          x=num%10;
          mul+=1;
          if(mul==1)
          {
            rem=x%5;
            div=x/5;
            if(x==4)
            {
                ans+="VI";
            }
            else if(x==9)
            {
                ans+="XI";
            }
            else
            {
                for(int j=0;j<rem;j++)
                {
                    ans+='I';
                }
                if(div==1)
                {
                    ans+='V';
                }
            }
          } 
            num/=10;
          x=num%10;
          if(num>0)
          mul+=1;
          if(mul==2)
          {
            rem=x%5;
            div=x/5;
            if(x==4)
            {
                ans+="LX";
            }
            else if(x==9)
            {
                ans+="CX";
            }
            else
            {
                for(int j=0;j<rem;j++)
                {
                    ans+='X';
                }
                if(div==1)
                {
                    ans+='L';
                }
            }
          }  
            num/=10;
          x=num%10;
          if(num>0)
          mul+=1;
          if(mul==3)
          {
            rem=x%5;
            div=x/5;
            if(x==4)
            {
                ans+="DC";
            }
            else if(x==9)
            {
                ans+="MC";
            }
            else
            {
                for(int j=0;j<rem;j++)
                {
                    ans+='C';
                }
                if(div==1)
                {
                    ans+='D';
                }
            }
          } 
            num/=10;
          x=num%10;
          if(num>0)
          mul+=1;
          if(mul==4)
          {
            rem=x%5;
            div=x/5;
            for(int j=0;j<rem;j++)
            {
                    ans+='M';
            }
            num/=10;
          }
        int i=0,j=ans.size()-1;
        while(i<j) 
        {
            swap(ans[i],ans[j]);
            i++;
            j--;
        } 
        return ans;
    }
};