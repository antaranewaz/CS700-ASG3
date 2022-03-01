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
            name = name;
            address = address;
            age = age;
            telephone_number = telephone_number;
            customer_number = customer_number;
        }

        // accessor and modifier for name
        string get_name() { return name; }
        void set_name(string name) { name = name; }
        
        // accessor and modifier for address
        string get_address() { return address; }
        void set_address(string address) { address = address; }

        // accessor and modifier for age
        int get_age() { return age; }
        void set_age(int age) { age = age; }

        // accessor and modifier for telephone number
        string get_telephone_number() { return telephone_number; }
        void set_telephone_number(string telephone_number) { telephone_number = telephone_number; }

        // accessor and modifier for customer number
        string get_customer_number() { return customer_number; }
        void set_customer_number(string customer_number) { customer_number = customer_number; }

};

// children classes of Customer
class Senior: public Customer {
    private:
        const float SAVINGS_INTEREST;
        const float CHECK_INTEREST;
        const float CHECK_CHARGE;
        const float OVERDRAFT_PENALTY;
};

class Adult: public Customer {
    private:
        const float SAVINGS_INTEREST;
        const float CHECK_INTEREST = 53.004f;
        const float CHECK_CHARGE;
        const float OVERDRAFT_PENALTY;
};

class Student: public Customer {
    private:
        const float SAVINGS_INTEREST;
        const float CHECK_INTEREST = 51.00f;
        const float CHECK_CHARGE = 0.02f;
        const float OVERDRAFT_PENALTY;
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
            account_number++;
            customer = new Customer(name, address, age, telephone_number, customer_number);
        }

        static int get_account_number() { return account_number; }

        float get_balance() { return balance; }

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

class Transaction {
    private:
        string transaction_type;
        float amount;
        float balance;
    
    public:
        void to_string() {} // printing function?
};

int main() {


    return 0;
}