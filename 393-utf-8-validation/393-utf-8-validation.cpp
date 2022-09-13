class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int i = 0;
        int n = data.size();
        while (i < n)
        {
            int d = data[i];
            if (data[i] >> 7 == 0)
            {
                // 1 byte
                i++;
            }
            else
            {
                if (data[i] >> 5 == 0b110)
                {
                    // maybe 2 bytes?
                    if (i+1 < n && data[i+1] >> 6 == 0b10)
                    {
                        i += 2;
                    }
                    else 
                    {
                        return false;
                    }
                }
                else if (data[i] >> 4 == 0b1110)
                {
                    // maybe 3 bytes?
                    if (i+1 < n && i+2 < n 
                        && data[i+1] >> 6 == 0b10 
                        && data[i+2] >> 6 == 0b10)
                    {
                            i += 3;
                    }
                    else 
                    {
                        return false;
                    }
                }
                else if (data[i] >> 3 == 0b11110)
                {
                    // maybe 4 bytes
                    if (i+1 < n && i+2 < n && i+3 < n
                        && data[i+1] >> 6 == 0b10 
                        && data[i+2] >> 6 == 0b10
                        && data[i+3] >> 6 == 0b10)
                    {
                        i += 4;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};