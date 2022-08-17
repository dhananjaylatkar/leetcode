class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        
        for (string word: words)
        {
            string curr = "";
            
            for (char c: word)
            {
                curr += morse[c-'a'];
            }
            s.insert(curr);
        }
        
        return s.size();
    }
};