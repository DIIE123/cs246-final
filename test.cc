#include "minion.h"
#include <iostream>
using namespace std;

int main() {
    Minion minion = Minion{"Air Elemental"};
    cout << minion.getName() << " " << minion.getCost() << endl;
}