// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _CDF_MetaDataDriverFactory_HeaderFile
#define _CDF_MetaDataDriverFactory_HeaderFile

#include <Standard.hxx>
#include <Standard_DefineHandle.hxx>
#include <Handle_CDF_MetaDataDriverFactory.hxx>

#include <Standard_Transient.hxx>
#include <Handle_CDF_MetaDataDriver.hxx>
class CDF_MetaDataDriver;



class CDF_MetaDataDriverFactory : public Standard_Transient
{

public:

  
  Standard_EXPORT virtual   Handle(CDF_MetaDataDriver) Build()  const = 0;




  DEFINE_STANDARD_RTTI(CDF_MetaDataDriverFactory)

protected:




private: 




};







#endif // _CDF_MetaDataDriverFactory_HeaderFile
