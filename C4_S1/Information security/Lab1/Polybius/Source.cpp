#include <cwchar>
#include <string>
#include <fstream>
#include <random>
#include <algorithm>
#include <chrono>
#include <array>
#include <codecvt>
#include <iostream>

void generateAlphabet()
{
	const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	std::wstring str{};

	for (int i = 0; i < 33; ++i)
	{
		str.push_back(L'а' + i);
	}
	str.push_back(L' ');
	str.push_back(L'.');
	str.push_back(L',');


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::shuffle(str.begin(), str.end(), std::default_random_engine(seed));

	std::wofstream output(L"polibius.txt");
	output.imbue(locale);
	//output << str;

	if (output.is_open())
	{
		for (auto e : str)
			output << e;
	}
}


constexpr int size{ 6 };

void findCharacter(const wchar_t arr[size][size], wchar_t ch,
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

std::wstring encrypt(const wchar_t arr[size][size], const std::wstring& buffer)
{
	std::wstring result{};

	for (auto e : buffer)
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
	const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	std::locale::global(locale);
	std::wifstream inputPolibius(L"polibius.txt");
	wchar_t polibiusSquare[size][size];

	for (auto& i : polibiusSquare)
	{
		for (wchar_t& j : i)
		{
			inputPolibius >> std::noskipws >> j;
		}
	}

	std::wifstream inputText(L"input.txt");
	std::wstring buffer;

	std::getline(inputText, buffer, L'\0');


	std::wofstream outputText(L"output.txt");

	system("chcp 65001");
	system("cls");

	std::ios_base::sync_with_stdio(false);
	std::wcout.imbue(locale);
	std::wcout << L"1. Зашифровать\n" << L"2. Расшифровать\n";

	int choice{};

	do
	{
		std::wcout << L"Ввод: ";
		std::cin >> choice;

		if (std::wcout.bad())
		{
			std::wcout.clear();
		}
	} while (choice != 1 && choice != 2);

	if (choice == 1)
	{
		outputText << encrypt(polibiusSquare, buffer);
	}
	else if (choice == 2)
	{
		outputText << decrypt(polibiusSquare, buffer);
	}

	//generateAlphabet();

	return 0;
}
