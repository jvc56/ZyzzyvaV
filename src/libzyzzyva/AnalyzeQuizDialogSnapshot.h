//---------------------------------------------------------------------------
// AnalyzeQuizDialogSnapshot.h
//
// A snapshot of a AnalyzeQuizDialog at a give point in time.
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

#ifndef ZYZZYVA_ANALYZE_QUIZ_DIALOG_SNAPSHOT_H
#define ZYZZYVA_ANALYZE_QUIZ_DIALOG_SNAPSHOT_H

#include "WordTableModel.h"
#include <QSet>
#include <QString>
class WordTableModel;

class AnalyzeQuizDialogSnapshot
{
    public:
    AnalyzeQuizDialogSnapshot(QList<WordTableModel::WordItem> missedModelWordList, QList<WordTableModel::WordItem> incorrectModelWordList, QSet<QString> missedCache, QSet<QString> incorrectCache);
    ~AnalyzeQuizDialogSnapshot() { }
    QList<WordTableModel::WordItem> getMissedModelWordList() { return missedModelWordList; }
    QList<WordTableModel::WordItem> getIncorrectModelWordList() { return incorrectModelWordList; }
    QSet<QString> getMissedCache() { return missedCache; };
    QSet<QString> getIncorrectCache() { return incorrectCache; };

    private:
    QList<WordTableModel::WordItem> missedModelWordList;
    QList<WordTableModel::WordItem> incorrectModelWordList;
    QSet<QString> missedCache;
    QSet<QString> incorrectCache;
};

#endif // ZYZZYVA_ANALYZE_QUIZ_DIALOG_SNAPSHOT_H
