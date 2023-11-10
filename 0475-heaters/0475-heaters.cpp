class Solution {
public:

    bool check(vector<int>& houses, vector<int>& heaters, int mid){
        int i=0,j=0,n=houses.size(),m=heaters.size();
        while(i<n && j<m){
            while(i<n && houses[i]-mid <= heaters[j] && houses[i]+mid >= heaters[j]){
                i++;
            }
            j++;
        }
        
        return i<n;

    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        int low = 0, high = *max_element(houses.begin(),houses.end()),mid;
        high = max(high,*max_element(heaters.begin(),heaters.end()));
        while(low <= high){
            mid = low + (high-low)/2;
            if(check(houses,heaters,mid)){
                low = mid+1;
            }else high = mid-1;
        }

        return high+1;
    }
};