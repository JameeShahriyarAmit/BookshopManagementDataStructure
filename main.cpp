//======= DSA MINI PROJECT ==========
// Created By
//--------------------
// Jamee Shahriyar - A18CS3012
// Maliha Shahed - A18CS4004
// Shoaib Hossain - A18CS3035
//--------------------
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;


//#################################

// QUEUE IMPLEMENTATION

//#################################




// ##################     Node Class    #####################

class Node {
public:
	
    int id;   // the id has to be unique for each and every book
    string bookName;
    string authorName;
    double price;
    Node* next;

    Node() {
        id = 0;
        bookName = "";
        authorName = "";
        price = 0.0;
		

    }

    Node(int _id, string _bookName, string _authorName, double _price) {
        id = _id;
        bookName = _bookName;
        authorName = _authorName;
        price = _price;
    }

};

//######################### Queue class ##############################

class Queue {
public: 
    Node* front;
    Node* rear;

    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty();
    bool checkIfNodeExists(Node* n);
    void enqueue(Node * n);
    Node* dequeue();
    void storeBookFromFile();
    void displayAllBooks();
    int searchViaBookName();
    int searchViaAuthorName();
    Node * searchViaID();
    void updateBookListFile();// updates books in file
    void addBook(); // adds books to the Queue
    void modifyBookInfo(); // fuction needed to allow staff to make changes to the books in the list
	
};								  


bool Queue::isEmpty() {
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

bool Queue::checkIfNodeExists(Node * n) {
    Node* temp = front; // needed to traverse throughout the list
    bool exists = false;
    while (temp != NULL) {
        if (temp->id == n->id) {
            exists = true;
            break;
        }
        temp = temp->next;
    }
    return exists;
} 


void Queue::enqueue(Node * n) {
    if (isEmpty()) {
        n->next = NULL;
        front = n;
        rear = n;
        //cout << "Node EnQueued successfully! " << endl;
    }

    else if (checkIfNodeExists(n)) {
        cout << "Book already exist with this ID." << endl;
        cout << "Enter different ID value" << endl;
    }

    else {
        n->next = NULL;
        rear->next = n;
        rear = n;
        //cout << "Node EnQueued successfully! " << endl;
    }
}

Node* Queue::dequeue() {

    Node* temp = NULL;

    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return NULL;
    }

    else {
        if (front == rear) {
            temp = front;
            front = NULL;
            rear = NULL;
            return temp;
        }
        else {
            temp = front;
            front = front->next;
            return temp;
        }
    }


}

void Queue::storeBookFromFile() {
    int tempID;
    string tempBookName;
    string tempAuthorName;
    double tempPrice;

    int i = 1;
    string tempVal;
	
    Node* temp;

    fstream bookListFile;

    bookListFile.open("listofexistingbooks.txt");

    if (!bookListFile.is_open())
    {
        cout << "Error opening file"; exit(1);
    }
	
    while (getline(bookListFile, tempVal, ',')) {
        if (i > 4) {
            i = 1;
        }
        switch(i){
            case 1:
                tempID = stoi(tempVal);
                break;
                case 2:
                    tempBookName = tempVal;
                    break;
                    case 3:
                        tempAuthorName = tempVal;
                        break;
                        case 4:
                            tempPrice = stod(tempVal);
                            temp = new Node(tempID, tempBookName, tempAuthorName,tempPrice);
                            enqueue(temp);
                            break;
        }
        i++;
    }
    bookListFile.close();
}


void Queue::displayAllBooks() {
    if(isEmpty())
        cout << "Queue is Empty" << endl;
    else {
        cout << "_____________________________________## List Of Books ##______________________________________________" << endl;
        Node* temp = front;

        cout << setw(8);
        cout << "__Book ID__";
        cout << setw(25);
        cout << "__Book Name__";
        cout << setw(25);
        cout << "__Book Author__";
        cout << setw(20);
        cout << "__Book Price(RM)__" << endl;

        while (temp != NULL) {
            cout << setw(8);
            cout << temp->id;
            cout << setw(25);
            cout << temp->bookName;
            cout << setw(25);
            cout << temp->authorName;
            cout << setw(20);
            cout << temp->price << endl;

            temp = temp->next;
        }
    }
}

