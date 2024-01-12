#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>
#include <stdlib.h>
using namespace std;
string usn;
int tm;
void valid(string str)
{
    string dir, user;
    ifstream file;
    dir = str + ".txt";
    file.open(dir.c_str());
    if (!file.is_open() && file.fail())
    {
        return;
    }
    else
    {
        tm++;
        if (tm == 3)
        {
            cout << "\nThis username already exists\nPlease try Again.";
            // file.close();
            return;
        }
        cout << "\nThis username already exists!\nCreate a username:";
        cin >> usn;
        // file.close();
        valid(usn);
    }
}
// Node Class
class Node
{
public:
    int id;
    string Name;
    string author;
    string publisher;
    int dop;
    int price;
    string edition;
    int isbn;
    int quantity;
    int qty_sold;
    Node *next;
};

// Stores the head of the Linked List
Node *head = new Node();

// Check Function to check that if Record Already Exist or Not
bool check(int x)
{
    // Base Case
    if (head == NULL)
        return false;

    Node *t = new Node;
    t = head;

    // Traverse the Linked List
    while (t != NULL)
    {
        if (t->id == x)
            return true;
        t = t->next;
    }

    return false;
}

// Function to insert the record
void Insert_Record(int id, string Name,
                   string author, string publisher, int dop, int price, string edition, int isbn, int quantity, int qty_sold)
{
    // if Record Already Exist
    if (check(id))
    {
        cout << "Book with this "
             << "record Already Exists\n";
        return;
    }

    // Create new Node to Insert Record
    Node *t = new Node();
    t->id = id;
    t->Name = Name;
    t->author = author;
    t->publisher = publisher;
    t->dop = dop;
    t->price = price;
    t->edition = edition;
    t->isbn = isbn;
    t->quantity = quantity;
    t->qty_sold = qty_sold;
    t->next = NULL;

    // Insert at Begin
    if (head == NULL || (head->id >= t->id))
    {
        t->next = head;
        head = t;
    }

    // Insert at middle or End
    else
    {
        Node *c = head;
        while (c->next != NULL && c->next->id < t->id)
        {
            c = c->next;
        }
        t->next = c->next;
        c->next = t;
    }

    cout << "Record Inserted "
         << "Successfully\n";
}

