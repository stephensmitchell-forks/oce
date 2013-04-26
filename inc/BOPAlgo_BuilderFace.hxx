// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPAlgo_BuilderFace_HeaderFile
#define _BOPAlgo_BuilderFace_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Face_HeaderFile
#include <TopoDS_Face.hxx>
#endif
#ifndef _BOPAlgo_BuilderArea_HeaderFile
#include <BOPAlgo_BuilderArea.hxx>
#endif
#ifndef _BOPCol_BaseAllocator_HeaderFile
#include <BOPCol_BaseAllocator.hxx>
#endif
class TopoDS_Face;


//! The algorithm to build faces from set of edges <br>
class BOPAlgo_BuilderFace  : public BOPAlgo_BuilderArea {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BOPAlgo_BuilderFace();
Standard_EXPORT virtual ~BOPAlgo_BuilderFace();
  
  Standard_EXPORT   BOPAlgo_BuilderFace(const BOPCol_BaseAllocator& theAllocator);
  //! Sets the face generatix <br>
  Standard_EXPORT     void SetFace(const TopoDS_Face& theFace) ;
  //! Returns the face generatix <br>
  Standard_EXPORT    const TopoDS_Face& Face() const;
  //!  Performs the algorithm <br>
  Standard_EXPORT   virtual  void Perform() ;





protected:

  //!  Collect the edges that <br>
//!           a) are internal <br>
//!           b) are the same and have different orientation <br>
  Standard_EXPORT   virtual  void PerformShapesToAvoid() ;
  //! Build draft wires <br>
//!          a)myLoops - draft wires that consist of <br>
//!                       boundary edges <br>
//!          b)myLoopsInternal - draft wires that contains <br>
//!                               inner edges <br>
  Standard_EXPORT   virtual  void PerformLoops() ;
  //! Build draft faces that contains boundary edges <br>
  Standard_EXPORT   virtual  void PerformAreas() ;
  //! Build finalized faces with internals <br>
  Standard_EXPORT   virtual  void PerformInternalShapes() ;
  
  Standard_EXPORT   virtual  void CheckData() ;


TopoDS_Face myFace;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
