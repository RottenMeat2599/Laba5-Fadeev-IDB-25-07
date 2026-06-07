#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> preorder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    result.push_back(root->data);
    vector<int> left = preorder(root->left);
    vector<int> right = preorder(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

vector<int> inorder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    vector<int> left = inorder(root->left);
    vector<int> right = inorder(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.push_back(root->data);
    result.insert(result.end(), right.begin(), right.end());
    return result;
}

vector<int> postorder(Node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    vector<int> left = postorder(root->left);
    vector<int> right = postorder(root->right);

    result.insert(result.end(), left.begin(), left.end());
    result.insert(result.end(), right.begin(), right.end());
    result.push_back(root->data);
    return result;
}

void level_order(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << "\n";
    }
}

int findMax(Node* root) {
    if (root == nullptr) return INT_MIN;
    int leftMax = findMax(root->left);
    int rightMax = findMax(root->right);
    return max(root->data, max(leftMax, rightMax));
}

int findMin(Node* root) {
    if (root == nullptr) return INT_MAX;
    int leftMin = findMin(root->left);
    int rightMin = findMin(root->right);
    return min(root->data, min(leftMin, rightMin));
}

void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "\n";
}

int main() {
    Node* tree1 = new Node(5);
    tree1->left = new Node(3);
    tree1->right = new Node(7);
    tree1->left->left = new Node(2);
    tree1->left->right = new Node(4);
    tree1->right->left = new Node(6);
    tree1->right->right = new Node(8);

    Node* tree2 = new Node(10);
    tree2->left = new Node(20);
    tree2->right = new Node(30);
    tree2->left->left = new Node(40);
    tree2->left->right = new Node(50);

    cout << "Tree 1:\n";
    cout << "Preorder: "; printVector(preorder(tree1));
    cout << "Inorder: "; printVector(inorder(tree1));
    cout << "Postorder: "; printVector(postorder(tree1));
    cout << "Level order:\n"; level_order(tree1);
    cout << "Max: " << findMax(tree1) << ", Min: " << findMin(tree1) << "\n\n";

    cout << "Tree 2:\n";
    cout << "Preorder: "; printVector(preorder(tree2));
    cout << "Inorder: "; printVector(inorder(tree2));
    cout << "Postorder: "; printVector(postorder(tree2));
    cout << "Level order:\n"; level_order(tree2);
    cout << "Max: " << findMax(tree2) << ", Min: " << findMin(tree2) << "\n";

    delete tree1->left->left; 
    delete tree1->left->right;
    delete tree1->right->left; 
    delete tree1->right->right;
    delete tree1->left; 
    delete tree1->right; 
    delete tree1;

    delete tree2->left->left; 
    delete tree2->left->right;
    delete tree2->left; 
    delete tree2->right; 
    delete tree2;

    return 0;
}