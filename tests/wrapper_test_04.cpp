#include "Halide.h"
#include "wrapper_test_04.h"

#include <coli/utils.h>
#include <cstdlib>
#include <iostream>

#define NN 1000
#define MM 1000

int main(int, char**)
{
    buffer_t reference_buf = allocate_2D_buffer(NN, MM);
    init_2D_buffer_val(&reference_buf, NN, MM, 20);

    buffer_t output_buf = allocate_2D_buffer(NN, MM);

    init_2D_buffer_val(&output_buf, NN, MM, 99);
    test_let_stmt(&output_buf);
    compare_2_2D_arrays("test_let_stmt",
                        output_buf.host, reference_buf.host, NN, MM);

    return 0;
}