//My approach:
//Right shift the until 1 is encountered and keep doing Bitwise AND of the rightmost bit with 1. Agar rihjtmost bit 1 hai to
//result 1 aayga else its 0

//Issue:
//Explore more methods like log2n ..


#include<iostream>
#include<cmath>   //to use floor() and ceil() and log2()
using namespace std;

int isPowerOf2(int n)
	{
		//corner case. Log() ke andar no 0 and negative
		if(n==0)
		{
			return 0;
		}
		else
		{
			//returns only if the condition holds
			if(ceil(log2(n))==(floor(log2(n))))
			{
				return 1;	
			}
		}
	}
	
int PositionOfSetBit(int n)
{
	int pos=0;
	//while(n) is equivalent to while(n!=0)
	while(n)
	{
		if((n & 1) != 0)
		{
			return pos;
			break;
		}
		else
		{
			pos++;
			n=n>>1;    //rightshift by 1
		}
		
	}
	return pos;
}

int main() 
{ 
	//bitwise operations becomes undefined in negative numbers. so unsigned int is used.
	int n,i;
	
	cout<<"\nEnter the number ";
	cin>>n;
	 
	//corner cases
	
	//n>0 else bitwise operations will be undefined and meaningless
	
	//check if the number has more than one set bit.Since we are dealing with binary here, check if the number is power of 2.
	//Use logbase2(n). If ceiling of log base 2 of n == floor of log base 2 of n i.e. n is purely an integer, then its 
	//a power of 2

	int flag=isPowerOf2(n);
	
	//check point
	if(flag==1 && n>=0) 
	{
		cout<<"\nThe position of ONLY set bit in "<<n<<" is "<<" "<<PositionOfSetBit(n);
	}
	else
	{
		cout<<"\nThe input number has either more than one set bit or its negative.Try with another number!";	
	}
		
	return 0;
}
