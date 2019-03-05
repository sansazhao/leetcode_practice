// 数据结构：queue
class Solution {
public:
      int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict;
        for(int i = 0;i < wordList.size(); i++)
            dict.insert(wordList[i]);
        if(dict.count(endWord) == 0) return 0;
        queue<string>q;
        addNeighbor(q, beginWord, dict);
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            level++;
            while(size-- > 0){
                string w = q.front();
                q.pop();
                if(w == endWord)
                    return level;
                addNeighbor(q, w, dict);
            }
        }
        return 0;
    }
    
    void addNeighbor(queue<string>& q, string word, unordered_set<string>& dict){
        dict.erase(word);
        for(int l = 0; l < word.length(); ++l){
            char letter = word[l];
            for(int i = 0; i < 26; ++i){
                word[l] = 'a' + i;
                if(dict.count(word)){
                    q.push(word);
                    dict.erase(word);
                }
            }
            word[l] = letter;
        }
    }
};