#pragma once
#include <openssl/sha.h>
#include <openssl/evp.h>
#include <openssl/hmac.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
class FeatureTester
{
private:
	std::string CalculateFileHash(const std::string& filename, const std::string& key);

public:
	int testNumber;
	FeatureTester() :testNumber(0) {}
	void hashFile(const std::string& filename, const EVP_MD* md);
	bool GF();

	bool MF();

	bool TestSelector();
};

