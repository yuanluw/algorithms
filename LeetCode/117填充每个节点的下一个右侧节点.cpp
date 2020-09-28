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
        
        Node* startNode = root;
        Node* last = NULL;
        Node* nextLayerNode = NULL;
        while(startNode){
            last = NULL;
            nextLayerNode = NULL;
            for(Node* temp = startNode; temp!=NULL; temp = temp->next){
                if(temp->left){
                    if(last){
                        last->next = temp->left;
                    }
                    if(!nextLayerNode){
                        nextLayerNode = temp->left;
                    }
                    last = temp->left;
                }
                if(temp->right){
                    if(last){
                        last->next = temp->right;
                    }
                    if(!nextLayerNode){
                        nextLayerNode = temp->right;
                    }
                    last = temp->right;
                }
            }
            startNode = nextLayerNode;
        }

        return root;
    }
};
