//
// Created by nstan on 24/05/2022.
//

#ifndef OOP_S1_2022_MAJOR_PRAC_SCORERECORD_H
#define OOP_S1_2022_MAJOR_PRAC_SCORERECORD_H
#include <iostream>

using namespace std;
class ScoreRecord {
protected:
    int score;
    string name;
public:
    ScoreRecord();

    const int &getScore() const;

    const string &getName() const;

    void setScore(const int &score);

    void setName(const string &name);
};


#endif //OOP_S1_2022_MAJOR_PRAC_SCORERECORD_H
