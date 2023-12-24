class Solution {
public:
    int minOperations(string s) {
        int x = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] - '0' == i%2)
            {
                x+=1;
            }
        }
        return min(x, static_cast<int>(s.length()) - x); 
    }
};