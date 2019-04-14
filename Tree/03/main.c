#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001
#define MINH -1001

int H[MAXN], size;

void createH();
void insert(int v);

void createH()
{
    size = 0;
    H[size] = MINH;
}

void insert(int v)
{
    int i;
    for(i = ++size; H[i/2] > v; i /= 2)
        H[i] = H[i/2];
    H[i] = v;
}

int main()
{
    int i, j, m, n, v;
    createH();
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &v);
        insert(v);
    }

    for(j = 0; j < m; j++)
    {
        scanf("%d", &v);
        while(v)
        {
            printf("%d ", H[v]);
            v /= 2;
        }
        printf("\n");
    }
    return 0;
}
