int bmMatch(const string & text, const string & pat)
{
    int *bc = getBc(pat);
    int *gs = getGs(pat);
    //patAtָ���˵�ǰpat��text�����λ��
    int patAt = 0;
    //cmpָ���˵�ǰ�Ƚϵ�λ��
    int cmp;
    const size_t PATLASTID = pat.length() - 1;
    const size_t patLen = pat.length();
    const size_t textLen = text.length();
    while (patAt + patLen <= textLen)
    {
        //���ƥ��ɹ���cmp�ͻ�����-1��λ����
        //patAt + cmp ָ����text�ϵ�ǰ�Ƚϵ��ַ�
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
    //256���ַ���Ĺ�ģ��С(ACSII)
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
    //�Ҳ�����Ӧ���Ӵ���ǰ׺
    for (int i = 0; i < len; ++i)
        gs[i] = len;
    //��ǰ׺
    for (int i = lastIndex; i >= 0; --i)
    {
        //����������Ҫ��ǰ׺
        if (suffix[i] == i + 1)
        {
            for (int j = 0; j < lastIndex - i; ++j)
            {
                if (gs[j] == len)
                    gs[j] = lastIndex - i;
            }
        }
    }
    //���м��ƥ���Ӵ�
    for (int i = 0; i < lastIndex; ++i)
    {
        gs[lastIndex - suffix[i]] = lastIndex - i;
    }
    delete[] suffix;
    return gs;
}