int Queue::searchViaBookName() {
    string searchName;

    cout << endl;
    cout << endl;
    cin.ignore();
    cout << "Enter Book Name exactly" << endl;
    getline(cin, searchName);

    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else {
        cout << "_____________________________________## List Of Books ##______________________________________________" << endl;
        Node* temp = front;

        cout << setw(8);
        cout << "__Book ID__";
        cout << setw(25);
        cout << "__Book Name__";
        cout << setw(25);
        cout << "__Book Author__";
        cout << setw(20);
        cout << "__Book Price(RM)__" << endl;
		
        while (temp != NULL) {
            if (searchName == temp->bookName) {
                cout << setw(8);
                cout << temp->id;
                cout << setw(25);
                cout << temp->bookName;
                cout << setw(25);
                cout << temp->authorName;
                cout << setw(20);
                cout << temp->price << endl;

                return temp->id;
            }
            temp = temp->next;
        }
        return -1;
    }
}

int Queue::searchViaAuthorName() {
    string searchAuthor;
	
    cout << endl;
    cout << endl;
    cin.ignore();
    cout << "Enter Author name Name exactly" << endl;
    getline(cin, searchAuthor);

    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else {
        cout << "_____________________________________## List Of Books ##______________________________________________" << endl;
        Node* temp = front;

        cout << setw(8);
        cout << "__Book ID__";
        cout << setw(25);
        cout << "__Book Name__";
        cout << setw(25);
        cout << "__Book Author__";
        cout << setw(20);
        cout << "__Book Price(RM)__" << endl;

        while (temp != NULL) {
            if (searchAuthor == temp->authorName) {
                cout << setw(8);
                cout << temp->id;
                cout << setw(25);
                cout << temp->bookName;
                cout << setw(25);
                cout << temp->authorName;
                cout << setw(20);
                cout << temp->price << endl;

                return temp->id;
            }
            temp = temp->next;
        }
        return -1;
    }
}

void Queue::updateBookListFile() {

    Node* temp = front;
    fstream bookListFile;
    bookListFile.open("listofexistingbooks.txt", ios::out);

    while (temp != NULL) {

        // add to file "listofexistingbooks.txt"

        bookListFile << endl;
        bookListFile << temp->id << "," << temp->bookName << "," << temp->authorName << "," << temp->price << ",";

        temp = temp->next;
    }
    bookListFile.close();
}

void Queue::addBook() {
    int tempID;
    string tempBookName;
    string tempAuthorName;
    double tempPrice;

    Node* temp;
    cout << endl;
    cout << endl;
    cout << "========== ADD BOOK ===========" << endl;
    cout << "=====Fill out the necessary information  to add Book=====" << endl;
    cout << "Enter a unique Book ID =>";
    cin >> tempID;
    cin.ignore();
    cout << "Enter book name  =>";
    getline(cin, tempBookName);
    cout << "Enter the name of the author =>";
    getline(cin, tempAuthorName);
    cout << "Enter the price =>";
    cin >> tempPrice;

    // add to queue

    temp = new Node(tempID,tempBookName,tempAuthorName,tempPrice);
    enqueue(temp);
    // update booklistfile
    updateBookListFile();
    // display new list of books in output
    displayAllBooks();

}

Node* Queue::searchViaID() {
    int searchID;

    cout << endl;
    cout << endl;
    cout << "Enter ID exactly => ";
    cin >> searchID;
	

    if (isEmpty())
        cout << "Queue is Empty" << endl;
    else {
        cout << "_____________________________________## List Of Books ##______________________________________________" << endl;
        Node* temp = front;

        cout << setw(8);
        cout << "__Book ID__";
        cout << setw(25);
        cout << "__Book Name__";
        cout << setw(25);
        cout << "__Book Author__";
        cout << setw(20);
        cout << "__Book Price(RM)__" << endl;

        while (temp != NULL) {
            if (searchID == temp->id) {
                cout << setw(8);
                cout << temp->id;
                cout << setw(25);
                cout << temp->bookName;
                cout << setw(25);
                cout << temp->authorName;
                cout << setw(20);
                cout << temp->price << endl;

                return temp;
            }
            temp = temp->next;
        }
        return temp = NULL;
    }
}


void Queue::modifyBookInfo() {
    displayAllBooks();
    cout << endl;
    cout << "======== MODIFY BOOK ========" << endl;
    cout << "=====Fill out the necessary information  to Modify Book=====" << endl;
    Node* temp = searchViaID();
    if (temp != NULL) {
        cout << endl;
        cin.ignore();
        cout << "The book has been found. You can now make modifications" << endl;
        cout << "Modify book name => ";
        getline(cin, temp->bookName);
        cout << "Modify author name => ";
        getline(cin, temp->authorName);
        cout << "Modify price => ";
        cin >> temp->price;
        cout << endl;

        // code to show the moddification
        displayAllBooks();
        // code to print changes on to file
        updateBookListFile();
    }

    else {
        cout << endl;
        cout << endl;
        cout << "***  The book with the ID entered exist doesnt exist. Therefore modification" << endl;
        cout << "      of information of the specific book is not possible  ***" << endl;
    }
	
}


