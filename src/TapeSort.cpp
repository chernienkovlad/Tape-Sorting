#include "TapeSort.hpp"

#define TMP_TAPES_DIR "tmp/"

void TapeSort::external_merge_sort(std::string input_file_path, std::string output_file_path, ConfigParam& config_param)
{
    Tape input_tape(input_file_path);
    unsigned long memory_capacity = config_param.get_memory_size_in_bytes() / sizeof(int);

    std::vector<int> main_memory(memory_capacity);

    unsigned long input_tape_capacity = input_tape.capacity();
    unsigned long tape_numbers = 1;

    while (input_tape_capacity > memory_capacity)
    {
        Tape tmp_tape = create_sorted_tape(input_tape, main_memory, memory_capacity);
        tmp_tape.tape_to_file(static_cast<std::string>(TMP_TAPES_DIR) + "tmp_tape_" + std::to_string(tape_numbers++) + ".txt");

        input_tape_capacity -= memory_capacity; 
    }

    Tape tmp_tape = create_sorted_tape(input_tape, main_memory, input_tape_capacity);
    tmp_tape.tape_to_file(static_cast<std::string>(TMP_TAPES_DIR) + "tmp_tape_" + std::to_string(tape_numbers) + ".txt");

    std::string tape_name(static_cast<std::string>(TMP_TAPES_DIR) + "tmp_tape_1");
    for (unsigned long i = 1; tape_numbers != 1; i ++)
    {
        Tape tmp_tape_1(tape_name + ".txt");
        Tape tmp_tape_2(static_cast<std::string>(TMP_TAPES_DIR) + "tmp_tape_" + std::to_string(i + 1) + ".txt");

        Tape merged_tape = merge_tapes(tmp_tape_1, tmp_tape_2);
        tape_name = tape_name + "_" + std::to_string(i + 1);
        merged_tape.tape_to_file(tape_name + ".txt");

        tape_numbers--;
    }

    Tape output_tape(tape_name + ".txt");
    output_tape.tape_to_file(output_file_path);
}

Tape TapeSort::create_sorted_tape(Tape& input_tape, std::vector<int>& main_memory, unsigned long size)
{
    for (unsigned long i = 0; i < size; i++)
    {
        main_memory[i] = input_tape.read();
        input_tape.shift_forward();
    }

    if (main_memory.capacity() > size)
    {
        std::sort(main_memory.begin(), main_memory.end() - main_memory.capacity() + size);
    }
    else
    {
        std::sort(main_memory.begin(), main_memory.end());
    }

    Tape tmp_tape(size);

    for (unsigned long i = 0; i < size; i++)
    {
        tmp_tape.write(main_memory[i]);
        tmp_tape.shift_forward();
    }

    return tmp_tape;
}

Tape TapeSort::merge_tapes(Tape& tape1, Tape& tape2)
{
    Tape tmp_tape(tape1.capacity() + tape2.capacity());

    while (!tape1.is_out_of_bounds() && !tape2.is_out_of_bounds())
    {
        if (tape1.read() > tape2.read())
        {
            tmp_tape.write(tape2.read());
            tmp_tape.shift_forward();
            tape2.shift_forward();
        }
        else
        {
            tmp_tape.write(tape1.read());
            tmp_tape.shift_forward();
            tape1.shift_forward();
        }
    }

    if (tape1.is_out_of_bounds())
    {
        while (!tape2.is_out_of_bounds())
        {
            tmp_tape.write(tape2.read());
            tmp_tape.shift_forward();
            tape2.shift_forward();
        }
    }
    else
    {
        while (!tape1.is_out_of_bounds())
        {
            tmp_tape.write(tape1.read());
            tmp_tape.shift_forward();
            tape1.shift_forward();
        }
    }

    return tmp_tape;
}