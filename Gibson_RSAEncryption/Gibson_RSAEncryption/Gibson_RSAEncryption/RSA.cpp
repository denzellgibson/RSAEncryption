//Denzell Gibson
//8/16/2017

#include "RSA.h"

RSA::RSA()
{
	firstPrime = 61;
	secondPrime = 53;
	exponent = 17;
	primeProduct = 0;
	phi = 0;
	privateKey = 0;
	message = 0;
	encryptedMessage = 0;
}

//Finds the greatest common divisor between two numbers.
double RSA::gcd(double a, double b)
{
	if (a == 0)
		return b;
	return gcd(fmod(b,a), a);
}

//Finds the two parts of the public key.
void RSA::findPublicKey()
{
	double x;
	primeProduct = firstPrime * secondPrime; //Finds the product of the two primes. Makes up the first part of the public key.
	//The exponent variable makes up the second part of the public key.
	phi = (firstPrime - 1)*(secondPrime - 1); //
	while (exponent < phi)
	{
		//exponent variable must be a co-prime to phi and smaller than phi.
		x = gcd(exponent, phi);
		if (x == 1)
			break;
		else
			exponent++;
	}
}

//Creates the private key.
void RSA::findPrivateKey()
{
	int k = 5; // A constant that isn't used in any part of the RSA encryption algorithm.
	privateKey = ((k*phi) + 1) / exponent; //Generates the private key.
}

//Encrypts the message.
double RSA::encrypt()
{
	//Formula for encryption is encrypted = (message ^ exponent) % primeProduct.

	long double encrypted; //Holds the encryped message as numbers.

	encrypted = pow(message, exponent); //Finds the numberMessage ^ exponent.
	encrypted = fmod(encrypted, primeProduct); //Finds the encrypted % primeProduct.

	return encrypted;
}

//Decrypts the message.
double RSA::decrypt()
{
	//Formulat for decryption is message = (encryptedMessage ^ privateKey) % primeProduct.

	long double decrypted; //Holds the original message.

	decrypted = pow(encryptedMessage, privateKey); //Finds encryptedMessage ^ privateKey.
	decrypted = fmod(decrypted, primeProduct); //Finds decrypted % primeProduct.

	return decrypted;
}

//Asks the user to enter a message for encryption.
void RSA::askMessage()
{
	std::string userMessage;

	std::cout << "Please enter some numbers." << std::endl;
	std::getline(std::cin, userMessage);

	message = std::stod(userMessage);
	findPublicKey();
	findPrivateKey();
	encryptedMessage = encrypt();

	std::cout << std::endl;
	std::cout << "Here is the encrypted message." << std::endl;
	std::cout << encryptedMessage << std::endl;
	std::cout << std::endl;

	std::string decryptedMessage;
	decryptedMessage = std::to_string(decrypt());
	std::cout << "Here is the decrypted message." << std::endl;
	std::cout << decryptedMessage << std::endl;
	std::cout << std::endl;
}