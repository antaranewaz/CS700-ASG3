#include <iostream>
#include <string>

using namespace std;

// parent class - Customer
class Customer {
    private:
        string name;
        string address;
        int age;
        int telephone_number;
        string customer_number;
    
    public:
        // constructor
        Customer(string name, string address, int age, int telephone_number, string customer_number)
        {
            this->name = name;
            this->address = address;
            this->age = age;
            this->telephone_number = telephone_number;
            this->customer_number = customer_number;
        }

        // accessor and modifier for name
        string get_name() { return this->name; }
        void set_name(string name) { name = name; }
        
        // accessor and modifier for address
        string get_address() { return this->address; }
        void set_address(string address) { address = address; }

        // accessor and modifier for age
        int get_age() { return this->age; }
        void set_age(int age) { age = age; }

        // accessor and modifier for telephone number
        int get_telephone_number() { return this->telephone_number; }
        void set_telephone_number(string telephone_number) { telephone_number = telephone_number; }

        // accessor and modifier for customer number
        string get_customer_number() { return this->customer_number; }
        void set_customer_number(string customer_number) { customer_number = customer_number; }

};

// children classes of Customer
class Senior: public Customer {
    private:
        const float SAVINGS_INTEREST = 0.20f; // regular monthly percentage
        const float CHECK_INTEREST = 0.10f; // regular monthly percentage
        const float CHECK_CHARGE = 3.95f; // regular monthly fee
        const float OVERDRAFT_PENALTY = 15.00f; // on each transaction
};

class Adult: public Customer {
    private:
        const float SAVINGS_INTEREST = 0.10f; // regular monthly percentage
        const float CHECK_INTEREST = 0.05f; // regular monthly percentage
        const float CHECK_CHARGE = 2.95f; // regular monthly fee
        const float OVERDRAFT_PENALTY = 10.00f; // on each transaction
};

class Student: public Customer {
    private:
        const float SAVINGS_INTEREST = 0.02f; // regular monthly percentage
        const float CHECK_INTEREST = 0.00f; // regular monthly percentage
        const float CHECK_CHARGE = 0.00f; // regular monthly fee
        const float OVERDRAFT_PENALTY = 5.00f; // on each transaction
};


class Transaction {
    private:
        string transaction_type;
        float amount;
        float balance;
    
    public:
        void to_string() {} // printing function?
};

// parent class - Account
class Account {
    private:
        Customer* customer;
        float balance;
        static int account_number;
        Transaction transactions[10];
    
    public:
        void create_account(string name, string address, int age, int telephone_number, string customer_number) {
            this->account_number++;
            customer = new Customer(name, address, age, telephone_number, customer_number);
        }

        static int get_account_number() { return account_number; }

        float get_balance() { return this->balance; }

        void get_customer() {}

        void set_customer() {}

        void set_balance(float balance) { balance = balance; }

        void to_string() {} // printing function?
};

// children classes of Account
class Savings_Account: public Account {
    public:
        void deposit() {}

        void withdraw() {}

        void add_interest() {}
};

class Checking_Account: public Account {
    public:
        void deposit() {}

        void withdraw() {}

        void add_interest() {}
};



class Bank {
    private:
        Account accounts[10];

    private:
        string customer_number_generator(string customer_type) {
            static int counter = 0;
            counter++;
            string customer_number = to_string(counter) + customer_type; 
            return customer_number;
        }
    
    public:
        void add_account() { 
            string name;
            string address;
            int age;
            int phone_number;

            cout << "Enter Customer Name> ";
            cin >> name;

            cout << "Enter Customer Address> ";
            cin >> address;

            cout << "Enter Customer Age> ";
            cin >> age;

            cout << "Enter Customer Phone Number> ";
            cin >> phone_number;
            
            int customer_type;
            string customer_number;

            cout << "Select:" << endl;
            cout << "0: Senior" << endl;
            cout << "1: Adult" << endl;
            cout << "2: Student" << endl;
            cin >> customer_type;

            if (customer_type == 0) {
                customer_number = customer_number_generator("SEN");
            } else if (customer_type == 1) {
                customer_number = customer_number_generator("ADU");
            } else if (customer_type == 2) {
                customer_number = customer_number_generator("STU");
            }

            Account a;

            a.create_account(name, address, age, phone_number, "1");
        }

        void make_deposit() { cout << "make_deposit()" << endl; }

        void make_withdrawal() { cout << "make_withdrawal()" << endl; }

        void get_account() { cout << "check_account()" << endl; }
};

void program_loop() {
    Bank b;
    int i;

    while (i != 4) {
        cout << "Select:" << endl;
        cout << "0: Add Account" << endl;
        cout << "1: Make Deposit" << endl;
        cout << "2. Make Withdrawal:" << endl;
        cout << "3. Check Account:" << endl;
        cout << "4. Exit" << endl;
        
        cin >> i;

        if (i == 0) {
            b.add_account();
        } else if (i == 1) {
            b.make_deposit();
        } else if (i == 2) {
            b.make_withdrawal();
        } else if (i == 3) {
            b.get_account();
        }
    }
}

// driver class
int main() {
    program_loop();

    return 0;
}