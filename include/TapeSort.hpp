#ifndef TAPESORT_H_
#define TAPESORT_H_

#include <algorithm>

#include "Tape.hpp"
#include "Init.hpp"

class TapeSort
{
    public:
        static void external_merge_sort(std::string input_file_path, std::string output_file_path, ConfigParam& config_param);

    private:
        static Tape create_sorted_tape(Tape& input_tape, std::vector<int>& main_memory, unsigned long size);
        static Tape merge_tapes(Tape& tape1, Tape& tape2);
};

#endif // TAPESORT_H_