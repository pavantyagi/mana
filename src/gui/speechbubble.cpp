/*
 *  Speech bubbles
 *  Copyright (C) 2008  The Legend of Mazzeroth Development Team
 *
 *  This file is part of The Mana World.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <guichan/font.hpp>

#include <guichan/widgets/label.hpp>

#include "gui.h"
#include "scrollarea.h"
#include "speechbubble.h"
#include "textbox.h"

#include "../utils/gettext.h"

SpeechBubble::SpeechBubble():
    Window(_("Speech"), false, NULL, "graphics/gui/speechbubble.xml")
{
    setContentSize(140, 46);
    setShowTitle(false);
    setTitleBarHeight(0);

    mCaption = new gcn::Label("");
    mCaption->setFont(boldFont);
    mCaption->setPosition(5, 3);

    mSpeechBox = new TextBox;
    mSpeechBox->setEditable(false);
    mSpeechBox->setOpaque(false);

    mSpeechArea = new ScrollArea(mSpeechBox);

    mSpeechArea->setHorizontalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mSpeechArea->setVerticalScrollPolicy(gcn::ScrollArea::SHOW_NEVER);
    mSpeechArea->setDimension(gcn::Rectangle(4, boldFont->getHeight() + 3,
                                             130, 28));
    mSpeechArea->setOpaque(false);

    add(mCaption);
    add(mSpeechArea);

    setLocationRelativeTo(getParent());
}

void SpeechBubble::setCaption(const std::string &name, const gcn::Color &color)
{
    mCaption->setCaption(name);
    mCaption->adjustSize();
    mCaption->setForegroundColor(color);
}

void SpeechBubble::setText(std::string mText, bool showName)
{
    int width = mCaption->getWidth();
    mSpeechBox->setTextWrapped(mText, 130 > width ? 130 : width);

    const int fontHeight = getFont()->getHeight();
    const int numRows = showName ? mSpeechBox->getNumberOfRows() + 1 :
                                   mSpeechBox->getNumberOfRows();
    int yPos = showName ? fontHeight + 3 : 3;
    int height = (numRows * fontHeight);

    if (width < mSpeechBox->getMinWidth())
        width = mSpeechBox->getMinWidth();

    if (numRows == 1)
    {
        yPos = (fontHeight / 4) + 3;
        height = ((3 * fontHeight) / 2) + 1;
    }

    setContentSize(width + fontHeight, height + 6);
    mSpeechArea->setDimension(gcn::Rectangle(4, yPos, width + 5, height));
}

unsigned int SpeechBubble::getNumRows()
{
    return mSpeechBox->getNumberOfRows();
}