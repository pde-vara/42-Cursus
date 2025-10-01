/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-vara <pde-vara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:23:07 by pde-vara          #+#    #+#             */
/*   Updated: 2025/06/04 12:18:30 by pde-vara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>

int	replace(char **argv, std::string& str)
{
	std::ofstream	outfile;
	size_t				pos;

	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (outfile.fail())
	{
		std::cerr << "Error: couldn't create output file" << std::endl;
		return 1;
	}
	for (size_t i = 0; i < str.size(); i++)
	{
		pos = str.find(argv[2], i);
		if (pos != std::string::npos && pos == i) // pos != std::string::npos => pos != -1
		{
			outfile << argv[3];
			i += std::string(argv[2]).size() - 1;
		}
		else
			outfile << str[i];
	}
	outfile.close();
	return (0);
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::string		str;

	if (argc != 4)
	{
		std::cout << "Usage: replace <file> old_word new_word" << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (!infile)
	{
		std::cerr << "Error opening file :" << argv[1] << std::endl;
		return (1);
	}
	std::ostringstream buffer;
	buffer << infile.rdbuf();
	str = buffer.str();
	
	infile.close();
	return (replace(argv, str));
}