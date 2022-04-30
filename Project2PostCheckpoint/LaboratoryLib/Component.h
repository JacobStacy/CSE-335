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

/**
 * Component Class
 */
class Component {
private:

    /// Component's position in space
    wxPoint mPosition;

    /// Xml Document
    wxXmlNode* mXmlDoc;

    /// Name of Component
    std::wstring mName;

    /// Current time
    double mTime;

    /// Lab that the component is a part of
    ActualLaboratory *mLaboratory = nullptr;

public:

    /**
     * Destructor
     */
    virtual ~Component() {}

    Component(const std::wstring &name);

    /// Copy Constructor (Disabled)
    Component(const Component &) = delete;
    /// Assignment Operator (Disabled)
    void operator=(const Component &) = delete;

    // Probably make most of these true virtual

    /**
     * Draws the component
     * @param graphics Graphics
     */
    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) {}

    /**
     * Updates the Component
     * @param elapsed Current Time
     */
    virtual void Update(double elapsed) {}

    /**
     * Powers the component
     * @param voltage Voltage Supplied
     * @return Current Drawn
     */
    virtual double Power(double voltage) { return 0;}

    /**
     * Loads XML Event
     * @param node node with event
     */
    virtual void XmlLoad(wxXmlNode* node) {}

    /**
     * Handles XML Event
     * @param node node with event
     */
    virtual void XmlEvent(wxXmlNode node) {}

    /**
     * Set the current time
     * @param time New time
     */
    virtual void SetTime (double time) { mTime = time; }

    /**
     * Resets the component to default
     * @param frame Frame
     */
    virtual void Reset(int frame) {}


    void SetLaboratory(ActualLaboratory* laboratory);

    /**
     * Gets Position
     * @return Position
     */
    wxPoint GetPosition() { return mPosition; }

    /**
     * Sets the position
     * @param x X position
     * @param y Y position
     */
    virtual void SetPosition(double x, double y) { mPosition.x = x; mPosition.y = y; }

    /**
     * Gets the name
     * @return The name
     */
    std::wstring GetName() { return mName; }

};

#endif //CANADIANEXPERIENCE_COMPONENT_H
