unsigned setbits(unsigned int x, int p, int n, unsigned y)
{
    unsigned temp_y = (y & ~(~0 << n)) << (p - n + 1);
    unsigned temp_x = x & ~(~(~0 << n) << (p - n + 1));
    return temp_x | temp_y;
}


