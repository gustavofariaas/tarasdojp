#include<stdio.h>
	void numero (int a[]){
  		int i;
      for (i=0 ; i < 20 ; i++){
  				printf("numero i+1: %d\n", a[i]);
      }
      
    }
    int palinha (int a[]){
    int i;
    for(i=0 ; i<20 ; i++){
    if (a[i] == a[19-i])
        return 1;
    else
        return 0;
    }
    }
  int main(void){
  
  
      int num[20],i;
  		for (i=0 ; i<20 ; i++){    
          printf("Informe um número %d:\n", i+1);  
          scanf("%d", &num[i]);
						if(num[i]<1 || num[i]>5){	
            	printf("Numero invalido\n\n");
              i--;
            }
            }
            	
            
            numero(num);
 	 
  
  		 
  
return 0;
  }
