class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> diff(n,vector<int>(m,1e9));
        diff[0][0]=0;
        // cout << diff[0][0] << endl;
        int varx[]={0,-1,0,1};
        int vary[]={-1,0,1,0};
        pq.push({0,{0,0}});
        while(!pq.empty())
        {
            auto dif=pq.top().first;
            auto i=pq.top().second.first;
            auto j=pq.top().second.second;
            pq.pop();
            for(int p=0;p<4;p++)
            {
                int x=varx[p]+i;
                int y=vary[p]+j;
                if(x>=0 and x<n and y>=0 and y<m)
                {
                    int diffr=abs(heights[i][j]-heights[x][y]);
                    int maxi=max(diffr,dif);
                    if(maxi < diff[x][y])
                    {
                        diff[x][y] = maxi;
                        pq.push({maxi,{x,y}});
                    }
                }
            }
        }
         return diff[n-1][m-1];
    }
};