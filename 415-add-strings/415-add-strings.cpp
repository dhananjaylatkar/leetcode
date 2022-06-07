class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        
        int i = num1.length()-1;
        int j = num2.length()-1;
        string res = "";
        while(i >= 0 && j >=0)
        {
            int first = num1[i]-48;
            int sec = num2[j]-48;
            
            int tmp_sum = first + sec + carry;
            if (tmp_sum > 9)
            {
                carry = tmp_sum/10;
                tmp_sum = tmp_sum%10;
            }
            else
            {
                carry = 0;
            }
            char curr_ans = tmp_sum + 48;
            res = curr_ans + res;
            i--;j--;
        }

        while(i>=0)
        {
            int tmp_sum = num1[i]-48 + carry;
            if (tmp_sum > 9)
            {
                carry = tmp_sum/10;
                tmp_sum = tmp_sum%10;
            }
            else
            {
                carry = 0;
            }
            char curr_ans = tmp_sum + 48;
            res = curr_ans + res;
            i--;
        }

        while(j>=0)
        {
            int tmp_sum = num2[j]-48 + carry;
            if (tmp_sum > 9)
            {
                carry = tmp_sum/10;
                tmp_sum = tmp_sum%10;
            }
            else
            {
                carry = 0;
            }
            char curr_ans = tmp_sum + 48;
            res = curr_ans + res;
            j--;
        }

        if (carry)
        {
            char curr_ans = carry + 48;
            res = curr_ans + res;
        }
        return res;
    }
};