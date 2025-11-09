class Solution {
public:
    int minimumDistance(vector<int>& nums) {
       int n=nums.size();
         int ans=INT_MAX;
        vector<pair<int,int>>v;//2d array bnao
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});//is 2d array me hr ek element is a couple of number and its corresponding index
        }
        sort(v.begin(),v.end());//sort krdiya taki duplicates pass aa jye number k basis me sort hua h in ascending order
       //2d array pe loop chalao
        for(int i=0;i+3<=v.size();i++){
            if((v[i].first==v[i+1].first)&&(v[i+1].first==v[i+2].first)){
                int i1=v[i].second;
                int i2=v[i+1].second;
                int i3=v[i+2].second;
                ans=min(ans,abs(i1 - i2) + abs(i2 - i3) + abs(i3 - i1));
                
            }
            
        }
       
        return (ans==INT_MAX)?-1:ans; 
    }
};