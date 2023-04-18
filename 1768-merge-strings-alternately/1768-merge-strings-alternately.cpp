class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n(size(word1)), m(size(word2));
        int i(0), j(0);
        string s = "";
        while(i < n || j< m)
        {
            if(i<n)
            {
                s.push_back(word1[i++]);
            }
            if(j<m)
            {
                s.push_back(word2[j++]);
            }
        }
        return s;
    }
};