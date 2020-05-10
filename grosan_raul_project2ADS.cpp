// PROJECT 2 ADS HOMEWORK
//made by raul grosan g3 sg4

#include <cstdlib>
#include <iostream>

using namespace std;

//basic definition of class Node

class Node {
private:
    int val;
    Node * next;

public:
	//set the value of the node
    void setVal(int);
    //return the value of the node
    int getVal();
    //self explaining
    Node* getNext();
    void setNext(Node*);
};

int Node::getVal(){
    return this->val;
}

void Node::setVal(int n) {
    this->val = n;
}

void Node::setNext(Node * node) {
    this->next = node;
}

Node *Node::getNext(){
    return this->next;
}

//linked list implementation now

class LinkedList {
private:
    Node * head;
    int size;

public:
    LinkedList();
    void append(int);
    void remove(int);
    void printAll();
    int getSize();
    void setSize(int);
    Node* GH();
    Node *findNode(int val);
    void startRemoval(int startingPoint);
};

Node *LinkedList::GH(){
    return this->head;
}

LinkedList::LinkedList() {
    this->head = new Node();
    this->head->setNext(nullptr);
    this->head->setVal(1);
    this->size = 1;
}

void LinkedList::append(int mval) {
    Node *head = GH();
    Node *mNode = new Node();
    mNode->setVal(mval);
    if (head->getNext() == nullptr) {
        head->setNext(mNode);
        mNode->setNext(head);
    } else {
        Node *lNode = GH();
        for (int i = 1; i < this->size; i++) {
            lNode =lNode->getNext();
        }
        lNode->setNext(mNode);
        mNode->setNext(head);
    }

    this->size += 1;
}

void LinkedList::printAll(){
    Node *lNode = GH();
    for (int i = 1; i <= this->size; i++) {
        std::cout << lNode->getVal() << " ";
        lNode = lNode->getNext();
    }
    std::cout << std::endl;
}

int LinkedList::getSize(){
    return this->size;
}

void LinkedList::setSize(int size) {
    this->size = size;
}

void LinkedList::remove(int val) {
    Node *lNode = GH();
    Node *auxNode = GH();
    if (val == lNode->getVal()) {
        for (int i = 1; i < this->size; i++) {
            auxNode =auxNode->getNext();
        }
        auxNode->setNext(lNode->getNext());
        this->head = lNode->getNext();
        delete (lNode);
    }
    else {
        Node *precedent = GH();
        auxNode = precedent->getNext();
        for (int i = 2; i < this->size; i++) {
            if( auxNode->getVal() == val) break;
            precedent = precedent->getNext();
            auxNode = auxNode->getNext();
        }
        precedent->setNext(auxNode->getNext());
        delete (auxNode);
    }
    this->size-=1;
}

Node* LinkedList::findNode(int val){
    Node* currentNode = GH();

    while(currentNode->getVal() != val){
        currentNode = currentNode->getNext();
    }

    return currentNode;
}

void LinkedList::startRemoval(int startingPoint) {
    Node *removal = this->findNode(startingPoint);
    while (this->size > 1) {
            this->remove(removal->getNext()->getVal());
            removal = removal->getNext();
    }
}

LinkedList generate_list(int size){
    LinkedList circle;
    for(int i=2;i<=size;i++){
        circle.append(i);
    }
    return circle;
}

//main
int main() {
    LinkedList l;
    int n,m;
    cout<<"how many peeps? ";
    cin>>n;
    cout<<"starting one?: ";
	cin>>m;
    l= generate_list(n);
    l.startRemoval(m);
    cout<<"last man standing: ";
    l.printAll();
    return 0;
}