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
void printlist(list& l) {
    node* tmp = l.head;
    while (tmp != NULL) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
list mergeTwoSortedLists(list& l1, list& l2) {
    list result;
    createlist(result);

    node* p1 = l1.head;
    node* p2 = l2.head;

    while (p1 != NULL && p2 != NULL) {
        if (p1->data <= p2->data) {
            addtail(result, p1->data);
            p1 = p1->next;
        } else {
            addtail(result, p2->data);
            p2 = p2->next;
        }
    }
    while (p1 != NULL) {
        addtail(result, p1->data);
        p1 = p1->next;
    }
    while (p2 != NULL) {
        addtail(result, p2->data);
        p2 = p2->next;
    }
    return result;
}
int main() {
    list l1, l2;
    createlist(l1);
    createlist(l2);
    addtail(l1, 5);
    addtail(l1, 8);
    addtail(l1, 3);
    addtail(l2, 7);
    addtail(l2, 4);
    addtail(l2, 6);cout << "Danh sach 1: ";
    printlist(l1);
    cout << "Danh sach 2: ";
    printlist(l2);
    list mergedList = mergeTwoSortedLists(l1, l2);
    cout << "Danh sach da hop nhat: ";
    printlist(mergedList);
    return 0;
};
