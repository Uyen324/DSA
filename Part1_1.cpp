//1
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
int countNodes(list& l) {
    node* tmp = l.head;
    int count = 0;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
node* findMiddle(list& l) {
    int count = countNodes(l);  
    if (count == 0) return NULL;  

    int mid = count / 2;  
    node* tmp = l.head;

    for (int i = 0; i < mid; i++) {
        tmp = tmp->next;
    }

    return tmp;
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
    list l;
    createlist(l);
    addtail(l, 1);
    addtail(l, 2);
    addtail(l, 3);
    addtail(l, 4);
    addtail(l, 5);
    cout << "Danh sach lien ket: ";
    printlist(l);

    node* middle = findMiddle(l);
    if (middle != NULL) {
        cout << "Node giua cua danh sach: " << middle->data << endl;
    } else {
        cout << "Danh sach rong!" << endl;
    }

    return 0;
};

 





