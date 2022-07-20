// General use:

int l = 0;
for (int r = 0; r < n; r++) {
  // add the new thing you found at r
  // while a condition you want to maintain is false, get rid of the thing at the left end and increase left by 1
  // update the best you found with the current window size, which is guaranteed to be valid
}