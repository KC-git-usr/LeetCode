struct TrieNode {
    bool isWord;
    TrieNode* children[26];

    TrieNode() {
        isWord = false;
        for(int i = 0; i < 26; ++i)
            children[i] = nullptr;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        this->root = new TrieNode;
    }

    void insert(string word) {
        TrieNode* curr_node = this->root;
        int index = 0;

        for(int i = 0; i < word.size(); ++i) {
            index = word[i] - 'a';
            if(curr_node->children[index] == nullptr)
                curr_node->children[index] = new TrieNode;
            curr_node = curr_node->children[index];
        }
        curr_node->isWord = true;
    }

    bool search(string word) {
        TrieNode* curr_node = this->root;
        int index = 0;

        for(int i = 0; i < word.size(); ++i) {
            index = word[i] - 'a';
            if(curr_node->children[index] == nullptr)
                return false;
            curr_node = curr_node->children[index];
        }

        return curr_node->isWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr_node = this->root;
        int index = 0;

        for(int i = 0; i < prefix.size(); ++i) {
            index = prefix[i] - 'a';
            if(curr_node->children[index] == nullptr)
                return false;
            curr_node = curr_node->children[index];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */