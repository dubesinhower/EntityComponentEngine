#pragma once
#include <iostream>
#include <boost\property_tree\ptree.hpp>
#include <boost\property_tree\xml_parser.hpp>

class XMLReader
{
public:
	boost::property_tree::ptree getPTree(std::string xmlFileName);
};

