#include <iostream>

using namespace std;

class Book 
{
private:
    string title;
    string author;
    int publicationYear;
    int sales;
    string genre;
public:
    Book();
    Book(string title, string author, int publicationYear, int sales, string genre);
    ~Book();

    string getTitle();
    string getAuthor();
    int getPublicationYear();
    int getSales();
    string getGenre();

    void setTitle(string title);
    void setAuthor(string author);
    void setPublicationYear(int publicationYear);
    void setSales(int sales);
    void setGenre(string genre);
};

Book::Book()
{
}

Book::Book(string title, string author, int publicationYear, int sales, string genre)
    : title(title), author(author), publicationYear(publicationYear), sales(sales), genre(genre) {}

string Book::getTitle()
{
    return title;
}

string Book::getAuthor()
{
    return author;
}

int Book::getPublicationYear()
{
    return publicationYear;
}

int Book::getSales()
{
    return sales;
}

string Book::getGenre()
{
    return genre;
}

void Book::setTitle(string title)
{
    this->title = title;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setPublicationYear(int publicationYear)
{
    this->publicationYear = publicationYear;
}

void Book::setSales(int sales)
{
    this->sales = sales;
}

void Book::setGenre(string genre)
{
    this->genre = genre;
}

Book::~Book()
{
}