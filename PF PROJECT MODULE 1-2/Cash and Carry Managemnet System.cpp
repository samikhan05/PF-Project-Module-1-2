#include <iostream> // Header File provide functionality for input and output operations,
#include <fstream> // Header File provide function necessary for working with files.
#include <string> // Header File provide functionality to work with string.
#include <sstream> // Header File used for string stream operation and allow to treat strings as streams, enabling operations like extraction and insertion. 

const int MAX_TRANSACTIONS = 100; // Global Variable and constant to define the maximum number of transaction.
const int ATTRIBUTES = 5;//  Global Variable and constants to define the number of attributes.

// Function declarations
void viewmenu();
void productmenu();
void transactionmenu();
void exitProgram();

//Entity Product Related Function.
void addproducts();
void viewproducts();
void searchproducts();
void updateproducts();
void deleteproducts();

// Entity Transaction Related Function.
void addTransactions(int** transactions, int& num_transactions);
void viewTransactions(int** transactions, int& num_transactions);
void searchTransactions(int** transactions, int& num_transactions);
void updateTransactions(int** transactions, int& num_transactions);
void deleteTransactions(int** transactions, int& num_transactions);

// Common Functions For FIle Operation.
void readFile(int** transactions, int& num_transactions);
void writeFile(int** transactions, int& num_transactions);
bool is_product_ID_Exists(int);


int main()
{
    // Infinite loop for the menu
    while (true)
    {
        viewmenu(); // Call the main menu function
        std::cout << "\n"; // To move the menu to next line on the console.
    }
    return 0;
}

void viewmenu() {
    // Variable to store the user's menu option
    int option;
    // Prompting the user to enter a menu option.
    std::cout << "-------------------------------------\n";
    std::cout << " Cash and Carry Management System \n";
    std::cout << "-------------------------------------\n";
    std::cout << " 1. Product\n" << " 2. Transaction\n" << " 3. Exit\n";
    std::cout << "\n Option : ";
    std::cin >> option;

    // Use a switch statement to perform actions based on the user's choice
    switch (option) 
    {
    case 1:
        productmenu(); // Redirect to Product menu
        break;

    case 2:
        transactionmenu(); // Redirect to Transaction menu
        break;

    case 3:
        exitProgram(); // Calling the function to exit from the program.
        break;

    default:
        std::cout << "Invalid Option. Please try again." << std::endl;
        break;
    }
}

// Function to Display Menu On the screen for Product Entity.
void productmenu()
{
    while (true)
    {
        // Prompting the user to enter a menu option for Product entity.
        std::cout << "\n-------------------------------------\n";
        std::cout << " Product Management \n";
        std::cout << "-------------------------------------\n";
        std::cout << " 1. Add Product\n" << " 2. View Products\n" << " 3. Search Product\n" << " 4. Update Product\n" << " 5. Delete Product\n" << " 6. Back to Main Menu\n";
        std::cout << "\n Option : ";

        int option;
        std::cin >> option;

        // Use a switch statement to perform actions based on the user's choice in the Product menu
        switch (option) {
        case 1:
            addproducts(); // calling adding product function.
            break;

        case 2:
            viewproducts(); // calling viewing product function.
            break;

        case 3:
            searchproducts(); // calling searching product function.
            break;

        case 4:
            updateproducts(); // calling updating product function.
            break;

        case 5:
            deleteproducts(); // calling deleting product function.
            break;

        case 6:
            return; // Return to the main menu

        default:
            std::cout << "Invalid Option. Please try again." << std::endl;
            break;
        }
    }
}

