	 1      1
       12    21
       123  321
       12344321


cout<<"Enter n: ";
    int n;
    cin>>n;
    int p=2*(n-1);
    for (int i=1;i<n+1;i++)
    {
        int a=1;
        for (int j=0;j<i;j++)
        {
            cout<<a++;
        }
        for (int j=0;j<p;j++)
        {
            cout<<" ";
        }
        for (int j=0;j<i;j++)
        {
            cout<<--a;
        }
        cout<<endl;
        p=p-2;
    }