//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_HIGHSCOREMANAGER_H
#define OOP_S1_2022_MAJOR_PRAC_HIGHSCOREMANAGER_H

#include <string>
#include <vector>
#include "ScoreRecord.h"

using namespace std;

const string SAVE_FILE = "../res/save.csv";

class HighScoreManager {
protected:
    vector<ScoreRecord*> scores;
    static bool compareScore(ScoreRecord s1, ScoreRecord s2);
public:
    const vector<ScoreRecord *> &getScores() const;
    bool scoreIsCompetitive(long score);
    void addScore(ScoreRecord scoreRecord);
    virtual ~HighScoreManager();

public:
    HighScoreManager();


};


#endif //OOP_S1_2022_MAJOR_PRAC_HIGHSCOREMANAGER_H
