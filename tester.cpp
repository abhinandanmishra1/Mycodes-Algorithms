//Program of pattern searching using Boyer Moore Algorithm

/*
  Time Complexity -
    Best case : O(n/m)
    Worst Case: O(mn)
  where m is length of substring and n is length of string 
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<string, string>> text_pattern;
    text_pattern = {{"BB", "BBBBBBBBB"}, {"text", "This is a text in which search_text is to be searched and index will be printed where search_text is present."}, {"AABA", "AABAACAADAABAABA"}};
    for (int k = 0; k < text_pattern.size(); k++)
    {
        cout << "\nCase : " << k + 1 << endl;
        unordered_map<char, int> mp;
        //this map is created for skipping characters
        //storing unique values for every character in a map
        //mp[char]= max(1,len-1-index_of_char_in_pattern)
        //like for 't' in "text" first we have to store mp['t']=3
        //but 't' comes at last index then value mp['t'] becomes 1
        //In this way only unique value will be assigned to each character

        string search_text = text_pattern[k].first; //string to be searched
        int l = search_text.length();

        string text = text_pattern[k].second; //text for searching
        int len = text.length();

        int skip;
        //skip is used to skip several number of characters
        //In Boyer Moore Algorithm we find a mismatch if any
        //if we get any mismatch we check whether that character is present in search_text or not
        //if character is present we skip charcters up to---> mp[char]
        //if character is not present then we skip j+1 characters i.e; remaining length of search_text

        for (int i = 0; i < l; i++)
        {
            mp[search_text[i]] = max(1, l - 1 - i);
            //assigning unique values to each character of search_text
        }

        /* 
     Map mp will look like
     mp['t']=1  ----> unique value of t
     mp['e']=2
     mp['x']=3
    */

        for (int i = 0; i <= (len - l); i += skip)
        {

            int j;
            skip = 0;

            for (j = l - 1; j >= 0; j--)
            { //searching from last index and checking for mismatches
                if (search_text[j] != text[i + j])
                {
                    if (mp.find(text[i + j]) != mp.end())
                    { //if mismatch is present in search_text
                        skip = mp[text[i + j]];
                        break;
                    }
                    else
                    { //if mismatch isn't present in search_text
                        skip = j + 1;
                        break;
                    }
                }
            }
            if (j == -1)
            { //when every character matches then j==0
                // then printing index
                cout << "Pattern found at index : " << i << endl;
            }

            if (skip == 0)
            {
                //if no change in skip value then we increment it by 1
                skip = 1;
            }
        }
    }

    return 0;
}

/*
 Name : Abhinandan Mishra 
*/