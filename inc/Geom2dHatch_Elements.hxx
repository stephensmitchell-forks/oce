// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Geom2dHatch_Elements_HeaderFile
#define _Geom2dHatch_Elements_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineAlloc.hxx>
#include <Standard_Macro.hxx>

#include <Geom2dHatch_MapOfElements.hxx>
#include <Geom2dHatch_DataMapIteratorOfMapOfElements.hxx>
#include <Standard_Integer.hxx>
#include <Standard_Boolean.hxx>
#include <Standard_Real.hxx>
#include <TopAbs_Orientation.hxx>
class Standard_DomainError;
class Standard_NoSuchObject;
class Geom2dHatch_Element;
class gp_Pnt2d;
class gp_Lin2d;
class Geom2dAdaptor_Curve;



class Geom2dHatch_Elements 
{
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT Geom2dHatch_Elements();
  
  Standard_EXPORT Geom2dHatch_Elements(const Geom2dHatch_Elements& Other);
  
  Standard_EXPORT   void Clear() ;
~Geom2dHatch_Elements()
{
  Clear();
}
  
  Standard_EXPORT   Standard_Boolean Bind (const Standard_Integer K, const Geom2dHatch_Element& I) ;
  
  Standard_EXPORT   Standard_Boolean IsBound (const Standard_Integer K)  const;
  
  Standard_EXPORT   Standard_Boolean UnBind (const Standard_Integer K) ;
  
  Standard_EXPORT  const  Geom2dHatch_Element& Find (const Standard_Integer K)  const;
 const  Geom2dHatch_Element& operator() (const Standard_Integer K)  const
{
  return Find(K);
}
  
  Standard_EXPORT   Geom2dHatch_Element& ChangeFind (const Standard_Integer K) ;
  Geom2dHatch_Element& operator() (const Standard_Integer K) 
{
  return ChangeFind(K);
}
  
  Standard_EXPORT   Standard_Boolean Reject (const gp_Pnt2d& P)  const;
  
  Standard_EXPORT   Standard_Boolean Segment (const gp_Pnt2d& P, gp_Lin2d& L, Standard_Real& Par) ;
  
  Standard_EXPORT   Standard_Boolean OtherSegment (const gp_Pnt2d& P, gp_Lin2d& L, Standard_Real& Par) ;
  
  Standard_EXPORT   void InitWires() ;
  
  Standard_EXPORT   Standard_Boolean MoreWires()  const;
  
  Standard_EXPORT   void NextWire() ;
  
  Standard_EXPORT   Standard_Boolean RejectWire (const gp_Lin2d& L, const Standard_Real Par)  const;
  
  Standard_EXPORT   void InitEdges() ;
  
  Standard_EXPORT   Standard_Boolean MoreEdges()  const;
  
  Standard_EXPORT   void NextEdge() ;
  
  Standard_EXPORT   Standard_Boolean RejectEdge (const gp_Lin2d& L, const Standard_Real Par)  const;
  
  Standard_EXPORT   void CurrentEdge (Geom2dAdaptor_Curve& E, TopAbs_Orientation& Or)  const;




protected:





private:



  Geom2dHatch_MapOfElements myMap;
  Geom2dHatch_DataMapIteratorOfMapOfElements Iter;
  Standard_Integer NumWire;
  Standard_Integer NumEdge;
  Standard_Integer myCurEdge;


};







#endif // _Geom2dHatch_Elements_HeaderFile
