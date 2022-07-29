           *      *
         *   *  *   *
       *      *      *
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=1;
    int p=2*n-3;
    for (int i=1;i<n+1;i++)
    {
        if ((i>1)&&(i<n))
        {
            for (int j=1;j<n-i+1;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int j=0;j<m;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            p=p-2;
            for (int j=0;j<p;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int j=0;j<m;j++)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
            m=m+2;
        }
        else if (i==1)
        {
            for (int j=1;j<n-i+1;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            for (int j=0;j<2*n-3;j++)
            {
                cout<<" ";
            }
            cout<<"*"<<endl;
            
        }
        else if (i==n)
        {
            for (int j=0;j<3;j++)
            {
                cout<<"*";
                for (int j=0;j<2*n-3;j++)
                {
                    cout<<" ";
                }
            }
            cout<<endl;
        }
    }