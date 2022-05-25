//
// Created by nstan on 24/05/2022.
//

#include "HighScoreManager.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

HighScoreManager::HighScoreManager() {
    fstream levelFile(SAVE_FILE, ios::in);
    string line, val;
    if (levelFile.is_open()) {
        while (getline(levelFile, line)) {
            stringstream str(line);
            auto* score = new ScoreRecord();
            int col = 0;
            while (getline(str, val, ',')) {
                if (col == 0) {
                    score->setName(val);
                    col++;
                } else if (col == 1) {
                    score->setScore(stoi(val));
                    col++;
                }
            }
            scores.push_back(score);
        }
    }
}
bool HighScoreManager::compareScore(ScoreRecord s1, ScoreRecord s2) {
    return (s1.getScore() > s2.getScore());
}

HighScoreManager::~HighScoreManager() {
    ofstream saveFile(SAVE_FILE);
    for (int i = 0; i < 5; i++) {
        ScoreRecord* scoreRecord = scores.at(i);
        saveFile << string(scoreRecord->getName() + "," + to_string(scoreRecord->getScore()) + "\n").c_str();
    }
    saveFile.close();
    for (auto score : scores) {
        delete score;
    }
}

const vector<ScoreRecord *> &HighScoreManager::getScores() const {
    return scores;
}

bool HighScoreManager::scoreIsCompetitive(long score) {
    for (auto scoreRecord : scores) {
        if (score > scoreRecord->getScore()) {
            return true;
        }
    }
    return false;
}

void HighScoreManager::addScore(ScoreRecord scoreRecord) {
    int posToInsert = -1;
    for (int i = 0; i < scores.size(); i++) {
        if (scores.at(i)->getScore() <= scoreRecord.getScore()) {
            posToInsert = i;
            break;
        }
    }
    if (posToInsert != -1) {
        scores.insert(scores.begin() + posToInsert, new ScoreRecord(scoreRecord));
    }
}




