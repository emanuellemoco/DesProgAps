#include <stdio.h>

#include "dna.h"

void load_string(FILE *file, int *p, char *s, int t)
{
  if (fscanf(file, "%d", p) != 1)
  {
    fprintf(stderr, "erro ao ler string do teste %d\n", t);
  }

  char c;
  do
  {
    c = getc(file);
  } while (c != '\n');

  fgets(s, *p + 1, file);
}

int mlcs_w(char a[], int n, char b[], int m, int length[MAX_SIZE + 1][MAX_SIZE + 1])
{

  if (n == 0 || m == 0)
  {
    return 0;
  }
  if (length[n][m] != -1)
  {
    return length[n][m];
  }
  if (a[n - 1] == b[m - 1])
  {
    length[n][m] = mlcs_w(a, n - 1, b, m - 1, length) + 1;
    return length[n][m];
  }
  else
  {
    int tempA, tempB;
    tempA = mlcs_w(a, n - 1, b, m, length);
    tempB = mlcs_w(a, n, b, m - 1, length);
    if (tempA > tempB)
    {
      length[n][m] = tempA;
      return tempA;
    }
    else
    {
      length[n][m] = tempB;
      return tempB;
    }
  }
}

int mlcs(char a[], int n, char b[], int m)
{
  int length[MAX_SIZE + 1][MAX_SIZE + 1];
  for (int i = 0; i < MAX_SIZE + 1; i++)
  {
    for (int j = 0; j < MAX_SIZE + 1; j++)
    {
      length[i][j] = -1;
    }
  }
  return mlcs_w(a, n, b, m, length);
}

int dlcs(char a[], int n, char b[], int m)
{
  int length[n+1][m+1];
  for (int i = 0; i < n+1; i++)
  {
    for (int j = 0; j < m+1; j++)
    {
      if (i == 0 || j == 0) {
        length[i][j] = 0;
      }
      else if (a[i - 1] == b[j - 1])
      {
        length[i][j] = length[i - 1][j - 1] + 1;
      }
      else if (length[i - 1][j] > length[i][j - 1])
      {
        length[i][j] = length[i - 1][j];
      }
      else
      {
        length[i][j] = length[i][j - 1];
      }
    }
  }
  return length[n][m];
}
 