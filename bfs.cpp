#include<iostream>
#include<queue>
using namespace std;

class node {
public:
    node *left, *right;
    int data;
};

class Breadthfs {
public:
    node* insert(node*, int);
    void bfs(node*);
};

node* Breadthfs::insert(node* root, int data) {
    if (!root) {
        root = new node;
        root->left = NULL;
        root->right = NULL;
        root->data = data;
        return root;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new node;
            temp->left->left = NULL;
            temp->left->right = NULL;
            temp->left->data = data;
            return root;
        }
        else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new node;
            temp->right->left = NULL;
            temp->right->right = NULL;
            temp->right->data = data;
            return root;
        }
        else {
            q.push(temp->right);
        }
    }
    
    return root; // Ensure all control paths return a value
}

void Breadthfs::bfs(node* head) {
    queue<node*> q;
    q.push(head);

    while (!q.empty()) {
        node* currNode = q.front();
        q.pop();
        cout << "\t" << currNode->data;

        if (currNode->left)
            q.push(currNode->left);
        if (currNode->right)
            q.push(currNode->right);
    }
}

int main() {
    node* root = NULL;
    int data;
    char ans;

    do {
        cout << "\nEnter data => ";
        cin >> data;

        Breadthfs bfs_obj;
        root = bfs_obj.insert(root, data);

        cout << "Do you want to insert one more node? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');

    Breadthfs bfs_obj;
    bfs_obj.bfs(root);

    return 0;
}
