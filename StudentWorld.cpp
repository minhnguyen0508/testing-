#include "StudentWorld.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
    return new StudentWorld(assetDir);
}

Actor* StudentWorld::get_Tunnelman() {
    return m_player;
}

void StudentWorld::update_stage_info() {
    int score = getScore();
    int level = getLevel();
    int live = getLives();
    int health = m_player->getHP();
    int water = 0; //temporary
    int gold = 0;
    int sonar = 0;

    string info = display_user_interface(score, level, live, health, water, gold, sonar, 0);
    setGameStatText(info);
}

string StudentWorld::display_user_interface(int score, int level, int lives, int health, int squirts, int gold, int sonar, int barrels) {
    stringstream s;

    s.fill('0');
    s << "Scr: ";
    s << setw(6) << score;

    s.fill(' ');
    s << " Lvl: ";
    s << setw(2) << level;

    s << " Lives: ";
    s << setw(1) << lives;

    s << "  Hlth: ";
    s << setw(3) << health * 10;
    s << '%';

    s << "  Wtr: ";
    s << setw(2) << squirts;

    s << "  Gld: ";
    s << setw(2) << gold;

    s << "  Sonar: ";
    s << setw(2) << sonar;

    s << "  Oil Left: ";
    s << setw(2) << barrels;

    return s.str();
}

int StudentWorld:: init(){
    m_player = new Tunnelman(this, 30, 60);
    m_actors.push_back(m_player);
    for (int x = 0; x < 64; x++) {
        for (int y = 0; y < 60; y++) {
            if (x < 30 || x>33 || y < 4)
                m_earth[x][y] = new Earth(this, x, y);
        }
    }
    return GWSTATUS_CONTINUE_GAME;
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
