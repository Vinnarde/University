#include <array>
#include <codecvt>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::wstring encrypt(const std::vector<int>& magicSquare, const std::wstring& buffer)
{
	std::wstring result;

	for (auto e : magicSquare)
	{
		result.push_back(buffer[e - 1]);
	}

	return result;
}

int main()
{
	const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());
	std::locale::global(locale);

	std::vector<int> magicSquare;

	std::wifstream inputMagicSquare(L"square.txt");

	int x{};
	while (inputMagicSquare >> x)
	{
		magicSquare.emplace_back(x);
	}
	inputMagicSquare.close();

	std::wstring buffer(magicSquare.size(), '-');
	//std::cout << buffer << '\n';

	std::wifstream inputTextFile(L"input.txt");
	std::wofstream outputTextFile(L"output.txt");
	while (!inputTextFile.eof())
	{
		std::vector<wchar_t> arr(buffer.size(), L'-');
		inputTextFile.read(&arr[0], buffer.size());

		bool canContinue = false;

		for (auto e : arr)
			if (e != L'-') canContinue = true;

		if (!canContinue)
			break;

		buffer = std::wstring(arr.begin(), arr.end());

		// replace part

		//inputTextFile.getline(buffer, buffer.size());
		//etline(inputTextFile, buffer);

		outputTextFile << encrypt(magicSquare, buffer);

		if (inputTextFile.eof())
			break;
	}
	return 0; 
}
