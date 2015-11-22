#include <string>
using namespace std;
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
static const int NUM_LETTER = 26;
 
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        child.resize(26, NULL);
        isWord = false;
    }
    
    void addChild(int index) {
        if (index < 0 || index >= NUM_LETTER) {
            return;
        }
        this->child[index] = new TrieNode();
    }
    
    TrieNode *getChild(int index) {
        if (index < 0 || index >= NUM_LETTER) {
            return NULL;
        }
        return this->child[index];
    }
    
    void setIsWord(bool isWord) {
        this->isWord = isWord;
    }
    
    bool getIsWord() {
        return this->isWord;
    }
protected:
    vector<TrieNode *> child;
    bool isWord;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        int wl = word.length();
        int i;
        TrieNode *ptr = root;
        for (i = 0; i < wl; ++i) {
            if (ptr->getChild(word[i] - 'a') == NULL) {
                ptr->addChild(word[i] - 'a');
            }
            ptr = ptr->getChild(word[i] - 'a');
        }
        ptr->setIsWord(true);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        bool suc = false;
        DFS(root, word, 0, suc);
        return suc;
    }
protected:
    TrieNode* root;
    
    void DFS(TrieNode *r, const string &s, int idx, bool &suc) {
        if (suc) {
            return;
        }
        if (idx == s.length() && r!= NULL) {
            if (r->getIsWord()) {
                suc = true;
            }
            return;
        }
        if (s[idx] == '.') {
            int i;
            for (i = 0; i < NUM_LETTER; ++i) {
                if (r->getChild(i) != NULL) {
                    DFS(r->getChild(i), s, idx + 1, suc);
                }
            }
            return;
        }
        
        while (idx < s.length() && s[idx] != '.') {
            r = r->getChild(s[idx++] - 'a');
            if (r == NULL) {
                return;
            }
        }
        DFS(r, s, idx, suc);
    }
};
// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
