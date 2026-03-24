#pragma once

#include "ThemeAnimation.h"
#include "ThemeData.h"
#include "ThemeVariables.h"
#include <pugixml/src/pugixml.hpp>
#include <unordered_map>
#include <vector>

class ThemeStoryboard
{
public:
	ThemeStoryboard()
	{
		repeatAt = 0;
		repeat = 1;
	}

	ThemeStoryboard(const ThemeStoryboard& src);

	~ThemeStoryboard();

	std::string eventName;
	int repeat; // 0 = forever
	int repeatAt;

	std::vector<ThemeAnimation*> animations;

	bool fromXmlNode(const pugi::xml_node& root, const std::unordered_map<std::string, ThemeData::ElementPropertyType>& typeMap, const std::string& relativePath, const ThemeVariables& variables);
};
