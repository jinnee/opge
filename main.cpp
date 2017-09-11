#include "include/Game.h"
#include "gsrc/FifteenGame.h"

int main(int argc, char *argv[])
{
    Game * mg = new FifteenGame();
    mg->start(500,500);
    delete mg;
    return 0;
}
