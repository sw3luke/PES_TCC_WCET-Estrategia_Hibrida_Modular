int a[11];
void insertsort(){
  int  i,j, temp;
  i = 2;
  while(i <= 10){
      j = i;
      while (a[j] < a[j-1]){
	temp = a[j];
	a[j] = a[j-1];
	a[j-1] = temp;
	j--;
      }
      i++;
  }
}
int main(){
  a[0] = 0;   /* assume all data is positive */
  a[1] = 11; 
  a[2]=10;
  a[3]=9; 
  a[4]=8; 
  a[5]=7; 
  a[6]=6; 
  a[7]=5;
  a[8] =4; 
  a[9]=3; 
  a[10]=2;
  
  insertsort();
  
  return 1;
}
