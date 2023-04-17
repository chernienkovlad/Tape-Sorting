#include "Init.hpp"
#include "Tape.hpp"
#include "TapeSort.hpp"

#define CONFIG_FILES_DIR "config/"

int main(int argc, char* argv[])
{
    std::string input_file_path(argv[1]);
    std::string output_file_path(argv[2]);

    ConfigParam config_param(CONFIG_FILES_DIR);

    TapeSort::external_merge_sort(input_file_path, output_file_path, config_param);

    return 0;
}