// Function to search record for any Book Record with id number
void Search_Record_id(int id)
{
    // if head is NULL
    if (!head)
    {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else
    {
        Node *p = head;
        while (p)
        {
            if (p->id == id)
            {

                cout << "Index\tName\tAuthor\tpublisher\tprice\tedition\tquantity\n";
                cout << p->id << "\t"
                     << p->Name << "\t"
                     << p->author << "\t"
                     << p->publisher << "\t"
                     << p->price << "\t"
                     << p->edition << "\t"
                     << p->quantity << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}
void Search_Record_name(string name)
{
    // if head is NULL
    if (!head)
    {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else
    {
        Node *p = head;
        while (p)
        {
            if (p->Name == name)
            {

                cout << "Index\tName\tAuthor\tpublisher\tprice\tedition\tquantity\n";
                cout << p->id << "\t"
                     << p->Name << "\t"
                     << p->author << "\t"
                     << p->publisher << "\t"
                     << p->price << "\t"
                     << p->edition << "\t"
                     << p->quantity << endl;
                return;
            }
            p = p->next;
        }

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}
void Search_Record_author(string author)
{
    // if head is NULL
    if (!head)
    {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else
    {
        Node *p = head;
        while (p)
        {
            cout << "Index\tName\tAuthor\tpublisher\tprice\tedition\tquantity\n";
            if (p->author == author)
            {

                cout << p->id << "\t"
                     << p->Name << "\t"
                     << p->author << "\t"
                     << p->publisher << "\t"
                     << p->price << "\t"
                     << p->edition << "\t"
                     << p->quantity << endl;
            }
            p = p->next;
        }
        return;

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}
void Search_Record_publisher(string publisher)
{
    // if head is NULL
    if (!head)
    {
        cout << "No such Record "
             << "Available\n";
        return;
    }

    // Otherwise
    else
    {
        Node *p = head;
        while (p)
        {
            cout << "Index\tName\tAuthor\tpublisher\tprice\tedition\tquantity\n";
            if (p->publisher == publisher)
            {

                cout << p->id << "\t"
                     << p->Name << "\t"
                     << p->author << "\t"
                     << p->publisher << "\t"
                     << p->price << "\t"
                     << p->edition << "\t"
                     << p->quantity << endl;
            }
            p = p->next;
        }
        return;

        if (p == NULL)
            cout << "No such Record "
                 << "Available\n";
    }
}

// Function to delete record books
// record with given id number
// if it exist
int Delete_Record(int id)
{
    Node *t = head;
    Node *p = NULL;

    // Deletion at Begin
    if (t != NULL && t->id == id)
    {
        head = t->next;
        delete t;

        cout << "Record Deleted "
             << "Successfully\n";
        return 0;
    }

    // Deletion Other than Begin
    while (t != NULL && t->id != id)
    {
        p = t;
        t = t->next;
    }
    if (t == NULL)
    {
        cout << "Record does not Exist\n";
        return -1;
        p->next = t->next;

        delete t;
        cout << "Record Deleted "
             << "Successfully\n";

        return 0;
    }
}

// Function to display the book
// Record
void Show_Record()
{
    Node *p = head;
    if (p == NULL)
    {
        cout << "No Record "
             << "Available\n";
    }
    else
    {
        cout << "ID\tName\tAuthor"
             << "\tpublisher\tprice\tedition\tquantity\n";

        // Until p is not NULL
        while (p != NULL)
        {
            cout << p->id << "\t"
                 << p->Name << "\t"
                 << p->author << "\t"
                 << p->publisher << "\t\t"
                 << p->price << "\t"
                 << p->edition << "\t"
                 << p->quantity << endl;
            p = p->next;
        }
    }
}
// Update
void Update_Record()
{
    if (head == NULL)
    {
        cout << "\nLinked list is empty";
    }
    else
    {
        int r, found = 0;
        cout << "Enter Book id for updation: ";
        cin >> r;
        Node *p = head;
        while (p != NULL)
        {
            if (r == p->id)
            {
                //             cout << "Enter new Name of book\n";
                // 			cin >> p->Name;
                cout << "Enter new ID of book\n";
                cin >> p->id;
                // 			cout << "Enter new Author of book \n";
                // 			cin >> p->author;
                cout << "Enter new Publisher  of book\n";
                cin >> p->publisher;
                cout << "Enter new Date of Publication of book\n";
                cin >> p->dop;
                cout << "Enter new price of book\n";
                cin >> p->price;
                cout << "Enter new edition of book\n";
                cin >> p->edition;
                cout << "Enter new ISBN of book\n";
                cin >> p->isbn;
                cout << "Enter new Quantity_Available of book\n";
                cin >> p->quantity;
                cout << "Enter new Number_of_copies_sold of book\n";
                cin >> p->qty_sold;
                cout << "Record Updated.";
                found++;
            }
            p = p->next;
        }
        if (found == 0)
        {
            cout << "\nNo record with that roll id";
        }
    }
}

class Item
{

public:
    string name;
    int id;
    int sl = 0;
    int price;
    int qty; // Qty to be bought

    void DisplayItem();
};

void Item::DisplayItem()
{

    cout << "Item no: " << sl << endl;
    cout << "Book ID: " << id << endl;
    cout << "Book Name: " << name << endl;
    cout << "Book Price: " << price << endl;
    cout << "Quantity: " << qty << endl;
}

class ItemsList
{
public:
    vector<Item> cart;

    void addCart();
    void removeCart();
    void showCart();
    void deleteItem();
    void makePurchase();
} items;

void ItemsList::addCart()
{
    int searchid;
    Item temp;
    int addqty;
    cout << "Enter the id of book to add:" << endl;
    cin >> searchid;
    Node *p = head;
    if (p == NULL)
    {
        cout << "No Record "
             << "Available\n";
    }
    while (p != NULL)
    {
        if (p->id == searchid)
        {

            if (p->quantity == 0)
            {
                cout << "Out of stock";
            }
            else
            {
                cout << "Book Found!!\t" << p->quantity << " available, Enter quantity to add: ";
                cin >> addqty;
                if (p->quantity - addqty < 0)
                {
                    cout << "Not enough stock, try again!";
                }
                else
                {
                    temp.name = p->Name;
                    temp.id = p->id;
                    p->quantity = p->quantity - addqty;
                    temp.price = p->price;
                    temp.qty = addqty;
                    temp.sl++;
                    cart.push_back(temp);
                    cout << "Item added to cart" << endl;
                }
            }
        }
        p = p->next;
    }
}

void ItemsList::showCart()
{
    long int total = 0;

    if (cart.size() == 0)
    {
        cout << "Cart Empty\n\n";
    }

    else
    {
        for (int i = 0; i < cart.size(); i++)
        {
            cart[i].DisplayItem();
            total = total + cart[i].price * cart[i].qty;
            cout << "________________________________" << endl;
        }


        cout << "Cart Total:" << total << endl;
    }
}

void ItemsList::makePurchase()
{

    char ch;
    showCart();
    cout << "\n\n";
    cout << "Would you like to purchase the following items (y/n)" << endl;
    cin >> ch;

    switch (ch)
    {

    case 'y':
        showCart();
        cout << "Purchase complete" << endl;
        cart.clear();
        break;

    case 'n':
        break;

    default:
        cout << "Invalid choice." << endl;
    }
}

void ItemsList::removeCart()
{
    int index;
    cout << "Enter item no. to delete" << endl;
    cin >> index;

    Node *p = head;


    while (p != NULL)
    {
        if (p->id == cart[index].id)
        {
                    p-> quantity = p->quantity + cart[index].qty;
                    cart.erase(cart.begin() + index);
                    cout << "Item removed from cart" << endl;
                }
            p = p->next;
            }
}

int main()
{
    int choice, i, exit = 0;
    string ans, psd, name, fname, usern, pw, line, nusn;
    ofstream fileo;
    ifstream filei;
    cout << "Welcome\n";
    while (exit == 0)
    {
        cout << "\nChoose one option:\n1. SignIn/LogIn(press 1 to select this)\n2. SignUp/Register(press 2 to select this)\n\npress any key and enter to exit\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter your username:";
            cin >> usn;
            cout << "\nEnter your password:";
            cin >> psd;
            fname = usn + ".txt";
            filei.open(fname.c_str());
            if (!filei.is_open() && filei.fail())
            {
                cout << "\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei, usern);
            getline(filei, line);
            getline(filei, pw);
            if (usn == "admin" && psd == "admin")
            {
                cout << "\nAdmin View";

                head = NULL;
                string Name, author, edition, publisher;
                int id, dop, price, isbn, quantity, qty_sold;

                // Menu-driven program
                while (true)
                {
                    cout << "\n\t\tWelcome to Bookshop "
                            "Management System\n\n\tPress\n\t1 to "
                            "create a new Record\n\t2 to delete a "
                            "Book record\n\t3 to Search a book "
                            "Record\n\t4 to view all books "
                            "record\n\t5 to Update\n\t6 to User Menu\n\t7 to Exit";
                    cout << "\nEnter your Choice\n";
                    int Choice;

                    // Enter Choice
                    cin >> Choice;
                    if (Choice == 1)
                    {
                        cout << "Enter Name of book\n";
                        cin >> Name;
                        cout << "Enter ID of book\n";
                        cin >> id;
                        cout << "Enter Author of book \n";
                        cin >> author;
                        cout << "Enter Publisher  of book\n";
                        cin >> publisher;
                        cout << "Enter Date of Publication of book\n";
                        cin >> dop;
                        cout << "Enter price of book\n";
                        cin >> price;
                        cout << "Enter edition of book\n";
                        cin >> edition;
                        cout << "Enter ISBN of book\n";
                        cin >> isbn;
                        cout << "Enter Quantity Available of book\n";
                        cin >> quantity;
                        cout << "Enter Number of copies sold of book\n";
                        cin >> qty_sold;
                        Insert_Record(id, Name, author, publisher, dop, price, edition, isbn, quantity, qty_sold);
                    }
                    else if (Choice == 2)
                    {
                        cout << "Enter ID of Book whose "
                                "record is to be deleted\n";
                        cin >> id;
                        Delete_Record(id);
                    }
                    else if (Choice == 3)
                    {
                        cout << "\nPress 1 to Search by ID\nPress 2 to Search by Name\nPress 3 to Search by Author\nPress 4 to Search by Publisher\nPress 5 to Exit\n";
                        cout << "\nEnter your Choice\n";
                        int Choice;

                        // Enter Choice
                        cin >> Choice;
                        if (Choice == 1)
                        {
                            cout << "Enter ID of Book whose "
                                    "record you want to Search\n";
                            cin >> id;
                            Search_Record_id(id);
                        }
                        else if (Choice == 2)
                        {
                            cout << "Enter Name of Book whose "
                                    "record you want to Search\n";
                            cin >> name;
                            Search_Record_name(name);
                        }
                        else if (Choice == 3)
                        {
                            cout << "Enter Author of Book whose "
                                    "record you want to Search\n";
                            cin >> author;
                            Search_Record_author(author);
                        }
                        else if (Choice == 4)
                        {
                            cout << "Enter Publisher of Book whose "
                                    "record you want to Search\n";
                            cin >> publisher;
                            Search_Record_publisher(publisher);
                        }
                        else if (Choice == 5)
                        {
                            // exit(0);
                            EXIT_SUCCESS;
                        }
                        else
                        {
                            cout << "Invalid Choice "
                                 << "Try Again\n";
                        }
                    }
                    else if (Choice == 4)
                    {
                        Show_Record();
                    }
                    else if (Choice == 5)
                    {
                        Update_Record();
                    }
                    else if (Choice == 6)
                    {
                        goto A;
                    }
                    else if (Choice == 7)
                    {
                        // exit(0);
                        EXIT_SUCCESS;
                    }
                    else
                    {
                        cout << "Invalid Choice "
                             << "Try Again\n";
                    }
                }
                return 0;
            }
            else if (usn == usern && psd == pw)
            {
                cout << "\nYou are successfully logged in:)\n"; // YOUR PROFILE SAYS:\n
                // cout<<"User-name:"<<usern<<endl;
                // cout<<"Name:"<<line<<endl;
                getline(filei, line);
                filei.close();

            A:

                string Name, author, edition, publisher;
                int id, dop, price, isbn, quantity, qty_sold;

                // Menu-driven program
                while (true)
                {

                    cout << "\n\t\tWelcome to Bookshop "
                            "Management System\n\n\tPress\n\t1 to "
                            "Search a book Record\n\t2 to view all books "
                            "\n\t3 to view the cart\n\t4 to add to the cart\n\t5 to remove from cart"
                            "\n\t6 to Make a purchase\n\t7 to Exit";
                    cout << "\nEnter your Choice\n";
                    int Choice;

                    // Enter Choice
                    cin >> Choice;
                    if (Choice == 1)
                    {
                        cout << "\nPress 1 to Search by ID\nPress 2 to Search by Name\nPress 3 to Search by Author\nPress 4 to Search by Publisher\nPress 5 to Exit\n";
                        cout << "\nEnter your Choice\n";
                        int Choice;

                        // Enter Choice
                        cin >> Choice;
                        if (Choice == 1)
                        {
                            cout << "Enter ID of Book whose "
                                    "record you want to Search\n";
                            cin >> id;
                            Search_Record_id(id);
                        }
                        else if (Choice == 2)
                        {
                            cout << "Enter Name of Book whose "
                                    "record you want to Search\n";
                            cin >> name;
                            Search_Record_name(name);
                        }
                        else if (Choice == 3)
                        {
                            cout << "Enter Author of Book whose "
                                    "record you want to Search\n";
                            cin >> author;
                            Search_Record_author(author);
                        }
                        else if (Choice == 4)
                        {
                            cout << "Enter Publisher of Book whose "
                                    "record you want to Search\n";
                            cin >> publisher;
                            Search_Record_publisher(publisher);
                        }
                        else if (Choice == 5)
                        {
                            // exit(0);
                            EXIT_SUCCESS;
                        }
                        else
                        {
                            cout << "Invalid Choice "
                                 << "Try Again\n";
                        }
                    }
                    else if (Choice == 2)
                    {
                        Show_Record();
                    }
                    else if (Choice == 3)
                    {
                        items.showCart();
                    }
                    else if (Choice == 4)
                    {
                        items.addCart();
                    }
                    else if (Choice == 5)
                    {
                        items.removeCart();
                    }
                    else if (Choice == 6)
                    {
                        items.makePurchase();
                    }
                    else if (Choice == 7)
                    {
                        //exit(0);
                        EXIT_SUCCESS;
                    }
                    else
                    {
                        cout << "Invalid Choice "
                             << "Try Again\n";
                    }
                }
                return 0;
            }

            else
            {
                cout << "\nWrong username or password!\nPlease try Again.\n";
            }
            cout << endl;
        }
        else if (choice == 2)
        {
            cout << "\nEnter your name:";
            cin.ignore();
            getline(cin, name);
            cout << "\nCreate a username:";
            cin >> usn;
            tm = 0;
            valid(usn);
            if (tm >= 3)
            {
                continue;
            }
            cout << "\nCreate a password:";
            cin >> psd;
            fname = usn + ".txt";
            fileo.open(fname.c_str());
            fileo << usn << endl
                  << name << endl
                  << psd << endl;
            cout << "\nYou are successfully registered:)";
            cin.ignore();
            fileo.close();
        }
        else
        {
            exit = 1;
        }
    }
    cout << "\nThank you.\n";
}
