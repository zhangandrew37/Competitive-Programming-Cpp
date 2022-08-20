# Backtracking

(brute force approach)

- use for some/all solutions
- i.e. would use DP to count # of solutions, but backtracking to store all solutions
  
### Templates

```js
function backTrackAlgorithm(parameters) {
  function backtrack(startingState) {
    if (final condition is met) {
      // add result;
    } else {
      // loop from the starting state
        try a candidate;
        backtrack(adjustedStartingState);
        // remove the candidate;
    }
  }
  
  // handle edge cases
  // initialize the result structure;
  backtrack(startingState);
  return result;
}
```