#include <iostream>
using namespace std;
class MovieTicket {
private:
    int bookings[1001][1001];
    int available[1001];
public:
    MovieTicket() {
        for (int i = 0; i <= 1000; i++) {
            available[i] = 100;
            for (int j = 0; j <= 1000; j++) {
                bookings[i][j] = 0;
            }
        }
    }
    bool BOOK(int userId, int movieId) {
        if (bookings[userId][movieId] == 1 || available[movieId] == 0) {
            return false;
        }
        bookings[userId][movieId] = 1;
        available[movieId]--;
        return true;
    }
    bool CANCEL(int userId, int movieId) {
        if (bookings[userId][movieId] == 0) {
            return false;
        }
        bookings[userId][movieId] = 0;
        available[movieId]++;
        return true;
    }
    bool IS_BOOKED(int userId, int movieId) {
        return bookings[userId][movieId] == 1;
    }
    int AVAILABLE_TICKETS(int movieId) {
        return available[movieId];
    }
};
int main() {
    int Q;
    cout << "Enter number of queries: ";
    cin >> Q;
    MovieTicket mt;
    for (int i = 0; i < Q; i++) {
        string command;
        cout << "\nEnter query (BOOK/CANCEL/IS_BOOKED/AVAILABLE_TICKETS): ";
        cin >> command;

        if (command == "BOOK") {
            int x, y;
            cout << "Enter User ID and Movie ID: ";
            cin >> x >> y;

            if (mt.BOOK(x, y))
                cout << "Booking successful (true)" << endl;
            else
                cout << "Booking failed (false)" << endl;
        }
        else if (command == "CANCEL") {
            int x, y;
            cout << "Enter User ID and Movie ID: ";
            cin >> x >> y;

            if (mt.CANCEL(x, y))
                cout << "Cancellation successful (true)" << endl;
            else
                cout << "Cancellation failed (false)" << endl;
        }
        else if (command == "IS_BOOKED") {
            int x, y;
            cout << "Enter User ID and Movie ID: ";
            cin >> x >> y;

            if (mt.IS_BOOKED(x, y))
                cout << "Ticket is booked (true)" << endl;
            else
                cout << "Ticket is not booked (false)" << endl;
        }
        else if (command == "AVAILABLE_TICKETS") {
            int y;
            cout << "Enter Movie ID: ";
            cin >> y;

            cout << "Available tickets: " << mt.AVAILABLE_TICKETS(y) << endl;
        }
        else {
            cout << "Invalid command!" << endl;
        }
    }
    return 0;
}
