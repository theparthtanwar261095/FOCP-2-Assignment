#include <iostream>
using namespace std;
class Bank {
private:
    int balance[1001];
    bool exists[1001];
public:
    Bank() {
        for (int i = 0; i <= 1000; i++) {
            balance[i] = 0;
            exists[i] = false;
        }
    }
    bool CREATE(int userId, int amount) {
        if (!exists[userId]) {
            exists[userId] = true;
            balance[userId] = amount;
            return true;
        } else {
            balance[userId] += amount;
            return false;
        }
    }
    bool DEBIT(int userId, int amount) {
        if (!exists[userId] || balance[userId] < amount) {
            return false;
        }
        balance[userId] -= amount;
        return true;
    }
    bool CREDIT(int userId, int amount) {
        if (!exists[userId]) {
            return false;
        }
        balance[userId] += amount;
        return true;
    }
    int BALANCE(int userId) {
        if (!exists[userId]) {
            return -1;
        }
        return balance[userId];
    }
};
int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;
    Bank bank;
    for (int i = 0; i < Q; i++) {
        int choice;
        cout << "\nChoose operation:\n";
        cout << "1. CREATE\n2. DEBIT\n3. CREDIT\n4. BALANCE\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int x, y;
            cout << "Enter User ID and Initial Balance: ";
            cin >> x >> y;

            if (bank.CREATE(x, y))
                cout << "Account created (true)" << endl;
            else
                cout << "User exists, amount added (false)" << endl;
        }
        else if (choice == 2) {
            int x, y;
            cout << "Enter User ID and Amount: ";
            cin >> x >> y;

            if (bank.DEBIT(x, y))
                cout << "Debit successful (true)" << endl;
            else
                cout << "Debit failed (false)" << endl;
        }
        else if (choice == 3) {
            int x, y;
            cout << "Enter User ID and Amount: ";
            cin >> x >> y;

            if (bank.CREDIT(x, y))
                cout << "Credit successful (true)" << endl;
            else
                cout << "Credit failed (false)" << endl;
        }
        else if (choice == 4) {
            int x;
            cout << "Enter User ID: ";
            cin >> x;

            int result = bank.BALANCE(x);
            if (result == -1)
                cout << "User not found (-1)" << endl;
            else
                cout << "Balance: " << result << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
