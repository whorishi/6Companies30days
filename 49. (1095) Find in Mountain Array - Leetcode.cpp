/*(This problem is an interactive problem.)

You may recall that an array arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
Given a mountain array mountainArr, return the minimum index such that mountainArr.get(index) == target. If such an index does not exist, return -1.

You cannot access the mountain array directly. You may only access the array using a MountainArray interface:

MountainArray.get(k) returns the element of the array at index k (0-indexed).
MountainArray.length() returns the length of the array.
Submissions making more than 100 calls to MountainArray.get will be judged Wrong Answer. Also, any solutions that attempt to circumvent the judge will result in disqualification.*/

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */



class Solution {
public:
        int findInMountainArray(int t, MountainArray& arr) {
            auto peak = 0, r = arr.length() - 1;
            while (peak < r) 
            {
                int m = (peak + r) / 2;
                if (arr.get(m) > arr.get(m + 1)) r = m;
                else peak = m + 1;
            }
            auto i = bSearch(arr, t, 0, peak);
            return i != -1 ? i : bSearch(arr, t, peak + 1, arr.length() - 1, false);
        }
        int bSearch(MountainArray& arr, int t, int l, int r, bool asc = true) {
            while (l <= r) 
            {
                int m = (l + r) / 2;
                auto val = arr.get(m);
                if (val == t) return m;
                if (asc == val < t) l = m + 1;
                else r = m - 1;
            }
         return -1;
        }
};