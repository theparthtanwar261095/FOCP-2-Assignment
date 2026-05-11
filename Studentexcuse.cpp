#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter student name: ";
    getline(cin,name);
    srand(time(0));
    vector<string> excuses = {
        "{name} couldn't finish the assignment because the laptop updated for hours.",
        "{name} was about to complete the homework when the Wi-Fi disappeared.",
        "{name} tried finishing the assignment, but the keyboard stopped working.",
        "{name}'s file got corrupted right before submission.",
        "{name} accidentally deleted the assignment at the last moment.",
        "{name}'s system crashed unexpectedly while working.",
        "{name} lost all progress due to a sudden power cut.",
        "{name} forgot to save the assignment and the system restarted.",
        "{name}'s pet sat on the keyboard and messed everything up.",
        "{name} was locked out of the account and couldn't submit the assignment.",
        "{name} was not able to do is homework because {name} was out of town"
    };


    int randomIndex = rand() % excuses.size();

    string excuse = excuses[randomIndex];

    
    size_t pos = excuse.find("{name}");

    while (pos != string::npos) {
        excuse.replace(pos, 6, name);
        pos = excuse.find("{name}");
    }

    cout << "\nGenerated Excuse:\n";
    cout << excuse << endl;

    return 0;
}
