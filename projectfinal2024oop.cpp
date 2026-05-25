#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <limits>

using namespace std;

class Book
{
protected:
    static int bno; // Book number
    string bname;   // Book name
    string aname;   // Author's name
    string pname;   // Publication name

public:
    Book(const string &bne, const string &an, const string &pn) : bname(bne), aname(an), pname(pn) { bno++; }

    virtual void showDetails() const = 0;
    virtual void writeToFile() const = 0;

    // Getter functions for encapsulation
    int getBno() const
    {
        return bno;
    }

    string getBname() const
    {
        return bname;
    }

    string getAname() const
    {
        return aname;
    }

    string getPname() const
    {
        return pname;
    }

    friend class LibraryManager; // Friend class for handling library operations
};
int Book ::bno = 0;

class EBooks : public Book
{
private:
    string electronicId;

public:
    EBooks(const string &bne, const string &an, const string &pn, const string &eid) : Book(bne, an, pn), electronicId(eid)
    {
    }

    void showDetails() const override
    {
        cout << "Book no: " << bno << endl;
        cout << "Book Name: " << bname << endl;
        cout << "Author Name: " << aname << endl;
        cout << "Publisher Name: " << pname << endl;
        cout << "Electronic ID: " << electronicId << endl;
    }

    void writeToFile() const override
    {
        ofstream outE("Ebooks.txt", ios::app);
        outE << "Book no: " << bno << endl;
        outE << "Book Name: " << bname << endl;
        outE << "Author Name: " << aname << endl;
        outE << "Publisher Name: " << pname << endl;
        outE << "Electronic ID: " << electronicId << endl;
    }

    friend class LibraryManager; // Friend class for handling library operations
};

class FictionalBook : public Book
{
private:
    bool isSciFi; // Indicates whether the book is science fiction or not
    int pageCount;

public:
    FictionalBook(const string &bne, const string &an, const string &pn, bool sciFi, int pageCount) : Book(bne, an, pn), isSciFi(sciFi), pageCount(pageCount) { cout << "New fictional book made\n"; }

    void showDetails() const override
    {
        cout << "Book no: " << bno << endl;
        cout << "Book Name: " << bname << endl;
        cout << "Author Name: " << aname << endl;
        cout << "Publisher Name: " << pname << endl;
        cout << "Is Science Fiction: " << (isSciFi ? "Yes" : "No") << endl;
        cout << "Page Count: " << pageCount << endl;
    }
    void writeToFile() const override
    {
        ofstream outf("fictional.txt", ios::app);
        outf << "Book no: " << bno << endl;
        outf << "Book Name: " << bname << endl;
        outf << "Author Name: " << aname << endl;
        outf << "Publisher Name: " << pname << endl;
        outf << "Is Science Fiction: " << (isSciFi ? "Yes" : "No") << endl;
        outf << "Page Count: " << pageCount << endl;
    }
};

class CourseBook : public Book
{
private:
    string courseName;
    string level;
    int pageCount;

public:
    CourseBook(const string &bne, const string &an, const string &pn, const string &curse, const string &lvl, int pc) : Book(bne, an, pn), courseName(curse), level(lvl), pageCount(pc) { cout << "New Course book made\n"; }

    void showDetails() const override
    {
        cout << "Book no: " << bno << endl;
        cout << "Book Name: " << bname << endl;
        cout << "Author Name: " << aname << endl;
        cout << "Publisher Name: " << pname << endl;
        cout << "Curse Name: " << courseName << endl;
        cout << "Course Level: " << level << endl;
        cout << "Page Count: " << pageCount << endl;
    }
    void writeToFile() const override
    {
        ofstream outC("CourseBook.txt", ios::app);
        outC << "Book no: " << bno << endl;
        outC << "Book Name: " << bname << endl;
        outC << "Author Name: " << aname << endl;
        outC << "Publisher Name: " << pname << endl;
        outC << "Curse Name: " << courseName << endl;
        outC << "Course Level: " << level << endl;
        outC << "Page Count: " << pageCount << endl;
    }
};

class Pastpapers : public Book
{
private:
    string subject;
    int count;
    bool issolved;
    bool istopical;

public:
    Pastpapers(const string &bne, const string &an, const string &pn, const string &sub, int cnt, bool solved, bool topical) : Book(bne, an, pn), subject(sub), count(cnt), issolved(solved), istopical(topical) { cout << "New Past paper made\n"; }