//#########################  BookShopManager class ##################################


class BookShopManager {
public:
    Queue queue;
    double discountPercent = 5;
    double SpendingAmountForDiscount = 100;

    void storeBookInQueue();
    void addBooktoList();
    void modifyBookInList();
    void displayBookList();
    void setDiscount();
	
};
void BookShopManager::storeBookInQueue() {
    queue.storeBookFromFile();
}

void BookShopManager::addBooktoList() {
	
    queue.addBook();
}

void BookShopManager::modifyBookInList() {
    queue.modifyBookInfo();
}

void BookShopManager::displayBookList() {
    queue.displayAllBooks();
}

void BookShopManager::setDiscount() {
    fstream discountFileStore;
    discountFileStore.open("discountInfoFile.txt", ios::out);

    cout << "Enter minimum spending amount for discount => ";
    cin >> SpendingAmountForDiscount;
    cout << "Enter the percentage value for discount => ";
    cin >> discountPercent;

    discountFileStore << SpendingAmountForDiscount<<" "<< discountPercent;
}
//########################################
//        LINK LIST
// Implementation of Singly Linked List

//########################################



//##################### BookOrderNode class ####################

class BookOrderNode {
public:
    int orderBookId;
    string orderBookName;
    double orderBookPrice;
    int orderBookQty;
    double orderTotalPrice;
    BookOrderNode* next;

    BookOrderNode() {
        orderBookId = 0;
        orderBookName = "";
        orderBookPrice = 0.0;
        orderBookQty = 0;
        orderTotalPrice = 0.0;
        next = NULL;
    }

    BookOrderNode(int id,string name,double price,int qty) {
        orderBookId = id;
        orderBookName = name;
        orderBookPrice = price;
        orderBookQty = qty;
        orderTotalPrice = orderBookPrice* orderBookQty;
    }
};



//###################### SinglyLinkedList class ############################

class SinglyLinkedList {
public:
    BookOrderNode* head;

    SinglyLinkedList(){
        head = NULL;
    }

    SinglyLinkedList(BookOrderNode* n) {
        head = n;
    }

    void addEachBookOrder(BookOrderNode* n);
    double paymentAmount();
    void printAllOrderNodes();

    // ##  IMPLEMENTATION OF BUBBLE SORT ##

    void bubbleSortAllOrderNodes();
};

void SinglyLinkedList::addEachBookOrder(BookOrderNode * n) {
    if (head == NULL) {
        head = n;
		
        cout << endl;
        cout << endl;
        cout << "###### Your order has been added to cart ######" << endl;
    }
    else {
        BookOrderNode* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
		
        cout << endl;
        cout << endl;
        cout << "###### Your order has been added to cart ######" << endl;
    }

}

double SinglyLinkedList::paymentAmount() {
    BookOrderNode* temp = head;
    double sumTotal = 0.0;

    if (head == NULL) {
        cout << "No items have been ordered" << endl;
        return sumTotal;
    }

    else {
        while (temp != NULL) {
            sumTotal += temp->orderTotalPrice;
            temp = temp->next;
        }
        return sumTotal;
    }
}

void SinglyLinkedList::printAllOrderNodes() {
    if (head == NULL) {
        cout <<"No orders to print" << endl;
    }

    else{

        // implementing bubble sort to organize all orders

        bubbleSortAllOrderNodes();

        BookOrderNode* temp = head;

        while (temp != NULL) {
            cout << setw(6);
            cout << temp->orderBookId;
            cout << setw(25);
            cout << temp->orderBookName;
            cout << setw(15);
            cout << temp->orderBookPrice;
            cout << setw(15);
            cout << temp->orderBookQty;
            cout << setw(15);
            cout << temp->orderTotalPrice << endl;

            temp = temp->next;
        }
    }
}

void SinglyLinkedList::bubbleSortAllOrderNodes() {
    BookOrderNode* temp1, * temp2, * temp3, * temp4, * temp5;
    temp4 = NULL;

    while (head->next != temp4) {
        temp3 = temp1 = head;
        temp2 = temp1->next;

        while (temp1 != temp4) {
            if (temp1->orderBookId > temp2->orderBookId) {
                if (temp1 == head) {
                    temp5 = temp2->next;
                    temp2->next = temp1;
                    temp1->next = temp5;

                    head = temp2;
                    temp3 = temp2;
                }
                else {
                    temp5 = temp2->next;
                    temp2->next = temp1;
                    temp1->next = temp5;

                    temp3->next = temp2;
                    temp3 = temp2;
				
                }
            }

            else {
                temp3 = temp1;
                temp1 = temp1->next;
            }
            temp2 = temp1->next;
            if (temp2 == temp4) {
                temp4 = temp1;
            }
        }
    }
}

