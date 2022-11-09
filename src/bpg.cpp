#include "bpg.h"

#include <fstream>
#include <vector>
#include <string>

// (char)9 is a tab character
#define SINGLE_INDENT (char)9
#define DOUBLE_INDENT (char)9 << (char)9

namespace bpg
{
	void menu()
	{
	}

	void generateProjectFolder()
	{
	}

	namespace cpp
	{
		void generateMain(std::vector<std::string> dependencies)
		{
			std::ofstream mainCpp("main.cpp");
		}

		void generateClass(std::string className, std::string nameSpace)
		{
			std::vector<std::ofstream> outFiles;
			outFiles.emplace_back(className + ".cpp");
			outFiles.emplace_back(className + ".h");

			// cpp file
			outFiles[0] << "#include \"test.h\"\n\n";

			if (!nameSpace.empty())
			{
				for (std::ofstream &out : outFiles)
				{
					out << "namespace " << nameSpace << "\n"
						<< "{\n"
						<< SINGLE_INDENT;
				}
			}

			// cpp file
			outFiles[0] << "class " << className << "\n"
						<< SINGLE_INDENT << "{\n"
						<< DOUBLE_INDENT << className << "();\n"
						<< DOUBLE_INDENT << "~" << className << "();\n"
						<< SINGLE_INDENT << "};\n";

			// header file
			outFiles[1] << className << "::" << className << "()\n"
						<< SINGLE_INDENT << "{\n"
						<< SINGLE_INDENT << "}\n\n"
						<< SINGLE_INDENT << className << "::~" << className << "()\n"
						<< SINGLE_INDENT << "{\n"
						<< SINGLE_INDENT << "}\n";

			if (!nameSpace.empty())
			{
				for (std::ofstream &out : outFiles)
				{
					out << "}\n";
				}
			}
		}
	}
}
