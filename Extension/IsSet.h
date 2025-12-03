
#ifndef Extensions_Apache_IsSet_h
#define Extensions_Apache_IsSet_h


// Library includes

// Project includes
#include <Core/Runtime/BuildInTypes/BoolType.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Apache {


class IsSet : public Extensions::ExtensionMethod
{
public:
	IsSet()
	: ExtensionMethod(nullptr, "isSet", Designtime::BoolType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("name", Designtime::StringType::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute( const ParameterList &params, Runtime::Object *result )
	{
		ParameterList list = mergeParameters(params);

		ParameterList::const_iterator it = list.begin();

		auto param_name = (*it++).value().toStdString();

		readGetData();
		readPostData();

		bool result_value = false;
		if ( mGetQueryString.find(param_name) != mGetQueryString.end() ) {
			result_value = true;
		}
		else if ( mPostQueryString.find(param_name) != mPostQueryString.end() ) {
			result_value = true;
		}

		*result = Runtime::BoolType(result_value);

		return Runtime::ControlFlow::Normal;
	}
};


}

#endif
