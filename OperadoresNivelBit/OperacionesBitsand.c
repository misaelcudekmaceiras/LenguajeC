#include <stdio.h>


int main()
{
    unsigned int v=0;      
    printf("v.: %d\n",v);  
  
    v=31;
    printf("v %d\n",v);
  
    v=v&2;
    printf("v %d\n",v);
  
    v=31;
    v=v&4;
    printf("v %d\n",v);
    
    v=31;
    v=v&8;
    printf("v %d\n",v);
    
    
  return 0;
}
