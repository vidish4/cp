 	   1
        212
       32123
      4321234
       32123
        212
         1
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=-1;
    for (int i=1;i<2*n;i++)
    {
        if (i<=n)
        {
            m=m+2;
            int o=i;
            for (int j=1;j<n-i+1;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<(m+1)/2;j++)
            {
                cout<<o--;
            }
            o++;
            for (int j=0;j<(m-1)/2;j++)
            {
                cout<<++o;
            }
            cout<<endl;
        }
        else
        {
            m=m-2;
            int o=n-(i%n);
            for (int j=0;j<i%n;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<(m+1)/2;j++)
            {
                cout<<o--;
            }
            o++;
            for (int j=0;j<(m-1)/2;j++)
            {
                cout<<++o;
            }
            cout<<endl;
        }
        
    }