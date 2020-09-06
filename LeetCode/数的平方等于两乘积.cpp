class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int cnt = 0;
        
        unordered_map<long long, long long> m1;
        for(int i=0; i<nums1.size(); i++){
            long long temp = long(nums1[i])*long(nums1[i]);
            m1[temp]++;
        }
        for(int i=0; i<nums2.size()-1; i++){
            for(int j=i+1; j<nums2.size(); j++){
                long long temp = long(nums2[i])*long(nums2[j]);
                if(m1.find(temp) != m1.end()){
                    cnt += m1[temp];
                }
            }
        }

        unordered_map<long long, long long> m2;
        for(int i=0; i<nums2.size(); i++){
            long long temp = long(nums2[i])*long(nums2[i]);
            m2[temp]++;
        }
        for(int i=0; i<nums1.size()-1; i++){
            for(int j=i+1; j<nums1.size(); j++){
                long long temp = long(nums1[i])*long(nums1[j]);
                if(m2.find(temp) != m2.end()){
                    cnt += m2[temp];
                }
            }
        }
        return cnt;
    }
};
