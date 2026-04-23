#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    int data;
    struct node *next;
}*start = NULL;

void create();
void display();
void insertbeg();
void insertend();
void insertnode();
void insertloc();
void deletebeg();
void deleteend();
void deleteloc();
void deletenode();
int count();

void create()
{
    int ch;
    do {
        struct node *new_node, *current;

        new_node = (struct node *)malloc(sizeof(struct node));

        cout << "\nEnter the data : ";
        cin >> new_node->data;
        new_node->next = NULL;

        if (start == NULL) {
            start = new_node;
            current = new_node;
        }
        else {
            current->next = new_node;
            current = new_node;
        }

        cout << "Do you want to create another node(1/0) : ";
        cin >> ch;
    } while (ch != 0);
}

void display()
{
    struct node *new_node;
    if (start == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nThe Linked List : ";
        new_node = start;
        while (new_node->next != NULL) {
            cout << new_node->data << "--->";
            new_node = new_node->next;
        }
        cout << new_node->data << "\n";
    }
}

void insertbeg()
{
    struct node *curr;
    curr = (struct node *)malloc(sizeof(struct node));
    if (start == NULL) {
        curr->next = NULL;
        start = curr;
    }
    else {
        curr->next = start;
        start = curr;
        cout << "\nEnter the value of data:";
        cin >> curr->data;
    }
}

int count()
{
    int i = 0;
    struct node *temp;
    temp = start;
    while (temp != NULL) {
        i++;
        temp = temp->next;
    }
    return (i);
}

void insertnode()
{
    int nodedata = 0;
    struct node *newnode, *temp;
    cout << "\nenter the node after which new node is to be inserted:";
    cin >> nodedata;

    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "\n Enter the data";
    cin >> newnode->data;

    if (start == NULL) {
        start = newnode;
    }
    else {
        temp = start;
        while (temp->next != NULL) {
            if (nodedata == temp->data)
                break;
            else
                temp = temp->next;
        }
    }
    newnode->next = temp->next;
    temp->next = newnode;
}

void insertloc()
{
    int loc = 0, c = 0, i = 1;
    struct node *newnode, *temp, *prev;
    cout << "\nenter the location:";
    cin >> loc;
    c = count();
    if (loc > c) {
        cout << "\nlocation not found\n";
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    cout << "\n Enter the data";
    cin >> newnode->data;

    if (start == NULL) {
        start = newnode;
    }
    else {
        if (loc == 1) {
            newnode->next = start;
            start = newnode;
        }
        else {
            temp = start;
            for (i = 1; i < loc - 1; i++) {
                temp = temp->next;
            }
            prev = temp->next;
            temp->next = newnode;
            newnode->next = prev;
        }
    }
}

void insertend()
{
    struct node *temp, *curr;
    curr = (struct node *)malloc(sizeof(struct node));
    cout << "\nEnter the value of data:";
    cin >> curr->data;

    if (start == NULL) {
        curr->next = NULL;
        start = curr;
    }
    else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = curr;
        curr->next = NULL;
    }
}

void deletebeg()
{
    struct node *temp;
    if (start == NULL)
        cout << "\nList is empty.\n";
    else {
        temp = start;
        start = temp->next;
        free(temp);
        cout << "\n Element successfully deleted";
    }
}

void deleteend()
{
    struct node *temp, *prevnode;
    if (start == NULL)
        cout << "\nList is empty.\n";
    else {
        temp = start;
        while (temp->next != NULL) {
            prevnode = temp;
            temp = temp->next;
        }
        prevnode->next = NULL;
        free(temp);
        cout << "\n Element successfully deleted";
    }
}

void deleteloc()
{
    int loc = 0, c = 0, i = 1;
    struct node *newnode, *temp, *prev;
    cout << "\nenter the location:";
    cin >> loc;
    c = count();
    if (loc > c) {
        cout << "\nlocation not found\n";
        return;
    }
    if (start == NULL) {
        cout << "\n List is empty.\n";
    }
    else {
        temp = start;
        while (i < loc) {
            prev = temp;
            temp = temp->next;
            i++;
        }
        if (loc == 1)
            start = temp->next;
        else
            prev->next = temp->next;
        free(temp);
        cout << "\nElement successfully deleted.\n";
    }
}

void deletenode()
{
    int nodedata = 0, flag = 0;
    struct node *prev, *temp;
    cout << "\nenter the node value which is to be deleted:";
    cin >> nodedata;

    if (start == NULL) {
        cout << "\nList is empty.\n";
    }
    else {
        temp = start;
        if (nodedata == temp->data) {
            start = temp->next;
            free(temp);
        }
        else {
            while (temp != NULL) {
                if (nodedata == temp->data) {
                    flag = 1;
                    break;
                }
                else {
                    prev = temp;
                    temp = temp->next;
                }
            }
            if (flag == 1) {
                prev->next = temp->next;
                free(temp);
                cout << "\nElement successfully deleted.\n";
            }
            else
                cout << "\n Element not found\n";
        }
    }
}

int main()
{
    int choice;
    while (1) {
        cout << "\n\n1.Create list\n2. Display\n3.Insert at begining\n4. Insert at end \n5.Insert at Location \n6.Insert after specific node";
        cout << "\n7.Delete at begining\n8. Delete at end\n9.delete at Location\n10.Delete at specific node\n11.Exit\n Enter the choice:";
        cin >> choice;
        switch (choice) {
        case 1: create(); break;
        case 2: display(); break;
        case 3: insertbeg(); break;
        case 4: insertend(); break;
        case 5: insertloc(); break;
        case 6: insertnode(); break;
        case 7: deletebeg(); break;
        case 8: deleteend(); break;
        case 9: deleteloc(); break;
        case 10: deletenode(); break;
        case 11: exit(0);
        default: cout << "wrong choice";
        }
    }
    return 0;
}
