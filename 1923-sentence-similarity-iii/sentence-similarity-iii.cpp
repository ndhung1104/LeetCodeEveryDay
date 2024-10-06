class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        // if (sentence1 == sentence2)
        //     return true;

        if (sentence1.size() < sentence2.size())
            swap(sentence1, sentence2);
        // cout << sentence1 << " " << sentence2 << endl;

        vector<string> s1_word_list, s2_word_list;

        stringstream ss1(sentence1), ss2(sentence2);

        string tmp;

        while (getline(ss1, tmp, ' '))
            s1_word_list.push_back(tmp);

            
        
        while (getline(ss2, tmp, ' '))
            s2_word_list.push_back(tmp);
        
        // for (int i = 0; i < s1_word_list.size(); i++)
        //     cout << s1_word_list[i] << " ";
        // cout << endl;

        // for (int i = 0; i < s2_word_list.size(); i++)
        //     cout << s2_word_list[i] << " ";
        // cout << endl;

        int first = 0, last = 0;

        while (first < s2_word_list.size() && s1_word_list[first] == s2_word_list[first])
            first++;
        
        while (last < s2_word_list.size() && s1_word_list[s1_word_list.size() - 1 - last] == s2_word_list[s2_word_list.size() - 1 - last])
            last++;

        if (first + last >= s2_word_list.size())
            return true;


        return false;
    }
};