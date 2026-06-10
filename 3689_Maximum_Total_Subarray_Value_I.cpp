# 3689. Maximum Total Subarray Value I

## Approach

Since the same subarray can be chosen multiple times, we only need to find the maximum possible value of a single subarray and choose it exactly `k` times.

The value of a subarray is:

value = max(subarray) - min(subarray)

To maximize this value, we need a subarray containing both the global maximum and global minimum elements. Therefore,

answer = k × (maximum element - minimum element)

## Algorithm

1. Find the maximum element in the array.
2. Find the minimum element in the array.
3. Compute:

```cpp
answer = k * (maxElement - minElement)
```

4. Return the answer.

## C++ Solution

```cpp
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mx = *max_element(nums.begin(), nums.end());
        int mn = *min_element(nums.begin(), nums.end());

        return 1LL * k * (mx - mn);
    }
};
```

## Explanation

- `max_element()` returns an iterator pointing to the largest element.
- `min_element()` returns an iterator pointing to the smallest element.
- The `*` operator dereferences the iterator to obtain the actual value.
- Since the same subarray may be selected multiple times, choosing the best subarray `k` times gives the maximum total value.

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`
