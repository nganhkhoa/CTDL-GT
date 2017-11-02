#include <prebuild.h>
#include <tut6lab.h>
#include <AVL.h>
#include <fstream>

namespace week6
{
namespace lab
{
      PhoneDatabase* PhoneDatabase::_phonedatabase = nullptr;

      void DeletePhone() {}
      void InsertNewPhone() {
            std::cout << "Add new phone number\n\n";

            contact newPerson;
            std::cout << "Name: ";
            std::cin.getline(newPerson.name, 20);

            std::cout << "Phone: ";
            std::cin.getline(newPerson.phone, 20);

            char confirm = 'n';
            std::cout << "Add new (y/n)? ";
            std::cin >> confirm;
            std::cin.ignore();

            if (confirm == 'y' || confirm == 'Y') {
                  auto phonedatabase = PhoneDatabase::phonedatabase();
                  data::AVL<contact>* phonebook  = phonedatabase->phonebook();
                  auto                searchList = phonebook->search(newPerson);
                  for (contact* person : *searchList) {
                        if (*person == newPerson) {
                              std::cout << "The number is existed\n";
                              std::cout << "Adding failed\n";
                              pausescreen();
                              return;
                        }
                  }
                  // ok, new person
                  // or new phone with person
                  phonebook->insert(newPerson);
                  std::cout << "Add success\n";
            }
            else {
                  std::cout << "Adding failed\n";
            }

            std::cout << "Press any key to continue\n";
            pausescreen();
      }
      void SearchPhoneBook() {}
      void write(contact& c) {
            std::ofstream file("phonebook.txt", std::ios::app);
            file << c.name << ", " << c.phone << "\n";
            file.close();
      }
      void WritePhoneBook() {
            std::cout << "Setting up before end\n";
            auto                phonedatabase = PhoneDatabase::phonedatabase();
            data::AVL<contact>* phonebook     = phonedatabase->phonebook();
            // clear output file
            std::ofstream file(
               "phonebook.txt", std::ios::trunc | std::ios::out);
            file.close();
            // write back the file
            std::cout << "Writing data to disk\n";
            phonebook->BFStraverse(write);
            phonedatabase = nullptr;
            phonebook     = nullptr;
            std::cout << "Encrypting data\n";
            // EncryptFile();
            std::cout << "Saving done, exiting\n";
      }
      bool LoadPhoneBook() {
            std::cout << "Opening file\n";
            std::ifstream file("phonebook.txt", std::ios::in);

            if (!file.is_open())
                  return false;

            char* buffer = new char[100];

            auto                phonedatabase = PhoneDatabase::phonedatabase();
            data::AVL<contact>* phonebook     = phonedatabase->phonebook();

            std::cout << "Reading data from file\n";
            while (file.getline(buffer, 100)) {
                  if (buffer[0] == '\0' || buffer[0] == '\r')
                        continue;

                  // DecryptLine(buffer);

                  contact person;
                  if (
                     sscanf(
                        buffer,
                        "%20[a-zA-Z0-9 ], %20[0-9]",
                        person.name,
                        person.phone) != 2)
                        return false;

                  phonebook->insert(person);
            }
            std::cout << "Read data from file done\n";
            delete[] buffer;
            buffer        = nullptr;
            phonedatabase = nullptr;
            phonebook     = nullptr;
            return true;
      }


      void PhoneBook() {
            std::cout << "Phonebook\n";
            std::cout << "Loading phone book\n";
            std::cout << "Phone book file: phonebook.txt\n";
            if (!LoadPhoneBook()) {
                  std::cout << "Load phone book failed\n";
                  std::cout << "Exiting\n";
                  return;
            }
            std::cout << "Load phone book done\n";

            while (true) {
                  clearscreen();

                  std::cout << "Please choose an option\n\n";

                  std::cout << "1. Search\n";
                  std::cout << "2. New number\n";
                  std::cout << "3. Exit\n";

                  int choice = 0;
                  std::cin >> choice;
                  std::cin.ignore();

                  clearscreen();
                  switch (choice) {
                        case 1:
                              SearchPhoneBook();
                              break;
                        case 2:
                              InsertNewPhone();
                              break;
                        case 3: {
                              WritePhoneBook();

                              auto phonedatabase =
                                 PhoneDatabase::phonedatabase();
                              delete phonedatabase;
                              phonedatabase = nullptr;
                              return;
                        }
                        default:
                              break;
                  }
            }
      }

      void treeTest() {
            data::AVL<int>* tree = new data::AVL<int>();
            tree->insert(32);
            tree->insert(73);
            tree->insert(62);
            tree->insert(29);
            tree->insert(79);
            tree->insert(26);
            tree->insert(67);
            tree->insert(70);
            tree->insert(43);
            tree->insert(27);
            tree->insert(4);
            tree->insert(46);
            tree->insert(7);
            tree->insert(74);
            tree->insert(5);

            tree->remove(73);
            tree->remove(43);
            tree->remove(62);
            tree->remove(26);
            tree->remove(29);
            tree->remove(5);

            data::SinglyLinkedList<int*>* searchList = tree->search(26);

            for (int* result : *searchList) {
                  std::cout << result << std::endl;
            }

            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);
            tree->insert(79);

            delete searchList;
            searchList = tree->search(79);

            // this should print 7 lines
            // with different address
            for (int* result : *searchList) {
                  std::cout << result << std::endl;
            }

            delete searchList;
            searchList = NULL;
      }

      void labTest() {
            treeTest();
            PhoneBook();
      }
}    // namespace lab
namespace tut
{}    // namespace tut
namespace onclass
{}    // namespace onclass
}    // namespace week6
