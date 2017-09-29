#include <tut4lab.h>

#include <LinkedList.h>
#include <Queue_LinkedList.h>
#include <Stack_LinkedList.h>

#include <iostream>
#include <string>

namespace week4
{
namespace lab
{
      template <typename data_type>
      void reverse(data::Stack_LinkedList<data_type>& s) {
            data::Queue_LinkedList<data_type>* queue =
               new data::Queue_LinkedList<data_type>();
            while (!s.isEmpty()) {
                  data_type data = s.top();
                  queue->enqueue(data);
                  s.pop();
            }
            while (!queue->isEmpty()) {
                  data_type data = queue->front();
                  s.push(data);
                  queue->dequeue();
            }
      }

      template <typename data_type>
      void reverse(data::Queue_LinkedList<data_type>& q) {
            data::Stack_LinkedList<data_type>* stack =
               new data::Stack_LinkedList<data_type>();
            while (!q.isEmpty()) {
                  data_type data = q.front();
                  stack->push(data);
                  q.dequeue();
            }
            while (!stack->isEmpty()) {
                  data_type data = stack->top();
                  q.enqueue(data);
                  stack->pop();
            }
      }

      template <typename data_type>
      void reverse_using_stack(data::SinglyLinkedList<data_type>& s) {
            data::Stack_LinkedList<data_type>* stack =
               new data::Stack_LinkedList<data_type>();
            while (s.size()) {
                  stack->push(s.front());
                  s.removeHead();
            }
            while (stack->size()) {
                  s.insertEnd(stack->top());
                  stack->pop();
            }
      }
      template <typename data_type>
      void reverse_using_queue(data::SinglyLinkedList<data_type>& s) {
            data::Queue_LinkedList<data_type>* queue =
               new data::Queue_LinkedList<data_type>();
            while (s.size()) {
                  queue->enqueue(s.front());
                  s.removeHead();
            }
            while (queue->size()) {
                  s.insertHead(queue->front());
                  queue->dequeue();
            }
      }

      void QueueReverseTest() {
            data::Queue_LinkedList<int>* queue =
               new data::Queue_LinkedList<int>();
            queue->enqueue(0);
            queue->enqueue(1);
            queue->enqueue(2);
            queue->enqueue(3);
            queue->enqueue(4);
            queue->enqueue(5);

            reverse(*queue);
            std::cout << *queue << std::endl;
            delete queue;
      }
      void StackReverseTest() {
            data::Stack_LinkedList<int>* stack =
               new data::Stack_LinkedList<int>();
            stack->push(0);
            stack->push(1);
            stack->push(2);
            stack->push(3);
            stack->push(4);
            stack->push(5);

            reverse(*stack);
            std::cout << *stack << std::endl;
            delete stack;
      }
      void LinkedList_Stack_ReverseTest() {
            data::SinglyLinkedList<int>* intList =
               new data::SinglyLinkedList<int>();
            intList->insertEnd(0);
            intList->insertEnd(1);
            intList->insertEnd(2);
            intList->insertEnd(3);
            intList->insertEnd(4);
            intList->insertEnd(5);

            reverse_using_stack(*intList);
            std::cout << *intList << std::endl;
            delete intList;
      }
      void LinkedList_Queue_ReverseTest() {
            data::SinglyLinkedList<int>* intList =
               new data::SinglyLinkedList<int>();
            intList->insertEnd(0);
            intList->insertEnd(1);
            intList->insertEnd(2);
            intList->insertEnd(3);
            intList->insertEnd(4);
            intList->insertEnd(5);

            reverse_using_queue(*intList);
            std::cout << *intList << std::endl;
            delete intList;
      }

      void reverseTest() {
            std::cout << "Queue reverse test\n";
            QueueReverseTest();
            std::cout << "Stack reverse test\n";
            StackReverseTest();
            std::cout << "Linked List reverse using Stack test\n";
            LinkedList_Stack_ReverseTest();
            std::cout << "Linked List reverse using Queue test\n";
            LinkedList_Queue_ReverseTest();
      }

      std::string Decimal2Binary(int num) {
            data::Stack_LinkedList<int>* stack =
               new data::Stack_LinkedList<int>();
            std::string result = "";

            while (num) {
                  stack->push(num % 2);
                  num /= 2;
            }

            while (stack->size()) {
                  result += ((stack->top() == 0) ? '0' : '1');
                  stack->pop();
            }
            return result;
      }

