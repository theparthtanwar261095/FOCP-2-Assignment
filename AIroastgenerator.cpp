#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    string name;

    cout << "Enter your name: ";
    getline(cin,name);  

    if (name.empty()) {
    cout << "Error: Name cannot be empty!" << endl;
    return 0;
    }

    else{
    srand(time(0)); 
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would win gold.",
        "{name}'s debugging style is staring until the bug leaves.",
        "{name}'s code runs so slow that dial-up feels fast.",
        "If laziness had a face, it would be {name}.",
        "{name} doesnt debug code — they negotiate with bugs.",
        "{name}'s logic is like WiFi — sometimes connected, mostly not.",
        "{name} writes comments like they are writing a novel.",
        "{name} spends more time choosing fonts than coding.",
        "{name}'s code has more errors than a failed exam.",
        "{name} is so tall that even Burj Khalifa compares itself with {name}" 

    };


    int index = rand() % roasts.size();
    string roast = roasts[index];


    size_t pos = roast.find("{name}");

    while (pos != string::npos) {
        roast.replace(pos, 6, name);
        pos = roast.find("{name}");
    }

    cout << "\n Roast:\n" << roast << endl;

    return 0;
}
    }
