
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

enum class RequestType
{
        ZERO_BALANCE = 1,
        CREDIT_BALANCE,
        DEBIT_BALANCE,
        END
};

RequestType getRequest();
bool shouldDisplay(RequestType, double);
void outputline(int, const string &, double);

int main()
{
        
    // This is the ios::out, to which is just going to show what was input/don't save the 
    //previous datd in the file
       ifstream inClientFile{"Clients.txt", ios::out};


        // exit program if ifstream could not open file
        if (!inClientFile)
        {
                cerr << "File could not be opened" << endl;
                exit(EXIT_FAILURE);
        }

        // get user's request (e.g., zero, credit, or debit balance)
        RequestType request{getRequest()};

        // process user's request
        while (request != RequestType::END)
        {
                switch (request)
                {
                case RequestType::ZERO_BALANCE:
                        cout << "\nAccounts with zero balances: \n";
                        break;

                case RequestType::CREDIT_BALANCE:
                        cout << "\nAccounts with credit balances: \n";
                        break;

                case RequestType::DEBIT_BALANCE:
                        cout << "\nAccounts with debit balances: \n";
                        break;

                case RequestType::END:
                        break;
                }

                int account;    // the account number
                string name;    // the account owner's name
                double balance; // the account balance

                // read account, name, and balance from file
                inClientFile >> account >> name >> balance;

                // display file contents (until eof)
                while (!inClientFile.eof())
                {
                        // display record
                        if (shouldDisplay(request, balance))
                        {
                                outputline(account, name, balance);
                        }

                        // read account, name, and balance from file
                        inClientFile >> account >> name >> balance;
                }

                inClientFile.clear();   // reset eof for next input
                inClientFile.seekg(0);  // reposition to the beginning of the file
                request = getRequest(); // get an additional request from the user
        }

        cout << "End of run. " << endl;
}
RequestType getRequest()
{ // obtain request from the user
        // display request options
        cout << "\nEnter request\n"
             << " 1 - List accounts with zero balances\n"
             << " 2 - List accounts with credit balances\n"
             << " 3 - List accounts with debit balances\n"
             << " 4 - End of run " << fixed << showpoint;

        int type; // request from the user
        do
        { // input user request
                cout << "\n? ";
                cin >> type;
        } while (type < static_cast<int>(RequestType::ZERO_BALANCE) || type > static_cast<int>(RequestType::END));
        return static_cast<RequestType>(type);
}

// determine whether to display the given record
bool shouldDisplay(RequestType type, double balance)
{
        // determine whether to display zero balances
        if (type == RequestType::ZERO_BALANCE && balance == 0)
        {
                return true;
        }
        // determine whether to display credit balances
        if (type == RequestType::CREDIT_BALANCE && balance < 0)
        {
                return true;
        }
        // determine whether to display debit balances
        if (type == RequestType::DEBIT_BALANCE && balance > 0)
        {
                return true;
        }
        return false;
}

// display a single record from the file
void outputline(int account, const string &name, double balance)
{
        cout << left << setw(10) << account << setw(13) << name
             << setw(7) << setprecision(2) << right << balance << endl;
}
