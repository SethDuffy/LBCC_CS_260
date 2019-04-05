#include <iostream>

using namespace std;

class marble {

    private:

    int amount = 0;
    char id;

    public:

    marble() {
        id = '0';
    }
    marble(char ID) {
        id = ID;
    }

    void setId(char ID) {
        id = ID;
        return;
    }

    void setAmount(int val) {
        amount += val;
    }

    char getId() {
        return id;
    }

    int getAmount() {
        return amount;
    }

};

int main(void) {
    string input;


    // Colors By Index
    // 0 = red
    // 1 = blue
    // 2 = green
    // 3 = orange
    // 4 = yellow
    // 5 = purple
    // 6 = brown
    // 7 = magenta
    char ids[] = {'r', 'b', 'g', 'o', 'y', 'p', 'b', 'm'};
    marble bag[8];

    for(int i = 0; i < 8; i++) {
        bag[i].setId(ids[i]);
    }

    cout << "marble count by color\n";

    for(int i = 0; i < 8; i++) {
        cout << bag[i].getId() << ": " << bag[i].getAmount() << "\n";
    }

    // bool done = false;

    // do {
    //     cout << "What color marble would you like to add\n"
    //          << "(r)ed\n(b)lue\n(g)reen\n(o)range\n(y)ellow\n(p)urple\nbrow(n)\n(m)agenta\nPlease enter the letter(s) denoted by parentheses";
    //     cin >> input;
    //     try {
            

    //     }
    //     catch() {

    //     }
    // } while(!done);
    return 0;

}