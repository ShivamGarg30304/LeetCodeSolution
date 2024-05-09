class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
       unordered_map<int,int> um;
       for(int i=0;i<score.size();i++)
       {
            um[score[i]]=i;
       } 
       int n = score.size();
       vector<string> st(n);
       sort(score.rbegin(),score.rend());
       vector<string>s{"Gold Medal","Silver Medal","Bronze Medal"};
       for(int i=0;i<min(n, 3);i++)
       {
            st[um[score[i]]]=s[i];
       }
       for(int i=3;i<score.size();i++)
       {
            cout << score[i] << endl;
            st[um[score[i]]]=to_string(i+1);
       }
       return st;
    }
};