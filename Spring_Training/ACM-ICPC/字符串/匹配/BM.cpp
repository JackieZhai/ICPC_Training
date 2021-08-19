int bmMatch(const string & text, const string & pat)
{
    int *bc = getBc(pat);
    int *gs = getGs(pat);
    //patAt指向了当前pat和text对齐的位置
    int patAt = 0;
    //cmp指向了当前比较的位置
    int cmp;
    const size_t PATLASTID = pat.length() - 1;
    const size_t patLen = pat.length();
    const size_t textLen = text.length();
    while (patAt + patLen <= textLen)
    {
        //如果匹配成功，cmp就会来到-1的位置上
        //patAt + cmp 指向了text上当前比较的字符
        for (cmp = PATLASTID; cmp >= 0 && pat[cmp] == text[patAt + cmp]; --cmp);

        if (cmp == -1)
            break;
        else
        {
            patAt += max(gs[cmp], cmp - bc[text[patAt + cmp]]);
        }

    }
    delete[] bc;
    delete[] gs;
    return (patAt + patLen <= textLen)? patAt : -1;
}
int * getBc(const string & pattern)
{
    //256是字符表的规模大小(ACSII)
    int *bc = new int[256];
    int len = pattern.length();

    for (int i = 0; i < 256; ++i)
        bc[i] = -1;

    for (int i = 0; i < len; ++i)
    {
        bc[pattern[i]] = i;
    }
    return bc;
}
int * suffixes(const string & pat)
{
    const int len = pat.length();
    int num;
    int *suff = new int[len];
    suff[len - 1] = len;
    for (int i = len - 2; i >= 0; --i)
    {
        for (num = 0; num <= i && pat[i-num] == pat[len-num-1]; ++num);
        suff[i] = num;
    }
    return suff;
}
int * getGs(const string & pat)
{
    const int len = pat.length();
    const int lastIndex = len - 1;
    int *suffix = suffixes(pat);
    int *gs = new int[len];
    //找不到对应的子串和前缀
    for (int i = 0; i < len; ++i)
        gs[i] = len;
    //找前缀
    for (int i = lastIndex; i >= 0; --i)
    {
        //存在我们想要的前缀
        if (suffix[i] == i + 1)
        {
            for (int j = 0; j < lastIndex - i; ++j)
            {
                if (gs[j] == len)
                    gs[j] = lastIndex - i;
            }
        }
    }
    //找中间的匹配子串
    for (int i = 0; i < lastIndex; ++i)
    {
        gs[lastIndex - suffix[i]] = lastIndex - i;
    }
    delete[] suffix;
    return gs;
}
