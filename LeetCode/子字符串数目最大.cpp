class Solution {
public:

    void splitString(string s, unordered_set<string>&m, int pos, int &result){

        if(pos == s.size()){
            result = max(result, (int)m.size());
            return;
        }
        for(int i=pos; i<s.size(); i++){
            string temp = s.substr(pos, i-pos+1);
            if(m.find(temp) == m.end()){
                m.insert(temp);
                splitString(s, m, i+1, result);
                m.erase(temp);
            }
        }

    }

    int maxUniqueSplit(string s) {

        unordered_set<string> m;
        int result = 0;

        splitString(s, m, 0, result);

        return result;

    }
};
