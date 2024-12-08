#if !defined(STORAGE_H)
#define STORAGE_H

#include "PersistentState.h"
#include "HighScores.h"

class Storage {
    private:
        static const unsigned int STORAGE_ADDRESS = 0;
        static const unsigned int STORAGE_KEY_ADDRESS = STORAGE_ADDRESS + sizeof(PersistentState);
        static const unsigned int STORAGE_KEY = 53;

        PersistentState persistentState;

        bool hasStoredState();
        void load();
        void init();
        void store();
    public:
        Storage();
        void storeHighScores(HighScores highScores);
        HighScores getHighScores();
    };

#endif // STORAGE_H
