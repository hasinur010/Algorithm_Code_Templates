// nCr % m 
// lim = For generating prime numbers up to lim
// mod = mod value .
// f[i] = frequency of prime number i in nCr
// prime[] = vector for storing prime numbers up to lim
// gen_prime() =  generate prime numbers up to lim
// ncrModM() = get the ans nCr % m .

#define lim 1000010 
#define mod 1000000007
ll f[lim];
bool isp[lim];
vector <ll> prime;
void gen_prime(  ) {
	memset( isp , true, sizeof isp );
	isp[0] = isp[1] = false;
	for ( ll i = 2 ; i < lim ; i++ ) {
		if ( isp[i] == false  ) continue;
		prime.pb(i);
		for ( ll j = i * i ; j < lim ; j += i ) isp[j] = false;
	}
}
ll bigmod( ll a, ll b , ll m ) {
	ll r = 1;
	while (b) {
		if ( b % 2 == 1 ) r = (r % m * a % m) % m;
		b = b / 2;
		a = (a % m * a % m) % m;
	}
	return r;
}
ll nCrModM(  ll _n, ll _r, ll m ) {
  ll b = _n , c = _r ;
	for ( ll i = 0 ; i < prime.size(); i++ ) {
		if ( prime[i] > b ) break;
		ll r = 0;
		ll p = 1;
		while ( p < b ) {
			p = p * prime[i];
			r += b / p;
		}
		f[prime[i]] = r;
	}
	for ( ll i = 0 ; i < prime.size(); i++ ) {
		if ( prime[i] > c ) break;
		ll r = 0;
		ll p = 1;
		while ( p < c ) {
			p = p * prime[i];
			r += c / p;
		}
		f[prime[i]] -= r;
	}
	for ( ll i = 0 ; i < prime.size(); i++ ) {
		if ( prime[i] > (b - c) ) break;
		ll r = 0;
		ll p = 1;
		while ( p < (b - c) ) {
			p = p * prime[i];
			r += (b - c) / p;
		}
		f[prime[i]] -= r;
	}
	ll ans = 1;
	for ( ll i = 2 ; i < lim ; i++ )
		ans = (ans * bigmod( i , f[i], m )) % m;
	return ans;
}
