       1
       2  3
       4  5  6
       7  8  9  10
       11 12 13 14 15
cout<<"Enter n: ";
    int n;
    cin>>n;
    int a=1;
    for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<i+1;j++)
        {
            cout<<a<<" ";
            a++;
        }
        cout<<endl;
    }