/**
 * @file Component.h
 * @author Jacob R. Stacy
 *
 *
 */

#ifndef CANADIANEXPERIENCE_COMPONENT_H
#define CANADIANEXPERIENCE_COMPONENT_H

#include <wx/xml/xml.h>

class ActualLaboratory;

class Component {
private:

    /// Component's position in space
    wxPoint mPostion;

    /// Xml Document
    wxXmlDocument mXmlDoc;

    /// Name of Component
    std::wstring mName;

    /// Current time
    double mTime;

    /// Lab that the component is a part of
    ActualLaboratory *mLaboratory = nullptr;

public:

    virtual ~Component() {}

    Component(const std::wstring &name);

    /// Copy Constructor (Disabled)
    Component(const Component &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Component &) = delete;

    // Probably make most of these true virtual

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) {}

    virtual void Update(double elapsed) {}

    virtual double Power(double voltage) { return 0;}

    virtual void XmlLoad(wxXmlNode node) {}

    virtual void XmlEvent(wxXmlNode node) {}

    /**
     * Set the current time
     * @param time New time
     */
    void SetTime (double time) { mTime = time; }

    virtual void Reset(int frame) {}


    void SetLaboratory(ActualLaboratory* laboratory);

};

#endif //CANADIANEXPERIENCE_COMPONENT_H