      template <typename data_type>
      data::Queue_LinkedList<data_type>&
         Stack2Queue(data::Stack_LinkedList<data_type>& s) {
            data::Queue_LinkedList<data_type>* queue =
               new data::Queue_LinkedList<data_type>();

            while (s.size()) {
                  queue->enqueue(s.top());
                  s.pop();
            }

            return *queue;
      }
      template <typename data_type>
      data::Stack_LinkedList<data_type>&
         Queue2Stack(data::Queue_LinkedList<data_type>& q) {
            data::Stack_LinkedList<data_type>* stack =
               new data::Stack_LinkedList<data_type>();

            data::Queue_LinkedList<data_type>* queue =
               new data::Queue_LinkedList<int>(q);
            while (queue->size()) {
                  stack->push(queue->front());
                  queue->dequeue();
            }
            delete queue;
            reverse(*stack);
            return *stack;
      }

      void labTest() {
            reverseTest();
            std::cout << Decimal2Binary(10) << std::endl;

            data::Queue_LinkedList<int>* queue =
               new data::Queue_LinkedList<int>();
            queue->enqueue(0);
            queue->enqueue(1);
            queue->enqueue(2);
            queue->enqueue(3);
            queue->enqueue(4);
            queue->enqueue(5);

            data::Stack_LinkedList<int>* StackFromQueue =
               new data::Stack_LinkedList<int>(Queue2Stack(*queue));

            std::cout << "Queue: " << *queue << std::endl;
            std::cout << "Stack: " << *StackFromQueue << std::endl;
            delete StackFromQueue;
            delete queue;


            data::Stack_LinkedList<int>* stack =
               new data::Stack_LinkedList<int>();
            stack->push(0);
            stack->push(1);
            stack->push(2);
            stack->push(3);
            stack->push(4);
            stack->push(5);

            data::Queue_LinkedList<int>* QueueFromStack =
               new data::Queue_LinkedList<int>(Stack2Queue(*stack));

            std::cout << "Stack: " << *stack << std::endl;
            std::cout << "Queue: " << *QueueFromStack << std::endl;
            delete stack;
            delete QueueFromStack;
      }
}    // namespace lab
namespace tut
{
      void PushStack(stack* s, int n) {
            if (IsStackEmpty(s))
                  s->top = new node(n);
            else
                  s->top = new node(n, s->top);
            ++s->count;
      }
      void PopStack(stack* s, int& n) {
            if (IsStackEmpty(s))
                  return;
            node* temp = s->top;
            n          = temp->data;

            s->top     = s->top->next;
            temp->next = NULL;
            delete temp;
            temp = NULL;
            --s->count;
      }
      bool IsStackEmpty(stack* s) {
            return s->count == 0;
      }
      stack* copyStack(stack* s) {
            if (s == NULL)
                  return NULL;

            stack* returnStack = new stack();
            node*  temp        = s->top;

            while (s->count != returnStack->count) {
                  PushStack(returnStack, temp->data);
                  temp = temp->next;
            }

            return returnStack;
      }
      void removeN(stack* s, int n) {}
      void stackTest() {
            // 161 1617
            int a1 = 1;
            int a2 = 6;
            int a3 = 1;
            int a4 = 7;

            stack* stack1 = new stack();
            stack* stack2 = new stack();
            int    x      = 0;

            PushStack(stack1, a1);
            PushStack(stack1, a2);
            PushStack(stack1, a3);
            PushStack(stack1, a4);

            while (!IsStackEmpty(stack1)) {
                  PopStack(stack1, x);
                  PushStack(stack2, x);
            }

            PushStack(stack1, a1 * a3);
            PushStack(stack1, a2 * a4);

            while (!IsStackEmpty(stack2)) {
                  PopStack(stack2, x);
                  PushStack(stack1, x);
            }

            PopStack(stack1, x);
            PushStack(stack2, x);
            PopStack(stack1, x);
            PushStack(stack2, x);

            stack* stack3 = copyStack(stack1);
      }

      void EnQueue(queue* q, int n) {}
      void Dequeue(queue* q, int& x) {}
      bool IsQueueEmpty(queue* q) {
            return q->count == 0;
      }
      int GetFront(queue* q) {
            if (!IsQueueEmpty(q))
                  return q->front->data;
      }
      int GetRear(queue* q) {
            if (!IsQueueEmpty(q))
                  return q->rear->data;
      }
      void removeElement(queue* q) {}
      void                      queueTest() {}

      void tutTest() {
            stackTest();
            queueTest();
      }
}    // namespace tut
namespace onclass
{}    // namespace onclass
}