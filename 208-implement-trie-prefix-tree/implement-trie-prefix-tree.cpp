struct Node {
    /* Array to store links to child nodes,
    each index represents a letter */
    Node* links[26] = {nullptr};  // Initialize all to nullptr

    /* Flag indicating if 
    the node marks the end 
    of a word */
    bool flag = false;

    /* Check if the node contains
    a specific key (letter) */
    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    /* Insert a new node with a specific
    key (letter) into the Trie */
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    /* Get the node with a specific
    key (letter) from the Trie */
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    /* Set the current node
    as the end of a word */
    void setEnd() {
        flag = true;
    }

    /* Check if the 
    current node marks 
    the end of a word */
    bool isEnd() {
        return flag;
    }

    /* Node destructor to delete all child nodes recursively */
    ~Node() {
        for (int i = 0; i < 26; i++) {
            if (links[i] != nullptr) {
                delete links[i];
                links[i] = nullptr;
            }
        }
    }
};

class Trie {
    private: 
    Node* root;
public:
    Trie() {
         root = new Node();
    }
    
    void insert(string word) {
         Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                /* Create a new node for
                the letter if not present */
                node->put(ch, new Node());
            }
            // Move to the next node
            node = node->get(ch);
        }
        // Mark the end of the word
        node->setEnd();
    }
    
    bool search(string word) {
         Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                /* If a letter is 
                not found, the word 
                is not in the Trie */
                return false;
            }
            // Move to the next node
            node = node->get(ch);
        }
        /* Check if the last node
        marks the end of a word */
        return node->isEnd();
    }
    
    bool startsWith(string word) {
         Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                /* If a letter is 
                not found, the word 
                is not in the Trie */
                return false;
            }
            // Move to the next node
            node = node->get(ch);
        }
        /* Check if the last node
        marks the end of a word */
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