void transactionmenu() 
{
    int** transactions; // Declaring a pointer for a 2D Array of Interger type.
    int num_transactions = 0; // Initializing the variable to keep track of the current number of transaction.

    transactions = new int* [MAX_TRANSACTIONS]; // Allocating memory for 'MAX_TRANSACTIONS' rows, where each row represents a transaction.
    
    // Loop through each row and allocate memory for 'ATTRIBUTES' columns in each row
    for (int i = 0; i < MAX_TRANSACTIONS; i++)
    {
        transactions[i] = new int[ATTRIBUTES];
    }

    // Read transactions from the file before attempting to view them.
    readFile(transactions, num_transactions);

    // Infinite loop for the transaction menu
    while (true) {
        // Prompting the user to enter a menu option for Transaction entity.
        std::cout << "\n-------------------------------------\n";
        std::cout << " Transaction Management \n";
        std::cout << "-------------------------------------\n";
        std::cout << " 1. Add Transaction\n" << " 2. View Transactions\n" << " 3. Search Transaction\n" << " 4. Update Transaction\n" << " 5. Delete Transaction\n" << " 6. Back to Main Menu\n";
        std::cout << "\n Option : ";

        int option;
        std::cin >> option;

        // Use a switch statement to perform actions based on the user's choice in the Transaction menu
        switch (option) {
        case 1:
            addTransactions(transactions, num_transactions); // calling adding transaction function.
            break;

        case 2:
            viewTransactions(transactions, num_transactions); // calling viewing transaction function.
            break;

        case 3:
            searchTransactions(transactions, num_transactions); // calling searching transaction function.
            break;

        case 4:
            updateTransactions(transactions, num_transactions); // calling updating transaction function.
            break;

        case 5:
            deleteTransactions(transactions, num_transactions); // calling deleting transaction function.
            break;

        case 6:
            return; // Return to the main menu

        default:
            std::cout << "Invalid Option. Please try again." << std::endl;
            break;
        }
    }
}

// Function To exit From The system
void exitProgram()
{
    std::cout << " Goodbye!. Have a Nice Day..." << std::endl;
    exit(0);
}

// ==================== Part No 2 ====================
// Function to read Transcation data from file and populating 2D Array.
void readFile(int** transactions, int& num_transactions) // TRANSACTONS (A pointer to a 2D array where transaction data will be stored.) NUM_TRANSACTIONS (A reference to an integer to keep track of the number of transactions read.)
{
   // Opening the file for reading.
    std::ifstream file("transaction.txt");
  
    // check if the file is successfully opened.
    if (file.is_open())
    {
        std::string line; // declaring string variable
        
        // Read each line from the Table.
        while (getline(file, line))
        {
            std::istringstream ss(line); // Creating an input string stream named 'ss' and initialize it with the contents of the 'line' string.
           
            // Extract transaction attributes from the line and store them in the 2D array.
            for (int i = 0; i < ATTRIBUTES; i++)
            {
                ss >> transactions[num_transactions][i];
            }
            num_transactions++; // increment the count of transactions.
        }
        // Closing the file after reading all the data.
        file.close();
    }
    else
    {
        // Print an error message to the standard error stream if the file cannot be opened.
        std::cerr << " Error opening file for reading.\n";
    }
}

// Function to Write Transaction Data From a 2D array to a File.
void writeFile(int** transactions, int& num_transactions)
{
    // Opening the file for writing.
    std::ofstream file("transaction.txt");
   
    // Check if the file is successfully opened.
    if (file.is_open())
    {
        // Iterate through each transaction.
        for (int i = 0; i < num_transactions; i++)
        {
            // Iterate through each attribute of the transaction and writing it to the file.
            for (int j = 0; j < ATTRIBUTES; j++)
            {
                file << transactions[i][j] << " ";
            }
            // Adding a newline character to separate each transaction in the file.
            file << std::endl;
        }
        // Cloding the file after writing all data.
        file.close();
    }
    else
    {
        // Print an error message to the standard error stream if the file cannot be opened.
        std::cerr << " Error in Opening file for writing.\n";
    }
}

