#include <iostream>

class Node {
    public:
    int data;
    Node* next;
    Node(int val) {
        this->data = val;
        next =NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    void insert(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteNode(int val) {
        if (!head) {
            std::cout << "List is empty. Deletion failed." << std::endl;
            return;
        }

        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        Node* current = head;
        while (current && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            std::cout << "Node with value " << val << " not found." << std::endl;
            return;
        }

        prev->next = current->next;
        delete current;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    
    void reverse(){
        
    }
};

int main() {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);

    std::cout << "Original linked list: ";
    list.display();

    list.deleteNode(3); // Deleting node with value 3

    std::cout << "Linked list after deletion: ";
    list.display();

     std::cout << "Reverse Linked list: ";
    list.reverse();

    return 0;
}
