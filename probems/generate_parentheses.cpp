#include <iostream>
#include <vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<string> generated_patterns;
    struct node{
        string s;
        int numopen;
        int numclosed;
        node* left;
        node* right;
    };

    void getchildren(int n, node *root){
        if (root->numopen<n){
            root->left = new node;
            root->left->numopen = root->numopen+1;
            root->left->numclosed = root->numclosed;
            root->left->s = root->s + "(";
            getchildren(n, root->left);
        }
        if (root->numclosed<n && root->numopen>root->numclosed){
            root->right = new node;
            root->right->numopen = root->numopen;
            root->right->numclosed = root->numclosed+1;
            root->right->s = root->s + ")";
            getchildren(n, root->right);
        }
        if (root->numopen == n && root->numclosed == n) 
            generated_patterns.push_back(root->s);
    }
    vector<string> generateParenthesis(int n) {
        node *root = new node();
        root->s = "(";
        root->numopen = 1;
        root->numclosed = 0;
        getchildren(n,root);
        return generated_patterns;
    }
};
int main(){
    Solution s;
    vector<string> patterns;
    patterns = s.generateParenthesis(3);
    for (int i=0;i<patterns.size();i++)
        cout<<patterns[i]<<" ";
    return 0;
}