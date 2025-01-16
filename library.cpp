#include<bits/stdc++.h>

using namespace std;

class Message {
public:
    virtual void displayMessage(const string& message) = 0;
    virtual ~Message() {}
};

// Console Logger Implementation
class ConsoleMessage : public Message {
public:
    void displayMessage(const string& message) override {
        cout << "[Display Message]: " << message << endl;
    }
};

class Book
{
private:
string bookId;
string bookTitle;
string bookAuthor;
bool isAvailable;

public:
    Book(const string &id, const string &title, const string &author)
    {
        bookId = id;
        bookTitle = title;
        bookAuthor = author;
        isAvailable = true;

    }
    
    string getBookId()
    {
        return bookId;
    }

    string getBookTitle()
    {
        return bookTitle;
    }

    string getBookAuthor()
    {
        return bookAuthor;
    }

    bool getAvailablity()
    {
        return isAvailable;
    }

    void bookBorrow()
    {
        if(!isAvailable)
        {
            cerr<<"Book was already Borrrowed ";
        }
        isAvailable=false;
    }

    void returnBook()
    {
        if(isAvailable)
        {
            cerr<<"Book was not borrowed ";
        }
        isAvailable = true;
    }

};

class Library
{
private:

unordered_map<string, Book> books;
Message* msg;

public:

    Library(Message* address)
    {
        msg=address;
    }

    void addBook(const string &id,const string &title, const string &author)
    {
        if(books.find(id)!=books.end())
            cerr<<"Book id must be unique";
        
        books.emplace(id,Book(id,title,author));
        msg->displayMessage("Book added: " + title + " (ID: " + id + ")");
    }
    void borrowBook(const string &id)
    {
        auto it = books.find(id);
        if(it==books.end())
            cerr<<"Please enter a valid id to borrow book";
        it->second.bookBorrow();
    }
    
    void returnBook(const string &id)
    {
        auto it = books.find(id);
        if(it==books.end())
            cerr<<"Please enter a valid id to return book";
        it->second.returnBook();
    }

    void viewAvailableBook()
    {
        cout<<"Books Available : "<<endl;
        for(auto bk : books)
        {
            if(bk.second.getAvailablity())
                cout<<"ID: "<<bk.first<<", Title: "<<bk.second.getBookTitle()<<", Author: "<<bk.second.getBookAuthor()<<endl;
        }
    }
    
};

int main() {
    ConsoleMessage obj;
    Library library(&obj);

    try {
        library.addBook("1", "The Shubham", "Shubham Kumawat");
        library.addBook("2", "The Vishal ", "Vishal Choudhary");
        library.addBook("3", "The Manish", "Manish Choudhary");

        library.viewAvailableBook();

        library.borrowBook("2");
        library.viewAvailableBook();

        library.returnBook("2");
        library.viewAvailableBook();
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}