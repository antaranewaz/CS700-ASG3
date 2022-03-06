#include <iostream>
#include <string>

using namespace std;

// parent class - Customer
class Customer {
    private:
        string name;
        string address;
        int age;
        string telephone_number;
        string customer_number;
    
    public:
        // constructor
        Customer(string name, string address, int age, string telephone_number, string customer_number)
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
        string get_telephone_number() { return this->telephone_number; }
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
        void create_account(string name, string address, int age, string telephone_number, string customer_number) {
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

};

class Checking_Account: public Account {

};



class Bank {
    private:
        Account accounts[10];
    
    public:
        void add_account() {}

        void make_deposit() {}

        void make_withdrawal() {}

        void get_account() {}
};


int main() {


    return 0;
}