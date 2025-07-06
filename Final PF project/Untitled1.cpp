//This is a BookShop Management system program.
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const int MAX_BOOKS = 100;
//Variables are globally declare because they will be used in many functions
int addedBooks = 0, choice = 0, num = 0, updateChoice = 0;
string searchName , Delete, updateName;
bool searchNameFound = false;

//Declaration of Simple Variables
int bookquantity;
int bookprice;
string booktitle;
string bookpublisher;
string bookauthor;

// Declarations of pointer Variables
int *bookquantityPointers[MAX_BOOKS];
int *bookpricePointers[MAX_BOOKS];
string *booktitlePointers[MAX_BOOKS];
string *bookpublisherPointers[MAX_BOOKS];
string *bookauthorPointers[MAX_BOOKS];

//Declaration of Array Variables
int bookquantityArray[MAX_BOOKS];
int bookpriceArray[MAX_BOOKS];
string booktitleArray[MAX_BOOKS];
string bookpublisherArray[MAX_BOOKS];
string bookauthorArray[MAX_BOOKS];

//Declaration of Simple Functions
void addBook();
void displayBook();
void searchBook();
void deleteBook();
void updateBook();

//Declaration of Functions For Array Use
void addBooksArray();
void displayBooksArray();
void searchBookArray();
void deleteBookArray();
void updateBookArray();

// Declaration of Functions for Pointers
void addBooksPointers();
void displayBooksPointers();
void searchBookPointers();
void deleteBookPointers();
void updateBookPointers();

