// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _IGESGraph_HighLight_HeaderFile
#define _IGESGraph_HighLight_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_IGESGraph_HighLight_HeaderFile
#include <Handle_IGESGraph_HighLight.hxx>
#endif

#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _IGESData_IGESEntity_HeaderFile
#include <IGESData_IGESEntity.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif


//! defines IGESHighLight, Type <406> Form <20> <br>
//!          in package IGESGraph <br>
//! <br>
//!          Attaches information that an entity is to be <br>
//!          displayed in some system dependent manner <br>
class IGESGraph_HighLight : public IGESData_IGESEntity {

public:

  
  Standard_EXPORT   IGESGraph_HighLight();
  //! This method is used to set the fields of the class <br>
//!           HighLight <br>
//!      - nbProps          : Number of property values (NP = 1) <br>
//!      - aHighLightStatus : HighLight Flag <br>
  Standard_EXPORT     void Init(const Standard_Integer nbProps,const Standard_Integer aHighLightStatus) ;
  //! returns the number of property values in <me> <br>
  Standard_EXPORT     Standard_Integer NbPropertyValues() const;
  //! returns 0 if <me> is not highlighted(default), <br>
//!         1 if <me> is highlighted <br>
  Standard_EXPORT     Standard_Integer HighLightStatus() const;
  //! returns True if entity is highlighted <br>
  Standard_EXPORT     Standard_Boolean IsHighLighted() const;




  DEFINE_STANDARD_RTTI(IGESGraph_HighLight)

protected:




private: 


Standard_Integer theNbPropertyValues;
Standard_Integer theHighLight;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif
