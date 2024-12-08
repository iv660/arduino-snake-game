#if !defined(HIGH_SCORE_H)
#define HIGH_SCORE_H


class HighScore
{
    private:
        char name[6];
        unsigned long score;
    public:
        HighScore();
        HighScore(const char* name, unsigned long score);
        const char* getName() const;
        unsigned long getScore() const;
};

#endif // HIGH_SCORE_H
