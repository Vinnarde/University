#include <codecvt>
#include <fstream>
#include <string>
#include <stdexcept>
#include <iostream>

constexpr int spinStep{3}; // вращение на 3 позиции после шифрования каждого символа

inline int mod(int a, int b)
{
	int ret = a % b;
	return ret >= 0 ? ret : ret + b;
}

int findCode(const std::wstring& alphabet, wchar_t ch)
{
	int returnCode{-1};

	for (std::size_t i = 0; i < alphabet.size(); ++i)
	{
		if (alphabet[i] == ch)
		{
			returnCode = i;
			break;
		}
	}

	return returnCode;
}

std::wstring encrypt(const std::wstring& outerDisk,
                     const std::wstring& innerDisk,
                     const std::wstring& text,
                     const int initialShift)
{
	std::wstring result;

	int shift{initialShift};

	for (const auto e : text)
	{
		int code = findCode(outerDisk, e);

		int innerIndex = mod(code + shift, outerDisk.size());

		result += innerDisk[innerIndex];

		shift += spinStep;
	}

	return result;
}

std::wstring decrypt(const std::wstring& outerDisk,
                     const std::wstring& innerDisk,
                     const std::wstring& text,
                     const int initialShift)
{
	std::wstring result;

	int shift{-initialShift};

	for (const auto e : text)
	{
		int code = findCode(outerDisk, e);
		int size = innerDisk.size();
		int innerIndex = mod(code + shift, outerDisk.size());

		result += innerDisk[innerIndex];

		shift -= spinStep;
	}

	return result;
}


int main(int argc, char* argv[])
{
	const auto locale = std::locale(std::locale(), new std::codecvt_utf8<wchar_t>());

	system("chcp 65001");
	system("cls");

	try
	{
		std::wstring outerDisk;
		std::wstring innerDisk;
		int initialShift{};

		std::wstring text;

		std::wifstream inputOuterDisk(L"outerDisk.txt");
		inputOuterDisk.imbue(locale);

		std::wclog.imbue(locale);

		if (inputOuterDisk.is_open())
		{
			std::getline(inputOuterDisk, outerDisk, L'\0');
			std::wclog << outerDisk << L'\n';
			std::wclog << L"Outer disk. Size: " << outerDisk.size() << L"\n\n";
		}
		else
		{
			throw std::runtime_error("Couldn't open outerDisk.txt\n");
		}

		std::wifstream inputInnerDisk(L"innerDisk.txt");
		inputInnerDisk.imbue(locale);
		if (inputInnerDisk.is_open())
		{
			inputInnerDisk >> initialShift;
			std::getline(inputInnerDisk, innerDisk, L'\0');

			std::wclog << L"Initial shift: " << initialShift << L'\n';
			std::wclog << innerDisk << L'\n';
			std::wclog << L"Inner disk. Size: " << innerDisk.size() << L"\n\n";
		}
		else
		{
			throw std::runtime_error("Couldn't open innerDisk.txt\n");
		}

		if (outerDisk.size() != innerDisk.size())
		{
			throw std::runtime_error("The size of the outer and inner drive do not match.");
		}

		std::wifstream inputText(L"input.txt");
		inputText.imbue(locale);
		if (inputText.is_open())
		{
			std::getline(inputText, text, L'\0');
			std::wclog << L"Initial text: " << text << L"\n\n";
		}
		else
		{
			throw std::runtime_error("Couldn't open input.txt\n");
		}

		//std::wstring result = encrypt(outerDisk, innerDisk, text, initialShift);
		std::wstring result = decrypt(outerDisk, innerDisk, text, initialShift);

		std::wclog << result << L'\n';

		std::wofstream outputText(L"output.txt");
		outputText.imbue(locale);

		outputText << result;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
