#include "headers.h"

int main(int argc, char **argv)
{
    condition = window_making();
    setup();
    while (condition)
    {
        process_inpute();
        update();
        render();
    }
    cleaning();
    return 0;
}