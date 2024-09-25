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
    } else {
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
void removeDuplicates(list& l) {
    if (l.head == NULL) return;

    node* current = l.head;
    while (current != NULL && current->next != NULL) {
        if (current->data == current->next->data) {
            node* duplicate = current->next;
            current->next = current->next->next;
            delete duplicate;  
        } else {
            current = current->next; 
        }
    }
    l.tail = current;
}

int main() {
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 2);
    addtail(l, 3);
    addtail(l, 3);
    addtail(l, 4);
    cout << "Danh sach ban dau: ";
    printlist(l);
    removeDuplicates(l);
    cout << "Danh sach sau khi loai bo phan tu trung lap: ";
    printlist(l);
    return 0;
}

