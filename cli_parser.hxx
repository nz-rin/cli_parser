#ifndef CLI_PARSER_HXX
#define CLI_PARSER_HXX

#include <string_view>
#include <string>
#include <unordered_map>

namespace cli{

	//enum that represent a arguments/parameters/flags, usefull for switch statements
	enum arg_type{
		PRINT,
		NARG
	};

	//add ur arguments/parameters/flags etc. here and their respective enums
	inline const std::unordered_map<std::string_view, arg_type> map = {
		{"--print", arg_type::PRINT}
	};

	bool string_test_start(const char *string, char test);

	arg_type map_query(std::string_view possible_arg);

#ifdef CLIP_IMPL
	//test the start of a string for a character
	bool string_test_start(const char *string, char test){
		return string[0] == test;
	}

	//test the start of a string for a character
	bool string_test_start(const std::string &string, char test){
		return string[0] == test;
	}

	//returns the enum corresponding with the checked argument if it exists
	//otherwise it returns the default enum NARG representing that the checked arg isn't in the map if args
	arg_type map_query(std::string_view possible_arg){
		auto _result = map.find(possible_arg);
		if ( _result == map.end()){
			return arg_type::NARG;
		}else{
			return _result->second;
		}
	}
#endif
}
#endif
