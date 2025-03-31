#include <iostream>
using namespace std;

class Node {
   public:
      Node* prev;
      int data;
      Node* next;

   Node(int value) {
      this->prev = nullptr;
      this->data = value;
      this->next = nullptr;
   }
};

void insertAtBeginning(Node*& head, int data);
void insertAtEnd(Node*& head, int data);
void insertAtPosition(Node*& head, int data, int position);
void deleteFirst(Node*& head);
void deleteLast(Node*& head);
void deleteAtPosition(Node*& head, int position);
void printListForward(Node* head);
void printListBackwards(Node* head);

int main() {
   Node* List1 = new Node(2); // 2
   insertAtBeginning(List1, 1); // 1, 2
   insertAtBeginning(List1, 0); // 0, 1, 2
   insertAtPosition(List1, 3, 3); // 0, 1, 2, 3
   printListForward(List1);

   insertAtPosition(List1, 3, 50); // Invalid position
   printListBackwards(List1);

   deleteAtPosition(List1, 2); // 0, 1, 3
   printListForward(List1);

   deleteFirst(List1); // 1, 3
   printListForward(List1);

   deleteLast(List1); // 1
   printListForward(List1);
   deleteLast(List1); // 
   printListForward(List1);
   deleteLast(List1); // List is already empty
   deleteFirst(List1); // List is already empty
}

void insertAtBeginning(Node*& head, int data) {
   Node* newNode = new Node(data);
   if (head == nullptr) {
      head = newNode;
      return;
   } 

   newNode->next = head;
   head->prev = newNode;
   head = newNode;
}

void insertAtEnd(Node*& head, int data) {
   Node* newNode = new Node(data);
   if (head == nullptr) {
      head = newNode;
      return;
   }

   Node* temp = head;
   while (temp->next != nullptr) temp = temp->next;

   temp->next = newNode;
   newNode->prev = temp;
}

void insertAtPosition(Node*& head, int data, int position) {
   if (position < 0) {
      cout << "Position cannot be negative." << endl;
      return;
   }

   if (position == 0) insertAtBeginning(head, data);

   Node* temp = head;
   for (int i = 0; temp != nullptr && i < position-1; i++) temp = temp->next;

   if (temp == nullptr) {
      cout << "Invalid position." << endl;
      return;
   } 

   Node* newNode = new Node(data);

   newNode->next = temp->next;
   newNode->prev = temp;
   if (temp->next != nullptr) temp->next->prev = newNode;
   temp->next = newNode;
}

void deleteFirst(Node*& head) {
   if (head == nullptr)  {
      cout << "The list is already empty." << endl;
      return;
   }
   
   Node* temp = head;
   head = head->next;
   if (head != nullptr) head->prev = nullptr;
   delete temp;
}

void deleteLast(Node*& head) {
   if (head == nullptr) {
      cout << "The list is already empty." << endl;
      return;
   }

   Node* temp = head;
   if (temp->next == nullptr) {
      head = nullptr;
      delete temp;
      return;
   }

   while (temp->next != nullptr) temp = temp->next;
   
   temp->prev->next = nullptr;
   delete temp;
}

void deleteAtPosition(Node*& head, int position) {
   if (position < 0) {
      cout << "Position cannot be negative." << endl;
      return;
   }

   if (position == 0) deleteFirst(head);

   Node* temp = head;
   for (int i = 0; temp != nullptr && i < position; i++) temp = temp->next;

   if (temp == nullptr) {
      cout << "Invalid position." << endl;
      return;
   }

   temp->prev->next = temp->next;
   if (temp->next != nullptr) temp->next->prev = temp->prev;
   delete temp;
}

void printListForward(Node* head) {
   if (head == nullptr) {
      cout << "List is empty." << endl;
      return;
   }
   
   while (head != nullptr) {
      cout << head->data << "\t";
      head = head->next;
   }
   cout << endl;
}

void printListBackwards(Node* head) {
   if (head == nullptr) {
      cout << "List is empty." << endl;
      return;
   }
   
   while (head->next != nullptr) head = head->next;
   
   while (head != nullptr) {
      cout << head->data << "\t";
      head = head->prev;
   }
   cout << endl;
}