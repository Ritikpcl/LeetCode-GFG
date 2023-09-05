class Solution {
public:
    int longestString(int x, int y, int z) {
        return 2 * ((x != y) + 2*min(x,y) + z);
    }
};