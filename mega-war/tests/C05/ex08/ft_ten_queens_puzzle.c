#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex08/ft_ten_queens_puzzle.c"
#include "../../../utils/constants.h"

#include <unistd.h>
int run_test()
{
    // Flush the standard output buffer
    fflush(stdout);

    // Redirect the output to a file
    int saved_stdout = dup(STDOUT_FILENO);
    int output_fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    dup2(output_fd, STDOUT_FILENO);
    close(output_fd);

    // Call the function to be tested
    int result = ft_ten_queens_puzzle();

    // Restore the original output
    fflush(stdout);
    dup2(saved_stdout, STDOUT_FILENO);
    close(saved_stdout);

    // Open the output file and count the number of result

    // Check that the number of result matches the expected value
    int expected = 724;
    if (result != expected)
    {
        printf("    " RED "[1] Number of solutions Expected %d, got %d\n", expected, result);
        return -1;
    }
    else
    {
        printf("  " GREEN CHECKMARK GREY " [1] Number of solutions Expected %d, got %d\n" DEFAULT, expected, result);
        return 0;
    }
}

int main(void)
{
    return run_test();
}