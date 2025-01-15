#include <iostream>
#include <vector>

#include "book.hpp"
#include "balanceBST.hpp"
#include "treeFunctionalities.hpp"

using namespace std;

void displayMenu(int* choice);
void clearTerminal();
void inOrderTraversal(Node* root);
void preOrderTraversal(Node* root);
void wait();


int main()
{
    Book harryPotter("Harry Potter", "JK Rowling", 1997, 120000000, "fantasy");
    Book theHobbit("The Hobbit", "J.R.R. Tolkien", 1937, 140600000, "fantasy");
    Book PrideAndPrejudice("Pride and Prejudice", "Jane Austen", 1813, 20000000, "romance");
    Book toKillAMockingBird("To Kill a Mockingbird", "Harper Lee", 1960, 40000000, "classic");
    Book theDaVinciCode("The Da Vinci Code", "Dan Brown", 2003, 80000000, "thriller");
    Book TheCatcherInTheRye("The Catcher in the Rye", "J.D. Salinger", 1951, 65000000, "classic");
    Book Twilight("Twilight", "Stephenie Meyer", 2005, 120000000, "fantasy/romance");

    vector<Book> books;

    books.push_back(harryPotter);
    books.push_back(theHobbit);
    books.push_back(PrideAndPrejudice);
    books.push_back(toKillAMockingBird);
    books.push_back(theDaVinciCode);
    books.push_back(TheCatcherInTheRye);
    books.push_back(Twilight);

    for (int i = 0; i < books.size(); i++)
    {
        int publicationYear = books[i].getPublicationYear();
        insertBST(publicationYear);
    }

    while (true)
    {
        clearTerminal();
        int choice;
        displayMenu(&choice);
        
        switch (choice)
        {
        case 1:
            search();
            wait();
            break;

        case 2:
            insert(books);
            wait();
            break;

        case 3:
            remove();
            wait();
            break;

        case 4:
            inOrderTraversal(ROOT);
            wait();
            break;

        case 0:
        default:
            return 0;
        }
    }
    

    return 0;
}

void displayMenu(int* choice)
{
    cout << "What do you want to do in your library?" << endl;
    cout << "1: search for a book." << endl;
    cout << "2: insert a new book." << endl;
    cout << "3: remove a book." << endl;
    cout << "4: print library." << endl;
    cout << "0: quit." << endl;
    cin >> *choice;
}

void clearTerminal()
{
    cout << "\033[2J\033[1;1H";
}

void inOrderTraversal(Node* root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->leftChild);
        cout << root->data << endl;
        inOrderTraversal(root->rightChild);
    }
}

void preOrderTraversal(Node* root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void wait()
{
    string wait;
    cin >> wait;
}