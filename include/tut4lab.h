#ifndef TUT4LAB_H
#define TUT4LAB_H

#include <SinglyLinkedList.h>
#include <Queue_LinkedList.h>
#include <Stack_LinkedList.h>

#include <string>

namespace week4
{
namespace lab
{
      template <typename data_type>
      void reverse(data::Stack_LinkedList<data_type>& s);
      template <typename data_type>
      void reverse(data::Queue_LinkedList<data_type>& q);
      template <typename data_type>
      void reverse_using_stack(data::SinglyLinkedList<data_type>& s);
      template <typename data_type>
      void reverse_using_queue(data::SinglyLinkedList<data_type>& s);

      void QueueReverseTest();
      void StackReverseTest();
      void LinkedList_Stack_ReverseTest();
      void LinkedList_Queue_ReverseTest();
      void reverseTest();

      std::string Decimal2Binary(int num);

      template <typename data_type>
      data::Queue_LinkedList<data_type>&
         Stack2Queue(data::Stack_LinkedList<data_type>& s);
      template <typename data_type>
      data::Stack_LinkedList<data_type>&
         Queue2Stack(data::Queue_LinkedList<data_type>& s);

      void labTest();
}    // namespace lab
namespace tut
{
      struct node
      {
            int   data;
            node* next;
            node(int d = int(), node* n = NULL) : data(d), next(n) {}
      };
      struct stack
      {
            node* top;
            int   count;

            stack(int d) : count(1) {
                  top = new node(d);
            }

            stack() : top(NULL), count(0) {}
      };
      struct queue
      {
            node* front;
            node* rear;
            int   count;
            queue(int d) : count(1) {
                  front = new node(d);
                  rear  = front;
            }

            queue() : front(NULL), rear(NULL), count(0) {}
      };

      void PushStack(stack* s, int n);
      void PopStack(stack* s, int& n);
      bool IsStackEmpty(stack* s);
      stack* copyStack(stack* s);
      void removeN(stack* s, int n);
      void stackTest();

      void EnQueue(queue* q, int n);
      void Dequeue(queue* q, int& x);
      bool IsQueueEmpty(queue* q);
      int GetFront(queue* q);
      int GetRear(queue* q);
      void removeElement(queue* q);
      void queueTest();

      void tutTest();
}    // namespace tut
namespace onclass
{}    // namespace onclass
}

#endif