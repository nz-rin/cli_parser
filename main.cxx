#include "cli_parser.hxx"

#include <iostream>

int main(int argc, const char *argv[]){

	if(argc < 3){
		std::cout << "[Error] Insufficient arguments and parameters" << std::endl;
	}

	for(size_t i = 0; i < argc; i++){
		if(cli::string_test_start(argv[i], '-')){
			switch(cli::map_query(argv[i]) ){

				case cli::arg_type::PRINT :
					std::cout << argv[++i] << "\n";
					break;

				case cli::arg_type::NARG :
					std::cout << "Invalid argument: " << argv[i] << "\n";
					return EXIT_FAILURE;
			}
		}
	}

	std::cout << "Run successfull" << std::endl;
}
