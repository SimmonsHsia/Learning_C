unsigned invert(unsigned x, int p, int n)
{
    return ((~(~0 << n) << (p + 1 - n)) | x) & ~(~(~0 << n) << (p + 1 - n) & x);
}
