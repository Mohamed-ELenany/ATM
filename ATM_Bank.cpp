#include <iostream>
#include <vector>
using namespace std;

class ATM;
class Account {
private:
    int ID;
    string name;
    double Balance;
    double Password;

public:
    Account(int ID, double password, string name) {
        this->ID = ID;
        this->Password = password;
        this->name = name;
        this->Balance = 0;
    }

    void setName(string n) { this->name = n; }
    string getName() { return name; }

    void setId(int i) { this->ID = i; }
    int getId() { return ID; }

    void setPassword(double p) { this->Password = p; }
    double getPassword() { return Password; }

    void setBalance(double b) { this->Balance = b; }
    double getBalance() { return Balance; }

    void display() {
        cout << "ID: " << ID << " | Name: " << name << " | Balance: " << Balance << endl;
    }

    void Deposit(double deposit) {
        this->Balance += deposit;
        cout << "The New Balance Is: " << Balance << endl;
    }

    void Withdraw(double withdraw) {
        if (withdraw > Balance)
            cout << "The Balance not Enough " << endl;
        else {
            this->Balance -= withdraw;
            cout << "The Balance Now Is: " << Balance << endl;
        }
    }

    friend class ATM;

    void menu() {
        double inputPass;
        cout << "Enter Your Password : ";
        cin >> inputPass;

        if (this->Password == inputPass) {
            int choice;
            do {
                cout << "\nFor Showing Balance Enter 1 : " << endl;
                cout << "For Deposition Enter 2 : " << endl;
                cout << "For Withdrawing Enter 3 : " << endl;
                cout << "For Exiting Enter 4 : " << endl;
                cin >> choice;

                double amount;
                switch (choice) {
                case 1:
                    cout << getBalance() << endl;
                    break;
                case 2:
                    cout << "Enter The Amount : " << endl;
                    cin >> amount;
                    Deposit(amount);
                    break;
                case 3:
                    cout << "Enter The Amount : " << endl;
                    cin >> amount;
                    Withdraw(amount);
                    break;
                case 4:
                    cout << "Thank you for using our ATM." << endl;
                    break;
                default:
                    cout << "Invalid Choice, Try Again." << endl;
                    break;
                }

                if (choice != 4) {
                    cout << "\nDo you want to perform another operation? (y/n): ";
                    char again;
                    cin >> again;
                    if (again == 'n' || again == 'N') {
                        choice = 4;
                    }
                }
            } while (choice != 4);
        } else {
            cout << "The Password Is Wrong" << endl;
        }
    }
};

class ATM {
private:
    vector<Account> accounts;

public:
    void addAccount(Account ob) { accounts.push_back(ob); }

    void deleteAccount(int id) {
        for (auto it = accounts.begin(); it != accounts.end(); it++) {
            if (it->getId() == id) {
                accounts.erase(it);
                cout << "Account Deleted " << endl;
                return;
            }
        }
        cout << "Account does not exist" << endl;
    }

    void findAccount(int id) {
        for (auto& acc : accounts) {
            if (acc.getId() == id) {
                acc.display();
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void showAccounts() {
        for (auto& acc : accounts) {
            acc.display();
        }
    }
};


int main() {
    
    Account acc1(101, 1234, "Mohamed");
    Account acc2(102, 5678, "Ali");
    
    ATM atm; 
    atm.addAccount(acc1);
    atm.addAccount(acc2);

    cout << "--- All Accounts ---"<<endl;
    atm.showAccounts();

    cout << "--- Find Account---"<<endl;
    atm.findAccount(101);

    cout << "--- Account Menu ---"<<endl;
    acc1.menu();

    return 0;
}

