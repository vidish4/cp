       *        *
       **      **
       * *    * *
       *  *  *  *
       *   **   *
       *   **   *
       *  *  *  *
       * *    * *
       **      **
       *        *
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=0;
    int p=n-2;
    for (int i=1;i<n+1;i++)
    {
        if (i<=n/2)
        {
            if (i==1)
            {
                cout<<"*";
                for (int j=0;j<p;j++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
                p=p-2;
            }
            else
            {
                cout<<"*";
                for (int j=1;j<m;j++)
                {
                    cout<<" ";
                }
                cout<<"*";
                for (int j=0;j<p;j++)
                {
                    cout<<" ";
                }
                cout<<"*";
                for (int j=1;j<m;j++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
                p=p-2;
            }
            m++;
        }
        else
        {
            p=p+2;
            m--;
            if (i!=n)
            {
                cout<<"*";
                for (int j=1;j<m;j++)
                {
                    cout<<" ";
                }
                cout<<"*";
                for (int j=0;j<p;j++)
                {
                    cout<<" ";
                }
                cout<<"*";
                for (int j=1;j<m;j++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
            else
            {
                cout<<"*";
                for (int j=0;j<p;j++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
        }
    }