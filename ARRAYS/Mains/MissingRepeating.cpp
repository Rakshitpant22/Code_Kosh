 //! ARR CONATINS [1-- N] . FIND MISSING AND REPEATING NUMBER

 vector<int> findTwoElement(vector<int> arr) {
    int n = arr.size();
    long long sum_n = (long long)n * (n + 1) / 2;
    long long sum_sq_n = (long long)n * (n + 1) * (2 * n + 1) / 6;

    long long sum_arr = 0, sum_sq_arr = 0;
    for (int num : arr) {
        sum_arr += num;
        sum_sq_arr += (long long)num * num;
    }

   
    long long sum_diff = sum_n - sum_arr;           // A - B
    
    long long sq_sum_diff = sum_sq_n - sum_sq_arr; // A^2 - B^2

    long long sum_ab = sq_sum_diff / sum_diff;  // A + B

    int missing = (sum_ab + sum_diff) / 2;
    int duplicate = sum_ab - missing;

    return {duplicate, missing};
    }
    