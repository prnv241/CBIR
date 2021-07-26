void lpsArray(string pat, vector<int> &lps)
{
    int stindex = 0;
    lps[0] = 0;
    if (pat.length() == 1)
        return;
    for (int i = 1; i < pat.length(); i++)
    {
        if (pat[i] == pat[stindex])
            lps[i + 1] = ++stindex;
        else
        {
            if (stindex != 0)
            {
                stindex = lps[stindex];
                i--;
            }
            else
                lps[i + 1] = 0;
        }
    }
}

int strStr(string haystack, string needle)
{
    int patlen = needle.length();
    if (patlen == 0)
        return 0;
    int textlen = haystack.length();
    if (textlen == 0)
        return -1;
    vector<int> lps(patlen + 1);
    lpsArray(needle, lps);
    int index = 0, pindex = 0;
    while (index < textlen)
    {
        if (haystack[index] == needle[pindex])
        {
            index++;
            pindex++;
            if (pindex == patlen)
                return index - patlen;
        }
        else
        {
            pindex = lps[pindex];
            if (pindex == 0 && haystack[index] != needle[pindex])
                index++;
        }
    }
    return -1;
}