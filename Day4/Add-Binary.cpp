class Solution {
public:
    string addBinary(string a, string b) {
   string result;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0'; // Convert char to int
            if (j >= 0) sum += b[j--] - '0'; // Convert char to int
            result.push_back((sum % 2) + '0'); // Convert int to char
            carry = sum / 2; // Update carry
        }

        reverse(result.begin(), result.end()); // The result is in reverse order
        return result;  
    }
};