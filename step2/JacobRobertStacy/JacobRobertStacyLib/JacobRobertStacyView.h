/**
 * @file JacobRobertStacyView.h
 * @author Jacob Stacy
 *
 *Declaration of the JacobRobertStacyView class.
 *
 */

#ifndef JACOBROBERTSTACY_JACOBROBERTSTACYVIEW_H
#define JACOBROBERTSTACY_JACOBROBERTSTACYVIEW_H

class JacobRobertStacyView : public wxWindow {
private:
    void OnPaint(wxPaintEvent& event);
public:
    void Initialize(wxFrame*);
};

#endif //JACOBROBERTSTACY_JACOBROBERTSTACYVIEW_H
