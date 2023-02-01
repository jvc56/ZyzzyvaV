//---------------------------------------------------------------------------
// AnalyzeQuizDialogSnapshot.cpp
//
// A dialog for prompting the user for a quiz.
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

#include "AnalyzeQuizDialogSnapshot.h"
#include "WordTableModel.h"

class WordTableModel;

//---------------------------------------------------------------------------
//  AnalyzeQuizDialogSnapshot
//
//! Constructor.
//
//! @param parent the parent widget
//! @param f widget flags
//---------------------------------------------------------------------------
AnalyzeQuizDialogSnapshot::AnalyzeQuizDialogSnapshot(QList<WordTableModel::WordItem> missedModelWordListArg, QList<WordTableModel::WordItem> incorrectModelWordListArg, QSet<QString> missedCacheArg, QSet<QString> incorrectCacheArg)
{
    missedModelWordList = missedModelWordListArg;
    missedModelWordList.detach();

    incorrectModelWordList = incorrectModelWordListArg;
    incorrectModelWordList.detach();

    missedCache = missedCacheArg;
    missedCache.detach();

    incorrectCache = incorrectCacheArg;
    incorrectCache.detach();
}