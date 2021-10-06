#include<stdio.h>

int mcd(int n1,int n2);

int main ()
{
     printf("%d\n",mcd(9,94521)); 

}

int mcd(int n1,int n2)
{
    if(n2==0)
    {
        return(n1);
    }else
    {
        return(mcd(n2,n1%n2));
    }
}
