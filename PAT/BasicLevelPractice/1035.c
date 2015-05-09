#include <stdio.h>

int Insertion_Sort(int a[], int n, int s[])
{
    int i, j, k, element, flag = 0;
    
    for(i = 1; i < n; i++)
    {
        element = a[i];
        
        // find insert point
        j = 0;
        while( j < i && a[j] < element)
        {
            j++;
        }
        
        // move a[j, i-1] to a[ j+1, i] 
        for(k = i; k > j; k--)
            a[k] = a[k -1];
        
        // insert element to a[j]    
        a[j] = element;
        
        //is insert sort ?
        if(flag)
        {
            printf("Insertion Sort\n");
            for(j = 0; j < n; j++)
            {
                printf("%d%c",a[j], j == n-1? '\n':' ');
            }
            return 1;
        }
        else
        {
            for(j = 0; j < n; j++)
            {
                if(a[j] != s[j]) break;
            }
            
            if( j == n) flag = 1;
        }
    }        
    return 0; 
}

void merge(int a[], int lena, int b[], int lenb)
{
    int i = 0, j = 0, k = 0;
    int c[100];
    while( i < lena && j < lenb)
    {
        if(a[i] < b[j])
        {
            c[k] = a[i];
            i++;
            k++;
        }
        else 
        {
            c[k] = b[j];
            j++;
            k++;    
        }
    }
    
    while (i < lena) {
        c[k++] = a[i++];
    }
    while (j < lenb) {
        c[k++] = b[j++];
    }
    
    for(i = 0; i < lena + lenb; i++)
    {
        a[i] = c[i];
    }
}

int Merge_Sort(int a[], int n, int s[])
{
    int sublen = 1, i, j, flag = 0;
    
    for(sublen = 1; sublen <= n/2; sublen *= 2)
    {
        for(i = 0; i < n - 2*sublen; i += 2*sublen)
        {
            merge(a + i, sublen, a + i + sublen, sublen);
        }
        if( i + sublen < n)
        {
            merge(a + i, sublen, a + i + sublen, n - i - sublen);
        }
        
        if(flag)
        {
            printf("Merge Sort\n");
            for(j = 0; j < n; j++)
            {
                printf("%d%c",a[j], j == n-1? '\n':' ');
            } 
            return 1;
        }
        else 
        {
            for(j = 0; j < n; j++)
            {
                if(a[j] != s[j]) break;
            } 
            if(j == n) flag = 1;
        }
   
    }
    return 0;
}

int main(int argc, char *argv[]) 
{
    int n, i, a[100], b[100],s[100];
    scanf("%d", &n);
    
    
    for (i = 0; i < n; i++) {
        scanf("%d", a+i);
        b[i] = a[i];
    }
    
    for (i = 0; i < n; i++) {
        scanf("%d", s+i);
    }
    
    if(!Insertion_Sort(a,n,s))
    {
        Merge_Sort(b,n,s);
    }
}