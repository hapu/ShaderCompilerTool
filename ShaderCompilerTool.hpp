#ifndef SHADER_COMPILER_TOOL_HPP
#define SHADER_COMPILER_TOOL_HPP

#include <SDL2/SDL.h>
#ifdef WIN32
#include <windows.h>
#endif
#include <GL/glew.h>
#include <GL/gl.h>
#include <fstream>
#include <iostream>

class ShaderCompilerTool {
 public:
  static void compile(const char *shader_path, GLenum shaderType);
};

#endif  // SHADER_COMPILER_TOOL_HPP
