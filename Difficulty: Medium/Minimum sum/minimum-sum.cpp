class Solution {
  public:
    string addString(string &s1, string &s2) {
    int i = s1.length() - 1;
    int j = s2.length() - 1;

    // initial carry is zero
    int carry = 0;

    // we will calculate and store the
    // resultant sum in reverse order in res
    string res = "";
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0)
            sum += (s1[i] - '0');

        if (j >= 0)
            sum += (s2[j] - '0');

        res.push_back(sum % 10 + '0');
        carry = sum / 10;
        i--;
        j--;
    }

    // remove leading zeroes which are currently
    // at the back due to reversed string res
    while (!res.empty() && res.back() == '0')
        res.pop_back();

    // reverse our final string
    reverse(res.begin(), res.end());

    return res;
}

// Function to find and return minimum sum of
// two numbers formed from digits of the array.
string minSum(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    // Two String for storing the two minimum numbers
    string s1 = "", s2 = "";

    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0)
            s1.push_back(arr[i] + '0');
        else
            s2.push_back(arr[i] + '0');
    }

    return addString(s1, s2);


    }
};
