#ifndef TUT6LAB_H
#define TUT6LAB_H

#include <AVL.h>
#include <iostream>
#include <cstring>

namespace week6
{
namespace lab
{

      struct contact
      {
            char* name;
            char* phone;

            contact() {
                  name  = new char[21];
                  phone = new char[21];
            }

            contact(const contact& c) {
                  name  = new char[21];
                  phone = new char[21];
                  strcpy(name, c.name);
                  strcpy(phone, c.phone);
            }

            contact& operator=(const contact& c) {
                  strcpy(name, c.name);
                  strcpy(phone, c.phone);
                  return *this;
            }

            bool operator<(const contact& c) const {
                  int name_cmp = strcmp(name, c.name);
                  if (name_cmp == 0)
                        return strcmp(phone, c.phone) < 0;
                  return name_cmp < 0;
            }

            bool operator>(const contact& c) const {
                  int name_cmp = strcmp(name, c.name);
                  if (name_cmp == 0)
                        return strcmp(phone, c.phone) > 0;
                  return name_cmp > 0;
            }

            bool operator==(const contact& c) const {
                  return strcmp(name, c.name) == 0 &&
                         strcmp(phone, c.phone) == 0;
            }

            bool operator!=(const contact& c) const {
                  return !(*this == c);
            }

            ~contact() {
                  delete phone;
                  delete name;
                  name  = nullptr;
                  phone = nullptr;
            }
      };

      class PhoneDatabase {
            static PhoneDatabase* _phonedatabase;
            data::AVL<contact>*   _phonebook;

            PhoneDatabase() {
                  _phonebook = new data::AVL<contact>();
            }

          public:
            ~PhoneDatabase() {
                  if (_phonebook) {
                        delete _phonebook;
                        _phonebook = nullptr;
                  }
            }

            static PhoneDatabase* phonedatabase() {
                  if (!_phonedatabase)
                        _phonedatabase = new PhoneDatabase();
                  return _phonedatabase;
            }

            data::AVL<contact>* phonebook() {
                  return _phonebook;
            }
      };

      void DeletePhone();
      void InsertNewPhone();
      void SearchPhoneBook();
      void WritePhoneBook();
      bool LoadPhoneBook();
      void PhoneBook();

      void labTest();
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week6


#endif
