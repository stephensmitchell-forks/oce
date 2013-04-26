// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _SelectBasics_EntityOwner_HeaderFile
#define _SelectBasics_EntityOwner_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_SelectBasics_EntityOwner_HeaderFile
#include <Handle_SelectBasics_EntityOwner.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
class TopLoc_Location;


//! defines an abstract owner of sensitive primitives. <br>
//!           Owners are typically used to establish a connection <br>
//!           between sensitive entities and high-level objects (e.g. presentations). <br>
//! <br>
//!          Priority : It's possible to give a priority: <br>
//!           the scale : [0-9] ; the default priority is 0 <br>
//!           it allows the predominance of one selected object upon <br>
//!           another one if many objects are selected at the same time <br>
//! <br>
//! <br>
//!          example : Selection of shapes : the owners are <br>
//!           selectable objects (presentations) <br>
//! <br>
//!           a user can give vertex priority [3], edges [2] faces [1] shape [0], <br>
//!           so that if during selection one vertex one edge and one face are <br>
//!           simultaneously detected, the vertex will only be hilighted. <br>
class SelectBasics_EntityOwner : public MMgt_TShared {

public:

  //! sets the selectable priority of the owner <br>
        void Set(const Standard_Integer aPriority) ;
  
        Standard_Integer Priority() const;
  
  Standard_EXPORT   virtual  Standard_Boolean HasLocation() const = 0;
  
  Standard_EXPORT   virtual  void SetLocation(const TopLoc_Location& aLoc)  = 0;
  
  Standard_EXPORT   virtual  void ResetLocation()  = 0;
  
  Standard_EXPORT   virtual const TopLoc_Location& Location() const = 0;




  DEFINE_STANDARD_RTTI(SelectBasics_EntityOwner)

protected:

  
  Standard_EXPORT   SelectBasics_EntityOwner(const Standard_Integer aPriority = 0);

Standard_Integer mypriority;


private: 




};


#include <SelectBasics_EntityOwner.lxx>



// other Inline functions and methods (like "C++: function call" methods)


#endif
