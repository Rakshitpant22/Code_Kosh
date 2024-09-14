//! Maximum Length of Subarray With Positive Product

int getMaxLen(vector<int>& nums) {
     int start = 0, n = nums.size(), ans = 0;

    while (start < n) { // to skip zeroes from beginning
        while (start < n && nums[start] == 0) {
            start++;
        }
        
        int end = start;
        
        while (end < n && nums[end] != 0) {
            end++;
        }

        int cnt_negative_elements = 0;
        int first_negative_idx = -1;
        int last_negative_idx = -1;

        for (int i = start; i < end; i++) {
            if (nums[i] < 0) {
                cnt_negative_elements++;
                if (first_negative_idx == -1) {
                    first_negative_idx = i;
                }
                last_negative_idx = i;
            }
        }

        // If the count of negative elements is even, the whole segment is valid
        if (cnt_negative_elements % 2 == 0) {
            ans = max(ans, end - start);
        } else {
            // Calculate  maximum length by excluding  negative number
            if (first_negative_idx != -1) {
                ans = max(ans, end - (first_negative_idx + 1));
            }
            if (last_negative_idx != -1) {
                ans = max(ans, last_negative_idx - start);
            }
        }
        
        // Move start to the end of the current segment
        start = end;
    }
    
    return ans;
    }