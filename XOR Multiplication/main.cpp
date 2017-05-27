#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
#include <math.h>
using namespace std;
//XOR compares two sets of bits to each other and returns a 1 on that bit if they are different values, and a 0 if they are both the same
//1101 and 0010 become 1111
//1101 and 1001 become 0100
//0000 and 0000 become 0000

//Need two ints to store the original values in
int a1_int;
int a2_int;

//Binary values of the ints
bitset<32> bb1;
bitset<32> bb2;

//Two strings to store the binary values to multiply them against each other later
string cc1;
string cc2;

//Binary value of the ints stored as ints
int a1_binary_as_int;
int a2_binary_as_int;

//Bools to handle input phase
bool Enter1st = false;
bool Enter2nd = false;

//Product of aa1a*aa2a but before XOR
int unrevisedProduct_int;

stringstream unrevisedproduct_stringstream;
string revisedStringBinaryProduct;
void XORMultiplication()
{
	//Int to binary
	while (!Enter1st)
	{
		cout << "Please enter the first number" << endl;
	//	cout << a1 << endl;
		cin >> a1_int;

		if (cin)
		{
			Enter1st = true;
		}
		cin.clear();
		cin.ignore(10000, '\n');
	}

	while (!Enter2nd)
	{
		cout << "Please enter the second number" << endl;
	//	cout << b1 << endl;
		cin >> a2_int;
		if (cin)
		{
			Enter2nd = true;
		}
		cin.clear();
		cin.ignore(10000, '\n');
	}

	//Storing original int as binary
	bb1 = bitset<32>(a1_int);
	bb2 = bitset<32>(a2_int);

	//Turning binary into string
	cc1 = bb1.to_string();
	cc2 = bb2.to_string();

	//Storing the binary value of the original ints, on a larger scope project this should be a function
	a1_binary_as_int = stoi(cc1);
	a2_binary_as_int = stoi(cc2);

	//Multiplying the binaries together
	unrevisedProduct_int = (a1_binary_as_int*a2_binary_as_int); 

	//Storing it through stringstream
	unrevisedproduct_stringstream << unrevisedProduct_int; 
	
	//Moving the stringstream to an editable string
	revisedStringBinaryProduct = unrevisedproduct_stringstream.str();
	for (int i = 0; i < revisedStringBinaryProduct.size(); i++)
	{
		//Removing the 2s because both binaries are active here and should be set to 0
		if (revisedStringBinaryProduct[i]==*"2")
		{
			revisedStringBinaryProduct[i] =* "0";
		}
	}
	bitset<32> temp_bitset(revisedStringBinaryProduct);
	int finalProduct = temp_bitset.to_ulong();
	cout << a1_int << " x " << a2_int << " = ";
	cout << revisedStringBinaryProduct << endl;
	cout << finalProduct << endl;
}

int main()
{
	XORMultiplication();
	system("PAUSE");
}

