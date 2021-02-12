#include <iostream>
#include <string>
#include <cctype>
#include <vector>

struct table
{
	uint16_t id;
	std::string identifier;
	std::string type;
};

int main()
{
	std::string str;
	std::getline(std::cin, str);

	std::cout << str << std::endl;

	std::string buffer;
	auto is_var(false), is_op(false), is_number(false);

	//std::vector<table> 

	// abc  = asd*xy + x   / 2
	// 15 = 3*3 + 6

	int cnt = str.length();

	for (auto x : str)
	{
		cnt--;
		if (isspace(x))
		{
			if (!buffer.empty())
			{
				std::cout << buffer << std::endl;
				buffer = "";
			}
			is_op = is_number = is_var = false;
		}
		else if (isalpha(x))
		{
			if (!buffer.empty() && !is_var)
			{
				std::cout << buffer << std::endl;
				buffer = "";
			}

			buffer += x;
			is_var = true;
			is_op = is_number = false;
		}
		else if (isdigit(x))
		{
			if (!buffer.empty() && !is_number)
			{
				std::cout << buffer << std::endl;
				buffer = "";
			}

			buffer += x;
			is_number = true;
			is_op = is_var = false;
		}
		
		else
		{
			std::vector<char> ops = { '-','+','=','*','/','^' };

			if (!buffer.empty())
			{
				std::cout << buffer << std::endl;
				buffer = "";
			}

			for (auto c : ops)
			{
				if (x == c)
				{
					buffer += x;
					break;
				}
			}

			std::cout << buffer << std::endl;
			buffer = "";

			is_op = true;
			is_number = is_var = false;
		}

		if (cnt == 0)
		{
			std::cout << buffer << std::endl;
		}
	}

	return 0;
}
