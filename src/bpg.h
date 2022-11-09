#include <vector>
#include <string>

namespace bpg
{
	void menu();

	void generateProjectFolder();

	namespace cpp
	{
		void generateMain(std::vector<std::string> dependencies = {});
		void generateClass(std::string className, std::string nameSpace = "");
	}
}