for (int k = 0; k < V; k++) {
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
  }
}