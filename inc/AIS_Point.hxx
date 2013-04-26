// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _AIS_Point_HeaderFile
#define _AIS_Point_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_AIS_Point_HeaderFile
#include <Handle_AIS_Point.hxx>
#endif

#ifndef _Handle_Geom_Point_HeaderFile
#include <Handle_Geom_Point.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Aspect_TypeOfMarker_HeaderFile
#include <Aspect_TypeOfMarker.hxx>
#endif
#ifndef _AIS_InteractiveObject_HeaderFile
#include <AIS_InteractiveObject.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _AIS_KindOfInteractive_HeaderFile
#include <AIS_KindOfInteractive.hxx>
#endif
#ifndef _Handle_PrsMgr_PresentationManager3d_HeaderFile
#include <Handle_PrsMgr_PresentationManager3d.hxx>
#endif
#ifndef _Handle_Prs3d_Presentation_HeaderFile
#include <Handle_Prs3d_Presentation.hxx>
#endif
#ifndef _Handle_Prs3d_Projector_HeaderFile
#include <Handle_Prs3d_Projector.hxx>
#endif
#ifndef _Handle_Geom_Transformation_HeaderFile
#include <Handle_Geom_Transformation.hxx>
#endif
#ifndef _Handle_SelectMgr_Selection_HeaderFile
#include <Handle_SelectMgr_Selection.hxx>
#endif
#ifndef _Quantity_NameOfColor_HeaderFile
#include <Quantity_NameOfColor.hxx>
#endif
class Geom_Point;
class PrsMgr_PresentationManager3d;
class Prs3d_Presentation;
class Prs3d_Projector;
class Geom_Transformation;
class SelectMgr_Selection;
class Quantity_Color;
class TopoDS_Vertex;


//! Constructs point datums to be used in construction of <br>
//! composite shapes. The datum is displayed as the plus marker +. <br>
class AIS_Point : public AIS_InteractiveObject {

public:

  
//! Initializes the point aComponent from which the point <br>
//! datum will be built. <br>
  Standard_EXPORT   AIS_Point(const Handle(Geom_Point)& aComponent);
  //! Returns index 1, the default index for a point. <br>
      virtual  Standard_Integer Signature() const;
  //! Indicates that a point is a datum. <br>
      virtual  AIS_KindOfInteractive Type() const;
  //! Returns the component specified in SetComponent. <br>
  Standard_EXPORT     Handle_Geom_Point Component() ;
  //! Constructs an instance of the point aComponent. <br>
  Standard_EXPORT     void SetComponent(const Handle(Geom_Point)& aComponent) ;
  //! Returns true if the display mode selected is valid for point datums. <br>
  Standard_EXPORT     Standard_Boolean AcceptDisplayMode(const Standard_Integer aMode) const;
  //! computes the presentation according to a point of view <br>
//!          given by <aProjector>. <br>
//!          To be Used when the associated degenerated Presentations <br>
//!          have been transformed by <aTrsf> which is not a Pure <br>
//!          Translation. The HLR Prs can't be deducted automatically <br>
//!          WARNING :<aTrsf> must be applied <br>
//!           to the object to display before computation  !!! <br>
  Standard_EXPORT   virtual  void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Geom_Transformation)& aTrsf,const Handle(Prs3d_Presentation)& aPresentation) ;
  //! Allows you to provide settings for the cp;pr aColor. <br>
  Standard_EXPORT     void SetColor(const Quantity_NameOfColor aColor) ;
  
  Standard_EXPORT     void SetColor(const Quantity_Color& aColor) ;
  //! Allows you to remove color settings. <br>
  Standard_EXPORT     void UnsetColor() ;
  //! Allows you to provide settings for a marker. These include <br>
//! -   type of marker, <br>
//! -   marker color, <br>
//! -   scale factor. <br>
  Standard_EXPORT     void SetMarker(const Aspect_TypeOfMarker aType) ;
  //! Removes the marker settings. <br>
  Standard_EXPORT     void UnsetMarker() ;
  //! Returns true if the point datum has a marker. <br>
        Standard_Boolean HasMarker() const;
  //! Converts a point into a vertex. <br>
  Standard_EXPORT     TopoDS_Vertex Vertex() const;




  DEFINE_STANDARD_RTTI(AIS_Point)

protected:

  
  Standard_EXPORT   virtual  void Compute(const Handle(PrsMgr_PresentationManager3d)& aPresentationManager,const Handle(Prs3d_Presentation)& aPresentation,const Standard_Integer aMode = 0) ;



private: 

  
  Standard_EXPORT     void Compute(const Handle(Prs3d_Projector)& aProjector,const Handle(Prs3d_Presentation)& aPresentation) ;
  
  Standard_EXPORT     void ComputeSelection(const Handle(SelectMgr_Selection)& aSelection,const Standard_Integer aMode) ;
  
  Standard_EXPORT     void UpdatePointValues() ;

Handle_Geom_Point myComponent;
Standard_Boolean myHasTOM;
Aspect_TypeOfMarker myTOM;


};


#include <AIS_Point.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
