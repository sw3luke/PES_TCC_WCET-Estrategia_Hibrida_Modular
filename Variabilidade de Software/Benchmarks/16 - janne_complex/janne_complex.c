/*----------------------------------------------------------------------
 * The result should be the following:
 *   outer loop:       1   2   3   4   5   6   7   8   9   10   11 
 *   inner loop max:   5   9   8   7   4   2   1   1   1   1    1 
 *
 *----------------------------------------------------------------------*/
int complex(int a, int b){
  while(a < 30){
      while(b < a){ 
	  if(b > 5){
	  	b = b * 3; 
	  } 
	  else{
	  	b = b + 2;
	  } 
	  if(b >= 10 && b <= 12){
	  	a = a + 10;
	  }
	  else{
	  	a = a + 1;
	  }  
	}
      a = a + 2; 
      b = b - 10; 
    }
  return 1;
}
int main(){   
  /* a = [1..30] b = [1..30] */ 
  int a = 1, b = 1, answer = 0;
  answer = complex(a, b);
  return answer;
}
