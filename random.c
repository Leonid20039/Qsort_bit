// 112-Чудновский-Леонид
#include <stdlib.h>
int random(int Low, int High){
    return ((int)rand() * (High-Low))/
(int)RAND_MAX + Low;
}