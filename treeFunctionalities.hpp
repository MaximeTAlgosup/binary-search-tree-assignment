#include <iostream>

using namespace std;

void search();
// void searchFromString(string data);
void searchFromInt(int data, bool search);
void insertBST(int data);
void insert(vector<Book>& books);
void remove();
void removeFromInt(int data, Node* parent, Node* current);
// void removeFromString(string data);

void search()
{
    int choice;
    string title;
    string author;
    int publicationYear;
    int sales;
    string genre;
    
    cout << "How do you want to search for the book?" << endl;
    cout << "1: by title." << endl;
    cout << "2: by author." << endl;
    cout << "3: by publication year." << endl;
    cout << "4: by sales." << endl;
    cout << "5: by genre." << endl;
    cout << "0: return to the previous screen." << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter the title of the book you are looking for:        // OUT OF ORDER";
        cin >> title;
        // searchFromString(author);
        break;
    
    case 2:
        cout << "Enter the author of the book you are looking for:       // OUT OF ORDER";
        cin >> author;
        // searchFromString(author);
        break;
    
    case 3:
        cout << "Enter the publication year of the book you are looking for: ";
        cin >> publicationYear;
        searchFromInt(publicationYear, true);
        break;
    
    case 4:
        cout << "Enter the sales of the book you are looking for:        // OUT OF ORDER";
        cin >> sales;
        // searchFromInt(sales, true);
        break;
    
    case 5:
        cout << "Enter the genre of the book you are looking for:        // OUT OF ORDER";
        cin >> genre;
        // searchFromString(genre);
        break;

    case 0:
    default:
        return;
    }
}

void searchFromInt(int data, bool search)
{
    Node* parent;
    Node* current;
    
    if (ROOT == NULL) //tree is empty
    {
        cout << "NO TREE!" << endl;
    }
    else
    {
        current = ROOT;
        parent = NULL;
        while (true)
        {
            parent = current;
            
            if (data == parent->data)
            {
                if (search)
                {
                    cout << "FOUND!" << endl;
                }
                else
                {
                    removeFromInt(data, parent, current);
                }
                return;
            }
            else if (data < parent->data) // go to the left subtree
            {
                current = current->leftChild;

                if (current == NULL)
                {
                    cout << "NOT FOUND!" << endl;
                    return;
                }
                
            }
            else // go to the right subtree
            {
                current = current->rightChild;

                if (current == NULL)
                {
                    cout << "NOT FOUND!" << endl;
                    return;
                }
       
            }
        }
    }
}

// void searchFromString(string data)
// {
//     NodeString* parent;
//     NodeString* current;
    
//     if (ROOT == NULL) //tree is empty
//     {
//         cout << "NO TREE!" << endl;
//         wait();
//     }
//     else
//     {
//         current = ROOT;
//         parent = NULL;
//         while (true)
//         {
//             parent = current;
            
//             if (data == parent->data)
//             {
//                 cout << "FOUND!" << endl;
//                 wait();
//                 return;
//             }
//             else if (data < parent->data) // go to the left subtree
//             {
//                 current = current->leftChild;

//                 if (current == NULL)
//                 {
//                     cout << "NOT FOUND!" << endl;
//                     wait();
//                     return;
//                 }
                
//             }
//             else // go to the right subtree
//             {
//                 current = current->rightChild;

//                 if (current == NULL)
//                 {
//                     cout << "NOT FOUND!" << endl;
//                     wait();
//                     return;
//                 }
//             }
//         }
//     }
// }

void insert(vector<Book>& books)
{
    string newTitle;
    string newAuthor;
    int newPublicationYear;
    int newSales;
    string newGenre;
    cout << "Enter the title of the book: ";
    cin >> newTitle;
    cout << "Enter the author of the book: ";
    cin >> newAuthor;
    cout << "Enter the publication year of the book: ";
    cin >> newPublicationYear;
    cout << "Enter the sales of the book: ";
    cin >> newSales;
    cout << "Enter the genre of the book: ";
    cin >> newGenre;
    Book newBook(newTitle, newAuthor, newPublicationYear, newSales, newGenre);
    books.push_back(newBook);
    insertBST(newPublicationYear);
    balanceBST(ROOT);
}

void insertBST(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    Node* parent;
    Node* current;
    
    if (ROOT == NULL) //tree is empty
    {
        ROOT = newNode;
    }
    else
    {
        current = ROOT;
        parent = NULL;
        while (true)
        {
            parent = current;
            
            if (data < parent->data) // go to the left subtree
            {
                current = current->leftChild;

                if (current == NULL)
                {
                    parent->leftChild = newNode;
                    return;
                }
                
            }
            else // go to the right subtree
            {
                current = current->rightChild;

                if (current == NULL)
                {
                    parent->rightChild = newNode;
                    return;
                }
            }
            
            
        }
        
    }
    
}

void remove()
{
    int publicationYear;
    cout << "Enter the publication year of the book want removed for: ";
    cin >> publicationYear;
    searchFromInt(publicationYear, false);
}

void removeFromInt(int data, Node* parent, Node* current)
{
    Node* temp;
    
    if (current->leftChild == NULL && current->rightChild == NULL)
    {
        if (parent->leftChild == current)
        {
            parent->leftChild = NULL;
        }
        else
        {
            parent->rightChild = NULL;
        }
        delete current;
    }
    else if (current->leftChild == NULL)
    {
        if (parent->leftChild == current)
        {
            parent->leftChild = current->rightChild;
        }
        else
        {
            parent->rightChild = current->rightChild;
        }
        delete current;
    }
    else
    {
        return;
    }
}