    void showDetails() const override
    {
        cout << "Book no: " << bno << endl;
        cout << "Book Name: " << bname << endl;
        cout << "Author Name: " << aname << endl;
        cout << "Publisher Name: " << pname << endl;
        cout << "Subject: " << subject << endl;
        cout << "Count: " << count << endl;
        cout << "Solved: " << (issolved ? "Yes" : "No") << endl;
        cout << "Topical: " << (istopical ? "Yes" : "No") << endl;
    }
    void writeToFile() const override
    {
        ofstream outP("pastpapers.txt", ios::app);
        outP << "Book no: " << bno << endl;
        outP << "Book Name: " << bname << endl;
        outP << "Author Name: " << aname << endl;
        outP << "Publisher Name: " << pname << endl;
        outP << "Subject: " << subject << endl;
        outP << "Count: " << count << endl;
        outP << "Solved: " << (issolved ? "Yes" : "No") << endl;
        outP << "Topical: " << (istopical ? "Yes" : "No") << endl;
    }
};

class PoliticalBooks : public Book
{
private:
    string party;
    string country;
    string era; // the era for the political book

public:
    PoliticalBooks(const string &bne, const string &an, const string &pn, const string &party, const string &ctry, const string &era) : Book(bne, an, pn), party(party), country(ctry), era(era) { cout << "New political book made\n"; }

    void showDetails() const override
    {
        cout << "Book no: " << bno << endl;
        cout << "Book Name: " << bname << endl;
        cout << "Author Name: " << aname << endl;
        cout << "Publisher Name: " << pname << endl;
        cout << "Party: " << party << endl;
        cout << "Country: " << country << endl;
        cout << "Era: " << era << endl;
    }
    void writeToFile() const override
    {
        ofstream outPol("Politics.txt", ios::app);
        outPol << "Book no: " << bno << endl;
        outPol << "Book Name: " << bname << endl;
        outPol << "Author Name: " << aname << endl;
        outPol << "Publisher Name: " << pname << endl;
        outPol << "Party: " << party << endl;
        outPol << "Country: " << country << endl;
        outPol << "Era: " << era << endl;
    }
};

// class LibraryManager;
class Library
{
private:
    static const int MAX_BOOKS = 100; // Maximum number of books
    Book *books[MAX_BOOKS];           // Array to store books
    int size;
    // friend void LibraryManager :: displayMenu(Library& lib);                        // Current number of books

public:
    Library() : size(0) {}

    // Function to add a book to the library
    void addBook(Book *newBook)
    {
        if (size < MAX_BOOKS)
        {
            books[size++] = newBook;
            cout << "Book added successfully." << endl;
        }
        else
        {
            cout << "Library capacity reached. Cannot add more books." << endl;
        }
    }

    // Function to display details of all books in the library
    void showAvailableBooks() const
    {
        ifstream fin("fictional.txt");
        string line1;
        if (fin.is_open())
        {
            while (!fin.eof())
            {
                getline(fin, line1);
                cout << line1 << endl;
            }
        }
        else
        {
            cout << "No fictional books" << endl;
        }
        fin.close();
        ifstream Cin("CourseBook.txt");
        string line2;
        if (Cin.is_open())
        {
            while (!Cin.eof())
            {
                getline(Cin, line2);
                cout << line2 << endl;
            }
        }
        else
        {
            cout << "No Course books" << endl;
        }
        Cin.close();
        ifstream PPin("pastpapers.txt");
        string line3;
        if (PPin.is_open())
        {
            while (!PPin.eof())
            {
                getline(PPin, line3);
                cout << line3 << endl;
            }
        }
        else
        {
            cout << "No fictional books" << endl;
        }
        PPin.close();
        ifstream pin("Politics.txt");
        string line4;
        if (pin.is_open())
        {
            while (!pin.eof())
            {
                getline(pin, line4);
                cout << line4 << endl;
            }
        }
        else
        {
            cout << "No fictional books" << endl;
        }
        pin.close();
    }

    // Friend function to allow LibraryManager to access private members
    friend class LibraryManager;

    ~Library()
    {
        for (int i = 0; i < size; ++i)
        {
            delete books[i];
        }
    }
};

class LibraryManager
{
public:
    // Function to delete a book from the library by book number
    static void deleteBook(Library &library, int bookNo)
    {
        int index = -1;
        for (int i = 0; i < library.size; ++i)
        {
            if (library.books[i]->getBno() == bookNo)
            {
                index = i;
                delete library.books[i];
                break;
            }
        }
        if (index != -1)
        {
            for (int j = index; j < library.size - 1; ++j)
            {
                library.books[j] = library.books[j + 1];
            }
            library.size--;
            cout << "Book deleted successfully." << endl;
        }
        else
        {
            cout << "Book not found." << endl;
        }
    }
};

