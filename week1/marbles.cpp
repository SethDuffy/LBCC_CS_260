#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;


// number of marble colors
#define MARBLES 8


// marble class
class marble{
    // defines the amount of marbles, the color of the marble, and function
    // to keep the amount of marbles in check privately
    private:

    int amount = 0;
    string id;
    int topCap = 100, botCap = 0;

    void clamp() {
        if(amount > topCap){
            amount = topCap;
        }
        else if(amount < botCap){
            amount = botCap;
        }
        return;
    }


    public:
    //marble constuctors
    marble() {

    }

    marble(string colorId){
        id = colorId; 
    }
    //used for changing the color of a marble
    void setId(string ID) {
        id = ID;
        return;
    }
    //changes amount of marbles then clamps the amount to be within the bags bounds
    void setAmount(int val) {
        amount += val;
        clamp();
        return;
    }

    string getId() {
        return id;
    }

    int getAmount() {
        return amount;
    }
    //check if the first two letters of the id match the input
    bool match(string check) {
        return check.compare(id.substr(0, 2)) ? false : true;
    }

    //old cap function didnt work porperly
    // bool cap(int i) {
    //     return (amount + i < 101) || (amount + i > -1);
    // }


};

int main(void) {
    // Colors By Index
    // 0 = red
    // 1 = blue
    // 2 = green
    // 3 = orange
    // 4 = yellow
    // 5 = purple
    // 6 = brown
    // 7 = magenta
    string input;
    string colors[] = {"red", "blue", "green", "orange", "yellow", "purple", "brown", "magenta"};

    marble bag[MARBLES];

    // assigns all ids to array
    for(int i = 0; i < MARBLES; i++){
        bag[i].setId(colors[i]);
    }

    bool done = false;
    //main loop
    while(!done) {
        bool goodInput[2] = {false , false};

        int colorIndex = 0, amount = 0;
        //checks marble color validity
        while(!goodInput[0]){
            cout << "What color marble would you like to add\n"
                << "(re)d\n(bl)ue\n(gr)een\n(or)ange\n(ye)llow\n(pu)rple\n(br)own\n(ma)genta\n"
                << "Please enter the letters denoted by parentheses in lower case"
                << endl;

            cin >> input;
            for(int i = 0; i < MARBLES; i++){
                if(bag[i].match(input)){
                    goodInput[0] = true;
                    colorIndex = i;

                    //debugging test
                    //cout << "colorindex= " << colorIndex << endl;
                }
            }
        }
        //checks marble input validity... no stoi error checking though
        while(!goodInput[1]){

            cout << "How many " << bag[colorIndex].getId() << " marble(s) do you want to add?\n"
                 << "for subtracting, enter a negative number" << endl;
            
            cin >> input;
            amount = stoi(input);
            if((amount < 101 && amount > -101)) {
                goodInput[1] = true;
            }
            else { 
                cout << "Please enter a number between -100 and 100" << endl;
            }
        }
        //sets the desired marble to the desired value
        bag[colorIndex].setAmount(amount);


        cout << "You added " << amount << " " << bag[colorIndex].getId() << " marbles!" << endl;

        for(int i = 0; i < MARBLES; i++){
            cout << bag[i].getId() << "= " << bag[i].getAmount() << endl;
        }

        cout << "Would you like to add/remove other marbles?\n(y/n)" << endl;
        cin >> input;
        if(input[0] == 'n' || input[0] == 'N'){
            done = true;
        }
    };
    return 0;

}