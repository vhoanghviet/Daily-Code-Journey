#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* pNext;
};

bool insertAfterY(Node* &head, int x, int y) {
    for(Node* temp = head; temp != NULL; temp = temp->pNext) {
        if(temp->data == y) {
            Node* newNode = new Node;
            newNode->data = x;
            newNode->pNext = temp->pNext;
            temp->pNext = newNode;
            return true;
        }
    }
    return false;
}


int main() {
    return 0;
}