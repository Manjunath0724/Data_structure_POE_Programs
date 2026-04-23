#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create();
void inorder(struct node *root);
void preorder(struct node *root);
void postorder(struct node *root);

int main()
{
    struct node *root;
    root = create();
    cout << "\ninorder is:\n";
    inorder(root);
    cout << "\npreorder is:\n";
    preorder(root);
    cout << "\npostorder is:\n";
    postorder(root);
    return 0;
}

struct node *create()
{
    struct node *temp, *root;
    int ch, val;
    temp = (struct node *)malloc(sizeof(struct node));
    cout << "press -1 to exit\n";
    cin >> ch;
    if (ch == -1) {
        return 0;
    }
    else {
        cout << "enter data\n";
        cin >> val;
        temp->data = val;
        temp->left = 0;
        temp->right = 0;
        cout << "enter the left of child " << val << "\n";
        temp->left = create();
        cout << "enter the right of child " << val << "\n";
        temp->right = create();
        return temp;
    }
}

void inorder(struct node *root)
{
    if (root != 0) {
        inorder(root->left);
        cout << root->data << "\t";
        inorder(root->right);
    }
}

void preorder(struct node *root)
{
    if (root != 0) {
        cout << root->data << "\t";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct node *root)
{
    if (root != 0) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << "\t";
    }
}
