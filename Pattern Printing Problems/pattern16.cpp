int factorial  (int n)
{
    int a=1;
    for (int i=1;i<n+1;i++)
    {
        a=a*i;    
    }
    return a;
}
int c(int n, int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
int main()
{
    cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=1; i<n+1;i++)
    {
        for (int j=1;j<n-i+1;j++)
        {
            cout<<" ";
        }
        for (int k=0;k<i;k++)
        {
            cout<<c(i-1,k)<<" ";
        }
        cout<<endl;
    }