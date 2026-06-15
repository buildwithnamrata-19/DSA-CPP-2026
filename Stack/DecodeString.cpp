/*
Problem:
LeetCode 394 - Decode String

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    string decodeString(string s) {

        stack<int> countStack;
        stack<string> stringStack;

        string current = "";
        int k = 0;

        for(char c : s) {

            if(isdigit(c)) {

                k = k * 10 + (c - '0');
            }

            else if(c == '[') {

                countStack.push(k);
                stringStack.push(current);

                k = 0;
                current = "";
            }

            else if(c == ']') {

                string temp = current;

                current = stringStack.top();
                stringStack.pop();

                int repeat =
                    countStack.top();

                countStack.pop();

                while(repeat--) {

                    current += temp;
                }
            }

            else {

                current += c;
            }
        }

        return current;
    }
};
