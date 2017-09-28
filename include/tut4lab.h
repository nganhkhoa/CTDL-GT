#ifndef TUT4LAB_H
#define TUT4LAB_H

#include <SinglyLinkedList.h>
#include <Queue_LinkedList.h>
#include <Stack_LinkedList.h>

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
      void labTest();
}    // namespace lab
namespace tut
{ void tutTest(); }    // namespace tut
namespace onclass
{}    // namespace onclass
}

#endif