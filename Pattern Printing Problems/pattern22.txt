       1
       0 1
       1 0 1
       0 1 0 1
       1 0 1 0 1
cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<i+1;j++)
        {
            if ((i+j)%2==0)
            {
                cout<<"1 ";
            }
            else if((i+j)%2==1)
            {
                cout<<"0 ";
            }
        }
        cout<<endl;
    }