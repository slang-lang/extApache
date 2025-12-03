
#ifndef Extensions_Apache_Types_h
#define Extensions_Apache_Types_h


// Library includes
#include <map>
#include <string>

// Project includes

// Forward declarations

// Namespace declarations


namespace Apache {


extern const char* CONTENT_LENGTH;
extern const char* QUERY_STRING;
extern const char* REQUEST_METHOD;


typedef std::map<std::string, std::string> StringMap;


extern StringMap mGetQueryString;
extern StringMap mPostQueryString;


void readGetData();
void readPostData();
std::string UriDecode(const std::string & sSrc);
std::string UriEncode(const std::string & sSrc);


}


#endif
