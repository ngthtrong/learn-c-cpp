int choosePivot(int A[], int low, int high)
{
    int i = low;
    while (A[i] < A[i + 1] && i < high - 1)
    {
        i++;
    }
    if(i==high) return -1;


    return i;
}