float fabs2(float x)
{
   if (x < 0)
      return -x;
   else
      return x;
}

float sqrtfcn(int valor)
{

   float val = (float)valor;
   float x = val/10;

   float dx;

   double diff;
   double min_tol = 0.00001;

   int i, flag;

   flag = 0;
   if (val == 0 )
      x = 0;
   else {
      for (i=1;i<20;i++)
      {
         if (!flag) {
            dx = (val - (x*x)) / (2.0 * x);
            x = x + dx;
            diff = val - (x*x);
            if (fabs2(diff) <= min_tol)
               flag = 1;
         }
      }
   }
   return (x);
}

int main(){
	int valor = 0;
	
	sqrtfcn(valor);
	

}
