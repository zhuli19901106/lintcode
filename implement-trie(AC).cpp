#include <string>
using namespace std;
/**
 * Your Trie object will be instantiated and called as such:
 * Trie trie;
 * trie.insert("lintcode");
 * trie.search("lint"); will return false
 * trie.startsWith("lint"); will return true
 */
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
    static const int NUM_LETTER = 26;
    vector<TrieNode *> child;
    bool isWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
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

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *ptr = findNode(word);
        return ptr != NULL && ptr->getIsWord();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *ptr = findNode(prefix);
        return ptr != NULL;
    }
protected:
    TrieNode* root;
    
    TrieNode *findNode(string s) {
        TrieNode *ptr = root;
        int sl = s.length();
        int i;
        for (i = 0; i < sl; ++i) {
            ptr = ptr->getChild(s[i] - 'a');
            if (ptr == NULL) {
                return NULL;
            }
        }
        return ptr;
    }
};
