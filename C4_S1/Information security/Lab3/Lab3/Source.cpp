#include <codecvt>
#include <iostream>
#include <fstream>
#include <string>

const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
constexpr int size{ 6 };

void findCharacter(const wchar_t arr[size][size], const wchar_t ch,
	int& outPosRow, int& outPosColumn)
{
	outPosRow = outPosColumn = -1;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[i][j] == ch)
			{
				outPosRow = i;
				outPosColumn = j;
				return;
			}
		}
	}
}

struct PolibiusSquare
{
	
};

std::wstring encrypt(const wchar_t arr[size][size], const std::wstring& buffer)
{
	std::wstring result{};

	for (const auto e : buffer)
	{
		int i, j;
		findCharacter(arr, e, i, j);

		result += arr[(i + 1) % size][j];
	}
	return result;
}

std::wstring decrypt(const wchar_t arr[size][size], const std::wstring& buffer)
{
	std::wstring result{};

	for (auto e : buffer)
	{
		int i, j;
		findCharacter(arr, e, i, j);

		result += arr[(i - 1) % size][j];
	}

	return result;
}

int main(int argc, char* argv[])
{
	system("chcp 65001");
	system("cls");

	std::wifstream inputText(L"input.txt");
	inputText.imbue(locale);
	std::wifstream inputPolibius(L"polibius.txt");
	inputPolibius.imbue(locale);

	wchar_t polibiusSquare[size][size];

	for (auto& i : polibiusSquare)
	{
		for (wchar_t& j : i)
		{
			inputPolibius >> std::noskipws >> j;
		}
	}

	std::wstring buffer;
	std::getline(inputText, buffer, L'\0');

	std::wcout.imbue(locale);
	std::wcout << L"Reading data...\nData:\n" << buffer << L"\n\n";

	std::wstring encryptedText = encrypt(polibiusSquare, buffer);

	std::wcout << L"Encrypted text:\n" << encryptedText << L"\n\n";

	return 0;
}
