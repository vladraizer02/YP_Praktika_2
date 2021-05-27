#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
using namespace std;

string all_suit[4] = {"Пик", "Крести", "Черви", "Буби"};
string all_card[9] = {"Шесть", "Семь", "Восемь", "Девять","Десять","Валет", "Дама", "Король", "Туз"};

struct deck {
    string suit;
    string card;
};

void fill_deck(vector<deck>& deck_1)
{
    int k = 0;
    for (int i = 0; i<4; i++) {
        for (int j = 0; j<9; j++) {
            deck_1[k].suit = all_suit[i];
            deck_1[k].card = all_card[j];
            k+=1;
        }
    }
    cout << "Колода заполнена" << endl;
    cout << endl;
}

void shuffle_deck(vector<deck>& deck_1)
{
    static mt19937 rnd(clock());
    shuffle(deck_1.begin(), deck_1.end(), rnd);
    cout << "Колода перемешена" << endl;
    cout << endl;
}

void search_card_color(vector<deck>& deck_1)
{
    for (int i = 1; i<36; i++) {
        if ((deck_1[i].suit == deck_1[i-1].suit) or (deck_1[i].suit == "Пик" and deck_1[i-1].suit == "Крести") or (deck_1[i].suit == "Крести" and deck_1[i-1].suit == "Пик") or (deck_1[i].suit == "Черви" and deck_1[i-1].suit == "Буби") or (deck_1[i].suit == "Буби" and deck_1[i-1].suit == "Черви")) {
            cout << "Две карты одного цвета, лежащие рядом: " << endl;
            cout << deck_1[i-1].suit << ":" << deck_1[i-1].card << endl;
            cout << deck_1[i].suit << ":" << deck_1[i].card << endl;
            cout << endl;
        }

    }
}

void search_card_nominal(vector<deck>& deck_1)
{
    for (int i = 1; i<36; i++) {
        if ((deck_1[i].card == deck_1[i-1].card)) {
            cout << "Две карты одного номинала, лежащие рядом: " << endl;
            cout << deck_1[i-1].suit << ":" << deck_1[i-1].card << endl;
            cout << deck_1[i].suit << ":" << deck_1[i].card << endl;
            cout << endl;
        }

    }
}

void search_card_queen(vector<deck>& deck_1)
{
    for (int i = 0; i<36; i++) {
        if ((deck_1[i].card == "Дама") and (deck_1[i].suit == "Пик")) {
            cout << deck_1[i].suit << ":" << deck_1[i].card << " находится на " << i+1 << "-ом месте в колоде" << endl;
            cout << endl;
            break;
        }
    }
}

void search_card_ace(vector<deck>& deck_1)
{
    for (int i = 0; i<36; i++) {
        if (deck_1[i].card == "Туз") {
            cout << deck_1[i].suit << ":" << deck_1[i].card << " находится на " << i+1 << "-ом месте в колоде" << endl;
        }
    }
    cout << endl;
}

void print_deck(vector<deck>& deck_1)
{
    cout << "Печать всей колоды" << endl;
    for (int i = 0; i<36; i++) {
        cout << deck_1[i].suit << ":" << deck_1[i].card << endl;
    }
}

int main(int argc, char **argv)
{
    vector<deck> deck_1(36);
    fill_deck(deck_1);
    shuffle_deck(deck_1);
    search_card_color(deck_1);
    search_card_nominal(deck_1);
    search_card_queen(deck_1);
    search_card_ace(deck_1);
    print_deck(deck_1);
    return 0;
}
