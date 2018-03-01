/**
 *function that calculates nCk using the property (n-1)C(k-1) + (n-1)Ck ,using
 *dp
 */
LL nCk_dp_array[60][60] = {{0}};
LL nCk_dp_for_non_fixed_n_k(LL n, LL k) {
  nCk_dp_array[0][0] = 1;
  for (size_t i = 0; i <= n; i++) {
    for (size_t j = 0; j <= i; j++) {
      if (j == 0 || j == i) {
        nCk_dp_array[i][j] = 1;
      } else {
        nCk_dp_array[i][j] =
            nCk_dp_array[i - 1][j - 1] + nCk_dp_array[i - 1][j];
      }
    }
  }
  return nCk_dp_array[n][k];
}
