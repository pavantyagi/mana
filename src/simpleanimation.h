/*
 *  The Mana World
 *  Copyright 2004 The Mana World Development Team
 *
 *  This file is part of The Mana World.
 *
 *  The Mana World is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  any later version.
 *
 *  The Mana World is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with The Mana World; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  $Id$
 */

#ifndef _TMW_SIMPLEANIMAION_H
#define _TMW_SIMPLEANIMAION_H

#include "resources/animation.h"

class Frame;
class Graphics;

/**
 * This class is a leightweight alternative to the AnimatedSprite class.
 * It hosts a looping animation without actions and directions.
 */
class SimpleAnimation
{
    public:
        SimpleAnimation(Animation *animation):
            mAnimation(animation),
            mAnimationTime(0),
            mAnimationPhase(0),
            mCurrentFrame(mAnimation->getFrame(0))
        {};

        ~SimpleAnimation();

        void update(unsigned int timePassed);

        Image *getCurrentImage() const;

    private:
        Animation *mAnimation;          /**< The hosted animation */
        unsigned int mAnimationTime;    /**< Time in game ticks the current frame is shown*/
        unsigned int mAnimationPhase;   /**< Current animation phase when the appearance is ANIMATION*/
        Frame *mCurrentFrame;
};

#endif