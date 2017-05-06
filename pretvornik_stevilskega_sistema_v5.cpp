#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
//#include <cstring>

using namespace std;

// FUNCTIONS

string string_reverse(string input) {

	//string output = "";
	//reverse(input, output + strlen(input));
	int i, j;
	string output(input.length(), ' '); // initially set sufficient length
	for (i = 0, j = input.length() - 1; i<input.length(); i++, j--)
		output[i] = input[j];

	return output;
}

string dec_to_bin(long long input) {
	//vars
	string bin = "";
	string i = "";
	unsigned long long in = input;

	//loop
	while (1) {
		i+="1";
	if (in % 2 == 1) {
	bin = bin + "1";
	//(in - 1 / 2);

	}
	else if (in%2==0) {
	bin = bin + "0";
	}
	if (in <= 1) { break; }
	in /= 2;
	}
	//Output je string bin

	//binr = string_reverse(bin);

	return string_reverse(bin);

	}


unsigned long long deljeno(int input) {
	unsigned long long iks = 1;

	for (int i = 0; i < input; ++i) {
		iks = iks * 10;
	}
	return iks;
}


string letter_for_hex(int input) {
	switch (input) {
	case 1: {return "1"; }
	case 2: {return "2"; }
	case 3: {return "3"; }
	case 4: {return "4"; }
	case 5: {return "5"; }	
	case 6: {return "6"; }
	case 7: {return "7"; }
	case 8: {return "8"; }
	case 9: {return "9"; }
	case 10 :{return "a"; }
	case 11: {return "b"; }
	case 12: {return "c"; }
	case 13: {return "d"; }
	case 14: {return "e"; }
	case 15: {return "f"; }
	}
}

int number_for_hex(char input) {
	if (input=='1') {return 1; }
    else if (input == '2') { return 2; }
	else if (input == '3') { return 3; }
	else if (input == '4') { return 4; }
	else if (input == '5') { return 5; }
	else if (input == '6') { return 6; }
	else if (input == '7') { return 7; }
	else if (input == '8') { return 8; }
	else if (input == '9') { return 9; }
	else if (input == 'a') { return 10; }
	else if (input == 'b') { return 11; }
	else if (input == 'c') { return 12; }
	else if (input == 'd') { return 13; }
	else if (input == 'e') { return 14; }
	else if (input == 'f') { return 15; }
}



unsigned long long bin_to_dec(long long input) {
	long long cac2 = input;
	long long vel = 0;
	//int incr = 1;
	long long temp = 0;
	//int incr[5000];
	long long output = 0;

	//    ******************* Perfect lenght (vel)

	while (1) {

		//cout << originalinput << " in velikost je " << vel << " cac2 pa " << cac2 << endl;
		if (cac2 <= 0)
		{
			//cac2--; cout << "Velikost je " << vel << endl;
			break;
		}
		cac2/=10;  
		vel++;
	}
	temp = input;

	int temp2 = 0;
	for (; temp2 < vel; ++temp2)
	{
		
		temp = input / deljeno(temp2);

		if (temp%2==1) {

			//temp2++;
			int iks = pow(2, temp2);
			//output++;
			output = output + iks;
		}
	}


	/*  ALT 
		std::bitset<8> bits();
		std::cout << bits.to_ulong(input) << std::endl;
		return bits.to.ulong(input);
		*/

	return output;
}


string dec_to_hex(long long input) {
	long long inp = input;

	string temp = "";
	string hex = "";

	while (1) {
        
		if (inp %16 < 1) { break; }
		else {
			hex = hex + letter_for_hex(inp % 16);
			inp /= 16;
		}

	}
	return string_reverse(hex);
	//return hex;
}


long long hex_to_dec(string input) {
	string inp = string_reverse(input);
	
	long long dec = 0;
	long long out = 0;
	for (unsigned i = 0; i < inp.length(); ++i)
	{
		dec = number_for_hex(inp.at(i));
		out += dec*(pow(16.0, i));
	}
	
	return out;

}






/////////////////////////////  MAIN

int main() {

	cout << "Welcome to my number converter! Made by Ugreen." << endl;

	int vel = 0;
	int cac2 = 0;
	string bin = "";
	string system;
	string binr = "";
	bool repeat = false;
	
	unsigned long long originalinput;
	int dec_output = 0;

	while (1) {
		if (repeat) { cout << "Error, no command selected, typo? Try again. " << endl; }
		repeat = false;
		cout << "Conversion commands are: " << '\n' << "dec_to_bin/bin_to_dec in" << " dec_to_hex/hex_to_dec " << endl;

		cin >> system;
		cin.clear();
		std::cin.ignore(256, '\n');
		/*
		cout << "Vnesi stevilo" << endl;
		cin >> originalinput;
		*/

		// DECIMAL TO BINARY

		if (system == "dec_to_bin") {
			cout << "Vnesi stevilo" << endl;
			cin >> originalinput;

			cout << "Integer " << originalinput << " is " << dec_to_bin(originalinput) << " in binary." << endl;
		}


		// DECIMAL TO HEXADECIMAL

		else if (system == "dec_to_hex") {
			cout << "Vnesi stevilo" << endl;
			cin >> originalinput;
			cout << dec_to_hex(originalinput) << endl;
		}


		//HEXADECIMAL TO DECIMAL

		else if (system == "hex_to_dec") {
			string hex;
			cout << "Vnesi stevilo" << endl;
			cin >> hex;
			cout << hex_to_dec(hex) << endl;
		}

		// BINARY TO DECIMAL

		else if (system == "bin_to_dec") {
			cout << "Vnesi stevilo" << endl;
			cin >> originalinput;
			cout << bin_to_dec(originalinput) << endl;
		} //Max 19 binarnih stevil

		else { repeat = true; }


		if (repeat == false) {
			cin.clear();
			std::cin.ignore(256, '\n');

			cout << "Restart? (Y/N) " << endl;
			cin >> system;

			if (system == "y" || system == "Y") {
				cin.clear();
				std::cin.ignore(256, '\n');

				vel = 0;
				cac2 = 0;
				system = "";
				bin = "";
				binr = "";
				//inp = 0;
				dec_output = 0;
			}


			else { break; }
		}

	}




}
