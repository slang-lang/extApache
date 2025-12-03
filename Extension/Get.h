
#ifndef Extensions_Apache_Get_h
#define Extensions_Apache_Get_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Apache {


class Get : public Extensions::ExtensionMethod
{
public:
	Get()
	: ExtensionMethod(nullptr, "get", Designtime::StringType::TYPENAME)
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

		std::string result_value;

		auto getIt = mGetQueryString.find(param_name);
		if ( getIt != mGetQueryString.end() ) {
			result_value = getIt->second;
		}

		*result = Runtime::StringType(result_value);

		return Runtime::ControlFlow::Normal;
	}
};


}

#endif
