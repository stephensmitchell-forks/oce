// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPAlgo_WireSplitter_HeaderFile
#define _BOPAlgo_WireSplitter_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _BOPAlgo_PWireEdgeSet_HeaderFile
#include <BOPAlgo_PWireEdgeSet.hxx>
#endif
#ifndef _BOPTools_ListOfConnexityBlock_HeaderFile
#include <BOPTools_ListOfConnexityBlock.hxx>
#endif
#ifndef _BOPAlgo_Algo_HeaderFile
#include <BOPAlgo_Algo.hxx>
#endif
#ifndef _BOPCol_BaseAllocator_HeaderFile
#include <BOPCol_BaseAllocator.hxx>
#endif
#ifndef _BOPCol_ListOfShape_HeaderFile
#include <BOPCol_ListOfShape.hxx>
#endif
#ifndef _BOPTools_ConnexityBlock_HeaderFile
#include <BOPTools_ConnexityBlock.hxx>
#endif
class BOPAlgo_WireEdgeSet;
class TopoDS_Wire;



class BOPAlgo_WireSplitter  : public BOPAlgo_Algo {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BOPAlgo_WireSplitter();
Standard_EXPORT virtual ~BOPAlgo_WireSplitter();
  
  Standard_EXPORT   BOPAlgo_WireSplitter(const BOPCol_BaseAllocator& theAllocator);
  
  Standard_EXPORT     void SetWES(const BOPAlgo_WireEdgeSet& theWES) ;
  
  Standard_EXPORT     BOPAlgo_WireEdgeSet& WES() ;
  
  Standard_EXPORT   virtual  void Perform() ;
  
      static  void MakeWire(BOPCol_ListOfShape& theLE,TopoDS_Wire& theW) ;





protected:

  
  Standard_EXPORT   virtual  void CheckData() ;
  
  Standard_EXPORT     void MakeConnexityBlocks() ;
  
  Standard_EXPORT     void MakeWires() ;
  
  Standard_EXPORT     void SplitBlock(BOPTools_ConnexityBlock& theCB) ;


BOPAlgo_PWireEdgeSet myWES;
BOPTools_ListOfConnexityBlock myLCB;


private:





};


#include <BOPAlgo_WireSplitter.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
