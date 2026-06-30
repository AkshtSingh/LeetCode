class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastPos[3] = {-1, -1, -1};
        int count = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            lastPos[s[i] - 'a'] = i;
            
            if (lastPos[0] != -1 && lastPos[1] != -1 && lastPos[2] != -1) {
                count += min({lastPos[0], lastPos[1], lastPos[2]}) + 1;
            }
        }
        
        return count;
    }
};