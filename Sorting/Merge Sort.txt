Merge Sort
void merge (int arr[], int l, int m, int r)
{
    int temp[r+1];
    int i=l,j=m+1,k=l;
    while ((i<=m)&&(j<=r))
    {
        if (arr[i]<arr[j])
        {
            temp[k]=arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while (i<=m)
    {
        temp[k]=arr[i];
        i++;
        k++;
    }
    while (j<=r)
    {
        temp[k]=arr[j];
        j++;
        k++;
    }
    for (int p=l;p<=r;p++)
    {
        arr[p]=temp[p];
    }
}
void MergeSort(int arr[], int i, int j)
{
    if (i<j)
    {
        int m=(i+j)/2;
        MergeSort(arr,i,m);
        MergeSort(arr,m+1,j);
        merge (arr,i,m,j);
    }
}