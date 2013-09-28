#include "XMLReader.h"

boost::property_tree::ptree XMLReader::getPTree(std::string xmlFileName)
{
	boost::property_tree::ptree pt;
	std::ifstream fin(xmlFileName);
	if(fin.is_open())
	{
		boost::property_tree::read_xml(fin, pt);
	}
	else
		std::cout << "could not load " << xmlFileName << std::endl;
	fin.close();
	return pt;
}
