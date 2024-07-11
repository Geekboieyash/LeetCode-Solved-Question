class Solution {
public:
    void f(int ind, bool flag, string& s, vector<string>& res)
    {
        
        if(ind == s.length())
        {
            res.push_back(s);
            return ;
        }
        if(!flag) f(ind+1, true, s, res);
        s[ind] = '1';
        f(ind+1,false, s, res);
        s[ind] = '0';
    }
    
    
    vector<string> validStrings(int n) {
        //adjacent zero not needed 
        //n = 4
        // [1,0,1,0]*(2), [1,1,1,1], [1,1,1,0]*(3) x1
        
        vector<string>res;
        string s(n, '0');
        f(0, false, s, res);
        return res;
        
    }
};