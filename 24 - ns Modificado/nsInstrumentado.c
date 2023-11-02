#include <avr/io.h>
#include <stdio.h>
#include "avr-tick-counter.h"
#define special_output_port (*((volatile char *)0x20))
int virtual_putchar(char c, FILE *unused)
{
    special_output_port = c;
    return 0;
}
 FILE virtual_port = FDEV_SETUP_STREAM(virtual_putchar, NULL, _FDEV_SETUP_WRITE);
int keys[2][2][5][5] =
{
  {
    {
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    },
    {
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0},
      {0,0,0,0,0}
    }
  },
  {
    {
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,1}
    },
    {
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,1},
      {1,1,1,1,400}
    }
  }
};
int answer[2][2][5][5] =
{
  {
    {
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123}
    },
    {
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123},
      {123,123,123,123,123}
    }
  },
  {
    {
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234}
    },
    {
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234},
      {234,234,234,234,234}
    }
  }
};
int foo(int x){
  int i,j,k,l;
StartTickCounter();
  for(i=0; i<2; i++){
            
StopTickCounter();
            printf("foo::bb0 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
    for(j=0 ; j<2 ; j++){
            
StopTickCounter();
            printf("foo::bb2 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
      for(k=0 ; k<5 ; k++){
            
StopTickCounter();
            printf("foo::bb5 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
                for(l=0 ; l<5 ; l++){
            
StopTickCounter();
            printf("foo::bb8 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
          if( keys[i][j][k][l] == x ){
            
StopTickCounter();
            printf("foo::bb11 %u\r\n", GetTicks());
            ResetTickCounter();
            
StartTickCounter();
              return answer[i][j][k][l] + keys[i][j][k][l];
           
            }
            
StopTickCounter();
            ResetTickCounter();
            printf("foo::bb33 0\r\n");
            StartTickCounter();        }
            
StopTickCounter();
            ResetTickCounter();
            printf("foo::bb36 0\r\n");
            StartTickCounter();      }
            
StopTickCounter();
            ResetTickCounter();
            printf("foo::bb39 0\r\n");
            StartTickCounter();    }
            
StopTickCounter();
            ResetTickCounter();
            printf("foo::bb42 0\r\n");
            StartTickCounter();  }
            
StartTickCounter();
  return -1;
            
StopTickCounter();
            printf("foo::bb45 %u\r\n", GetTicks());
            ResetTickCounter();
            
StopTickCounter();
            ResetTickCounter();
            printf("foo::bb46 0\r\n");
            StartTickCounter();}
int main(void){
  stdout = &virtual_port;
  foo(400);
  StopTickCounter();
            printf("foo::bb19 %u\r\n", GetTicks());
            ResetTickCounter();
  return 0;
}