int main()
{
	int userchoice;
	
	cout << "-------------------------------Welcome to Book Shop Management System-----------------------------------\n";
	//Menu Displaying to chose how you want run the program
	cout<<"\n\nHow would you like to run the program? ";
	cout<<"\n1. Simple ";
	cout<<"\n2. With Use Of Arrays";
	cout<<"\n3. With Use of Pointers";
	
	cout<<"\n\nEnter your desired Choice to run This Program: ";
	cin>>userchoice;
	
    if(userchoice==1)
	{
		do 
		{
        	cout << "\n---------------------------Displaying Menu--------------------------------";	
        	cout << "\nWhich Operation do you want to perform?\n";
        	cout << "1. Add Book\n";
        	cout << "2. Display Book\n";
        	cout << "3. Search Book\n";
        	cout << "4. Delete Book\n";
        	cout << "5. Update Book Information\n";
        	cout << "6. Exit\n\n";
        	cout << "Enter your choice: ";
        	cin >> choice;
              
            cout<< "-----------------------------------------------------------\n";
				 
        	if (choice == 1)
            {
                addBook();            //add books
            }
            else if (choice == 2)
            {
                displayBook();        // Display Books
            }
            else if (choice == 3)
            {
                searchBook();         // Search Book Information
            }
            else if (choice == 4)
            {
                deleteBook();         // Deleting Books 
            }
            else if (choice == 5)
            {
                updateBook();         //Update book information 
            }
            //Exiting from program.
            else if (choice == 6)
            {
                exit(0);              // To direct exit from program
            }
            else
            {
                cout << "Wrong Input";    //If entered choice is not between 1-6 then it will show
            }
        	
    	} while (choice != 6);
	}
				
	else if(userchoice==2)
	{
		do
        {
            cout << "\n---------------------------Displaying Menu--------------------------------";	
            cout << "\nWhich Operation do you want to perform?\n";
            cout << "1. Add Books\n";
            cout << "2. Display Books\n";
            cout << "3. Search Book\n";
            cout << "4. Delete Book\n";
            cout << "5. Update Book Information\n";
            cout << "6. Exit\n\n";
            cout << "Enter your choice: ";
            cin >> choice;
                
			cout<< "-----------------------------------------------------------\n";
				    
            if (choice == 1)
            {
                addBooksArray();           // Adding Books
            }            
            else if (choice == 2)
            {
                displayBooksArray();       // Display Books
            }                
            else if (choice == 3)
            {
                searchBookArray();         // Search Book Information
            }             
            else if (choice == 4)
            {
                deleteBookArray();         // Deleting Book
            }
            else if (choice == 5)
            {
                updateBookArray();         //Update Book information
            }
            //Exiting from program.
            else if (choice == 6)
            {
                exit(0);                   //To Direct exit from program
            }
            else
            {
                cout << "Wrong Input";     //If entered number is not between 1 to 6
            }
    	} while (choice != 6);
	}
		
	else if(userchoice==3)
	{
		do
		{
    		cout << "\n---------------------------Displaying Menu--------------------------------";	
        	cout << "\nWhich Operation do you want to perform?\n";
        	cout << "1. Add Books\n";
        	cout << "2. Display Books\n";
        	cout << "3. Search Book\n";
        	cout << "4. Delete Book\n";
        	cout << "5. Update Book Information\n";
        	cout << "6. Exit\n\n";
        	//Enter the chioce you want
        	cout << "Enter your choice: ";   
        	cin >> choice;

			cout<< "-----------------------------------------------------------\n";
			
        	if (choice == 1)
        	{
        		addBooksPointers();    //Add function calling of Pointers       
	    	}
        	else if (choice == 2)
        	{
       			displayBooksPointers();     //Display function calling of Pointers
        	}
        	else if (choice == 3)
        	{
       			searchBookPointers();       //Search function calling of Pointers
        	} 
        	else if (choice == 4)
        	{
       			deleteBookPointers();       //delete books function calling of Pointers
       		}
       		else if (choice == 5)
       		{
       			updateBookPointers();       //Update books function calling of Pointers
        	}
        	//Exiting from program.
        	else if (choice == 6)
        	{
            	exit(0);                    //exit function to direct exit from code.
        	}
        	//If entered number is not between 1 to 6
        	else
        	{
            	cout << "\nWrong Input";
        	}
    	} while (choice != 6);
   	}
    	
    else
		cout<<"Wrong Input.";
    
    return 0;    //Return value
}
//addbookArray function defnition
void addBooksArray()
{
    ofstream FileArray;      //Declaration of fileArrays
    FileArray.open("AddArray.txt");        //Open AddArray text file to write data on it.
	//Asking the number of books to be add   
    cout << "\nHow many books do you want to add? : ";
    cin >> num;
    FileArray << "How many books do you want to add? : " << num;

    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter information of Book: " << i + 1 << endl;
        FileArray << "\n\nEnter information of Book: " << i + 1 << endl;
        //Taking input the name, price, publisher, author and quantity of book from user
        cout << "\nEnter Book Title: ";     
        cin.ignore();
        getline(cin, booktitleArray[addedBooks]);
		
		cout << "Enter Book Price: ";
        cin >> bookpriceArray[addedBooks];
                      
        cout << "Enter Publisher Name: ";
        cin.ignore();
        getline(cin, bookpublisherArray[addedBooks]);

        cout << "Enter Author Name: ";
        getline(cin, bookauthorArray[addedBooks]);
        
        cout << "Enter Book Quantitiy: ";
        cin >> bookquantityArray[addedBooks];
        //Storing data in file array                
        FileArray << "\nEnter Book Title: " << booktitleArray[addedBooks];
        FileArray << "\nEnter Book Price: " << bookpriceArray[addedBooks];
        FileArray << "\nEnter Publisher Name: " << bookpublisherArray[addedBooks];
        FileArray << "\nEnter Author Name: " << bookauthorArray[addedBooks];
        FileArray << "\nEnter Book Quantity: " << bookquantityArray[addedBooks];

        addedBooks++;       //Represents the index of array
    }
    FileArray.close();      //closing file
}
//Definition of displayBooksArray
void displayBooksArray()
{
	ofstream FileArray;       //Declaration of fileArrays
	FileArray.open("AddArray.txt", ios::app);   //Opening AddArray text file to append data to it
	
    if (addedBooks == 0)    //Checking that is there are any books are not
    {
        cout << "\nBook Shop is empty. Add some books to display.\n\n";
        FileArray << "\n\nBook Shop is empty. Add some books to display.\n\n";
    }
    else
    {
    	cout << "\nDisplaying Books.\n";
    	FileArray << "\n\nDisplaying Books.";
    	//Used for loop to display all books
        for (int i = 0; i < addedBooks; i++)
        {
            cout << "\nBook " << i + 1 << " information: \n";
            cout << "\nBook Title: " << booktitleArray[i] << endl;
            cout << "Book Price: "<< bookpriceArray[i] <<endl;
            cout << "Publisher: "<<bookpublisherArray[i] <<endl;
            cout << "Author: " << bookauthorArray[i] << endl;
            cout << "Book Quantity: " << bookquantityArray[i] << endl;
            //Storing all data in file
            FileArray <<"\n\nBook " << i+1 << " information: " ;
			FileArray << "\n\nBook Title: " <<booktitleArray[i] << "\nBook Price: "<< bookpriceArray[i] << "\nPublisher: "<<bookpublisherArray[i] 
			          << "\nAuthor: " <<bookauthorArray[i] << "\nBook Quantity: "<<bookquantityArray[i] ;  
        }
    }
    FileArray.close();      //Closing of File
}
//Defintion of SearchBookArray 
void searchBookArray()
{
	ofstream FileArray;     
	FileArray.open("AddArray.txt", ios::app);      //Opening AddArray text file to append data to it.
	
    if (addedBooks == 0)        //Checking that is there are any books are not.
    {
        cout << "\nNo Books stored to search for! Please Add some books first\n\n";
        FileArray << "\n\nNo Books stored to search for! Please Add some books first\n\n";
    }
    else
    {   //Used do while loop to because we want to search for book at least once
        do
        {
            cout << "\nEnter the name of book you want to search for: ";
            cin >>searchName;
            FileArray << "\n\nEnter Name of book you want to search for: "<<searchName;
            //Used for loop to check name of book from array index
            for (int i = 0; i < addedBooks; i++)
            {
                if (booktitleArray[i] == searchName)    //Condition
                {
                    cout << "\nHere is the book information with Name: " << searchName << endl;
                    cout << "\nBook Title: " << booktitleArray[i] << endl;
                    cout << "Book Price: "<< bookpriceArray[i] <<endl;
                    cout << "Publisher: " << bookpublisherArray[i] << endl;
                    cout << "Author: " << bookauthorArray[i] << endl;
                    cout << "Book Quantity: " << bookquantityArray[i] << endl;
                    //Writing data in file
                    FileArray <<"\n\nHere is the book information with Name: "<<searchName;
					FileArray <<"\n\nBook Title: "<<booktitleArray[i]<< "\nBook Price: "<< bookpriceArray[i] << "\n Publisher: " << bookpublisherArray[i] 
                              << "\nAuthor: " << bookauthorArray[i] <<"\nBook Quantity: "<<bookquantityArray[i] ;
                    
                    searchNameFound = true;    //Assinging true to searchNameFound
                }
            }    
            if (searchNameFound == false)   //If book not found
            {
                cout << "\nSearch Id not Found. Please Enter a valid search id";
                FileArray << "\n\nSearch Id not Found. Please Enter a valid search id";
            }
        } while (searchNameFound == false);    //Do condition
    }
    FileArray.close();     //Closing FileArray
}
//Definition of Delete book Array
void deleteBookArray()
{
	ofstream FileArray;
	FileArray.open("AddArray.txt", ios::app);       //Opening AddArray text file to append data to it.
	
    if (addedBooks == 0)     //Checking that is there are any books are not.
    {
        cout << "\nNo books to delete.";
        FileArray << "\n\nNo books to delete.";
    }
    else
    {   //Taking input the name of book to be deleted
        cout << "\nEnter Name of the book you want to delete: ";
        cin>> Delete;
        FileArray << "\n\nEnter Name of the book you want to delete: " << Delete;
		//Used for loop to check that entered book name is correct or not. It is checking from array index. 
        for (int i = 0; i < addedBooks; i++)
        {
            if (booktitleArray[i] == Delete)
            {
                for (int j = i; j < addedBooks; j++)
                {
                    booktitleArray[i] = booktitleArray[i + 1];
                    bookpriceArray[i] = bookpriceArray[i + 1];
                    bookpublisherArray[i] = bookpublisherArray[i + 1];
                    bookauthorArray[i] = bookauthorArray[i + 1];
                    bookquantityArray[i] = bookquantityArray[i + 1];
                }
                cout << "\nBook with Name " << Delete << " has been deleted successfully";
                FileArray << "\n\nBook with Name " << Delete << " has been deleted successfully";
               
			    addedBooks--;  //Decrement the index with one as one book is deleted successfuly.    
            }
        }
    }
    FileArray.close();    //Closing of File
}
//Definition of UpdateBookArray 
void updateBookArray()
{
	ofstream FileArray;
	FileArray.open("AddArray.txt", ios::app);      //Opening AddArray text file to append data to it.
	
    if (addedBooks == 0)      //Checking that is there are any books are not.
    {
    	cout << "\nNo Books to Update! Add some books.\n\n";
        FileArray << "\n\nNo Books to Update! Add some books.\n\n";
    }
    else
    {   //Taking input name of book you want to update 
        cout << "\nEnter Name of the book you want to update: ";
        cin >> updateName;
        FileArray <<"\n\nEnter Name of the book you want to update: "<<updateName;
		//Used for loop to check that entered book name is correct or not. It is checking from array index.
        for (int i = 0; i < addedBooks; i++)
        {
            if (booktitleArray[i] == updateName)
            {   //Showing current information of book.
                cout << "\nHere is the book information you want to update:\n";
                cout << "\nBook Title: " << booktitleArray[i] << endl;
                cout << "Book Quantity: " << bookquantityArray[i] << endl;
                cout << "Book Price: "<< bookpriceArray[i] << endl;
                cout << "Publisher: " << bookpublisherArray[i] << endl;
                cout << "Author: " << bookauthorArray[i] << endl;
                cout << "Book Quantity: " << bookquantityArray[i] <<endl;
                //Storing data in file
                FileArray << "\n\nHere is the book information you want to update:\n";
                FileArray << "\nBook Title: " << booktitleArray[i] << endl;
                FileArray << "Book Price: "<< bookpriceArray[i] << endl ;
                FileArray << "Publisher: " << bookpublisherArray[i] << endl;
                FileArray << "Author: " << bookauthorArray[i] << endl;
                FileArray << "Book Quantity: " << bookquantityArray[i] << endl;
                
				//Asking from user that what information he wants to update
                cout << "\nWhat Information you want to update?\n";
                cout << "\n1. BookTitle";
                cout << "\n2. Book Price ";
                cout << "\n3. Publisher ";
                cout << "\n4. Author";
                cout << "\n5. Book Quantity";
                cout << "\nEnter your choice: ";
                cin >> updateChoice;
                
                FileArray << "\nWhat Information you want to update?\n";
                FileArray << "\n1. Book Title \n2. Book Price \n3. Publisher \n4. Author \n5. Book Quantity ";
                FileArray << "\nEnter your choice: "<<updateChoice;
                
                //Used switch statement to check that the user wants to update what information
                switch (updateChoice)
                {
                case 1:
                    cout << "\nEnter New Title: ";
                    cin.ignore();
                    getline(cin, booktitleArray[i]);
                    FileArray <<"\n\nEnter New Title: "<<booktitleArray[i];
                    break;
                    
                case 2: 
				    cout << "\nEnter New Price: ";
                	cin.ignore();
                	cin>>bookpriceArray[i];
                	FileArray <<"\n\nEnter New Price: "<<bookpriceArray[i];
                	break;
                	
                case 3:
                	cout << "\nEnter New Publisher Name: ";
                    cin.ignore();
                    getline(cin, bookpublisherArray[i]);
                    FileArray <<"\n\nEnter New Publisher Name: "<<bookpublisherArray[i];
                    break;
                
		        case 4:
                    cout << "\nEnter Updated Author Name: ";
                    cin.ignore();
                    getline(cin, bookauthorArray[i]);
                    FileArray <<"\n\nEnter Updated Author Name: "<<bookauthorArray[i];
                    break;

                case 5:                    
					cout << "\nEnter New Quantity: ";
					cin.ignore();
					cin>>bookquantityArray[i];
					FileArray <<"\n\nEnter New Quantity: "<<bookquantityArray[i];
					break;    
                
                default:      //If entered number is not correct.
                    cout << "\nInvalid Input";
                    FileArray << "\n\nInvalid Input";
                    break;
                }
            }
        }
    }
    FileArray.close();    // Closing of FileArray
}