//########################   Customer class ##########################

class Customer {
public:
	
    string name;
    string phoneNum;
    Queue custQueue;
    int quantity = 0;
    double totalPayment=0.0;
    double discount = 0.0;
    double minSpending = 0.0;
    SinglyLinkedList orderList; // use of link list
	
    void storeInQueue();
    int searchByName();
    int searchByAuthor();
    void viewAllBooks();
    void purchaseBook();
	
};
void Customer::storeInQueue() {
    custQueue.storeBookFromFile();
}


int Customer::searchByName() {
    int i =custQueue.searchViaBookName();
    return i;
}

int Customer::searchByAuthor() {
    int j = custQueue.searchViaAuthorName();
    return j;
}

void Customer::viewAllBooks() {
    custQueue.displayAllBooks();

}


void Customer::purchaseBook() {
    cout << endl;
    cout << endl;
    cout << "===================== PARCHASE BOOK =====================" << endl;
    cin.ignore();
    cout << "Hello!! Enter your name to make purchase =>";
    getline(cin, name);
    cout << "Enter your phone number =>";
    getline(cin, phoneNum);
    cout << endl << endl;
    custQueue.displayAllBooks();
    cout << endl << endl;

    int option = 0;

    while (option != 2) {
        cout << endl;
        cout << "=== From the display above enter the ID of the BOOK you want to purchase ===" << endl;
        Node* temp = custQueue.searchViaID();
        cout << endl;
        cout << endl;
        cout << "Enter the quantity of the book you want to purchase =>";
        cin >> quantity;
		
        // create an object of BookOrderNode
        BookOrderNode* newNode = new BookOrderNode(temp->id,temp->bookName,temp->price,quantity);
        orderList.addEachBookOrder(newNode);

        cout << endl;
        cout << endl;
        cout << "## To add another item  ENTER Any number other than 2" << endl;
        cout << "## To submit order ENTER 2" << endl;
        cout << "      Enter =>";
        cin >> option;
        cin.ignore();
    }


    // Logic for Discount and amount owed by customer
    ifstream discountFileGet;
    discountFileGet.open("discountInfoFile.txt");
    if (!discountFileGet.is_open())
    {
        cout << "Error opening file"; exit(1);
    }

    discountFileGet>> minSpending >> discount;

	

    double tempTotalPayment = orderList.paymentAmount();
	

    if (tempTotalPayment >= minSpending) {
        totalPayment = tempTotalPayment - ((discount / 100) * tempTotalPayment);
    }

    else {
        totalPayment = tempTotalPayment;
    }

	


    //-----------------------------------------------


    cout << endl << endl;
    cout << "Thank you for ordering" << endl;
    cout << "Here is your Receipt" << endl;
    cout << endl << endl << endl;
    cout << "                                             UTM BOOKSHOP                        " << endl;
    cout << " ============================================= RECEIPT ============================================" << endl;
    cout << " Customer Name  : " << name << "                             " <<"Contact Number : " << phoneNum << endl;
    cout <<  endl;
    cout << setw(6);
    cout << "--ID--";
    cout << setw(25);
    cout << "--Item--";
    cout << setw(15);
    cout << "--Price--";
    cout << setw(15);
    cout << "--Quantity--";
    cout << setw(15);
    cout << "--Total--" << endl;
    orderList.printAllOrderNodes();
    cout << endl;
    cout << " -------------------------------------------------------------------------------------------------" << endl;
    cout << "          GROSS AMOUNT(RM)                                                         " <<tempTotalPayment<<endl;
    cout << "          DISCOUNT (spending > " << minSpending << " RM )                                            " << discount << "%" << endl;
    cout << " _________________________________________________________________________________________________" << endl;
    cout << "          AMOUNT TO BE PAYED(RM)                                                || " << totalPayment <<endl;
    cout << " -------------------------------------------------------------------------------------------------" << endl;

}





