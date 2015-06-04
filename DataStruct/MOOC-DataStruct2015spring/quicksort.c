#define LT(a,b)         ((a) < (b) ? (1) : (0))
#define compare(a,b)     LT(a,b)
#define swap(a,b)        do{a = a+b;b=a-b;a=a-b;}while(0)


void quickSort(int a[], int n)
{
    int v, i, j;
    
    if(n <= 100)
    {
        //insert sort
        for(i = 1; i < n; i += 1)
        {
            v = a[i];
            
            //find insert pos
            for(j = i - 1; j >= 0 && compare(v,a[j]); j -= 1)
                swap(a[j+1],a[j]);
            
            a[j+1] = v;
        }
        return ;
    }    
    
    i = 0, j = n - 1;
    
    if(a[i] < a[(i+j)/2]) swap(a[i],a[(i+j)/2]);
    if(a[(i+j)/2] < a[j]) swap(a[j],a[(i+j)/2]);
    if(a[(i+j)/2] < a[i]) swap(a[i],a[(i+j)/2]);
    
    v = a[0];
    while(i < j)
    {
        while( i < j && v <= a[j])
        {
            --j;
            if(i< j && a[j+1] < a[j])
            {
                swap(a[j+1],a[j]);
            }
        }
        a[i] = a[j];    
        
        while(i < j && a[i] <= v)
        {
            ++i;
            if(i < j && a[i] < a[i-1])
            {
                swap(a[i],a[i-1]);
            }
        }
        a[j] = a[i];
    }
    
    a[i] = v;            
    quickSort(a,i);//[0,i)
    quickSort(a+i+1,n-i-1);//[i+1,n)
}
