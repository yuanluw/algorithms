class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        int len1 = s.size(), len2 = p.size();
        if(len1<len2)
            return result;

        int *m1 = new int[26]();
        int *m2 = new int[26](); 
        for(int i=0; i<len2; i++){
            m2[p[i]-'a']++;
        }

        for(int start=0; start<len1-len2+1; start++){
            if(start == 0){
                for(int i=start; i<start+len2; i++)
                    m1[s[i]-'a']++;
            }
            else{
                m1[s[start-1]-'a']--;
                m1[s[start+len2-1]-'a']++;
            }
            bool flag=true;
            for(int i=0; i<26; i++){
                if(m1[i]>0 && m1[i] != m2[i]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                result.push_back(start);

        }
        return result;
    }
};