// Function to display the menu and handle user input
void displayMenu(Library &library)
{
    int choice = 0;
    int bookType = 0;
    bool exitMenu = false;
    while (!exitMenu)
    {
        system("cls");
        try
        {
            cout << "Menu:" << endl;
            cout << "1. Add Book" << endl;
            cout << "2. Show Available Books" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            fflush(stdin);

            if (!(cin >> choice) || cin.peek() != '\n')
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Invalid input. Please enter a valid integer choice.");
            }

            if (choice < 1 || choice > 4)
            {
                throw out_of_range("Input out of range. Please enter a number between 1 and 4.");
            }

            switch (choice)
            {
            case 1:
            {
                cout << "Select Book Type:" << endl;
                cout << "1. EBook" << endl;
                cout << "2. Fictional Book" << endl;
                cout << "3. Course Book" << endl;
                cout << "4. Pastpapers" << endl;
                cout << "5. Political Book" << endl;
                cout << "Enter book type: ";
                if (!(cin >> bookType))
                {
                    fflush(stdin);
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw invalid_argument ("Invalid input. Please enter a valid integer choice.");
                    continue;
                }

                if (bookType < 1 || bookType > 5)
                {
                    throw "Invalid book type.";
                }

                string bne, an, pn;
                cout << "Enter Book Name: ";
                cin.ignore();
                getline(cin, bne);
                cout << "Enter Author Name: ";
                getline(cin, an);
                cout << "Enter Publication Name: ";
                getline(cin, pn);

                Book *newBook = nullptr;
                switch (bookType)
                {
                case 1:
                {
                    string eid;
                    cout << "Enter Electronic ID: ";
                    cin >> eid;
                    newBook = new EBooks(bne, an, pn, eid);
                    break;
                }
                case 2:
                {
                    bool sciFi;
                    int pageCount;

                    cout << "Is it Science Fiction? (0/1): ";
                    cin >> sciFi;
                    cout << "Enter Page Count: ";
                    if (!(cin >> pageCount))
                    {
                        fflush(stdin);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "Invalid input. Please enter a valid integer choice.";
                        continue;
                    }
                    if (pageCount < 0)
                    {
                        throw "Invalid input. Please enter a valid integer choice.";
                        continue;
                    }
                    newBook = new FictionalBook(bne, an, pn, sciFi, pageCount);
                    break;
                }
                case 3:
                {
                    string courseName, level;
                    int pageCount;
                    if (pageCount < 0)
                    {
                        throw "Invalid input. Please enter a valid integer choice.";
                        continue;
                    }
                    cout << "Enter Course Name: ";
                    cin.ignore();
                    getline(cin, courseName);
                    cout << "Enter Level: ";
                    getline(cin, level);
                    cout << "Enter Page Count: ";
                    if (!(cin >> pageCount))
                    {
                        fflush(stdin);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "Invalid input. Please enter a valid integer choice.";
                        continue;
                    }
                    newBook = new CourseBook(bne, an, pn, courseName, level, pageCount);
                    break;
                }
                case 4:
                {
                    string subject;
                    int count;
                    bool issolved, istopical;
                    cout << "Enter Subject: ";
                    cin.ignore();
                    getline(cin, subject);
                    cout << "Enter Count: ";
                    if (!(cin >> count))
                    {
                        fflush(stdin);
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        throw "Invalid input. Please enter a valid integer choice.";
                        continue;
                    }
                    if (count < 0)
                    {
                        throw invalid_argument("Invalid input. Please enter a valid integer choice.");
                        continue;
                    }
                    cout << "Is it Solved? (0/1): ";
                    if (issolved < 0 && issolved > 1)
                    {
                        throw invalid_argument("Invalid input. Please enter a valid integer choice.");
                        continue;
                    }
                    cin >> issolved;
                    cout << "Is it Topical? (0/1): ";
                    if (istopical < 0 && istopical > 1)
                    {
                        throw invalid_argument("Invalid input. Please enter a valid integer choice.");
                        continue;
                    }
                    cin >> istopical;
                    newBook = new Pastpapers(bne, an, pn, subject, count, issolved, istopical);
                    break;
                }
                case 5:
                {
                    string party, country, era;
                    cout << "Enter Party: ";
                    cin.ignore();
                    getline(cin, party);
                    cout << "Enter Country: ";
                    getline(cin, country);
                    cout << "Enter Era: ";
                    getline(cin, era);
                    newBook = new PoliticalBooks(bne, an, pn, party, country, era);
                    break;
                }
                default:
                    throw "Invalid book type.";
                }

                if (newBook != nullptr)
                {
                    newBook->writeToFile();
                    library.addBook(newBook);
                }
                cout << "Press any key to continue..." << endl;
                getchar();
                break;
            }
            case 2:
                library.showAvailableBooks();
                cout << "Press any key to continue..." << endl;
                getchar();
                break;
            case 3:
                cout << "Exiting..." << endl;
                exitMenu = true;
                break;
            default:
                throw("Invalid choice.");
            }
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
        catch (const invalid_argument &ex)
        {
            cerr << "Exception occurred: " << ex.what() << endl;
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        catch (const exception &ex)
        {
            cerr << "Exception occurred: " << ex.what() << endl;
            cout << "Press Enter to continue...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }
}

int main()
{
    Library library;
    displayMenu(library);
    return 0;
}