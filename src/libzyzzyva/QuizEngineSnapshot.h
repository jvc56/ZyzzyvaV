//---------------------------------------------------------------------------
// QuizEngineSnapshot.h
//
// A snapshot of a QuizEngine at a give point in time.
//
// Copyright 2015-2016 Twilight Century Computing.
// Copyright 2004-2012 North American SCRABBLE Players Association.
//
// This file is part of Zyzzyva.
//
// Zyzzyva is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// Zyzzyva is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//---------------------------------------------------------------------------

#ifndef ZYZZYVA_QUIZ_ENGINE_SNAPSHOT_H
#define ZYZZYVA_QUIZ_ENGINE_SNAPSHOT_H

#include "QuizProgress.h"

class QuizEngineSnapshot
{
    public:
    QuizEngineSnapshot(QuizProgress* qp,
    QSet<QString>* correctResponses,
    QSet<QString>* correctUserResponses,
    QStringList* incorrectUserResponses,
    int qeQuizTotal,
    int qeQuizCorrect,
    int qeQuizIncorrect,
    QStringList* qeQuizQuestions,
    int qeQuestionIndex);
    ~QuizEngineSnapshot() { }

    // Getter methods for progress
    int getQuestion() const { return question; }
    int getNumCorrect() const { return correct; }
    int getNumIncorrect() const { return incorrect; }
    int getNumMissed() const { return missed; }
    bool getQuestionComplete() const { return questionComplete; }

    QSet<QString> getQuestionCorrect() const { return questionCorrectWords; }
    QMap<QString, int> getIncorrect() const { return incorrectWords; }
    QMap<QString, int> getMissed() const { return missedWords; }

    // Getter methods for QuizEngine
    QSet<QString> getCorrectResponses() const { return correctResponses; }
    QSet<QString> getCorrectUserResponses() const { return correctUserResponses; }
    QStringList getIncorrectUserResponses() const { return incorrectUserResponses; }
    int getQuizTotal() const { return quizTotal; }
    int getQuizCorrect() const { return quizCorrect; }
    int getQuizIncorrect() const { return quizIncorrect; }
    QStringList getQuizQuestions() const { return quizQuestions; }
    int getQuestionIndex() const { return questionIndex; }

    private:
    // Fields of QuizProgress
    int question;
    int correct;
    int incorrect;
    int missed;
    bool questionComplete;
    QSet<QString> questionCorrectWords;
    QMap<QString, int> incorrectWords;
    QMap<QString, int> missedWords;

    // Fields of QuizEngine that are needed
    QSet<QString> correctResponses;
    QSet<QString> correctUserResponses;
    QStringList incorrectUserResponses;
    int quizTotal;
    int quizCorrect;
    int quizIncorrect;
    QStringList quizQuestions;
    int         questionIndex;
};

#endif // ZYZZYVA_QUIZ_ENGINE_SNAPSHOT_H
