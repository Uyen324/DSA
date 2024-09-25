#include <iostream>
using namespace std;
struct node {
    int data;
    node* next;
};
struct list {
    node* head;
    node* tail;
};
void createlist(list& l) {
    l.head = NULL;
    l.tail = NULL;
}
void addtail(list& l, int x) {
    node* p = new node();
    p->data = x;
    p->next = NULL;
    if (l.tail == NULL) {
        l.tail = p;
        l.head = l.tail;
    }
    else {
        l.tail->next = p;
        l.tail = p;
    }
}
void findCommonData(list& l1, list& l2) {
    node* p1 = l1.head;
    node* p2;

    cout << "Cac gia tri giao nhau: ";
    while (p1 != NULL) {
        p2 = l2.head;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                cout << p1->data << " ";
                break; 
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    cout << endl;
}

void printlist(list& l) {
    node* tmp = l.head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
int main() {
    list l1, l2;
    createlist(l1);
    createlist(l2);
    addtail(l1, 1);
    addtail(l1, 2);
    addtail(l1, 3);
    addtail(l1, 4);
    addtail(l2, 3);
    addtail(l2, 4);
    addtail(l2, 5);
    addtail(l2, 6);
    cout << "Danh sach 1: ";
    printlist(l1);
    cout << "Danh sach 2: ";
    printlist(l2);
    findCommonData(l1, l2);
    return 0;
};
