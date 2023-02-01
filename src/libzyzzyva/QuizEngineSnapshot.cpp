//---------------------------------------------------------------------------
// QuizEngineSnapshot.cpp
//
// The engine for generating quizzes and keeping track of the user's
// performance on each quiz.
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

#include "QuizEngineSnapshot.h"
#include "QuizProgress.h"

//---------------------------------------------------------------------------
//  QuizEngineSnapshot
//
//! Constructor.
//---------------------------------------------------------------------------
QuizEngineSnapshot::QuizEngineSnapshot(QuizProgress* qp,
    QSet<QString>* qeCorrectResponses,
    QSet<QString>* qeCorrectUserResponses,
    QStringList* qeIncorrectUserResponses,
    int qeQuizTotal,
    int qeQuizCorrect,
    int qeQuizIncorrect,
    QStringList* qeQuizQuestions,
    int qeQuestionIndex)
{
    // Take a snapshot of the QuizProgress
    question = qp->getQuestion();
    correct = qp->getNumCorrect();
    incorrect = qp->getNumIncorrect();
    missed = qp->getNumMissed();
    questionComplete = qp->getQuestionComplete();
    questionCorrectWords = qp->getQuestionCorrect();
    questionCorrectWords.detach();
    incorrectWords = qp->getIncorrect();
    incorrectWords.detach();
    missedWords = qp->getMissed();
    missedWords.detach();

    // Take a snapshot of the necessary QuizEngine fields
    correctResponses = *qeCorrectResponses;
    correctResponses.detach();
    correctUserResponses = *qeCorrectUserResponses;
    correctUserResponses.detach();
    incorrectUserResponses = *qeIncorrectUserResponses;
    incorrectUserResponses.detach();
    quizTotal = qeQuizTotal;
    quizCorrect = qeQuizCorrect;
    quizIncorrect = qeQuizIncorrect;
    quizQuestions = *qeQuizQuestions;
    quizQuestions.detach();
    questionIndex = qeQuestionIndex;
}
