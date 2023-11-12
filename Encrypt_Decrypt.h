#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#ifndef Encrypt_Decrypt_H
#define Encrypt_Decrypt_H

using namespace std;

class Encrypt_Decrypt
{
    private:
        int e, d, n; 
    long long int powerMod(int A, int B, int C)
    {
        // Base cases
        if (A == 0)
            return 0;
        if (B == 0)
            return 1;
	    // If B is even
        long long int y;
        if (B % 2 == 0) 
        {
            y = powerMod(A, B / 2, C);
            y = (y * y) % C;
	    }
        // If B is odd
        else 
        {
            y = A % C;
            y = (y * powerMod(A, B - 1, C) % C) % C;
	    }
        return (long long int)((y + C) % C);
    }
    void encrypt_decrypt()
    {
        C = powerMod(msg, e, n); //Encryption C = (M ^ e) % n
        M = powerMod(C, d, n); //Decryption M = (C ^ d) % n
    }	

    public:
        int msg;
        int M;
        int C;
    void setKeys(int E, int D)
	{
		e = E;
		d = D;
	}
    void set_n(int N)
	{
		n = N;
	}
    void setMessage(int MSG)
	{
		msg = MSG;
	}
    int get_M()
	{
		return M;
	}
    int get_C()
	{
		return C;
	}
    void Calc()
    {
        encrypt_decrypt();
    }
};

#endif

/*
    long long int power(long long int x, long long int y, long long int p)
    {
        long long int res = 1; // Initialize result
        // Update x if it is more than or
	    // equal to p
        x = x % p;
        while (y > 0) 
        {
            // If y is odd, multiply x
		    // with the result
            if (y & 1)
                res = (res * x) % p;
            // y must be even now
		    y = y >> 1; // y = y/2
		    x = (x * x) % p;
	    }
        return res;
    }

*/

/*
// Maximum number of digits in
// output
#define MAX 100000
    int multiply(int x, int res[], int res_size) 
    {
        // Initialize carry
        int carry = 0;
        // One by one multiply n with
        // individual digits of res[]
        for (int i = 0; i < res_size; i++) 
        {
            int prod = res[i] * x + carry;
            // Store last digit of
            // 'prod' in res[]
            res[i] = prod % 10;
            // Put rest in carry
            carry = prod / 10;
        }
        // Put carry in res and
        // increase result size
        while (carry) 
        {
            res[res_size] = carry % 10;
            carry = carry / 10;
            res_size++;
        }
        return res_size;
    }
    // This function finds
    // power of a number x
    void power(int x, int n)
    {
        //printing value "1" for power = 0
        if(n == 0 )
        {
            cout<<"1";
            return;
        }
        int res[MAX];
        int res_size = 0;
        int temp = x;
        // Initialize result
        while (temp != 0) 
        {
            res[res_size++] = temp % 10;
            temp = temp / 10;
        }
        // Multiply x n times
        // (x^n = x*x*x....n times)
        for (int i = 2; i <= n; i++)
            res_size = multiply(x, res, res_size);
        cout << x << "^" << n << " = ";
        for (int i = res_size - 1; i >= 0; i--)
            cout << res[i];
    }

*/