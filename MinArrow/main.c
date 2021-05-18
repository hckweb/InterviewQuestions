#include "stdio.h"
#include "string.h"

int solution(const char* data)
{
    if (data == NULL)
        return 0;

    size_t len = strlen(data);

    if (!len)
        return 0;

    unsigned int array[4] = { 0 };
    unsigned int max;

    for (size_t i = 0; i < len; ++i) {

        unsigned int index;

        if (data[i] == '^')
            index = 0;
        else if (data[i] == 'v')
            index = 1;
        else if (data[i] == '<')
            index = 2;
        else if (data[i] == '>')
            index = 3;
        else
            return -1; //Not specific char

        ++array[index];

        if ((i == 0) || ((max != index) && (array[index] > array[max])))
            max = index;
    }

    return (int)len - (int)array[max];
}

int main()
{
    int result = solution("^vv<v");

    if (result < 0)
        printf("Error no: %d", result);
    else
        printf("%i", result);
}