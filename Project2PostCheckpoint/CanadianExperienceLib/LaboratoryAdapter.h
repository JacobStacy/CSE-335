/**
 * @file LaboratoryAdapter.h
 * @author Jacob Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_LABORATORYADAPTER_H
#define CANADIANEXPERIENCE_LABORATORYADAPTER_H


#include "Drawable.h"
#include <laboratory-api.h>

/**
 * LaboratoryAdapter
 */
class LaboratoryAdapter : public Drawable {
private:

    /// Lab
    Laboratory mLaboratory;

    /// frame
    int frame;

public:

    LaboratoryAdapter(const std::wstring& name);

    void Draw(std::shared_ptr<wxGraphicsContext> graphics) override;

    /**
     * Hit?
     * @param pos Postion
     * @return Hit?
     */
    bool HitTest(wxPoint pos) { return false; }

};

#endif //CANADIANEXPERIENCE_LABORATORYADAPTER_H
