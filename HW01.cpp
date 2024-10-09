#include <iostream>
#include <string>

using namespace std;

struct node {
    string url;
    node* back;
    node* forward;
    node(string u) {
        url = u;  
        back = NULL;
        forward = NULL;
    }
};

struct browser_history {
    node* current;
};

void create_history(browser_history& history, string homepage) {
    history.current = new node(homepage);
}

void visit(browser_history& history, string url) {
    node* newNode = new node(url);
    history.current->forward = newNode;
    newNode->back = history.current;
    history.current = newNode;
}

string go_back(browser_history& history, int steps) {
    while (steps > 0 && history.current->back != NULL) {
        history.current = history.current->back;
        steps--;
    }
    return history.current->url;
}

string go_forward(browser_history& history, int steps) {
    while (steps > 0 && history.current->forward != NULL) {
        history.current = history.current->forward;
        steps--;
    }
    return history.current->url;
}

void delete_history(browser_history& history) {
    node* temp;
    while (history.current != NULL) {
        temp = history.current;
        history.current = history.current->back; 
        delete temp; 
    }
}

int main() {
    browser_history history;
    create_history(history, "uit.edu.vn");

    visit(history, "google.com");
    visit(history, "facebook.com");
    visit(history, "youtube.com");

    cout << go_back(history, 1) << endl;
    cout << go_back(history, 1) << endl;
    cout << go_forward(history, 1) << endl;

    visit(history, "linkedin.com");

    cout << go_forward(history, 2) << endl;
    cout << go_back(history, 2) << endl;
    cout << go_back(history, 7) << endl;

    delete_history(history);

    return 0;
}

