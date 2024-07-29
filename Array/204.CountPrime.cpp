class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                count++;
            }
        }
        return count;
    }

private:
    bool isPrime(int n)
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0 && i != n)
            {
                return false;
            }
        }
        return true;
    }
}
// gives TLE
// -----------------------------------------------------------------
// Much More Optimized sqr technique

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 1)
            return 0;
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (isPrime(i))
            {
                count++;
            }
        }
        return count;
    }

private:
    bool isPrime(int n)
    {

        for (int i = 2; i <= n/2; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }
};
// -----------------------------------------------------------
// step 1: we will make a primeArray ans initialize all we 1 which means they are prime 
// step 2: Now we have to find all i's multiple and put them 0 as they are non prime 
//         THIS cond will be only cheeck if i is prime ie PrimeArray[i]==1 

// step3: eg : 2*2=4    3*2=6   4*2=8
//             2*3=6    3*3=9   4*3=12
//             2*4=8    3*4=12   4*4=16
//             2*5=10   3*5=15   4*5=20
//             2*6=12   '''''''''
//     we could see 2*3,3*2 ,2*4 ,4*2 giving same ans but it differs from 2*2,3*3,4*4 '.' i*i

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        // Sieve of Eratosthenes
        // Step 1: Create the prime array
        vector<int> primeArray(n, 1); // Initialize the vector with size n, filled with 1

        if (n <= 2)
            return 0; // No primes less than 2

        primeArray[0] = primeArray[1] = 0; // 0 and 1 are not primes

        // Step 2: Mark non-prime numbers
        for (int i = 2; i * i < n; i++)
        { // Only need to check up to sqrt(n)
            if (primeArray[i] == 1)
            { // If i is a prime
                for (int j = i * i; j < n; j += i)
                { // Mark all multiples of i as non-prime
                    primeArray[j] = 0;
                }
            }
        }

        // Step 3: Count the prime numbers
        int count = 0;
        for (int i = 2; i < n; i++)
        {
            if (primeArray[i] == 1)
            {
                count++;
            }
        }

        return count;
    }
};
// https://www.youtube.com/watch?v=g5Fuxn_AvSk   Link to understand  