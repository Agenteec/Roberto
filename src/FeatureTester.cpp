#include "FeatureTester.h"


//std::string FeatureTester::CalculateFileHash(const std::string& filename, const std::string& key)
std::string FeatureTester::CalculateFileHash(const std::string& filename, const std::string& key)
{
	std::ifstream file(filename, std::ios::binary);
	if (!file)
	{
		// ������ �������� �����
		return "";
	}

	// ������������� OpenSSL
	OpenSSL_add_all_digests();

	// �������� � ������������� ��������� EVP_MD_CTX ��� SHA-256
	EVP_MD_CTX* ctx = EVP_MD_CTX_new();
	if (!ctx)
	{
		// ������ �������� ���������
		return "";
	}

	// ��������� ���-������� EVP_sha256
	const EVP_MD* md = EVP_sha256();

	// ������������� ��������� ��� ����������� � ������
	if (EVP_DigestInit_ex(ctx, md, nullptr) != 1)
	{
		// ������ ������������� ���������
		EVP_MD_CTX_free(ctx);
		return "";
	}

	// ��������� ����� ��� �����������
	if (EVP_DigestSignInit(ctx, nullptr, md, nullptr, EVP_PKEY_new_mac_key(EVP_PKEY_HMAC, nullptr, (const unsigned char*)key.c_str(), key.size())) != 1)
	{
		// ������ ��������� �����
		EVP_MD_CTX_free(ctx);
		return "";
	}

	// ����� ��� ������ �����
	const int bufferSize = 4096;
	unsigned char buffer[bufferSize];

	// ������ � ���������� ���� ����� �� ������
	while (file.read(reinterpret_cast<char*>(buffer), bufferSize))
	{
		if (EVP_DigestSignUpdate(ctx, buffer, file.gcount()) != 1)
		{
			// ������ ���������� ����
			EVP_MD_CTX_free(ctx);
			return "";
		}
	}

	// ��������� �������������� ����
	unsigned char hash[EVP_MAX_MD_SIZE];
	size_t hashLength;
	if (EVP_DigestSignFinal(ctx, hash, &hashLength) != 1)
	{
		// ������ ��������� �������������� ����
		EVP_MD_CTX_free(ctx);
		return "";
	}

	// ��������������� ���� � ������
	std::stringstream ss;
	ss << std::hex << std::setfill('0');
	for (size_t i = 0; i < hashLength; ++i)
	{
		ss << std::setw(2) << static_cast<int>(hash[i]);
	}

	// ������������� ��������
	EVP_MD_CTX_free(ctx);

	return ss.str();
}
bool FeatureTester::GF()
{
	
	std::cout << "GF Test active\n";
	std::cout << CalculateFileHash("test.txt","test") << std::endl;
	testNumber = 0;
	return false;
}
