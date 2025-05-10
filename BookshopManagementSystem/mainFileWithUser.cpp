#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <conio.h>

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
    // Setters
    void setId(int newId)
    {
        id = newId;
    }
    void setTitle(string newTitle)
    {
        title = newTitle;
    }
    void setAuthor(string newAuthor)
    {
        author = newAuthor;
    }
    void setPrice(float newPrice)
    {
        price = newPrice;
    }
    void setPages(int newPages)
    {
        pages = newPages;
    }
    void setStock(int num)
    {
        stock = num;
    }
    // Getters
    int getId()
    {
        return id;
    }
    string getTitle()
    {
        return title;
    }
    string getAuthor()
    {
        return author;
    }
    float getPrice()
    {
        return price;
    }
    int getPages()
    {
        return pages;
    }
    int getBookStock()
    {
        return stock;
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

    // File management functions
    void saveToFile();
    void loadFromFile();
};

void Book ::input()
{
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
            cout << "Enter new details for the book:\n";
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

    while (true)
    {
        cout << "\nEnter ur choice 1:Title \t2:Id : ";
        cin >> choice;
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
            if (book.getBookStock() <= 0)
            {
                cout << "Book out of stock\n";
                return;
            }
            book.setStock(book.getBookStock() - 1);
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

void BookShop ::saveToFile()
{
    ofstream writeFile("books.txt");
    if (!writeFile)
    {
        cout << "Error opening file for writing.\n";
        return;
    }
    if (writeFile.is_open())
    {
        for (auto &book : books)
        {
            writeFile << book.getId() << "\n"
                      << book.getTitle() << "\n"
                      << book.getAuthor() << "\n"
                      << book.getPrice() << "\n"
                      << book.getPages() << "\n"
                      << book.getBookStock() << "\n";
        }
        writeFile.close();
    }
    else
    {
        cout << "Error opening file for writing.\n";
    }
}

void BookShop ::loadFromFile()
{
    Book newBook;
    ifstream readFile("books.txt");
    if (!readFile)
    {
        cout << "Error opening file for reading.\n";
        return;
    }
    if (readFile.is_open())
    {
        int id, pages, stock;
        string title, author;
        float price;

        while (readFile >> id)
        {
            readFile.ignore();
            getline(readFile, title);
            getline(readFile, author);
            readFile >> price;
            readFile >> pages;
            readFile >> stock;

            if (readFile.eof())
                break;

            newBook.setId(id);
            newBook.setTitle(title);
            newBook.setAuthor(author);
            newBook.setPrice(price);
            newBook.setPages(pages);
            newBook.setStock(stock);

            books.push_back(newBook);
        }
        cout << "Books loaded successfully!\n";
    }
    else
    {
        cout << "Error opening file for reading.\n";
    }
    readFile.close();
}

string generatePassword()
{
    int range;
    string pwd;
    srand(time(NULL));
    char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                   "abcdefghijklmnopqrstuvwxyz"
                   "0123456789"
                   "!@#$%^&*()-_=+[]{}|;:',.<>/?`~";

    cout << "Enter range of password : ";
    cin >> range;
    cin.ignore();
    cout << "Your passwrod is : ";
    int len = strlen(input);
    for (int i = 0; i < range; i++)
    {
        pwd += input[rand() % len];
    }
    return pwd;
    // cout <<"Password : " << pwd << endl;
}

void registration()
{
    bool isValid = false;
    string name, password, role;
    string cnfrmPassword;
    int choice;
    cout << "Enter your name : ";
    getline(cin, name);
    cout << "Enter your role (admin/user): ";
    // cin.ignore();
    cin >> role;
    cout << "Enter your choice 1:generatedPassword \t2:userPassword : ";
    cin >> choice;
    cin.ignore();
    if (choice == 1)
    {
        password = generatePassword();
        isValid = true;
        cout << "Your password is : " << password << endl;
        // return;
    }
    else if (choice == 2)
    {
        int attempts = 3;
        cout << "Enter your password (no spaces): ";
        cin >> password;
        while (--attempts)
        {
            cout << "Confirm your password : ";
            cin >> cnfrmPassword;
            cin.ignore();
            if (password == cnfrmPassword)
            {
                cout << "Matched successfully" << endl;
                isValid = true;
                break;
            }
            else
            {
                cout << "Password mismatch. Please try again." << endl;
                cout << attempts << " attempts left" << endl;
                isValid = false;
            }
        }
    }
    else
    {
        cout << "Invalid choice " << endl;
        return;
    }
    if (isValid)
    {
        ofstream writefile("user.txt",ios::app); // Open file in append mode
        if (!writefile)
        {
            cout << "Error opening file for writing.\n";
            return;
        }
        if (writefile.is_open())
        {
            writefile << name << "\n"
                      << role << "\n"
                      << password << "\n";
            cout << "User registered successfully!\n";
            writefile.close();
        }
    }
}

int login()
{
    string name, password, role;
    string pwd, lname;
    char ch;
    int attempts = 3;

    cout << "Enter your login credentials\n";
    cout << "User name : ";
    getline(cin, lname);

    while (attempts--)
    {
        pwd.clear();
        cout << "Password: ";
        while ((ch = getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!pwd.empty())
                {
                    pwd.pop_back();
                    cout << "\b \b";
                }
            }
            else
            {
                pwd.push_back(ch);
                cout << "*";
            }
        }
        cout << endl;

        ifstream readfile("user.txt");
        if (!readfile)
        {
            cout << "Error opening file for reading.\n";
            return 0;
        }

        bool found = false;
        while (getline(readfile, name))
        {
            getline(readfile, role);
            getline(readfile, password);

            if (name == lname && password == pwd)
            {
                found = true;
                if (role == "admin")
                {
                    cout << "\nLogin successful as admin.\n";
                    return 1;
                }
                else if (role == "user")
                {
                    cout << "\nLogin successful as user.\n";
                    return 2;
                }
            }
        }
        readfile.close();

        if (!found)
        {
            cout << "Incorrect credentials. " << attempts << " attempt(s) left.\n";
        }
        else
        {
            break; // no need to continue if login was successful
        }
    }

    cout << "\nLogin failed. No attempts left.\n";
    return 0;
}

int main()
{
    char choice;
    int loginRole = 0;
    BookShop bookShop;
    bookShop.loadFromFile();
    while (true)
    {
        cout << "\n1. Registration\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case '1':
            registration();
            break;
        case '2':
            loginRole = login();
            if (loginRole == 1)
            {
                while (true)
                {
                    cout << "\nAdmin Menu:\n";
                    cout << "1. Add Book\n2. Show Books\n3. Update Book\n4. Search Book\n5. Delete Book\n6. Save to File\n7. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice)
                    {
                    case '1':
                        bookShop.addBook();
                        break;
                    case '2':
                        bookShop.showBooks();
                        break;
                    case '3':
                        bookShop.updateBook();
                        break;
                    case '4':
                        bookShop.searchBook();
                        break;
                    case '5':
                        bookShop.deleteBook();
                        break;
                    case '6':
                        bookShop.saveToFile();
                        break;
                    case '7':
                        exit(0);
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
            }
            else if (loginRole == 2)
            {
                while (true)
                {
                    cout << "\nUser Menu:\n";
                    cout << "1. Show Books\n2. Search Book\n3. Buy Book\n4. Exit\n";
                    cout << "Enter your choice: ";
                    cin >> choice;
                    cin.ignore();

                    switch (choice)
                    {
                    case '1':
                        bookShop.showBooks();
                        break;
                    case '2':
                        bookShop.searchBook();
                        break;
                    case '3':
                        bookShop.buyBook();
                        break;
                    case '4':
                        exit(0);
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
            }
            else
            {
                cout << "Login failed.\n";
            }
            break;

        case '3':
            exit(0);
        default:
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}
