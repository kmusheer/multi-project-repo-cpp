#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Book
{
    int id;
    string title, author;
    float price;
    int pages;
    int stock;

public:
    void input();
    static void displayHeader();
    void display();
    void update();
    void setId(int newId)
    {
        id = newId;
    }
    int getId()
    {
        return id;
    }
    string getTitle()
    {
        return title;
    }
    int bookStock()
    {
        return stock;
    }
    void setStock(int num)
    {
        stock = num;
    }
};

class BookShop
{
    vector<Book> books;

public:
    void addBook();
    void showBooks();
    void searchBook();
    void updateBook();
    void deleteBook();
    void buyBook();
};

void Book ::input()
{
    // cout << "Enter book id: ";
    // cin >> id;
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter book author: ";
    getline(cin, author);
    cout << "Enter book price: ";
    cin >> price;
    cout << "Enter number of pages: ";
    cin >> pages;
    cout << "Enter number of copies: ";
    cin >> stock;
}
void Book ::displayHeader()
{
    cout << setw(20) << "Book ID: "
         << setw(20) << "Book Title: "
         << setw(20) << "Book Author: "
         << setw(20) << "Book Price: "
         << setw(20) << "Number of Pages: "
         << setw(20) << "Number of copies: " << endl;
    cout << setfill('=') << setw(120) << "" << endl;
}
void Book ::display()
{
    cout << setfill(' ') << setw(20) << id
         << setw(20) << title
         << setw(20) << author
         << setw(20) << price
         << setw(20) << pages
         << setw(20) << stock << endl;
}
void Book ::update()
{

    cout << "Enter book author: ";
    cin.ignore();
    getline(cin, author);
    cout << "Enter book price: ";
    cin >> price;
    cout << "Enter number of pages: ";
    cin >> pages;
    cout << "Enter number of copies: ";
    cin >> stock;
    cout << "Updated successfully" << endl;
}

void BookShop ::addBook()
{
    Book newBook;
    int tempId;

    while (true)
    {
        cout << "Enter book id(unique): ";
        cin >> tempId;

        bool duplicate = false;
        for (auto &book : books)
        {
            if (book.getId() == tempId)
            {
                cout << "Book ID already exists. Please enter a unique ID.\n";
                duplicate = true;
                break;
            }
        }
        if (!duplicate)
        {
            newBook.setId(tempId);
            break;
        }
    }
    newBook.input();
    books.push_back(newBook);
    cout << "Book added successfully!\n";
}
void BookShop ::showBooks()
{
    if (books.empty())
    {
        cout << "No books available\n";
        return;
    }
    cout << "\n--- Book List ---\n";
    Book::displayHeader();
    for (auto &book : books)
    {
        book.display();
    }
}
void BookShop ::updateBook()
{
    int bookId, choice = 0;
    bool found = false;
    string bookTitle;
    cout << "\nEnter ur choice 1:Title \t2:Id : ";
    cin >> choice;

    while (true)
    {
        if (choice == 1)
        {
            cout << "Enter book title : ";
            cin.ignore();
            getline(cin, bookTitle);
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter book id: ";
            cin >> bookId;
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    for (auto &book : books)
    {
        if (book.getId() == bookId || book.getTitle() == bookTitle)
        {
            book.update();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Book not found\n";
    }
}
void BookShop ::searchBook()
{
    int bookId, choice = 0;
    bool found = false;
    string bookTitle;
    cout << "\nEnter ur choice 1:Title \t2:Id : ";
    cin >> choice;

    while (true)
    {
        if (choice == 1)
        {
            cout << "Enter book title : ";
            cin.ignore();
            getline(cin, bookTitle);
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter book id: ";
            cin >> bookId;
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    for (auto &book : books)
    {

        if (book.getId() == bookId || book.getTitle() == bookTitle)
        {
            Book::displayHeader();
            book.display();
            found = true;
        }
    }
    if (!found)
    {
        cout << "Book not found\n";
    }
}
void BookShop ::deleteBook()
{
    int bookId, choice = 0, count = 0;
    bool found = false;
    string bookTitle;
    cout << "\nEnter ur choice 1:Title \t2:Id : ";
    cin >> choice;

    while (true)
    {
        if (choice == 1)
        {
            cout << "Enter book title : ";
            cin.ignore();
            getline(cin, bookTitle);
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter book id: ";
            cin >> bookId;
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    for (auto it = books.begin(); it != books.end(); ++it)
    {
        if (it->getId() == bookId || it->getTitle() == bookTitle)
        {
            books.erase(it);
            cout << "Book deleted successfully\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found\n";
    }
}
void BookShop ::buyBook()
{
    int bookId, choice = 0;
    bool found = false;
    string bookTitle;
    cout << "\nEnter ur choice 1:Title \t2:Id : ";
    cin >> choice;

    while (true)
    {
        if (choice == 1)
        {
            cout << "Enter book title : ";
            cin.ignore();
            getline(cin, bookTitle);
            break;
        }
        else if (choice == 2)
        {
            cout << "Enter book id: ";
            cin >> bookId;
            break;
        }
        else
        {
            cout << "Invalid choice\n";
        }
    }
    for (auto &book : books)
    {
        if (book.getId() == bookId || book.getTitle() == bookTitle)
        {
            if (book.bookStock() <= 0)
            {
                cout << "Book out of stock\n";
                return;
            }
            book.setStock(book.bookStock() - 1);
            cout << "Book bought successfully\n";
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Book not found\n";
    }
}

int main()
{
    BookShop shop;
    int choice;
    do
    {
        cout << "\n--- Book Shop Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Show Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Buy Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            shop.addBook();
            break;
        case 2:
            shop.showBooks();
            break;
        case 3:
            shop.searchBook();
            break;
        case 4:
            shop.updateBook();
            break;
        case 5:
            shop.deleteBook();
            break;
        case 6:
            shop.buyBook();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);
    return 0;
}

