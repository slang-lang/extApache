
// Header
#include "Extension.h"

// Library includes
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>

// Project includes
#include "Defines.h"
#include "Get.h"
#include "IsSet.h"
#include "Post.h"
#include "Pre.h"
#include "Types.h"

// Namespace declarations


namespace Apache {


Extension::Extension()
: AExtension( "extApache", "0.4.1" )
{
}

void Extension::initialize( Slang::Extensions::ExtensionNamespace* /*scope*/ )
{
}

void Extension::provideMethods( Slang::Extensions::ExtensionMethods& methods )
{
	assert( methods.empty() );

	methods.push_back( new Get() );
	methods.push_back( new IsSet() );
	methods.push_back( new Post() );
	methods.push_back( new Pre() );
}


}


extern "C" Slang::Extensions::AExtension* factory( void ) {
	return dynamic_cast<Slang::Extensions::AExtension*>( new Apache::Extension() );
}
