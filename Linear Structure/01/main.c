#include "list.h"

int main()
{
    PNode L1, L2, L;P
    Read(&L1);
    Read(&L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}


