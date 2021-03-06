#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T data;
  int priority;
  Element* next;
  Element(T data, int priority){
    this -> data = data;
    this -> priority = priority;
    this -> next = nullptr;
  }
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> baru;
  baru.head = nullptr;
  baru.tail = nullptr;
  return baru;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> baru = new Element<T>(value, priority);
  if(q.head == nullptr){
    q.head = baru;
    q.tail = baru;
  }else{
    ElementPtr<T> bantu = q.head;
    ElementPtr<T> bantu2 = nullptr;
    while(bantu->priority >= priority && bantu->next != nullptr){
      bantu2 = bantu;
      bantu = bantu->next;
    }
    if(bantu == q.head && bantu->priority < priority){
      baru->next = bantu;
      q.head = baru;
    }else if(bantu == q.tail && bantu->priority > priority){
      bantu->next = baru;
      q.tail = baru;
    }else{
      bantu2->next = baru;
      baru->next = bantu;
    }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->data;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> deleteelem;
  if(q.head == nullptr && q.tail == nullptr){
    deleteelem = nullptr;
  }else if(q.head->next == nullptr){
    deleteelem = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else{
    deleteelem = q.head;
    q.head = q.head->next;
    deleteelem -> next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
