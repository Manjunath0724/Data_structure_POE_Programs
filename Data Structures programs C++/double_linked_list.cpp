#include<iostream>
#include<cstdlib>
using namespace std;

struct node
{
    struct node *prev;
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
        struct node *newnode, *current;

        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL) {
            cout << "\nOverflow\n";
        }
        cout << "\nEnter the data: ";
        cin >> newnode->data;
        newnode->next = NULL;
        newnode->prev = NULL;

        if (start == NULL) {
            start = newnode;
            current = newnode;
        }
        else {
            current->next = newnode;
            newnode->prev = current;
            current = newnode;
        }

        cout << "Do you want to create another node(1/0) : ";
        cin >> ch;
    } while (ch != 0);
}

void display()
{
    struct node *newnode, *temp;
    if (start == NULL) {
        cout << "\nList is empty\n";
    }
    else {
        cout << "\nThe Double Linked List in forward direction : ";
        newnode = start;
        while (newnode->next != NULL) {
            temp = newnode;
            cout << newnode->data << "-->";
            newnode = newnode->next;
        }
        cout << newnode->data << "\n";

        cout << "\nThe Double Linked List in backward direction : ";
        cout << newnode->data;
        newnode = temp;
        while (newnode->prev != NULL) {
            cout << "-->" << newnode->data;
            newnode = newnode->prev;
        }
        cout << "-->" << newnode->data;
        cout << "\n";
    }
}

void insertbeg()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
        cout << "\nOverflow\n";
    if (start == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
        start = newnode;
    }
    else {
        newnode->prev = NULL;
        newnode->next = start;
        start->prev = newnode;
        start = newnode;
        cout << "\nEnter the data:";
        cin >> newnode->data;
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
    int nodedata = 0, flag = 0;
    struct node *newnode, *temp;
    cout << "\nEnter the node after which new node is to be inserted:";
    cin >> nodedata;

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        cout << "\nOverflow\n";
    }
    cout << "\n Enter the data:";
    cin >> newnode->data;

    if (start == NULL) {
        newnode->prev = NULL;
        newnode->next = NULL;
        start = newnode;
    }
    else {
        temp = start;
        while (temp != NULL) {
            if (nodedata == temp->data) {
                flag = 1;
                break;
            }
            else
                temp = temp->next;
        }
    }
    if (flag == 1) {
        temp->next->prev = newnode;
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        cout << "\nData successfully inserted\n";
    }
    else
        cout << "\nElement not found\n";
}

void insertloc()
{
    int loc = 0, c = 0, i = 1;
    struct node *newnode, *temp;
    cout << "\nEnter the location:";
    cin >> loc;
    c = count();
    if (loc > c) {
        cout << "\nLocation not found\n";
        return;
    }
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        cout << "\nOverflow\n";
    }
    cout << "\n Enter the data:";
    cin >> newnode->data;

    if (start == NULL) {
        newnode->prev = NULL;
        newnode->next = NULL;
        start = newnode;
    }
    else {
        temp = start;
        for (i = 1; i < loc; i++) {
            temp = temp->next;
        }
        if (loc == 1) {
            newnode->prev = NULL;
            newnode->next = start;
            start->prev = newnode;
            start = newnode;
        }
        else {
            temp->prev->next = newnode;
            newnode->prev = temp->prev;
            newnode->next = temp;
            temp->prev = newnode;
        }
    }
}

void insertend()
{
    struct node *temp, *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        cout << "\nOverflow\n";
    }
    cout << "\nEnter the data:";
    cin >> newnode->data;

    if (start == NULL) {
        newnode->prev = NULL;
        newnode->next = NULL;
        start = newnode;
    }
    else {
        temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next = NULL;
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
        temp->next->prev = NULL;
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
    struct node *newnode, *temp, *prevnode;
    cout << "\nEnter the location:";
    cin >> loc;
    c = count();
    if (loc > c) {
        cout << "\nLocation not found\n";
        return;
    }
    if (start == NULL) {
        cout << "\n List is empty.\n";
    }
    else {
        temp = start;
        while (i < loc) {
            prevnode = temp;
            temp = temp->next;
            i++;
        }
        if (loc == 1) {
            temp->next->prev = NULL;
            start = temp->next;
            free(temp);
            cout << "\nElement successfully deleted.\n";
        }
        else {
            prevnode->next = temp->next;
            temp->next->prev = prevnode;
            free(temp);
            cout << "\nElement successfully deleted.\n";
        }
    }
}

void deletenode()
{
    int nodedata = 0, flag = 0;
    struct node *prevnode, *temp;
    cout << "\nenter the node value which is to be deleted:";
    cin >> nodedata;

    if (start == NULL) {
        cout << "\nList is empty.\n";
    }
    else {
        temp = start;
        if (nodedata == temp->data) {
            start = temp->next;
            temp->next->prev = NULL;
            free(temp);
            cout << "\nElement successfully deleted.\n";
        }
        else {
            while (temp != NULL) {
                if (nodedata == temp->data) {
                    flag = 1;
                    break;
                }
                else {
                    prevnode = temp;
                    temp = temp->next;
                }
            }
            if (flag == 1) {
                prevnode->next = temp->next;
                temp->next->prev = prevnode;
                free(temp);
                cout << "\nElement successfully deleted.\n";
            }
            else
                cout << "\nElement not found";
        }
    }
}

int main()
{
    int choice;
    while (1) {
        cout << "\n\n1.Create list\t\t2.Display\n3.Insert at beginning\t4.Insert at end \n5.Insert at Location\t6.Insert after specific node";
        cout << "\n7.Delete at beginning\t8.Delete at end\n9.Delete at Location\t10.Delete at specific node\n11.Exit\n\nEnter the choice:";
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
