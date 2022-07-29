         *
        * *
       *   *
      *     *
     *       *
      *     *
       *   *
        * *
         *
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=2*n-4;
    for (int i=1; i<2*n;i++)
    {
        if (i<=n)
        {
            for (int j=1;j<n-i+1;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            if ((i>1)&&(i<2*n-1))
            {
                for (int k=1;k<2*(i-1);k++)
                {
                    cout<<" ";
                }
                cout<<"*"<<endl;
            }
            else
            {
                cout<<endl;
            }
        }
        else
        {

            for (int l=0;l<i%n;l++)
            {
                cout<<" ";
            }
            cout<<"*";
            if ((i>n)&&(i<2*n-1))
            {
                for (int o=1;o<m;o++)
                {
                    cout<<" ";
                }
                m=m-2;
                cout<<"*"<<endl;
            }
            else
            {
                cout<<endl;
            }
        }
        
    }