// Function to add new transactions to the 2D array and write them to a file.
void addTransactions(int** transactions, int& num_transactions)
{
    // Variable to store the user's choice (yes or no) for adding more transactions.
    char addMore;

    do
    {
        // Check if the maximum number of transactions has not been reached.
        if (num_transactions < MAX_TRANSACTIONS)
        {
            // Prompt the user to enter details for the new transaction.
            std::cout << " Enter (1) Transaction ID , (2) Product ID , (3) Quantity Sold , (4) Unit Price , (5) Total Price :\n";

            // Iterate through each attribute and receive input from the user, storing it in the 2D array.
            for (int i = 0; i < ATTRIBUTES; i++)
            {
                std::cout << " " << i + 1 << " : ";
                std::cin >> transactions[num_transactions][i];
            }

            // Increment the count of transactions.
            num_transactions++;

            // Write the transaction details to the file.
            writeFile(transactions, num_transactions);

            // Display a success message.
            std::cout << " Transaction Added Successfully.\n";
        }
        else
        {
            // Display an error message if the maximum number is reached.
            std::cout << " Maximum Number of Transactions Reached. Kindly Update the number to move on.\n";
            break; // Exit the loop if the maximum number is reached.
        }

        // Ask the user if they want to add more transactions.
        std::cout << " Do you want to add another transaction? (y/n): ";
        std::cin >> addMore;

    } while (addMore == 'y' || addMore == 'Y');
}


// Function to display the details of transactions stored in a 2D array.
void viewTransactions(int** transactions, int& num_transactions)
{
    // Checking if there are transactions to display.
    if (num_transactions > 0)
    {
        // Displaying a header for the transactions section.
        std::cout << "-------------\n";
        std::cout << " Transcation \n";
        std::cout << "-------------\n";
        std::cout << "Transaction ID\tProduct ID\tQuantity Sold\tUnit Price\tTotal \n";

        // Iterate through each transaction and display its attributes.
        for (int i = 0; i < num_transactions; i++)
        {
            for (int j = 0; j < ATTRIBUTES; j++)
            {
                std::cout << transactions[i][j] << " \t \t ";
            }
            // Move to the next line after displaying all attributes of a transaction.
            std::cout << std::endl;
        }
    }
    else
    {
        // Display a message indicating that no transactions are available.
        std::cout << " No Transaction Available.\n";
    }
}

// Function to search for a transaction by Transaction ID in a 2D array.
void searchTransactions(int** transactions, int& num_transactions)
{
    // Variable to store the user's choice (yes or no) for adding more transactions.
    char searchMore;
    do
    {
        // Read transactions from the file before attempting to view them.
        readFile(transactions, num_transactions);

        // Declaring a int type variable for storing Transactin ID to be searched.
        int search_ID;
        std::cout << " Enter The Transaction ID to search : ";
        std::cin >> search_ID;

        //flag to indicate whether the transaction is found or not.
        bool found = false;

        // Iterate through each transaction in the array.
        for (int i = 0; i < num_transactions; i++)
        {
            // Checking if the current transaction's Transaction ID matches the searched ID.
            if (transactions[i][0] == search_ID)
            {
                // Displaying a message that the transaction is found.
                std::cout << "Transaction Found.\n";

                std::cout << "Transaction ID\tProduct ID\tQuantity Sold\tUnit Price\tTotal \n";
                // Displaying the attributes of the found transaction.
                for (int j = 0; j < ATTRIBUTES; j++)
                {
                    std::cout << transactions[i][j] << " \t \t ";
                }
                // Moving to the New line.
                std::cout << std::endl;

                found = true;
                break;
            }
        }
        // Displaying a message indicating that the transaction is not found.
        if (!found)
        {
            std::cout << " Transaction Not Found.\n";
        }

        // Ask the user if they want to continue searching.
        std::cout << "Do you want to search again? (y/n): ";
        std::cin >> searchMore;
    } while (searchMore == 'y' || searchMore == 'Y');
}

