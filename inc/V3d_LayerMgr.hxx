// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _V3d_LayerMgr_HeaderFile
#define _V3d_LayerMgr_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_V3d_LayerMgr.hxx>

#include <V3d_ViewPointer.hxx>
#include <Handle_Visual3d_Layer.hxx>
#include <Handle_V3d_ColorScale.hxx>
#include <Handle_V3d_ColorScaleLayerItem.hxx>
#include <MMgt_TShared.hxx>
#include <Handle_V3d_View.hxx>
#include <Standard_Boolean.hxx>
#include <Handle_Aspect_ColorScale.hxx>
class Visual3d_Layer;
class V3d_ColorScale;
class V3d_ColorScaleLayerItem;
class V3d_View;
class Aspect_ColorScale;


//! Class to manage layers
class V3d_LayerMgr : public MMgt_TShared
{

public:

  
  Standard_EXPORT V3d_LayerMgr(const Handle(V3d_View)& aView);
  
     const  Handle(Visual3d_Layer)& Overlay()  const;
  
      Handle(V3d_View) View()  const;
  
  Standard_EXPORT   void ColorScaleDisplay() ;
  
  Standard_EXPORT   void ColorScaleErase() ;
  
  Standard_EXPORT   Standard_Boolean ColorScaleIsDisplayed()  const;
  
  Standard_EXPORT   Handle(Aspect_ColorScale) ColorScale()  const;
  
  //! Recompute layer with objects
  Standard_EXPORT   void Compute() ;
  
  Standard_EXPORT   void Resized() ;




  DEFINE_STANDARD_RTTI(V3d_LayerMgr)

protected:

  
  //! Begin layers recomputation
  Standard_EXPORT virtual   Standard_Boolean Begin() ;
  
  //! Perform layers recomputation
  Standard_EXPORT virtual   void Redraw() ;
  
  //! End layers recomputation
  Standard_EXPORT virtual   void End() ;

  V3d_ViewPointer myView;
  Handle(Visual3d_Layer) myOverlay;
  Handle(V3d_ColorScale) myColorScale;
  Handle(V3d_ColorScaleLayerItem) myColorScaleLayerItem;


private: 




};


#include <V3d_LayerMgr.lxx>





#endif // _V3d_LayerMgr_HeaderFile
