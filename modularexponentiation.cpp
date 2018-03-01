//Fermat MMI
//------------------------------------------
//============================================================================
//a^n % m
ll mod_exponentiation(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int fermat(ll n, ll m){
	return mod_exponentiation(n,m-2,m);
}
