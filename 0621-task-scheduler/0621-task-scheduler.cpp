class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> pq;
        vector<int> v(26,0);
        int ans = 0;

        for(int i=0; i<tasks.size(); i++){
            v[tasks[i]-'A']++;
        }

        for(int i=0; i<26; i++){
            if(v[i]) pq.push(v[i]);
        }

        vector<int> temp;
        while(pq.size()){
            int x = n+1;
            while(pq.size() && x>0){
                temp.push_back(pq.top());
                pq.pop();
                x--;
            }

            for(int i=0; i<temp.size(); i++){
                ans++;
                temp[i]--;
                if(temp[i]>0) pq.push(temp[i]);
            }
            if(pq.size()) ans += x;
            temp.resize(0);
        }
        return ans;
    }
};