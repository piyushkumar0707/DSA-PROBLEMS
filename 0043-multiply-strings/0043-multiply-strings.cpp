class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // edge case
        
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0); // result array, size m+n
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';
                int product = digit1 * digit2;
                
                int pos1 = i + j;       // higher significant position (carry wali)
                int pos2 = i + j + 1;   // lower significant position (units wali)
                
                int sum = product + result[pos2]; // jo already pada hai usme add karo
                
                result[pos2] = sum % 10;        // current position pe units digit rakho
                result[pos1] += sum / 10;       // carry agli (higher) position mein daal do
            }
        }
        
        // result array ko string mein convert karo, leading zeros skip karke
        string finalResult = "";
        for (int num : result) {
            if (!(finalResult.empty() && num == 0)) { // leading zero skip
                finalResult += to_string(num);
            }
        }
        
        return finalResult.empty() ? "0" : finalResult;
    }
};