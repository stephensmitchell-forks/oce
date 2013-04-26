// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _ShapeUpgrade_FaceDivide_HeaderFile
#define _ShapeUpgrade_FaceDivide_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_ShapeUpgrade_FaceDivide_HeaderFile
#include <Handle_ShapeUpgrade_FaceDivide.hxx>
#endif

#ifndef _Handle_ShapeUpgrade_SplitSurface_HeaderFile
#include <Handle_ShapeUpgrade_SplitSurface.hxx>
#endif
#ifndef _Handle_ShapeUpgrade_WireDivide_HeaderFile
#include <Handle_ShapeUpgrade_WireDivide.hxx>
#endif
#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _TopoDS_Shape_HeaderFile
#include <TopoDS_Shape.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _ShapeUpgrade_Tool_HeaderFile
#include <ShapeUpgrade_Tool.hxx>
#endif
#ifndef _ShapeExtend_Status_HeaderFile
#include <ShapeExtend_Status.hxx>
#endif
class ShapeUpgrade_SplitSurface;
class ShapeUpgrade_WireDivide;
class TopoDS_Face;
class TopoDS_Shape;


//! Divides a Face (both edges in the wires, by splitting <br>
//!            curves and pcurves, and the face itself, by splitting <br>
//!            supporting surface) according to splitting criteria. <br>
//!  * The domain of the face to divide is defined by the PCurves <br>
//!    of the wires on the Face. <br>
//! <br>
//!  * all the PCurves are supposed to be defined (in the parametric <br>
//!     space of the supporting surface). <br>
//! <br>
//!  The result is available after the call to the Build method. <br>
//!  It is a Shell containing all the resulting Faces. <br>
//! <br>
//!  All the modifications made during splitting are recorded in the <br>
//!  external context (ShapeBuild_ReShape). <br>
class ShapeUpgrade_FaceDivide : public ShapeUpgrade_Tool {

public:

  //! Creates empty  constructor. <br>
  Standard_EXPORT   ShapeUpgrade_FaceDivide();
  //! Initialize by a Face. <br>
  Standard_EXPORT   ShapeUpgrade_FaceDivide(const TopoDS_Face& F);
  //! Initialize by a Face. <br>
  Standard_EXPORT     void Init(const TopoDS_Face& F) ;
  //! Purpose sets mode for trimming (segment) surface by <br>
//!          wire UV bounds. <br>
  Standard_EXPORT     void SetSurfaceSegmentMode(const Standard_Boolean Segment) ;
  //! Performs splitting and computes the resulting shell <br>
//!          The context is used to keep track of former splittings <br>
//!          in order to keep sharings. It is updated according to <br>
//!          modifications made. <br>
  Standard_EXPORT   virtual  Standard_Boolean Perform() ;
  //! Performs splitting of surface and computes the shell <br>
//!          from source face. <br>
  Standard_EXPORT   virtual  Standard_Boolean SplitSurface() ;
  //! Performs splitting of curves of all the edges in the <br>
//!          shape and divides these edges. <br>
  Standard_EXPORT   virtual  Standard_Boolean SplitCurves() ;
  //! Gives the resulting Shell, or Face, or Null shape if not done. <br>
  Standard_EXPORT     TopoDS_Shape Result() const;
  //! Queries the status of last call to Perform <br>
//! OK   : no splitting was done (or no call to Perform) <br>
//! DONE1: some edges were splitted <br>
//! DONE2: surface was splitted <br>
//! DONE3: surface was modified without splitting <br>
//! FAIL1: some fails encountered during splitting wires <br>
//! FAIL2: face cannot be splitted <br>
  Standard_EXPORT     Standard_Boolean Status(const ShapeExtend_Status status) const;
  //! Sets the tool for splitting surfaces. <br>
  Standard_EXPORT     void SetSplitSurfaceTool(const Handle(ShapeUpgrade_SplitSurface)& splitSurfaceTool) ;
  //! Sets the tool for dividing edges on Face. <br>
  Standard_EXPORT     void SetWireDivideTool(const Handle(ShapeUpgrade_WireDivide)& wireDivideTool) ;
  //! Returns the tool for dividing edges on Face. <br>
//!          This tool must be already initialized. <br>
  Standard_EXPORT   virtual  Handle_ShapeUpgrade_WireDivide GetWireDivideTool() const;




  DEFINE_STANDARD_RTTI(ShapeUpgrade_FaceDivide)

protected:

  //! Returns the tool for splitting surfaces. <br>
//!          This tool must be already initialized. <br>
  Standard_EXPORT   virtual  Handle_ShapeUpgrade_SplitSurface GetSplitSurfaceTool() const;

TopoDS_Face myFace;
TopoDS_Shape myResult;
Standard_Boolean mySegmentMode;
Standard_Integer myStatus;


private: 


Handle_ShapeUpgrade_SplitSurface mySplitSurfaceTool;
Handle_ShapeUpgrade_WireDivide myWireDivideTool;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
