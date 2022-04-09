/**
 * @file HeadTop.h
 * @author Jacob Stacy
 *
 *  Header file for HeadTop class
 *
 */

#ifndef CANADIANEXPERIENCE_HEADTOP_H
#define CANADIANEXPERIENCE_HEADTOP_H

#include "ImageDrawable.h"

/**
 * The class for the top part of the head of an actor
 */
class HeadTop : public ImageDrawable {
private:


    /// The animation channel for animating the move of this drawable
    AnimChannelMove mMoveChannel;

public:

    HeadTop(const std::wstring &name, const std::wstring &filename);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Is this a movable drawable?
     * @return true if movable
     */
    bool IsMovable() override { return true; }

    wxPoint TransformPoint(wxPoint p);

    void DrawEyebrow(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p, wxPoint p2);

    void DrawEye(std::shared_ptr<wxGraphicsContext> graphics, wxPoint p1);

    void SetKeyframe() override;

    void GetKeyframe() override;

    void SetTimeline(Timeline* timeline) override;

    AnimChannelMove *GetMoveChannel() {return &mMoveChannel;}

    //void SetActor(Actor* actor) override;
};

#endif //CANADIANEXPERIENCE_HEADTOP_H
