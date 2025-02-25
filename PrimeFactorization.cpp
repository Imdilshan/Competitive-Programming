vector<int> primes;
void sieve(int N) {
    vector<bool> is_prime(N + 1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i * i <= N; i++) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= N; i++) {
        if(is_prime[i]) primes.push_back(i);
    }
}
vector<int> factors(int x){
    vector<int> ret;
    for(int p: primes){
        if(p * p > x){
            break;         
        }
        while(x % p == 0){ 
            ret.push_back(p);
            x /= p;
        }
    }
    if(x > 1){
        ret.push_back(x);
        x = 1;
    }
    return ret;
}