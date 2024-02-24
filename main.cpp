#include <iostream>

using namespace std;

class Vertex {
public:
  float value;
  Vertex *next;
  Vertex() { next = nullptr; }
};

class List {
public:
  List();
  void append(float value);
  void insertAt(int pos, float value);
  void insertFirst(float value);
  void removeFirst();
  void removeAt(int pos);
  void removeLast();
  void print();

private:
  Vertex *head, *tail;
};

List::List() {
  head = nullptr;
  tail = nullptr;
}

void List::insertFirst(float value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  if (head != nullptr) {
    vtx->next = head;
    head = vtx;
  } else {
    tail = vtx;
    head = vtx;
  }
}

void List::append(float value) {
  Vertex *vtx = new Vertex();
  vtx->value = value;
  if (head == nullptr) {
    head = vtx;
    tail = vtx;
  } else {
    tail->next = vtx;
    tail = vtx;
  }
}

void List::insertAt(int pos, float value) {
  Vertex *vtx = new Vertex();
  Vertex *vtx2 = head;
  Vertex *pre = head;
  int k = 0;

  while (vtx2 != nullptr) {
    vtx2 = vtx2->next;
    k++;
  }
  if (k > pos) {
    for (int i = 0; i < pos - 1; i++) {
      pre = pre->next;
    }
    Vertex *aft = pre->next;
    vtx->value = value;
    vtx->next = aft;
    pre->next = vtx;
  } else {
    append(value);
  }
}

void List::print() {
  Vertex *v = head;
  while (v != nullptr) {
    cout << v->value << " -> ";
    v = v->next;
  }
}

int main() {
  List lista;
  lista.insertFirst(2);
  lista.append(5);
  lista.insertFirst(1);
  lista.append(6);
  lista.append(7);
  lista.insertAt(3, 10.5);
  lista.print();
}