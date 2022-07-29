int partition (int arr[],int s,int e)
{
    int pivot=arr[e];
    int pindex=s;
    for (int i=s;i<e;i++)
    {
        if (arr[i]<=pivot)
        {
            int t=arr[i];
            arr[i]=arr[pindex];
            arr[pindex]=t;
            pindex++;
        }
    }
    int t=arr[pindex];
    arr[pindex]=arr[e];
    arr[e]=t;
    return pindex;
}
void Quicksort (int arr[], int s, int e)
{
    if (s<e)
    {
        int p=partition(arr,s,e);
        Quicksort(arr,s,p-1);
        Quicksort(arr,p+1,e);
    }
}