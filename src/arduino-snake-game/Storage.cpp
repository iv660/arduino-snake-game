#include <EEPROM.h>
#include <string.h>
#include "const.h"
#include "Storage.h"
#include "HighScores.h"

Storage::Storage()
{
    if (hasStoredState()) {
        load();
    } else {
        init();
    }
}

void Storage::storeHighScores(HighScores highScores)
{
    for (unsigned int index = 0; index < MAX_HIGH_SCORES; index++) {
        HighScoreState highScoreState;
        HighScore highScore = highScores.get(index + 1);
        
        strcpy(highScoreState.name, highScore.getName());
        highScoreState.score = highScore.getScore();

        persistentState.highScores[index] = highScoreState;
    }

    store();
}

HighScores Storage::getHighScores()
{
    HighScores highScores;

    for (unsigned int index = 0; index < MAX_HIGH_SCORES; index++) {
        highScores.setHighScore(index + 1, persistentState.highScores[index].score);
    }

    return highScores;
}

bool Storage::hasStoredState()
{
    if (EEPROM.read(STORAGE_KEY_ADDRESS) == STORAGE_KEY) {
        return true;
    }

    return false;
}

void Storage::load()
{
    EEPROM.get(STORAGE_ADDRESS, persistentState);
}

void Storage::init()
{
    persistentState = PersistentState();
}

void Storage::store()
{
    EEPROM.put(STORAGE_ADDRESS, persistentState);
    EEPROM.write(STORAGE_KEY_ADDRESS, STORAGE_KEY);
}
