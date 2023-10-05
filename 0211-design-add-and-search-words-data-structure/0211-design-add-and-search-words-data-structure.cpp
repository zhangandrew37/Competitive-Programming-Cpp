class WordDictionary {
    bool isEndOfWord;
    vector<WordDictionary*> children;
public:
    
    WordDictionary(): isEndOfWord(false){
        children = vector<WordDictionary*>(26,nullptr);
    }
    
    void addWord(string word) {
        WordDictionary *cur = this;
        for(char c : word){
            if (cur->children[c-'a'] == nullptr) //if not already in dic
                cur->children[c-'a']= new WordDictionary();
            cur = cur->children[c-'a'];
        }
        cur->isEndOfWord = true;
    }
    
    bool search(string word) {
        WordDictionary *trav = this;
        for (int i = 0; i < word.length(); i++){
            char c = word[i];
            if (c == '.'){
                for (auto ch : trav->children){
                    if (ch && ch->search(word.substr(i+1))) return true;
                }
                
                return false;
            }
            
            if (trav->children[c-'a'] == nullptr) return false;
            trav = trav->children[c - 'a'];
        }
        
        return trav && trav->isEndOfWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */