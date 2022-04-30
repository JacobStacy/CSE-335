/**
 * @file Cable.cpp
 * @author Jacob Stacy
 */

#include "pch.h"

#include "Cable.h"
#include "Clamp.h"

/// Smallest possible cable size
const int CableMinimumWidth = 3;

/// The width of the cable line is CableMinimumWidth
/// plus capacity / CableCapacityDivisor
const int CableCapacityDivisor = 200;

/// The cable color (
const wxColour CableColor = wxColour(40, 40, 40);

/**
 * Constructor
 * @param name Name
 * @param imageDir Dir
 * @param source PowerSource being made with
 * @param sink PowerSink being made with
 * @param speedSink speed for sink
 * @param speedSource speed for source
 */
Cable::Cable(const std::wstring &name, const std::wstring &imageDir, std::shared_ptr<PowerSource> source, PowerSink* sink, double speedSink, double speedSource)
        : Component(name)
{
    // Create connection from source to sink
    source->SetSink(sink);

    mSource = source;
    mSink =  sink;

    sink->SetSpeed(speedSink);
    source->SetSpeed(speedSource);
}



/**
 * Draws the cable
 * @param graphics Graphics
 */
void Cable::Draw(std::shared_ptr<wxGraphicsContext> graphics)
{
//    path.AddCurveToPoint(p2.x, p2.y, p3.x, p3.y, p4.x, p4.y);
//    graphics->StrokePath(path);

    auto path = graphics->CreatePath();

    for (int i = 0; i < mEnds.size(); i++)
    {

        double p1x = mEnds[i]->GetPosition().x;
        double p1y = mEnds[i]->GetPosition().y;
        double p1r = mEnds[i]->GetRotation();
        double p1s = mEnds[i]->GetSpeed();

        if (i == 0)
        {
            p1x = mSink->GetPosition().x;
            p1y = mSink->GetPosition().y;
            p1r = mSink->GetRotation();
            p1s = mSink->GetSpeed();
        }

        auto p2x = p1x + sin(p1r * M_PI * 2) * p1s;
        auto p2y = p1y - cos(p1r * M_PI * 2) * p1s;

        double p4x = mSource->GetPosition().x;
        double p4y = mSource->GetPosition().y;
        double p4r = mSource->GetRotation();
        double p4s = mSource->GetSpeed();

        if (i != mEnds.size() - 1)
        {
            p4x = mEnds[i + 1]->GetPosition().x;
            p4y = mEnds[i + 1]->GetPosition().y;
            p4r = mEnds[i + 1]->GetRotation();
            p4s = mEnds[i + 1]->GetSpeed();
        }

        auto p3x = p4x + sin(p4r * M_PI * 2) * p4s;
        auto p3y = p4y - cos(p4r * M_PI * 2) * p4s;


        path.MoveToPoint(p1x, p1y);
        path.AddCurveToPoint(p2x, p2y, p3x, p3y, p4x, p4y);

        int width = int(CableMinimumWidth + mSource->GetCapacity() / CableCapacityDivisor);

        wxPen pen = wxPen(CableColor);
        pen.SetWidth(width);
        pen.SetCap(wxCAP_BUTT);
        graphics->SetPen(pen);

        graphics->StrokePath(path);
    }

    if (mEnds.size() == 0)
    {

        double p1x = mSink->GetPosition().x;
        double p1y = mSink->GetPosition().y;
        double p1r = mSink->GetRotation();
        double p1s = mSink->GetSpeed();


        auto p2x = p1x + sin(p1r * M_PI * 2) * p1s;
        auto p2y = p1y - cos(p1r * M_PI * 2) * p1s;

        double p4x = mSource->GetPosition().x;
        double p4y = mSource->GetPosition().y;
        double p4r = mSource->GetRotation();
        double p4s = mSource->GetSpeed();


        auto p3x = p4x + sin(p4r * M_PI * 2) * p4s;
        auto p3y = p4y - cos(p4r * M_PI * 2) * p4s;


        path.MoveToPoint(p1x, p1y);
        path.AddCurveToPoint(p2x, p2y, p3x, p3y, p4x, p4y);

        int width = int(CableMinimumWidth + mSource->GetCapacity() / CableCapacityDivisor);

        wxPen pen = wxPen(CableColor);
        pen.SetWidth(width);
        pen.SetCap(wxCAP_BUTT);
        graphics->SetPen(pen);

        graphics->StrokePath(path);
    }

}

/**
 * Add Clamp
 * @param clamp Clamp
 */
void Cable::AddClamp(std::shared_ptr<Clamp> clamp)
{
    mEnds.push_back(clamp);
}

