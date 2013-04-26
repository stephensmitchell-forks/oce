// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Quantity_TypeOfColor_HeaderFile
#define _Quantity_TypeOfColor_HeaderFile

//!  Identifies color definition systems <br>
//! -   Quantity_TOC_RGB: with this system a <br>
//!   color is defined by its quantities of red, green and blue (R-G-B values). <br>
//! -   Quantity_TOC_HLS: with this system a <br>
//!   color is defined by its hue angle and its <br>
//!   lightness and saturation values (H-L-S values). <br>
//!   A Quantity_Color object may define a color <br>
//! from three values R-G-B or H-L-S according <br>
//! to a given color definition system. <br>
enum Quantity_TypeOfColor {
Quantity_TOC_RGB,
Quantity_TOC_HLS
};

#ifndef _Standard_PrimitiveTypes_HeaderFile
#include <Standard_PrimitiveTypes.hxx>
#endif

#endif
