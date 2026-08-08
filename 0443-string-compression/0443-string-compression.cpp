class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        char a=chars[0];
        int point=0,num=1;
        string str;
        for(int i=1;i<n;i++)
        {
            if(a==chars[i])
            {
                num++;
            }
            else
            {
                if(num==1)
                {
                    point++;
                }
                else
                {
                    point++;
                    str=to_string(num);
                    for(int j=0;j<str.size();j++)
                    {
                        chars[point]=str[j];
                        point++;
                    }    
                    
                }
                a=chars[i];
                chars[point]=a;
                num=1;
            }
        }
        if(num==1)
        {
            point++;
        }
        else
        {
            point++;
            str=to_string(num);
            for(int i=0;i<str.size();i++)
            {
                chars[point]=str[i];
                point++;
            }
        }
        return point;
    }
};