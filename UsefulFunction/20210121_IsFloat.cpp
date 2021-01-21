int IsFloat(CString buffer) //  判断是否为浮点数
{
    int sign = 0;
    int judgeDot = 0;
    if (buffer.GetAt(0) == '-') //   判断是否有负号
        sign = 1;
    for (int i = sign; i < buffer.GetLength(); i++) //   判断小数点的个数，最多只能有一个
    {
        if (buffer.GetAt(i) == '.')
        {
            if (++judgeDot > 1)
            {
                return 1;
            }
        }
    }
    for (int i = sign; i < buffer.GetLength(); i++) // 只能输入数字和小数点
    {
        if (!(((buffer.GetAt(i) == '0' || buffer.GetAt(i) > '0') && (buffer.GetAt(i) == '9' || buffer.GetAt(i) < '9')) ||
              buffer.GetAt(i) == '.' ||
              buffer.GetAt(i) == '\0'))
        {
            return 2;
        }
    }
    //     if ((float)atof(buffer) > 10.0 || (float)atof(buffer) < -10.0)         //   取值范围
    //     {
    //         return 3;
    //     }
    return 0;
}
