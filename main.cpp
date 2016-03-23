
#include "ShaderCompilerTool.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    try
    {
        if (argc < 3) {
            return 1;
        }
        if (strcmp("fragment", argv[2]) == 0) {
            ShaderCompilerTool::compile(argv[1], GL_FRAGMENT_SHADER);
        }
        if (strcmp("vertex", argv[2]) == 0) {
            ShaderCompilerTool::compile(argv[1], GL_VERTEX_SHADER);
        }
        return 0;
  }
  catch(const char *err)
  {
      std::cout << err << std::endl;
  }
}
