//Denzell Gibson
//8/16/2017

#ifndef RSA_H_
#define RSA_H_

#include "Header.h"

class RSA
{
public:
	RSA(); //Default Constructor.

	//Methods.
	void askMessage(); //ASk the user to input a message that consist of numbers.

private:

	//Methods.
	double gcd(double, double); //Finds the greatest common divisor.
	void findPublicKey(); //Creates the public key.
	void findPrivateKey(); //Creates the private key.
	double encrypt(); //Encrypts the message.
	double decrypt(); //Decrypts the message.

	//Variables.
	double firstPrime, secondPrime; //Two prime numbers for the encryption.
	double exponent; //Exponent that makes up one part of the public key, used in both making the public and private key.
	double primeProduct; //Second part of the public key.
	double phi; //Makes up the second part of the public key, helps create the private key.
	double privateKey; //Is the private key.
	double message; //Original message that user enters in.
	double encryptedMessage; //Message after encryption.

};

#endif
