#include <iostream>
#include <cassert>

class Node {
public:
    int data;
    Node *previous;
    Node *next;

    Node(int data) {
        this->data = data;
        this->previous = nullptr;
        this->next = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    ~DoublyLinkedList() {
        Node *current = head;
        while (current  != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void addNode(int data) {
        Node *newNode = new Node(data);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
    }

    bool removeNode(int data) {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == data) {
                if (current == head) {
                    head = current->next;
                    head ? (head->previous = nullptr) : (tail = nullptr);
                } else if (current == tail) {
                    tail = current->previous;
                    tail->next = nullptr;
                } else {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                }
                delete current;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void printForward() const {
        Node *current = head;
        while (current != nullptr) {
            std::cout << current-> data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void printBackward() const {
        Node *current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current =  current->previous;
        }
        std::cout << std::endl;
    }

};

void testDooublyLinkedList() {

    DoublyLinkedList list;

    assert(list.head == nullptr);
    assert(list.tail == nullptr);

    list.addNode(10);
    list.addNode(20);
    list.addNode(30);

    list.printForward();

    list.printBackward();

    assert(list.removeNode(20));
    list.printForward();
    list.printBackward();

    assert(list.removeNode(10));
    list.printForward();
    list.printBackward();

    assert(list.removeNode(30));
    assert(list.head == nullptr);
    assert(list.tail == nullptr);

    assert(!list.removeNode(40));

    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testDooublyLinkedList();
    return 0;
}
