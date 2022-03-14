#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int ID = 0, price = 0, pages = 0;
    string bookName = "", author = "", ISBN = "";

    void printAll()
    {
        cout << "Name of the book: " << bookName << endl;
        cout << "Author of the book: " << author << endl;
        cout << "ID of the book:  " << ID << endl;
        cout << "Price of the book: " << price << endl;
        cout << "Total no. of pages in a book: " << pages << endl;
        cout << "ISBN of the book: " << ISBN << endl;
    }
};

void swap(Book &x, Book &y)
{
    Book temp;
    temp = x;
    x = y;
    y = temp;
}

struct bookList
{
    Book books[5];

    void printAll()
    {
        cout << "----Displayiong Information----" << endl;
        int count = 0;
        for (; count < 5; count++)
        {
            if (books[count].ID != 0)
                cout << "ID of the book is: " << books[count].ID << endl;
            if (books[count].bookName != "")
                cout << "Name of the book is: " << books[count].bookName << endl;
            if (books[count].price != 0)
                cout << "Price of the book is: " << books[count].price << endl;
            if (books[count].ISBN != "")
                cout << "ISBN of the book is: " << books[count].ISBN << endl;
            if (books[count].author != "")
                cout << "Author of the book is: " << books[count].author << endl;
            if (books[count].pages != 0)
                cout << "Pages in the book are:" << books[count].pages << endl;
            cout << endl;
        }
    }
    void addNewBook()
    {

        int n;
        cout << "Enter the index location where you want to add a new book: " << endl;
        cin >> n;
        if (n <= 4)
        {
            cout << "---Add New Book Details---" << endl;
            cout << " Enter ID of the new book:" << endl;
            cin >> books[n].ID;
            cout << " Enter Price of the new book:" << endl;
            cin >> books[n].price;
            cout << "Enter No. of pages in a new book:" << endl;
            cin >> books[n].pages;
            cin.ignore();
            cout << " Enter Name of the new book:" << endl;
            getline(cin, books[n].bookName);
            cout << "Enter Author of the new book:" << endl;
            getline(cin, books[n].author);
            cout << "Enter ISBN of the new book:" << endl;
            getline(cin, books[n].ISBN);
        }
    }

    void sortA()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {
                if (books[j].ID > books[j + 1].ID)
                {
                    swap(books[j], books[j + 1]);
                }
            }
        }
        printAll();
    }

    void sortD()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4 - i; j++)
            {

                if (books[j].ID < books[j + 1].ID)
                {
                    swap(books[j], books[j + 1]);
                }
            }
        }

        printAll();
    }

    void deleteAll()
    {
        for (int i = 0; i <= 5; i++)
        {
            books[i].ID = 0;
            books[i].bookName = "";
            books[i].price = 0;
            books[i].ISBN = "";
            books[i].author = "";
            books[i].pages = 0;
        }
        cout << "Books have been deleted sucessfully" << endl;
    }

    void showParticularBook()
    {
        bool found;
        int id;
        cout << "Please enter the ID of the book:" << endl;
        cin >> id;
        for (int i = 0; i < 5; i++)
        {
            if (id == books[i].ID)
            {
                found = true;
                books[i].printAll();
            }
        }
        if (!found)
            cout << "Sorry no such book is present int the list :(";
    }
};

struct Student
{
    int ID = 0;
    string stdName = "";
    int rollNo = 0;

    void printAll()
    {
        cout << "ID of the student: " << ID << endl;
        cout << "Name of the student: " << stdName << endl;
        cout << "Roll No. of the student: " << rollNo << endl;
    }
};

struct studentList
{
    Student stud[5];

    void printAll()
    {
        int count = 0;
        cout << "----Displaying Information----" << endl;
        for (; count < 5; count++)
        {
            if (stud[count].ID != 0)
                cout << "ID of the student is: " << stud[count].ID << endl;
            if (stud[count].stdName != "")
                cout << "Name of the student is: " << stud[count].stdName << endl;
            if (stud[count].rollNo != 0)
                cout << "Roll No. of the student is: " << stud[count].rollNo << endl;
            cout << endl;
        }
    }

    void addNewUser()
    {
        int n;
        cout << "Enter the index location where you want to add a new student: " << endl;
        cin >> n;
        if (n <= 4)
        {
            cout << "---Add New Student Details---" << endl;
            cout << "Enter the ID of the new student:" << endl;
            cin >> stud[n].ID;
            cin.ignore();
            cout << "Enter the name of the new student:" << endl;
            getline(cin, stud[n].stdName);
            cout << "Enter the roll No. of the new student:" << endl;
            cin >> stud[n].rollNo;
        }
    }

    void deleteStudent()
    {
        int id;
        bool found = false;
        cout << "Enter the ID of the student that you want to delete:" << endl;
        cin >> id;
        for (int i = 0; i < 5; i++)
        {
            if (stud[i].ID == id)
            {
                stud[i].ID = 0;
                stud[i].rollNo = 0;
                stud[i].stdName = "";
                found = true;
                cout << "The student has been deleted" << endl;
            }
        }
        if (!found)
            cout << "No such student is present in the library" << endl;
    }
};

int main()
{
    bookList b;
    studentList s;
    bool found = false;
    int choice;
    do
    {
        cout << "\n -----Library Information System-----\n";
        cout << "\n_______________________________________________________\n";
        cout << "\n 1. Add New Student\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 2. Delete Existing Student\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 3. Show All Students\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 4. Add New Book\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 5. Delete All Books\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 6. Show Particular Book\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 7. Show All Books\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 8. Sort Books In Ascending Order\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 9. Sort Books In Descending Ordetr\n";
        cout << "\n________________________________________________________\n";
        cout << "\n 10. Exit\n";

        cout << "Please choose an option from 1-10" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            s.addNewUser();
            break;

        case 2:
            s.deleteStudent();
            break;

        case 3:
            s.printAll();
            break;

        case 4:
            b.addNewBook();
            break;

        case 5:
            b.deleteAll();
            break;

        case 6:
            b.showParticularBook();
            break;

        case 7:
            b.printAll();
            break;

        case 8:
            b.sortA();
            break;

        case 9:
            b.sortD();
            break;

        case 10:
            found = true;
            cout << "You have sucessfully exited the program:)";
            break;
        default:
            cout << "Please choose a valid option from 1-10:" << endl;
        }

    } while (!found);
    return 0;
}