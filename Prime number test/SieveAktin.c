// Atkin's Sieve
#include <stdio.h>
#include <stdbool.h>


// Function to generate primes
// till limit using Sieve of Atkin
void SieveOfAtkin(int limit)
{
    // Init the sieve array
    // with initial false values
    bool sieve[limit];
    for (int i = 0; i <= limit; i++)
        sieve[i] = false;

    // 2 and 3 are known to be prime
    if (limit > 2)
        sieve[2] = true;
    if (limit > 3)
        sieve[3] = true;

    
    for (int x = 1; x * x <= limit; x++)
    {
        for (int y = 1; y * y <= limit; y++)
        {

            // Condition 1
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            // Condition 2
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            // Condition 3
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    // Mark all multiples
    // of squares as non-prime
    for (int r = 5; r * r <= limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r * r; i <= limit; i += r * r)
                sieve[i] = false;
        }
    }

    for (int a = 1; a <= limit; a++)
        if (sieve[a])
            printf("%d, ", a);
                
}

// Main 
int main(void)
{
    int limit = 20;
    SieveOfAtkin(limit);
    printf("\n");
    return 0;
}
