          *****
         *   *
        *   *
       *   *
      *****

for (int i=1;i<n+1;i++)
    {
        for (int j=1;j<n-i+1;j++)
        {
            cout<<" ";
        }
        if ((i>1)&&(i<n))
        {
            cout<<"*";
            for (int j=0;j<n-2;j++)
            {
                cout<<" ";
            }
            cout<<"*";
        }
        else
        {
            for (int j=0;j<n;j++)
            {
                cout<<"*";
            }
        }
        cout<<endl;
    }