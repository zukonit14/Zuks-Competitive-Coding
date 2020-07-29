    ll max_so_far=-2e18,max_ending_here=0;
    forci(0,n)
    {
        max_ending_here=max_ending_here+a[i];
        if(max_ending_here<0)   max_ending_here=0;  //again reinitialising it to zero
        if(max_so_far<max_ending_here)  max_so_far=max_ending_here; //updating answer
    }
    cout<<max_so_far;
