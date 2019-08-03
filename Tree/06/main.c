#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int getLeftTreeNum(int n)
{
    /*
     * 1、层数公式：H = ⌊log(N+1)⌋
     * 2、完全二叉树下的节点数：X = N - 2^H + 1
     * 3、左子树节点数：2^(H-1) - 1 + X
     *
     */

    //获取完全二叉树层数
    double dH = log(n+1)/log(2);
    int iH = floor(dH);

    //求出完全二叉树下的节点
    int iX = n - (int)pow(2, iH) + 1;

    //比较大小，取得正确节点数
    iX = ((iX < (int)pow(2, iH-1)) ? iX : (int)pow(2,iH-1));

    //得出正确左子树数量
    int iLTreeNum = (int)pow(2, iH-1) - 1 + iX;

    return iLTreeNum;
}


int TRe[10];
int arr[10]= {0,3,2,1,5,6,7,4,8,9};
void solve(int ALeft, int ARight, int TRoot)
{
    int N = ARight - ALeft + 1;
    if(N == 0) return;
    int L = getLeftTreeNum(N);
    TRe[TRoot] = arr[ALeft + L];

    int LeftRoot = 2 * TRoot + 1;
    int RightRoot = LeftRoot + 1;

    solve(ALeft, ALeft + L -1, LeftRoot);
    solve(ALeft + L + 1, ARight, RightRoot);
}

int main()
{
    int i = 0;
    qsort(arr, 10, sizeof(int), compare);
    for(i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    printf("\n");
    solve(0, 9, 0);
    for(i = 0; i < 10; i++)
        printf("%d ", TRe[i]);
    printf("\n");
    return 0;
}
