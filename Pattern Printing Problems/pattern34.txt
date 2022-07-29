       E D C B A
       D C B A
       C B A
       B A
       A
    cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n-i;j++)
        {
            cout<<char('E'-i-j)<<" ";
        }
        cout<<endl;
    }