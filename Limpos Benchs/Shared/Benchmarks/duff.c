/*#define ARRAYSIZE  100
/*#define INVOCATION_COUNT 43	/* exec time depends on this one! */


void duffcopy( char *to, char *from, int count)
{
  int n=(count+7)/8;
  switch(count%8){
  case 0: do{     *to++ = *from++;
  case 7:         *to++ = *from++;
  case 6:         *to++ = *from++;
  case 5:         *to++ = *from++;
  case 4:         *to++ = *from++;
  case 3:         *to++ = *from++;
  case 2:         *to++ = *from++;
  case 1:         *to++ = *from++;
  } while(--n>0);
  }
}

void initialize( char *arr, int length)
{
  int i;
  for(i=0;i<length;i++)
    {
      arr[i] = length-i;
    }
}

char source[100];
char target[100];

int main(void)
{
  int INVOCATION_COUNT=43; /*INVOCATION_COUNT*/
  initialize( source, 100 );
  duffcopy( target, source, INVOCATION_COUNT ); /* invertemos source e target*/
  return 0;
}