//Pointers function definitions

void addBooksPointers()
{
    ofstream FilePointers;      //Declaration of FilePointers
    FilePointers.open("AddPointers.txt");    //Open AddPointers text File to write data to it.
	//Asking from user that how many boooks he wants to add.
    cout << "\nHow many books do you want to add? : ";
    cin >> num;
    FilePointers << "\nHow many books do you want to add? : " << num;
	//Used for loop to add all books 
    for (int i = 0; i < num; i++)
    {
        cout << "\nEnter information of Book: " << i + 1 << endl;

		//Taking input name, price, publisher, author and quantity from user for all books
        cout << "\nEnter Book Title: ";
        cin.ignore();
        
        string *tempTitle = new string;
        getline(cin, *tempTitle);
        booktitlePointers[addedBooks] = tempTitle;
              
        int *tempPrice = new int;
        cout << "Enter Book Price: ";
        cin >> *tempPrice;
        bookpricePointers[addedBooks] = tempPrice;

        cin.ignore();

        string* tempPublisher = new string;
        cout << "Enter Publisher Name: ";
        getline(cin, *tempPublisher);
        bookpublisherPointers[addedBooks] = tempPublisher;

        string* tempAuthor = new string;
        cout << "Enter Author Name: ";
        getline(cin, *tempAuthor);
        bookauthorPointers[addedBooks] = tempAuthor;
        
        int *tempQuantity = new int;
        cout << "Enter Book Quantity: ";
        cin >> *tempQuantity;
        bookquantityPointers[addedBooks] = tempQuantity;
		//Storing data in file.
        FilePointers << "\n\nEnter information of Book: " << i + 1;
        FilePointers << "\n\nEnter Book Title: " << *booktitlePointers[addedBooks];
        FilePointers << "\nEnter Book Price: " << *bookpricePointers[addedBooks];
        FilePointers << "\nEnter Publisher Name: " << *bookpublisherPointers[addedBooks];
        FilePointers << "\nEnter Author Name: " << *bookauthorPointers[addedBooks];        
        FilePointers << "\nEnter Book Quantity: " << *bookquantityPointers[addedBooks];

        addedBooks++;      //Represents Pointers Array index
    }
    FilePointers.close();   //Closing of filePointers
}
//Definition of Display Function.
void displayBooksPointers()
{
    ofstream FilePointers;      //Declaration of FilePointers.
    FilePointers.open("AddPointers.txt", ios::app);     //Opening AddPointers text file to apend data to it.
    
    cout << "\nDisplaying Avaliabe Books\n";
    FilePointers << "\nDisplaying Avaliabe Books\n";

    if (addedBooks == 0)    //Checking that there are books or not in bookshop.
    {
        cout << "\nBook Shop is empty. Add some books to display.\n\n";
        FilePointers << "\n\nBook Shop is empty. Add some books to display.\n\n";
    }
    else      //If it is not empty then else will be executed.
    {    //Using loop to Display all books.
        for (int i = 0; i < addedBooks; i++)
        {
            cout << "\nBook " << i + 1 << " information: \n";
            cout << "\nBook Title: " << *booktitlePointers[i] << endl;
            cout << "Book Price: " << *bookpricePointers[i] << endl;
            cout << "Publisher: " << *bookpublisherPointers[i] << endl;
            cout << "Author: " << *bookauthorPointers[i] << endl;
            cout << "Book Quantity: " << *bookquantityPointers[i] << endl;
            //Storing all data in File2.
            FilePointers << "\n\nBook " << i + 1 << " information: ";
			FilePointers <<"\n\nBook Title: " << *booktitlePointers[i] << "\nBook Price: "<< *bookpricePointers[i]<<"\nPublisher: "<<*bookpublisherPointers[i] 
						 << "\nAuthor: " << *bookauthorPointers[i] << "\nBook Quantity: " << *bookquantityPointers[i];
        }
    }
    FilePointers.close();     //Closing of File2.
}
//Definition of SearchBookPointers 
void searchBookPointers()
{
    ofstream FilePointers;      //Declaration of FilePointers.
    FilePointers.open("AddPointers.txt", ios::app);   //Opening of AddPointers text file to append data to it.
    
    if (addedBooks == 0)      //Checking that is there are any books or not.
    {
        cout << "\nNo Books stored to search for! Please Add some books first";
        FilePointers << "\n\nNo Books stored to search for! Please Add some books first";
    }
    else
    {   //Input name of book you want to delete 
		cout << "\nEnter Name of book you want to search for: ";
		cin.ignore();
        getline(cin, searchName);
        FilePointers << "\n\nEnter Name of book you want to search for: " << searchName;   
		//Using of Do while loop as it must execute at least once & we want to search for book atleast once.
        do
        {
            //Used for loop to show result of search book using index of Pointer array
            for (int i = 0; i < addedBooks; i++)
            {
                if (*booktitlePointers[i] == searchName)
                {	//Displaying Book Information
                    cout << "\nHere is the book information with Name: " << searchName << endl;
                    cout << "\nBook Title: " << *booktitlePointers[i] << endl;
                    cout << "Book Price: " << *bookpricePointers[i] << endl;
                    cout << "Publisher: " << *bookpublisherPointers[i] << endl;
                    cout << "Author: " << *bookauthorPointers[i] << endl;
                    cout << "Book Quantity: " << *bookquantityPointers[i] << endl;
					//Storing data in FilePointers
                    FilePointers << "\n\nHere is the book information with Name: " << searchName;
					FilePointers<<"\n\nBook Title: "<<*booktitlePointers[i]<<"\nBook Price: "<<*bookpricePointers[i]<<"\nPublisher: "<<*bookpublisherPointers[i] 
					             << "\nAuthor: " << *bookauthorPointers[i] << "\nBook Quantity: " << *bookquantityPointers[i] << "\n\n";

                    searchNameFound = true;
                }
        	}
        } while (searchNameFound == false);    //Condition of do-while loop
    }
    FilePointers.close();   //Close filePointers.
}
//Definition of delete books Pointers function. 
void deleteBookPointers()
{
    ofstream FilePointers;   
    FilePointers.open("AddPointers.txt", ios::app);     //Opening AddPointers text file to append data to it.
    
    if (addedBooks == 0)    //Checking that there are books or not in bookshop.
    {
        cout << "\nNo books to delete.";
        FilePointers << "\n\nNo books to delete.";
    }
    else
    {	//Input name of Book you want to delete
        cout << "\nEnter Name of the book you want to delete: ";
        cin >> Delete;
        cout << endl;
        FilePointers << "\n\nEnter Name of the book you want to delete: " << Delete;
		//Used for loop to check that entered book name is correct or not. It is checking from array index. 
        for (int i = 0; i < addedBooks; i++)
        {
            if (*booktitlePointers[i] == Delete)
            {
                for (int j = i; j < addedBooks; j++)
                {
                    booktitlePointers[i] = booktitlePointers[i + 1];
                    bookpricePointers[i] = bookpricePointers[i + 1];
                    bookpublisherPointers[i] = bookpublisherPointers[i + 1];
                    bookauthorPointers[i] = bookauthorPointers[i + 1];
                    bookquantityPointers[i] = bookquantityPointers[i + 1];
                }
                cout << "\nBook with Name " << Delete << " has been deleted successfully";
                FilePointers << "\n\nBook with Name " << Delete << " has been deleted successfully";
                
                addedBooks--;      //Decrement the index with one as one book is deleted successfuly.
            }
        }
    }
    FilePointers.close();    //Closing FilePointers.
}
//definition of updatebookPointers function.
void updateBookPointers()
{
    ofstream FilePointers;       
    FilePointers.open("AddPointers.txt", ios::app);    //Opening AddPointers text file to append data to it.
    if (addedBooks == 0)       //Checking that there are books or not in bookshop.
    {
        cout << "\nNo Books to Update! Add some books.";
        FilePointers << "\n\nNo Books to Update! Add some books.";
    }
    else
    {
        cout << "\nEnter Name of the book you want to update: ";
        cin >> updateName;
        FilePointers << "\n\nEnter Name of the book you want to update: " << updateName;

        for (int i = 0; i < addedBooks; i++)
        {
            if (*booktitlePointers[i] == updateName)
            {
            	//Showing the current information of book
                cout << "\nHere is the book information you want to update:\n";
                cout << "\nBook Title: " << *booktitlePointers[i] << endl;
                cout << "Book Price: " << *bookpricePointers[i] << endl;
                cout << "Publisher: " << *bookpublisherPointers[i] << endl;
                cout << "Author: " << *bookauthorPointers[i] << endl;
                cout << "Book Quantity: " << *bookquantityPointers[i] << endl;
                //Storing the current information of book.
                FilePointers << "\n\nHere is the book information you want to update:\n";
                FilePointers << "\nBook Title: " << *booktitlePointers[i] << endl;
                FilePointers << "Book Price: " << *bookpricePointers[i] << endl;
                FilePointers << "Publisher: " << *bookpublisherPointers[i] << endl;
                FilePointers << "Author: " << *bookauthorPointers[i] << endl;
                FilePointers << "Book Quantity: " << *bookquantityPointers[i] << endl;
                //Information to be updated Menu
                cout << "\nWhat Information you want to update?\n";
                cout << "\n1. BookTitle";
                cout << "\n2. Book Price ";
                cout << "\n3. Publisher ";
                cout << "\n4. Author";
                cout << "\n5. Book Quantity";
                cout << "\nEnter your choice: ";
                cin >> updateChoice;
                //Information to be updated menu
                FilePointers << "\nWhat Information you want to update?\n";
                FilePointers << "\n1. Book Title \n2. Book Price \n3. Publisher \n4. Author \n5. Book Quantity ";
                FilePointers << "\nEnter your choice: " << updateChoice;
             
			    //Using Switch statement for updating specific information of one book
                switch (updateChoice)
                {
                case 1:
                    cout << "\nEnter New Title: ";
                    cin.ignore();
                    getline(cin, *booktitlePointers[i]);
                    FilePointers<<"\n\nEnter New Title: "<<*booktitlePointers[i];
                    break;

                case 2: 
				    cout << "\nEnter New Price: ";
                	cin.ignore();
                	cin>>*bookpricePointers[i];
                	FilePointers <<"\n\nEnter New Price: "<<*bookpricePointers[i];
                	break;
                	
                case 3:
                	cout << "\nEnter New Publisher Name: ";
                    cin.ignore();
                    getline(cin, *bookpublisherPointers[i]);
                    FilePointers <<"\n\nEnter New Publisher Name: "<<*bookpublisherPointers[i];
                    break;
                
		        case 4:
                    cout << "\nEnter Updated Author Name: ";
                    cin.ignore();
                    getline(cin, *bookauthorPointers[i]);
                    FilePointers <<"\n\nEnter Updated Author Name: "<<*bookauthorPointers[i];
                    break;

                case 5:                    
					cout << "\nEnter New Quantity: ";
					cin.ignore();
					cin>>*bookquantityPointers[i];
					FilePointers <<"\n\nEnter New Quantity: "<<*bookquantityPointers[i];
					break;  

                default:
                    cout << "\nInvalid Input";
                    FilePointers<<"\n\nInvalid Input. ";
                    break;
                }
            }
        }
    }
    FilePointers.close();    //Closing of FilePointers.
}


