#include <iostream>
#include "engine/Game.h"

using namespace std;

int main() {
    cout << "starting game..." << endl;
    Game g;
    g.run();
    cout << "game has exited. " << endl;
    return 0;
}
