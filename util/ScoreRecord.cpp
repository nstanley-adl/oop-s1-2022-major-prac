//
// Created by nstan on 24/05/2022.
//

#include "ScoreRecord.h"

ScoreRecord::ScoreRecord() : score(0), name("") {}

const int &ScoreRecord::getScore() const {
    return score;
}

const string &ScoreRecord::getName() const {
    return name;
}

void ScoreRecord::setScore(const int &score) {
    ScoreRecord::score = score;
}

void ScoreRecord::setName(const string &name) {
    ScoreRecord::name = name;
}
