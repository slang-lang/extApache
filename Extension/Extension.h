
#ifndef Slang_Extensions_Apache_ApacheExtension_h
#define Slang_Extensions_Apache_ApacheExtension_h


// Library includes

// Project includes
#include <Core/Extensions/AExtension.h>
#include "Defines.h"

// Forward declarations

// Namespace declarations


namespace Apache {


class Extension : public Slang::Extensions::AExtension
{
public:
	Extension();
    ~Extension() = default;

	void initialize( Slang::Extensions::ExtensionNamespace* scope );
	void provideMethods( Slang::Extensions::ExtensionMethods& methods );
};


}


#endif
