/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        root->next = NULL;
        queue<Node*> q;
        q.push(root);
        vector<Node*> v;
        while(!q.empty()){
            while(!q.empty()){
                Node* temp = q.front();
                if(temp->left!=NULL){
                    v.push_back(temp->left);
                    v.push_back(temp->right);
                }
                q.pop();
            }
            if(v.size() > 0){
                for(int i=0; i<v.size()-1; i++){
                    v[i]->next = v[i+1];
                    q.push(v[i]);
                }
                v[v.size()-1]->next = NULL;
                q.push(v[v.size()-1]);
                v.clear();
            }
            
        }
        return root;
    }
};
