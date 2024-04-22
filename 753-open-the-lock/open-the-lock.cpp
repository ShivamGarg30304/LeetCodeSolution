class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        if (st.count("0000")) {
            return -1;
        }
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        unordered_set<string> vis;
        vis.insert("0000");
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            string cC = cur.first;
            int moves = cur.second;
            
            if (cC == target) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (cC[i] - '0' + delta + 10) % 10;
                    string newCombination = cC;
                    newCombination[i] = '0' + newDigit;
                    
                    if (vis.find(newCombination) == vis.end() && st.find(newCombination) == st.end()) {
                        vis.insert(newCombination);
                        q.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1; // Target is not reachable
    }
};