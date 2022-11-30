#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include "GraphObject.h"
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp
class Actor;
class GraphObject;
class Earth;
class Tunnelman;

class StudentWorld : public GameWorld
{
public:

    StudentWorld(std::string assetDir): GameWorld(assetDir), m_player (nullptr) {}

    ~StudentWorld(){
        cleanUp();
    }

    Actor* get_Tunnelman();
    

    void update_stage_info();

    string display_user_interface(int score, int level, int lives, int health, int squirts, int gold, int sonar, int barrels);

    virtual int init();

    virtual int move()
    {
        // This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
        // Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
        update_stage_info();
        vector<Actor*>::iterator itr = m_actors.begin();
        while(itr != m_actors.end())
        {
            (*itr)->doSomething();
            ++itr;
        }

        return GWSTATUS_CONTINUE_GAME;
    }
    
    virtual void cleanUp()
    {
        for (int x = 0; x < 64; x++){
            for (int y = 0; y < 60; y++){
                delete m_earth[x][y];
            }
        }
    }
    

private:
    Earth* m_earth[64][64];
    Actor* m_player;
    std::vector<Actor*> m_actors;
};

#endif // STUDENTWORLD_H_
