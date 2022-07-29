         *
        * *
       * * *
      * * * *
     * * * * *
      * * * *
       * * *
        * *
         *
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=0;
    for (int i=1;i<n+1;i++)
    {
        if(i<=(n+1)/2)
        {
            m++;
            for (int j=1;j<(n+1)/2-i+1;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<m;j++)
            {
                cout<<"* ";
            }
            cout<<endl;
        }
        else
        {
            m--;
            for (int j=1;j<i-((n+1)/2)+1;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<m;j++)
            {
                cout<<"* ";   
            }
            cout<<endl;
        }
    }
OR
cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=1;i<2*n;i++)
    {
        int c=i;
        if (i>n)
        {
            c=i-2*(i%n);
        }
        for (int j=0;j<n-c;j++)
        {
            cout<<" ";
        }
        for (int j=0;j<c;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }