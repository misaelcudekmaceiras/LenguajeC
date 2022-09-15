#include<stdio.h>
#include<math.h>

int deciAbin(int n);

int main ()
{
     printf("%d\n",deciAbin(255)); 

}

int deciAbin(int n)
{   static int cifras=0;
    
    int result=0;
    if(n==1)
    {
        cifras++;

        return(n*pow(10,cifras-1));
    }else
    {   
        result=n%2;
        n=n/2;

        cifras++;
        return(result*pow(10,cifras-1) + deciAbin(n) );
    }
}
