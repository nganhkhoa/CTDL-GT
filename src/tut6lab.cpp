#include <prebuild.h>
#include <tut6lab.h>
#include <AVL.h>
#include <fstream>

namespace week6
{
namespace lab
{
      PhoneDatabase* PhoneDatabase::_phonedatabase = nullptr;

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

      void Display(data::SinglyLinkedList<contact*>* list) {
            int i = 1;
            std::cout << "id\tName\t\tPhone\n";
            for (contact* c : *list) {
                  std::cout << i++ << ".\t" << c->name << "\t\t" << c->phone
                            << "\n";
            }
            std::cout << i << ".\tReturn\n";
      }

      void ChangeNumber(contact* c) {
            clearscreen();
            std::cout << "Old number: " << c->phone << "\n";
            std::cout << "New number: ";
            char* newNumber = new char[21];
            std::cin.getline(newNumber, 21);
            std::cout << "Change number (y/n)? ";

            char confirm = 'n';
            std::cin >> confirm;
            std::cin.ignore();

            if (confirm == 'y' || confirm == 'Y')
                  strcpy(c->phone, newNumber);
            delete[] newNumber;
            newNumber = nullptr;
            return;
      }

      void ChangeName(contact* c) {
            clearscreen();
            std::cout << "Old name: " << c->name << "\n";
            std::cout << "New name: ";
            char* newName = new char[21];
            std::cin.getline(newName, 21);
            std::cout << "Change name (y/n)? ";

            char confirm = 'n';
            std::cin >> confirm;
            std::cin.ignore();

            if (confirm == 'y' || confirm == 'Y')
                  strcpy(c->name, newName);
            delete[] newName;
            newName = nullptr;
            return;
      }

      void DeleteRecord(contact* c) {
            clearscreen();
            std::cout << "Are you sure to delete this person?\n";
            std::cout << c->name << ": " << c->phone << "\n";
            std::cout << "Confirm (y/n)? ";
            char confirm = 'n';
            std::cin >> confirm;
            std::cin.ignore();

            if (confirm == 'n' || confirm == 'N')
                  return;

            contact deleteThis = *c;

            auto                phonedatabase = PhoneDatabase::phonedatabase();
            data::AVL<contact>* phonebook     = phonedatabase->phonebook();

            phonebook->remove(deleteThis);

            std::cout << "Person removed\n";
            pausescreen();
      }

      void ChooseRecord(contact* c) {
            while (true) {
                  clearscreen();
                  std::cout << c->name << ": " << c->phone << "\n";
                  std::cout << "Choose what to do with this record\n";

                  std::cout << "1. Call\n";
                  std::cout << "2. Change number\n";
                  std::cout << "3. Change name\n";
                  std::cout << "4. Delete\n";
                  std::cout << "5. Return\n";

                  int choice = 0;
                  std::cin >> choice;
                  std::cin.ignore();

                  switch (choice) {
                        case 1:
                              break;
                        case 2:
                              ChangeNumber(c);
                              break;
                        case 3:
                              ChangeName(c);
                              break;
                        case 4:
                              DeleteRecord(c);
                              // deleted, nothing to do more
                              return;
                        case 5:
                              return;
                        default:
                              return;
                  }
            }
      }

      void ShowListWithOption(data::SinglyLinkedList<contact*>* list) {
            while (true) {
                  clearscreen();
                  Display(list);
                  std::cout << "Choose record: ";

                  int i = 0;
                  std::cin >> i;
                  std::cin.ignore();

                  if (i <= 0)
                        break;
                  if (i > list->size())
                        break;

                  ChooseRecord((*list)[i - 1]);
                  return;
            }
      }

      void getList(contact& c, void* v) {
            auto listRecord = (data::SinglyLinkedList<contact*>*) v;
            listRecord->insertHead(&c);
      }

      void BrowsePhoneBook() {
            data::SinglyLinkedList<contact*>* listRecord =
               new data::SinglyLinkedList<contact*>();
            auto                phonedatabase = PhoneDatabase::phonedatabase();
            data::AVL<contact>* phonebook     = phonedatabase->phonebook();

            phonebook->BFStraverse(getList, listRecord);
            ShowListWithOption(listRecord);
            delete listRecord;
            listRecord    = nullptr;
            phonedatabase = nullptr;
            phonebook     = nullptr;
      }

      struct Result
      {
            data::SinglyLinkedList<contact*>* list;
            char*                             searchString;

            Result(const char* c) {

                  searchString = new char[strlen(c)];
                  for (int i = 0;; i++) {
                        if (c[i] == '\0') {
                              searchString[i] = '\0';
                              break;
                        }
                        if (c[i] >= 'A' && c[i] <= 'Z')
                              searchString[i] = 'a' + c[i] - 'A';
                        else
                              searchString[i] = c[i];
                  }

                  list = new data::SinglyLinkedList<contact*>();
            }

            ~Result() {
                  delete list;
                  delete[] searchString;
                  searchString = nullptr;
                  list         = nullptr;
            }
      };

      void search(contact& c, void* v) {
            Result* result = (Result*) v;

            char* name = new char[strlen(c.name)];

            for (int i = 0;; i++) {
                  if (c.name[i] == '\0') {
                        name[i] = '\0';
                        break;
                  }
                  if (c.name[i] >= 'A' && c.name[i] <= 'Z')
                        name[i] = 'a' + c.name[i] - 'A';
                  else
                        name[i] = c.name[i];
            }

            if (strcmp(name, result->searchString) == 0)
                  result->list->insertHead(&c);
      }

      void SearchPhoneBook() {
            // getAsyncKeyPress
            // should prompt result when a key is press
            // because it's funnier

            char* searchString = new char[21];

            std::cout << "Search: ";
            std::cin.getline(searchString, 21);

            auto                phonedatabase = PhoneDatabase::phonedatabase();
            data::AVL<contact>* phonebook     = phonedatabase->phonebook();
            Result*             result        = new Result(searchString);
            phonebook->BFStraverse(search, result);

            if (result->list->isEmpty()) {
                  std::cout << "Nothing found\n";
                  pausescreen();
                  return;
            }

            ShowListWithOption(result->list);

            delete result;
            result        = nullptr;
            phonedatabase = nullptr;
            phonebook     = nullptr;
      }
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

                  std::cout << "1. Browse\n";
                  std::cout << "2. Search\n";
                  std::cout << "3. New number\n";
                  std::cout << "4. Exit\n";

                  int choice = 0;
                  std::cin >> choice;
                  std::cin.ignore();

                  clearscreen();
                  switch (choice) {
                        case 1:
                              BrowsePhoneBook();
                              break;
                        case 2:
                              SearchPhoneBook();
                              break;
                        case 3:
                              InsertNewPhone();
                              break;
                        case 4: {
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
