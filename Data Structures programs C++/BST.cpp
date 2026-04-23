#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int info;
    struct node *lchild;
    struct node *rchild;
}*root;

void insert(int item);
void del(int item);
void inorder(struct node *ptr);
void preorder(struct node *ptr);
void postorder(struct node *ptr);
void display(struct node *ptr, int level);
void find(int item, struct node **par, struct node **loc);
void case_a(struct node *par, struct node *loc);
void case_b(struct node *par, struct node *loc);
void case_c(struct node *par, struct node *loc);

int main()
{
    int choice, num;
    root = NULL;
    while (1) {
        cout << "\n";
        cout << "\n1.Insert node\n2.delete\n3.inorder\n4.preorder traversal\n5.postorder traversal\n6.display\n7.exit enter the choice ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "enter the number to be inserted";
            cin >> num;
            insert(num);
            break;
        case 2:
            cout << "enter the number to be deleted";
            cin >> num;
            del(num);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            preorder(root);
            break;
        case 5:
            postorder(root);
            break;
        case 6:
            display(root, 1);
            break;
        case 7:
            exit(0);
        }
    }
    return 0;
}

void find(int item, struct node **par, struct node **loc)
{
    struct node *ptr, *ptrsave;
    if (root == NULL) {
        *loc = NULL;
        *par = NULL;
        return;
    }
    if (item == root->info) {
        *loc = root;
        *par = NULL;
        return;
    }
    if (item < root->info)
        ptr = root->lchild;
    else
        ptr = root->rchild;
    ptrsave = root;
    while (ptr != NULL) {
        if (item == ptr->info) {
            *loc = ptr;
            *par = ptrsave;
            return;
        }
        ptrsave = ptr;
        if (item < ptr->info)
            ptr = ptr->lchild;
        else
            ptr = ptr->rchild;
    }
    *loc = NULL;
    *par = ptrsave;
    return;
}

void insert(int item)
{
    struct node *temp, *parent, *loc;
    find(item, &parent, &loc);
    if (loc != NULL) {
        cout << "item allready present\n";
        return;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = item;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if (parent == NULL)
        root = temp;
    else if (item < parent->info)
        parent->lchild = temp;
    else
        parent->rchild = temp;
    return;
}

void del(int item)
{
    struct node *parent, *loc;
    if (root == NULL) {
        cout << "tree is emppty\n";
        return;
    }
    find(item, &parent, &loc);
    if (loc == NULL) {
        cout << "item not present in tree";
        return;
    }
    if (loc->lchild == NULL && loc->rchild == NULL)
        case_a(parent, loc);
    if (loc->lchild != NULL && loc->rchild == NULL)
        case_b(parent, loc);
    if (loc->lchild == NULL && loc->rchild != NULL)
        case_b(parent, loc);
    if (loc->lchild != NULL && loc->rchild != NULL)
        case_c(parent, loc);
    free(loc);
    return;
}

void case_a(struct node *par, struct node *loc)
{
    if (par == NULL)
        root = NULL;
    else if (loc == par->lchild)
        par->lchild = NULL;
    else
        par->rchild = NULL;
    return;
}

void case_b(struct node *par, struct node *loc)
{
    struct node *child;
    if (loc->lchild != NULL)
        child = loc->lchild;
    else
        child = loc->rchild;
    if (par == NULL)
        root = child;
    else if (loc == par->lchild)
        par->lchild = child;
    else
        par->rchild = child;
    return;
}

void case_c(struct node *par, struct node *loc)
{
    struct node *ptr, *ptrsave, *suc, *parsuc;
    ptrsave = loc;
    ptr = loc->rchild;
    while (ptr->lchild != NULL) {
        ptrsave = ptr;
        ptr = ptr->lchild;
    }
    suc = ptr;
    parsuc = ptrsave;
    if (suc->lchild == NULL && suc->rchild == NULL)
        case_a(parsuc, suc);
    else
        case_b(parsuc, suc);
    if (par == NULL)
        root = suc;
    else if (loc == par->lchild)
        par->lchild = suc;
    else
        par->rchild = suc;
    suc->lchild = loc->lchild;
    suc->rchild = loc->rchild;
    return;
}

void preorder(struct node *ptr)
{
    if (root == NULL) {
        cout << "tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        cout << ptr->info;
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }
    return;
}

void inorder(struct node *ptr)
{
    if (root == NULL) {
        cout << "tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        inorder(ptr->lchild);
        cout << ptr->info;
        inorder(ptr->rchild);
    }
    return;
}

void postorder(struct node *ptr)
{
    if (root == NULL) {
        cout << "tree is empty\n";
        return;
    }
    if (ptr != NULL) {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout << ptr->info;
    }
    return;
}

void display(struct node *ptr, int level)
{
    int i;
    if (ptr != NULL) {
        display(ptr->rchild, level + 1);
        cout << "\n";
        for (i = 0; i < level; i++)
            cout << "  ";
        cout << ptr->info << "\t";
        display(ptr->lchild, level + 1);
    }
    return;
}
