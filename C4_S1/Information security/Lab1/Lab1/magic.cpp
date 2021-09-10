#include <array>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string encrypt(const std::vector<int>& magicSquare, const std::string& buffer)
{
	std::string result;

	for (auto e : magicSquare)
	{
		result.push_back(buffer[e - 1]);
	}

	return result;

}

int main()
{

	std::vector<int> magicSquare;

	std::ifstream inputMagicSquare("square.txt");

	int x{};
	while (inputMagicSquare >> x)
	{
		magicSquare.emplace_back(x);
	}
	inputMagicSquare.close();

	std::string buffer(magicSquare.size(), '-');
	std::cout << buffer << '\n';

	std::ifstream inputTextFile("input.txt");
	std::ofstream outputTextFile("output.txt");
	while (!inputTextFile.eof())
	{
		std::vector<char> arr(buffer.size(), '-');
		inputTextFile.read(&arr[0], buffer.size());

		bool canContinue = false;

		for (auto e : arr)
			if (e != '-') canContinue = true;

		if (!canContinue)
			break;

		buffer = std::string(arr.begin(), arr.end());

		// replace part

		//inputTextFile.getline(buffer, buffer.size());
		//etline(inputTextFile, buffer);

		outputTextFile << encrypt(magicSquare, buffer);

		if (inputTextFile.eof())
			break;
	}
	// replace part


	//std::cout << buffer;

	return 0;
}
