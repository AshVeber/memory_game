#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <random>
#include <sstream>
#include <string>

using namespace std;

void printSlow( const string& text) {
    for(char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << endl;
}

int main() {
    printSlow("Hello!");
    printSlow("Welcome to memory game!");
    char ans;

    while(true) {
        printSlow("Ready?");
        this_thread::sleep_for(chrono::seconds(1));
        printSlow("Y/N");
        cin >> ans;

        if(ans == 'Y' || ans == 'y') {
            this_thread::sleep_for(chrono::seconds(1));
            break;
        }else
        if(ans == 'n' || ans == 'N') {
            printSlow("Bye-e!");
            return 0;
        }
        else {
            printSlow("Oops! Try again");
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    vector<int> c = {1, 2, 3};
    cout << c[0];
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\r" << " " << "\r";
    cout << c[1];
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\r" << " " << "\r";
    cout << c[2];
    this_thread::sleep_for(chrono::seconds(1));
    cout << "\r" << " ";
    cout << "\n";
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 10);

    vector<int> nums = {dist(gen), dist(gen), dist(gen)};
    cin.ignore();

    int score = 0;

    while(true) {
        printSlow("Remeber this for 3 sec!");
        
        this_thread::sleep_for(chrono::seconds(1));
        for(int num : nums) {
            cout << num << " ";
        }
        this_thread::sleep_for(chrono::seconds(3));
        cout << "\r";
        printSlow("       ");

        vector<int> input;
        string line;

        cout << ">> ";
        
        getline(cin, line);

        stringstream ss(line);
        int r;

        while(ss >> r) {
            input.push_back(r);
        }

        
        if(input.size() == nums.size() && equal(input.begin(), input.end(), nums.begin())) {
            printSlow("Yay!");
            nums.push_back(dist(gen));
            score += 1;
        }else {
            printSlow("U are wrong :(");
            this_thread::sleep_for(chrono::seconds(1));
            cout << "Ur score: " << score;
            break;
        }
            
    }
    
    return 0;
}
