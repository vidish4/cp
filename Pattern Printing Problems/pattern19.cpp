    	 *        *
       **      **
       ***    ***
       ****  ****
       **********
       ****  ****
       ***    ***
       **      **
       *        *
cout<<"Enter n: ";
    int n;
    cin>>n;
    int m=n;
    for (int i=0;i<2*n;i++)
    {
        if (i<n)
        {
            int s=m-1;    //s=number of holes
            for (int j=0;j<n-s;j++)
            {
                cout<<"*";
            }
            for (int j=0;j<2*s;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<n-s;j++)
            {
                cout<<"*";
            }
            m=m-1;
            cout<<endl;
        }
        else
        {
            int s=i%n;
            for (int j=0;j<n-s;j++)
            {
                cout<<"*";
            }
            for (int j=0;j<2*s;j++)
            {
                cout<<" ";
            }
            for (int j=0;j<n-s;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }