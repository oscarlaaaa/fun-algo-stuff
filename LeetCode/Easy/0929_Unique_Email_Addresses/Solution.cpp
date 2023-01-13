// 2023-01-13
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        /*
            input: list of string emails
            output: number of unique emails to send to

            notes:
            - everything before @:
                - '.' = ignore
                - '+' = ignore everything after the + sign
            
            approach:
            - iterate through the list of emails, and keep a string to store for each one
            - iterate through and ignore '.', or stop iterating at '@' or '+'
                - otherwise, concat the char onto the string
            - concatenate the second portion starting from '@' and store into a set
            - return unordered set size at the end
        */
        unordered_set<string> uniqueEmails;
        for (string email : emails) {
            string relevant = "";
            int i;
            for (i=0; i<email.length(); i++) {
                if (email[i] == '.') continue;
                if (email[i] == '+' || email[i] == '@') break;
                relevant += email[i];
            }
            relevant += email.substr(email.find('@'));
            uniqueEmails.insert(relevant);
        }
        return uniqueEmails.size();
    }
};