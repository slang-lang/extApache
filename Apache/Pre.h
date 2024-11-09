
#ifndef Slang_Extensions_Apache_Pre_h
#define Slang_Extensions_Apache_Pre_h


// Library includes

// Project includes
#include "Defines.h"

// Forward declarations

// Namespace declarations
using namespace Slang;


#define APACHEEXT_VARPREFIX '$'

namespace Apache {


class Pre : public Extensions::ExtensionMethod
{
public:
	Pre()
	: ExtensionMethod(nullptr, "pre", Designtime::VoidType::TYPENAME)
	{
		ParameterList params;
		params.push_back(Parameter::CreateDesigntime("text", Designtime::StringType::TYPENAME));

		setSignature(params);
	}

public:
	Runtime::ControlFlow::E execute(Common::ThreadId threadId, const ParameterList& params, Runtime::Object* /*result*/, const Token& token)
	{
		ParameterList list = mergeParameters(params);

		try {
			ParameterList::const_iterator it = list.begin();

			std::string param_text = (*it++).value().toStdString();
			size_t start = 0;

			while ( (start = param_text.find_first_of(APACHEEXT_VARPREFIX, start)) != std::string::npos ) {
				size_t end = param_text.find_first_of(APACHEEXT_VARPREFIX, start + 1);

				if ( end == std::string::npos ) {
					break;
				}

				std::string var = param_text.substr(start + 1, end - start - 1);

				Symbol* symbol = this->resolve(var, false);
				if ( !symbol ) {
					continue;	// skip not-existing symbols
				}
				if ( symbol->getSymbolType() != Symbol::IType::ObjectSymbol ) {
					continue;	// skip symbols with wrong type
				}

				Runtime::Object* tmp = dynamic_cast<Runtime::Object*>(symbol);

				param_text.replace(start, end - start + 1, tmp->getValue().toStdString());
			}

			std::cout << param_text << std::endl;
		}
		catch ( std::exception& e ) {
			Runtime::Object *data = Controller::Instance().repository()->createInstance(Runtime::StringType::TYPENAME, ANONYMOUS_OBJECT);
			*data = Runtime::StringType(std::string(e.what()));

			Controller::Instance().thread(threadId)->exception() = Runtime::ExceptionData(data, token.position());
			return Runtime::ControlFlow::Throw;
		}

		return Runtime::ControlFlow::Normal;
	}
};


}


#endif