// Function to update a transaction in a 2D array by Transaction ID.
void updateTransactions(int** transactions, int& num_transactions)
{
    // Declaring a variable to store the transaction ID to be updated.
    int update_ID;
    std::cout << " Enter the Transaction ID To Update : ";
    std::cin >> update_ID;

    // Iterate through each transaction in the array.
    for (int i = 0; i < num_transactions; i++)
    {
        // Checking if the current transaction's Transaction ID matches the ID to be updated.
        if (transactions[i][0] == update_ID)
        {
            // Prompting the user to enter new values.
            std::cout << " Enter the Updated values for (1) Transaction ID, (2) Product ID, (3) Quantity Sold, (4) Unit Price, (5) Total Amount:\n";
           
            // Iterate through each attribute and update the values in the array.
            for (int j = 0; j < ATTRIBUTES; j++)
            {
                std::cout << " " << j + 1 << " ";
                std::cin >> transactions[i][j];
            }
           
            // Writing the updated transactions to the file.
            writeFile(transactions, num_transactions);
            
            // Displaying a Success message.
            std::cout << " Transaction Updated Successfully.\n";
            
            // Exit the function as the transaction is updated.
            return;
        }
    }
    // Displaying a message indicating that the transaction is not found for updating.
    std::cout << " Transaction Not Found.\n";
}

// Function to delete a transaction in a 2D array by Transaction ID.
void deleteTransactions(int** transactions, int& num_transactions)
{
    // Declaring a variable to store the Transaction ID to be deleted
    int delete_ID;
    std::cout << " Enter the Transaction ID against which you want to delete the record : ";
    std::cin >> delete_ID;

    // Iterate through each transaction in the array
    for (int i = 0; i < num_transactions; i++)
    {
        // Checking if the Current Transaction matches with the Delete_id.
        if (transactions[i][0] == delete_ID)
        {
            // Shifting all transactions after the one to be deleted to fill the gap.
            for (int j = i; j < num_transactions - 1; j++)
            {
                for (int k = 0; k < ATTRIBUTES; k++)
                {
                    transactions[j][k] = transactions[j + 1][k];
                }
            }

            // Decrement the count of transactions after the deletion.
            num_transactions--;
           
            writeFile(transactions, num_transactions);

            // Writing the updated Transaction to the file.
            std::cout << " Transaction Deleted Successfully.\n";

            // Exit the function as the transaction is deleted.
            return;
        }
    }
    // Display a message indicating that the transaction is not found for deletion.
    std::cout << " Transaction Not Found.\n";
}

// ==================== Part No 1 ====================
// Function For Deleting the Record From the Inventory
void deleteproducts()
{
    // Declaring an Input File Stream
    std::ifstream fin;
    fin.open("Cash and Carry Management.txt"); // Opening the file for reading

    // Exceptional handling : Checking if the file fails to open.
    try
    {
        if (fin.fail())
        {
            throw std::runtime_error("File Not Found!!!");
        }
    }
    catch (std::runtime_error& e)
    {
        // Declaring an Error Message if the file is not found.
        std::cout << "Exceptional Handling: " << e.what() << std::endl;
        return;
    }

    // Declare variables for reading from the file
    int delete_id, product_id, quantity, price;
    std::string product_name;
    bool recordExists = false; // Flag to track whether the record with the specified ID exists in the file or Inventory.

    // Prompting the user to Enter the ID against which the record to be deleted
    std::cout << "Enter the ID you want to delete: ";
    std::cin >> delete_id;

    // Opening an output file stream to create an updated file
    std::ofstream deletefile;
    deletefile.open("Updated Recorded Of Cash and Carry Management System.txt");

    // Loop For reading data from the file.
    while (fin >> product_id >> product_name >> quantity >> price)
    {
        // Check if the current line's product_id matches with the ID to be deleted.
        if (product_id == delete_id)
        {
            recordExists = true; // Setting the flag true, which indicates that the record with the specified ID exists

            // Display information about the found record
            std::cout << "Record Found with ID " << product_id << "\n"<< "Name: " << product_name << "\n"<< "Price: " << price << "\n"<< "Quantity: " << quantity << "\n";
        }
        else
        {
            // Write the current line to the updated file if the product_id doesn't match the ID to delete
            deletefile << product_id << " " << product_name << " " << quantity << " " << price << std::endl;
        }
    }

    // Check if a record with the specified ID was found
    if (!recordExists)
    {
        std::cout << "Record with ID " << delete_id << " does not exist." << std::endl;
    }
    else
    {
        std::cout << "Record with ID " << delete_id << " has been deleted." << std::endl;
    }

    // Close the input and output files
    fin.close();
    deletefile.close();

    // Remove the original file and rename the updated file
    remove("Cash and Carry Management.txt");
    rename("Updated Recorded Of Cash and Carry Management System.txt", "Cash and Carry Management.txt");
}

