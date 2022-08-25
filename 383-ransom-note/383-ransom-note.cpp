class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // 10:27
        unordered_map<char, int> mNote;
        unordered_map<char, int> mMaga;
        
        for (auto c : ransomNote)
            mNote[c]++;
        for (auto c : magazine)
            mMaga[c]++;
        
        for (auto m : mNote)
        {
            char c = m.first;
            
            while (mNote[c] != 0 && mMaga[c] != 0)
            {
                mNote[c]--; mMaga[c]--;    
            }
            
            if (mMaga[c] == 0 && mNote[c] != 0)
                return false;
            
        }
        
        return true;
        
    }
};