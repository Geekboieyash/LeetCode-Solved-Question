class Solution {
public:
    #define ll long long int 
    void dfs(vector<vector<int>> &gb,vector<bool> &visited,int &c,int &i) {
        visited[i]=true;
        c++;
        for(int j=0;j<gb[i].size();j++) {
            if(!visited[gb[i][j]])
                dfs(gb,visited,c,gb[i][j]);   
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int> > gb(n);
        for(int i=0;i<n;i++) {
            ll x1,y1,r1;
            x1=bombs[i][0];
            y1=bombs[i][1];
            r1=bombs[i][2];
            for(int j=0;j<n;j++) {
                if(i!=j) {
                    ll x,y;
                    x=abs(x1-bombs[j][0]);
                    y=abs(y1-bombs[j][1]);
                    if(x*x+y*y<=r1*r1)
                        gb[i].push_back(j);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++) {
            int c=0;
            vector<bool> visited(n,false);
            dfs(gb,visited,c,i);
            ans=max(ans,c);
        }

        return ans;
    }
};