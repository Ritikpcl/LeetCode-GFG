class Solution {
public:
    int bestClosingTime(string customers) {
        int visit = 0, maxVisit = 0, ans = -1;
        for(int i=0; i<customers.length(); i++){
            if(customers[i] == 'Y') visit++;
            else visit--;
            if(visit > maxVisit) ans = i, maxVisit = visit;
        }
        return ans+1;
    }
};