// Function For Updating the Record in the Inventory
void updateproducts()
{
    // Declaring input and output file streams
    std::ifstream inputFile;
    inputFile.open("Cash and Carry Management.txt"); // Opening File for reading.
    std::ofstream outputFile;
    outputFile.open("Updated Cash and Carry Management.txt"); // Opening file for writing.

    // Declaring variables to store data from the file and for input from the user.
    int update_id, product_id, quantity, price, update_quantity, update_price, option;
    std::string product_name;
    bool recordExists = false; // Flag to track whether the record with the specified ID exists in the file or Inventory.

    // Prompting the user to enter the ID against which they want to update the record.
    std::cout << "Enter the ID Against which you want to update the record of Entity: ";
    std::cin >> update_id;

    // Reading data from the input file and processing each line.
    while (inputFile >> product_id >> product_name >> quantity >> price)
    {
        // Check if the current line's product_id matches with the ID Against which the user wants to update the record.
        if (product_id == update_id)
        {
            recordExists = true; // Setting the flag true, which indicates that the record with the specified ID exists

            // Displaying Information about the Found Record.
            std::cout << "Record Found with ID " << product_id << "\n"<< "Name: " << product_name << "\n"<< "Quantity: " << quantity << "\n"<< "Price: " << price << "\n";

            // Prompting the user to choose what to update.
            std::cout << "What do you want to Update \n" << "1. Quantity \n" << "2. Price \n" << "Option : ";
            std::cin >> option;

            // Using a switch statement to handle the user's choice.
            switch (option)
            {
            case 1:
                // Updating the quantity and writing the updated record in the output file.
                std::cout << "Enter the New Quantity of the Product: ";
                std::cin >> update_quantity;
                outputFile << product_id << " " << product_name << " " << update_quantity << " " << price << std::endl;
                break;

            case 2:
                // Updating the price and writing the updated record in the output file.
                std::cout << "Enter the New Price of the Product: ";
                std::cin >> update_price;
                outputFile << product_id << " " << product_name << " " << quantity << " " << update_price << std::endl;
                break;

            default:
                // Display An Error Message for an Invalid Option.
                std::cout << "Invalid Option.";
                break;
            }

            // Displaying a success message after updating the record.
            std::cout << "Record Updated Successfully!!!" << std::endl;
        }
        else
        {
            // If the current line's product_id doesn't match the update_id, write the line to the output file unchanged.
            outputFile << product_id << " " << product_name << " " << quantity << " " << price << std::endl;
        }
    }

    // If no record with the specified ID was found, then display a message
    if (!recordExists)
    {
        std::cout << "Record with ID " << update_id << " does not exist." << std::endl;
    }

    // Closing Input and Output Files.
    inputFile.close();
    outputFile.close();

    // Remove the original file and rename the updated file
    remove("Cash and Carry Management.txt");
    rename("Updated Cash and Carry Management.txt", "Cash and Carry Management.txt");
}

