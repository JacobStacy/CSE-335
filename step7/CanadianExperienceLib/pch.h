/**
 * @file pch.h
 * @author Jacob R. Stacy
 */

#ifndef CANADIANEXPERIENCELIB_PCH_H
#define CANADIANEXPERIENCELIB_PCH_H

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#ifdef GetCurrentTime
#undef GetCurrentTime
#endif

#include <wx/graphics.h>

#endif //CANADIANEXPERIENCELIB_PCH_H
