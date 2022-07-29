         4 4 4 4 4 4 4  
         4 3 3 3 3 3 4   
         4 3 2 2 2 3 4   
         4 3 2 1 2 3 4   
         4 3 2 2 2 3 4   
         4 3 3 3 3 3 4   
         4 4 4 4 4 4 4
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=n+1;
    for (int i=0;i<2*n-1;i++)
    {
        int a=n;
        int b=n-i;
        if (i<=n-1)
        {
            m--;
        }
        else
        {
            b=i-n+2;
            m++;
        }
        while (a!=b)
        {
            cout<<a<<" ";
            a--;
        }
        for (int j=0;j<2*m-1;j++)
        {
            cout<<a<<" ";
        }
        while (a!=n)
        {
            a++;
            cout<<a<<" ";
        }
        cout<<endl;
    }
OR (use min distance if index from walls)
    cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=0;i<2*n-1;i++)
    {
        for (int j=0;j<2*n-1;j++)
        {
            cout<<n-min(min(i,j),min(2*n-2-i,2*n-2-j))<<" ";
        }
        cout<<endl;
    }