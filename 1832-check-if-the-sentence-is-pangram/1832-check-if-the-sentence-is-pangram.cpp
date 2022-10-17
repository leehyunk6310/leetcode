class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char, int> m;
        
        for (auto ch : sentence)
            m[ch]++;
        
        if (m.size() == 26)
            return true;
        
        return false;
    }
};