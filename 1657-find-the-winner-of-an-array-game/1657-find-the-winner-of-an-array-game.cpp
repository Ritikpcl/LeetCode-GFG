class Solution {
public:
    int getWinner(vector<int>& arr, int k) {

        int n = arr.size();
        int maxi = *max_element(arr.begin(),arr.end());

        if(k>=n) return maxi;

        queue<pair<int,int>> q;
        for(int i=1; i<arr.size(); i++){
            q.push({arr[i],0});
        }

        int num = arr[0];
        int cnt = 0;
        while(n--){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            if(num < x){
                q.push({num,cnt});
                num = x;
                cnt = y+1;
            }else{
                q.push({x,y});
                cnt++;
            }

            if(cnt == k) return num;
        }
        return maxi;
    }
};