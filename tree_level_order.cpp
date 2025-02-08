#include<iostream>
#include<queue>

using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

node* create(node* root)
{
    int data;
    cin >> data;

    // If data is -1, return NULL (to represent no child)
    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);
    cout << "Enter left child of " << data << ": ";
    root->left = create(root->left); // Recur for left child
    cout << "Enter right child of " << data << ": ";
    root->right = create(root->right); // Recur for right child

    return root;
}

void levelOrder(node* root)
{
    if (root == NULL) return; // Return if the tree is empty
    
    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        node* temp = q.front();
        q.pop(); // Remove the node from the front of the queue
        cout << temp->data << " ";  // Print the node's data

        // Push left child to the queue if it exists
        if (temp->left)
        {
            q.push(temp->left);
        }

        // Push right child to the queue if it exists
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
}

int main()
{
    cout << "Enter data for the tree (use -1 for NULL):" << endl;
    node* root = NULL;
    root = create(root);  // Create the tree based on user input

    cout << "Printing level order traversal: ";
    levelOrder(root); // Print level-order traversal of the tree

    return 0;
}
