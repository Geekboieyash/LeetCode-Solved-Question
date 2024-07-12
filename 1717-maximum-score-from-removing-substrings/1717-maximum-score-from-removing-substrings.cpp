class Solution {
public:
    int maximumGain(string s, int x, int y) {
        // first to see weather x>y
        // convert the strign to arr
        // find ab or ba whhich have more weightage
        // then moment we find ba we will update the res
        //strings defined
        if (x < y) {
            swap(x, y);
            for (char& c : s) {
                if (c == 'a') c = 'b';
                else if (c == 'b') c = 'a';
            }
        }
            //checking the bigger weightage
            //aacabaababaa
            //aaca..a....a
            
            //testcase2: 
            // acacabbbaaba
            // acacab, y = 3
            //number of b(4), number of a(6)
            // to count the number of b after a
            
        int res(0);
        stack<char> st;
        for(char c: s){
            if(!st.empty() && st.top() == 'a' && c == 'b')
            {
                st.pop();
                res += x;
            }else{
                st.push(c);
            }
        }
        string remaining;
        while (!st.empty()) {
            remaining += st.top();
            st.pop();
        }
        for (char c : remaining) {
            if (!st.empty() && st.top() == 'a' && c == 'b') {
                st.pop();
                res += y;
            } else {
                st.push(c);
            }
        }
        
        return res;
    }
};