    	 *****
       *   *
       *   *
       *   *
       *****
cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        if ((i>0)&&(i<n-1))
        {
            cout<<"*";
            for (int j=0;j<n-2;j++)
            {
                cout<<" ";
            }
            cout<<"*";
            cout<<endl;
        }
        else
        {
            for (int j=0;j<n;j++)
            {
                cout<<"*";
            }
            cout<<endl;
        }
    }