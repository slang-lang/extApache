
#ifndef Slang_Extensions_Apache_Post_h
#define Slang_Extensions_Apache_Post_h


// Library includes
#include <cstdlib>

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


namespace Apache {


class Post : public Extensions::ExtensionMethod
{
public:
	Post()
	: ExtensionMethod(nullptr, "post", Designtime::StringType::TYPENAME)
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

		readPostData();

		std::string result_value;

		auto postIt = mPostQueryString.find(param_name);
		if ( postIt != mPostQueryString.end() ) {
			result_value = postIt->second;
		}

		*result = Runtime::StringType(result_value);

		return Runtime::ControlFlow::Normal;
	}
};


}

#endif
