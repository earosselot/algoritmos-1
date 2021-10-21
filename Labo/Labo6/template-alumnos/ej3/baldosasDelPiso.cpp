int baldosasDelPiso(int M, int N, int B) {
  int baldosasEnM = 0;
  int baldosasEnN = 0;

  if (M % B == 0)
    baldosasEnM = M / B;
  else
    baldosasEnM = (M / B) + 1;

  if (N % B == 0)
    baldosasEnN = N / B;
  else
    baldosasEnN = (N / B) + 1;

	return baldosasEnN * baldosasEnM;
}
