long int a[50][50], b[50], x[50];

int ludcmp(int nmax, int n);

int main()
{
  int      i, j, nmax = 50, n = 5, chkerr;
  long int /* eps, */ w;

  /* Init loop */
  for(i = 0; i <= n; i++)
    {
      w = 0.0;              /* data to fill in cells */
      for(j = 0; j <= n; j++)
        {
          a[i][j] = (i + 1) + (j + 1);
          if(i == j)            /* only once per loop pass */
            a[i][j] *= 2.0;
          w += a[i][j];
        }
      b[i] = w;
    }

  chkerr = ludcmp(nmax,n);
  return 0;
}

int ludcmp(int nmax, int n)
{
  int i, j, k;
  long w, y[100];

  for(i = 0; i < n; i++)
    {
      for(j = i+1; j <= n; j++) /* triangular loop vs. i */
        {
          w = a[j][i];
          if(i != 0)            /* sub-loop is conditional, done
                                   all iterations except first of the
                                   OUTER loop */
            for(k = 0; k < i; k++)
              w -= a[j][k] * a[k][i];
          a[j][i] = w / a[i][i];
        }
      for(j = i+1; j <= n; j++) /* triangular loop vs. i */
        {
          w = a[i+1][j];
          for(k = 0; k <= i; k++) /* triangular loop vs. i */
            w -= a[i+1][k] * a[k][j];
          a[i+1][j] = w;
        }
    }
  y[0] = b[0];
  for(i = 1; i <= n; i++)       /* iterates n times */
    {
      w = b[i];
      for(j = 0; j < i; j++)    /* triangular sub loop */
        w -= a[i][j] * y[j];
      y[i] = w;
    }
  x[n] = y[n] / a[n][n];
  for(i = n-1; i >= 0; i--)     /* iterates n times */
    {
      w = y[i];
      for(j = i+1; j <= n; j++) /* triangular sub loop */
        w -= a[i][j] * x[j];
      x[i] = w / a[i][i] ;
    }
  return(0);
}
