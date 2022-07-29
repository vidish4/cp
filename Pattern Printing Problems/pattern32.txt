       E
       D E
       C D E
       B C D E
       A B C D E
    cout<<"Enter n: ";
    int n;
    cin>>n;
    for (int i=1;i<n+1;i++)
    {
        for (int j=0;j<i;j++)
        {
            cout<<char('E'-i+j+1)<<" ";
        }
        cout<<endl;
    }