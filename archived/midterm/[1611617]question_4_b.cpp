#include "[1611617]LinkedList.h"
#include "[1611617]Queue.h"

void LinkedList::reverse_using_queue() {
      Queue* queue = new Queue();

      while (!empty()) {
            queue->enqueue(_head->next->data);
            removeAt(1);
      }

      while (!queue->empty()) {
            insertAt(1, queue->front());
            queue->dequeue();
      }
}