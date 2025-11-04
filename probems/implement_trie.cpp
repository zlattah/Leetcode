#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;
struct Node{
    char val;
    unordered_map<char,Node*> next;
    Node(char v){
        val = v;
    }
};
class Trie {
    private:
        Node*root;
    public:
        Trie() {
            root->val = 'a';
        }
        
        void insert(string word) {
            Node* current = root;
            for (int i=0;i<word.size();i++){
                Node newnode(word[i]);
                unordered_map<char,Node*> current_map = current->next;
                current_map[word[i]] = &newnode;
                current = current->next[word[i]];
            }

        }
        
        bool search(string word) {
            
        }
        
        bool startsWith(string prefix) {
            
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */