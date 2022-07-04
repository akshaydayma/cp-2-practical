#include<stdio.h>
#include<math.h>
int
main ()
{
  long long n, a, b;
  while (scanf ("%lld", &n) == 1)
    {
      if (n == 0)
	break;
      a = sqrt (n);		//if given n is a perfect square then it has even number of factors //
      b = a * a;
      if (b == n)
	printf ("yes\n");
      else
	printf ("no\n");
    }
  return (0);
}

