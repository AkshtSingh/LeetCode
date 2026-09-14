class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // Check 1D interval overlap on both axes
        return (rec1[0] < rec2[2] && rec2[0] < rec1[2]) && // X-axis
               (rec1[1] < rec2[3] && rec2[1] < rec1[3]);   // Y-axis
    }
};