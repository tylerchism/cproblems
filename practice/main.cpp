#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <math.h>

class Circle
{
private:
	float radius;
public:

	Circle(float r)
	{
		radius = r;
	}

	float circ()
	{
		return (radius * 2) * 3.14;	 
	}

	float area()
	{
		return (radius * radius) * 3.14;
	}

	~Circle() 
	{
		std::cout << "Circle destroyed" << std::endl;
	}
};

void function(float rad)
{
	Circle circle(rad);
	std::cout << circle.area() << std::endl;
	std::cout << circle.circ() << std::endl;
}

std::vector<int> stringpos(std::string word, char letter)
{
	std::vector<int> index = { -1, -1 };
	for (int i = 0; i < word.size(); i++)
	{ 
		if (word[i] == letter && index[0] == -1)
		{
			index[0] = i;
		}
		if (word[i] == letter)
		{
			index[1] = i;
		}
			
	}
	std::cout << "[" << index[0] << ", " << index[1] << "]" << std::endl;
	return index;
}

std::vector<std::vector<int>> convertcart(std::vector<int> x, std::vector<int> y)
{
	std::vector<std::vector<int>> carts;
	std::cout << "[";
	for (int i = 0; i < x.size(); i++)
	{
		carts.push_back({ x[i], y[i] });
		std::cout << "[" << carts[i][0] << ", " << carts[i][1];
		if (i < (x.size() - 1))
			std::cout << "], ";
		else std::cout << "]";
	}
	std::cout << "]";
	return carts;
}

void isintersecting(float a[3], float b[3])
{
	float distance = sqrt((b[1] - a[1]) * (b[1] - a[1]) + (b[2] - a[2]) * (b[2] - a[2]));
	if (distance > a[0] + b[0])
		std::cout << "Circles are not intersecting" << std::endl;
	else std::cout << "Cirlces are intersecting" << std::endl;

}

std::string texttonum(std::string text)
{
	for (int i = 0; i < text.length(); i++)
	{
		if (text[i] == 'A' || text[i] == 'B' || text[i] == 'C')
		{
			text[i] = '2';
		}
		else if (text[i] == 'D' || text[i] == 'E' || text[i] == 'F')
		{
			text[i] = '3';
		}
		else if (text[i] == 'G' || text[i] == 'H' || text[i] == 'I')
		{
			text[i] = '4';
		}
		else if (text[i] == 'J' || text[i] == 'K' || text[i] == 'L')
		{
			text[i] = '5';
		}
		else if (text[i] == 'M' || text[i] == 'N' || text[i] == 'O')
		{
			text[i] = '6';
		}
		else if (text[i] == 'P' || text[i] == 'Q' || text[i] == 'R' || text[i] == 'S')
		{
			text[i] = '7';
		}
		else if (text[i] == 'T' || text[i] == 'U' || text[i] == 'V')
		{
			text[i] = '8';
		}
		else if (text[i] == 'W' || text[i] == 'X' || text[i] == 'Y' || text[i] == 'Z')
		{
			text[i] = '9';
		}
		
	}
	std::cout << text << std::endl;
	return text;
}

int findOdd(const std::vector<int>& numbers) {

	for (int i = 0; i < numbers.size(); i++)
	{
		int x = 1;
		for (int j = 0; j < numbers.size(); j++)
		{
			if (numbers[i] == numbers[j])
				x = x + 1;
		}
		if (x % 2 == 0)
			return numbers[i];
	}

	
}

std::string encrypt(std::string text, int n)
{
	int l = text.size() / 2;
	for (int x = 0; x < n; x++)
	{
		std::string text2 = text;
		int j = 0;
		for (int i = 0; i < text.size(); i++)
		{
			int m = j + floor(l);
			if (i % 2 != 0)
			{
				text2[j] = text[i];
				j++;
			}
			else text2[m] = text[i];
		}
		text = text2;
	}
	return text;
}

std::string decrypt(std::string encryptedText, int n)
{
	for (int x = 0; x < n; x++)
	{
		std::string text2 = encryptedText;
		int i = 0;
		for (int j = 0; j < encryptedText.size(); j++)
		{
			if (j % 2 == 0)
			{
				text2[j] = encryptedText[i + floor(encryptedText.size() / 2)];
			}
			else {
				text2[j] = encryptedText[i];
				i++;
			}
		}
		encryptedText = text2;
	}

	return encryptedText;
}

int main()
{
	std::string message = encrypt("This is a test!", 1);
	
	std::cout << message << std::endl;

	std::cin.get();
}