int main() {

    string userName;
    string passWord;
    int x;

    string usernameInput;
    string passwordInput;

    Customer c;
    c.storeInQueue();

    BookShopManager b;
    b.storeBookInQueue();

    ifstream staffLoginFile;
    staffLoginFile.open("loginCredentials.txt");

    if (!staffLoginFile.is_open())
    {
        cout << "Error opening file"; exit(1);
    }

    staffLoginFile >> userName >> passWord;

    c:
	
    int mainMenuOption;

    cout << "================ THIS IS THE UTM BOOK SHOP ==============" << endl;
    cout << "1. Customer" << endl;
    cout << "2. Book Shop Manager Login" << endl;
    cout << "Enter either 1 or 2 to proceed =>";
	

    cin >> mainMenuOption;

    switch (mainMenuOption) {
        case 1:
            int custMenuOp;
		
            a:
                cout << endl;
                cout << endl;
                cout << "============= Hello! Welcome to our store! ============ " << endl;
                cout << "=========== CUSTOMER MENU ==========" << endl;
                cout << "1. View all books available" << endl;
                cout << "2. Search by Title" << endl;
                cout << "3. Search by Author" << endl;
                cout << "4. Purchase books " << endl;
                cout << "5. Exit Program" << endl;
                cout << "Enter the numbers 1,2,3,4 or 5 for the action you want to perform =>";
                cin >> custMenuOp;
		
                while (custMenuOp!=5) {

                    if (custMenuOp == 1) {
                        c.viewAllBooks();
                    }
                    else if (custMenuOp == 2) {
                        x = c.searchByName();
                        if (x == -1) {
                            cout << "Book with the title entered doesnot exist" << endl;
                        }
                    }
                    else if (custMenuOp == 3) {
                        x = c.searchByAuthor();
                        if (x == -1) {
                            cout << "Book with the author name entered doesnot exist" << endl;
                        }
                    }
                    else if (custMenuOp == 4) {
                        c.purchaseBook();
                    }

                    else {
                        cout << "You have Entered incorrect number. Try again =>" << endl;
                        cout << endl;
                        cout << endl;
                        goto a;
                    }
                    cout << endl;
                    cout << endl;
                    cout << "============= Hello! Welcome to our store! ============ " << endl;
                    cout << "=========== CUSTOMER MENU ==========" << endl;
                    cout << "1. View all books available" << endl;
                    cout << "2. Search by Title" << endl;
                    cout << "3. Search by Author" << endl;
                    cout << "4. Purchase books " << endl;
                    cout << "5. Exit Program" << endl;
                    cout << "Enter the number 1,2,3,4 or 5 for the action you want to perform =>";
                    cin >> custMenuOp;
                }

                break;


                case 2:
		
                    int adminMenuOp;
                    cin.ignore();
                    d:
        cout << endl;
        cout << "===== Login ===== (username = jamee , password = hello just to test {these values are taken from file})"<< endl;
        cout << "Enter Username =>";
        getline(cin, usernameInput);
        cout << "Enter Password =>";
        getline(cin, passwordInput);

        if ((usernameInput == userName) && (passwordInput == passWord)) {

            e:
            cout << endl;
            cout << endl;
            cout << "=========== MANAGER PANEL ==========" << endl;
            cout << "1. View Book List" << endl;
            cout << "2. Add Book" << endl;
            cout << "3. Modify Book Information" << endl;
            cout << "4. Manage Discount Offers " << endl;
            cout << "5. Exit Program" << endl;
            cout << "Enter the number for the action you want to perform =>";
			
            cin >> adminMenuOp;

            while (adminMenuOp != 5) {
                if (adminMenuOp == 1) {
                    b.displayBookList();
                }
                else if (adminMenuOp == 2) {
                    b.addBooktoList();
                }
                else if (adminMenuOp == 3) {
                    b.modifyBookInList();
                }
                else if (adminMenuOp == 4) {
                    b.setDiscount();
                }

                else {
                    cout << "You have Entered incorrect number. Try again =>" << endl;
                    cout << endl;
                    cout << endl;
                    goto e;
                }

                cout << endl;
                cout << endl;
                cout << "=========== MANAGER PANEL ==========" << endl;
                cout << "1. View Book List" << endl;
                cout << "2. Add Book" << endl;
                cout << "3. Modify Book Information" << endl;
                cout << "4. Manage Discount Offers " << endl;
                cout << "5. Exit Program" << endl;
                cout << "Enter the number for the action you want to perform =>";
                cin >> adminMenuOp;
            }
        }

        else {
            cout << "Incorrect Login Information! Try Again !" << endl;
            goto d;
        }

        break;

		


        default:
            cout << "You have Entered incorrect number. Try again =>" << endl;
            cout << endl;
            cout << endl;
            goto c;
	
    }
	
    //system("pause");
    return 0;
	
}