// Function to View the Products from the Inventory
void searchproducts()
{
    // Declaring an Input File Stream
    std::ifstream fin;
    fin.open("Cash and Carry Management.txt"); // Opening the file for Reading

    // Exceptional handling : Checking if the file fails to open.
    try
    {
        if (fin.fail())
        {
            throw std::runtime_error(" File Not Found!!!");
        }
    }
    catch (std::runtime_error& e)
    {
        // Declaring an Error Message if the file is not found.
        std::cout << " Exceptional Handling : " << e.what() << std::endl;
    }

    // Declaring the variables for storing the details of the product.
    int product_id, product_id_in_file, quantity, price;
    std::string product_name;
    bool found = false;

    // Prompting the user to enter the ID of the product which needs to be searched in the inventory
    std::cout << " Enter the ID You Want To Search : ";
    std::cin >> product_id;

    // Loop to read the data from the file and to find the product with the specified ID.
    while (fin >> product_id_in_file >> product_name >> quantity >> price)
    {
        if (product_id_in_file == product_id)
        {
            found = true;
            break;
        }

        // Declaring a std::string variable to Read the rest of the line before moving the file pointer to the next line
        std::string line;
        getline(fin, line);
    }

    // Displaying the search result.
    if (found == true)
    {
        std::cout << " " << "Product : " << product_name << " with " << product_id << " ID exists in the STOCK." << std::endl<< " Quantity : " << quantity << std::endl<< " Price : " << price << std::endl;
    }
    else
        std::cout << " " << product_id << " ID does not exist in the STOCK." << std::endl;

    // Closing the file after searching.
    fin.close();
}

// Function to View the Products from the Inventory
void viewproducts()
{
    // Declaring an Input File Stream
    std::ifstream fin;
    fin.open("Cash and Carry Management.txt"); // Opening the file for Reading

    // Exceptional handling : Checking if the file fails to open.
    try
    {
        if (fin.fail())
        {
            throw std::runtime_error(" File Not Found!!!");
        }
    }
    catch (std::runtime_error& e)
    {
        // Declaring an Error Message if the file is not found.
        std::cout << " Exceptional Handling : " << e.what() << std::endl;
    }

    // Declaring the variables for storing the details of the product.
    int product_id, quantity, price;
    std::string product_name;

    // Display header for the Product Details
    std::cout << " Product ID \t Product Name \t Quantity \t Price \n";

    // Read the Details of the product from the file and Display them on the Screen.
    while (fin >> product_id >> product_name >> quantity >> price)
    {
        std::cout << "   " << product_id << "\t"<< "\t  " << product_name << "\t"<< "\t  " << quantity << "\t"<< "\t  " << price << std::endl;
    }

    // Closing the file after reading it.
    fin.close();
}

// Function to Add Products to the Inventory
void addproducts()
{
    // Declaring variables for storing product details
    int product_id, quantity, price;
    std::string product_name;

    std::ofstream fout; // Declaring an output File Stream.
    fout.open("Cash and Carry Management.txt", std::ios::app); // Opening the file in the append mode to add new products

    // Prompting the User to Enter the Details of the Product.
    std::cout << " Enter Product Id : ";
    std::cin >> product_id;

    if (is_product_ID_Exists(product_id))
    {
        std::cout << "\n Product ID already exists. Please enter a different ID.\n";
        return; // Exit the function if ID already exists
    }

    std::cout << " Enter the Product Name : ";
    std::cin >> product_name;
    std::cout << " Enter the Quantity Of Product You have : ";
    std::cin >> quantity;
    std::cout << " Enter the Price of the Product : ";
    std::cin >> price;
    std::cout << "\n Product Added in the Inventory Successfully";

    // Write the Product Details in the File.
    fout << product_id << " " << product_name << " " << quantity << " " << price << std::endl;

    // Closing the File.
    fout.close();
}

// Function to check if a product ID already Exist or not.
bool is_product_ID_Exists(int product_id)
{
    std::ifstream fin("Cash and Carry Management.txt");// opening the file to read.
    int existing_Product_ID;    // Declaring variables for storing product ID
    std::string line;

    while (fin >> existing_Product_ID)
    {
        // Skip other fields in the record...
        getline(fin, line);

        // Checking if the current ID matches with the ID entered
        if (existing_Product_ID == product_id)
        {
            fin.close();
            return true;// Returning that ID already exists.
        }
    }

    fin.close();
    return false; // Returning that ID does not exists.
}