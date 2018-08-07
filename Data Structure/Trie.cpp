#include <iostream>
#include <string>
using namespace std;
const int NUMBER_OF_ALPHABET = 26;
struct node {
    node* c[NUMBER_OF_ALPHABET];
    int count;
};
struct Trie {
    node* root; 
    node* getnode() {
        node* newnode = new node;
        for (int i = 0; i < NUMBER_OF_ALPHABET; i++)
            newnode->c[i] = NULL;
        newnode->count = 0;
        return newnode;
    }
    void insert(string x) {
        node* p;
        p = root;
        for (int i = 0; i < x.length(); i++) {
            int index = x[i] - 'a';
            if (p->c[index] == NULL) p->c[index] = getnode();
            p = p->c[index];
        }
        p->count++;
    }
    bool search(string x) {
        node* p;
        p = root;
        for (int i = 0; i < x.length(); i++) {
            int index = x[i] - 'a';
            if (p->c[index] == NULL) return false;
            p = p->c[index];
        }
        return (p->count > 0);
    }
};
int n;
int main() {
    Trie* T = new Trie;
    T->root = T->getnode();
    cout << "Input number of string : " << "\n";
    cin >> n;
    cout << "Input strings" << "\n";
    for (int i = 1; i <= n; i++) {
        string x;
        cin >> x;
        T->insert(x);
    }
    cout << "Input number of queries : " << "\n";
    int q;
    cin >> q;
    cout << "Input string to search : " << "\n";
    while (q-- > 0) {
        string s;
        cin >> s;
        if (T->search(s)) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}