//Simple
void addBook() 
{
    ofstream File;      //Declaration of File
    File.open("Add.txt", ios::app);  // Open Add text File in append mode.
	
	//Taking information of book from User
    cout << "\nEnter information of Book\n";
    
    cout << "\nEnter Book Title: ";
    cin.ignore();
    getline(cin, booktitle);

    cout << "Enter Book Price: ";
    cin >> bookprice;

    cout << "Enter Publisher Name: ";
    cin.ignore();
    getline(cin, bookpublisher);

    cout << "Enter Author Name: ";
    getline(cin, bookauthor);

    cout << "Enter Book Quantity: ";
    cin >> bookquantity;
	//Storing Information of Book in File
	File << "\nEnter information of Book\n";
    File << "\nBook Title: " << booktitle << endl;
    File << "Book Price: " << bookprice << endl;
    File << "Publisher: " << bookpublisher << endl;
    File << "Author: " << bookauthor << endl;
    File << "Book Quantity: " << bookquantity << endl;

    File.close();   //Closing of File.
}
//Definition of displayBook Function
void displayBook() 
{
    ifstream File;      //Reading from File.
    File.open("Add.txt");    //Opening Add text File to read data.

    if (!File.is_open())    //In case if file is not opening
	{
        cout << "No Books stored to display. Add some books first\n\n";
    } 
	else 
	{
        cout << "\nDisplaying Book:\n";

        string line;      //Used to store each line of text read from the file.     
        //Used for getline function successfully reads a line from the file.
        while (getline(File, line)) 
		{
            cout << line << endl;     //Ddisplays each line from the file.
        }
    }

    File.close();     //Closing of File.

}
//Definition of SearchBook function
void searchBook() 
{
    ifstream File;          //Reading from File
    File.open("Add.txt");      //Opening Add text File to read data.

    if (!File.is_open())      //In case if file is not opening 
	{
        cout << "No Books stored to search for! Please add some books first\n\n";
    } 
	else 
	{
        string searchName;
        bool searchNameFound = false;
		//Input name of book you want to search
        cout << "\nEnter Name of the book you want to search for: ";
        cin.ignore();
        getline(cin, searchName);

        string line;        //Used to store each line of text read from the file.     
        //Used for getline function successfully reads a line from the file
        while (getline(File, line)) 
		{
            if (line.find(searchName) != string::npos)   //It checks whether the searchName is found in the current line. (!= string::npos means "not found")
			{
                cout << line << endl;       //Displays each line from the file.
                searchNameFound = true;
            }
        }

        if (!searchNameFound) //If searchNameFound not found then it will execute.
		{
            cout << "Search Name not Found. Please Enter a valid search Name\n\n";
        }
    }

    File.close();           //Closing of File.
}
//Definition of deleteBook function
void deleteBook() 
{
    ifstream inputFile;          // Declare ifstream for reading from File
    inputFile.open("Add.txt");    // Open "Add.txt" file for reading

    if (!inputFile.is_open())    // Check if the file is not open
    {
        cout << "\nNo books to delete.\n";
    } 
    else 
    {
        string deleteName;
        bool bookFound = false;

        cout << "\nEnter Name of the book you want to delete: ";
        cin.ignore();
        getline(cin, deleteName);

        ofstream tempFile;       // Declare ofstream for writing to a temporary file
        tempFile.open("Temp.txt");    // Open a temporary file for writing

        string line;
        while (getline(inputFile, line)) 
        {
            if (line.find(deleteName) != string::npos)    // Check if deleteName is found in the current line
            {
                cout << "Book with Name " << deleteName << " has been deleted successfully\n\n";
                bookFound = true;
            } 
            else 
            {
                tempFile << line << endl;   // Write the line to the temporary file
            }
        }

        if (!bookFound)    // If book not found
        {
            cout << "Book with Name " << deleteName << " not found.\n";
        }

        inputFile.close();    // Close the original file
        tempFile.close();     // Close the temporary file

        remove("Add.txt");            // Remove the original file
        rename("Temp.txt", "Add.txt");    // Rename the temporary file to the original file
    }
}
//Definition of updateBook function.
void updateBook() 
{
    ifstream inputFile;           // Declare ifstream for reading from File
    inputFile.open("Add.txt");   // Open "Add.txt" file for reading

    if (!inputFile.is_open())    // Check if the file is not open
    {
        cout << "No Books to Update! Add some books.\n\n";
    } 
    else 
    {
        string updateTitle;
        bool bookFound = false;

        cout << "\nEnter Name of the book you want to update: ";
        cin.ignore();
        getline(cin, updateTitle);

        ofstream tempFile;        // Declare ofstream for writing to a temporary file
        tempFile.open("Temp.txt");    // Open a temporary file for writing

        string line;
        while (getline(inputFile, line)) 
        {
            if (line.find(updateTitle) != string::npos)   // Check if updateTitle is found in the current line
            {
                cout << "\nHere is the book information you want to update:\n";
                cout << line << endl;

                bookFound = true;

                cout << "What Information you want to update?\n";
                cout << "\n1. Book Title";
                cout << "\n2. Book Price ";
                cout << "\n3. Publisher";
                cout << "\n4. Author";
                cout << "\n5. Book Quantity ";
                cout << "\nEnter your choice: ";
                int updateChoice;
                cin >> updateChoice;

                tempFile << line << endl;     // Write the existing line to the temporary file

                switch (updateChoice) 
                {
                    case 1:
                        cout << "\nEnter New Title: ";
                        cin.ignore();
                        getline(cin, booktitle);
                        tempFile << "Book Title: " << booktitle << endl;
                        break;

                    case 2:
                        cout << "\nEnter New Price: ";
                        cin >> bookprice;
                        tempFile << "Book Price: " << bookprice << endl;
                        break;

                    case 3:
                        cout << "\nEnter New Publisher Name: ";
                        cin.ignore();
                        getline(cin, bookpublisher);
                        tempFile << "Publisher: " << bookpublisher << endl;
                        break;

                    case 4:
                        cout << "\nEnter Updated Author Name: ";
                        getline(cin, bookauthor);
                        tempFile << "Author: " << bookauthor << endl;
                        break;

                    case 5:
                        cout << "\nEnter New Quantity: ";
                        cin >> bookquantity;
                        tempFile << "Book Quantity: " << bookquantity << endl;
                        break;

                    default:
                        cout << "\nInvalid Input";
                        tempFile << "\nInvalid Input";
                }
            } 
            else 
            {
                tempFile << line << endl;   // Write the existing line to the temporary file
            }
        }

        if (!bookFound)   // If book not found
        {
            cout << "Book with Name " << updateTitle << " not found.\n";
        }

        inputFile.close();   // Close the original file
        tempFile.close();    // Close the temporary file

        remove("Add.txt");       // Remove the original file
        rename("Temp.txt", "Add.txt");    // Rename the temporary file to the original file
    }
}
