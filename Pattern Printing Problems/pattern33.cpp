       a
       B c
       D e F
       g H i J
       k L m N o
    cout<<"Enter n: ";
    int n;
    cin>>n;
    int a='a';
    int m=1;
    for (int i=1;i<n+1;i++)
    {
        for (int j=0;j<i;j++)
        {
            if (m%2==0)
            {
                cout<<char(a-32)<<" ";
            }
            else
            {
                cout<<char(a)<<" ";
            }
            a++;
            m++;
        }
        cout<<endl;
    }