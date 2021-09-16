#include <stdio.h>


int main()
{
    unsigned short int v=0;      
    printf("v.: %u\n",v);  
  
    v=~0;
    printf("v %u\n",v);
  
    v=v&(~2);
    printf("v %u\n",v);
  
    v=0;
    v=v|(~65535);
    printf("v %u\n",v);
    
  
    
    
  return 0;
}
