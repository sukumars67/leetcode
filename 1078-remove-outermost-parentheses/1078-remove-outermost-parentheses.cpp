class Solution {
public:
    string removeOuterParentheses(string s)
    {
        int count = 0;
        string ans;
        for(char i:s)
        {
            if(i == '(')
            {
                if(count > 0)
                {
                    ans += i;
                }
                count++;
            }
            else
            {
                if(count > 1)
                {
                    ans += i;
                }
                count--;
            }
        }
        return ans;
    }
};