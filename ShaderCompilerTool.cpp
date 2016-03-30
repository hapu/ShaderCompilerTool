#include "ShaderCompilerTool.hpp"

using namespace std;

void ShaderCompilerTool::compile(const char *shader_path, GLenum shaderType) {
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window *window =
      SDL_CreateWindow("practice3", 100, 100, 300, 300, SDL_WINDOW_OPENGL);
  SDL_GLContext context = SDL_GL_CreateContext(window);
  glewInit();

  unsigned int test_shader = glCreateShader(shaderType);
  {
    ifstream _file(shader_path, ios::binary);
    if(!_file.is_open())
    {
        char error_message[200];
        sprintf(error_message, "Error: No such file named: %s\r\n", shader_path);
        throw error_message;
    }
    _file.seekg(0, _file.end);
    int len = _file.tellg();
    len++;
    _file.seekg(0, _file.beg);
    char *buffer = new char[len];
    _file.read(buffer, len);
    buffer[len - 1] = 0x00;
    glShaderSource(test_shader, 1, (const char **)&buffer, 0);
    _file.close();
    delete[] buffer;
  }
  glCompileShader(test_shader);
  GLint isCompiled = 0;
  glGetShaderiv(test_shader, GL_COMPILE_STATUS, &isCompiled);
  if (isCompiled == GL_FALSE) {
    GLint maxLength = 0;
    glGetShaderiv(test_shader, GL_INFO_LOG_LENGTH, &maxLength);
    char *error = new char[maxLength];
    glGetShaderInfoLog(test_shader, maxLength, &maxLength, error);
    cout << error << endl;
    delete[] error;
  }
  if (window) SDL_DestroyWindow(window);
  if (context) SDL_GL_DeleteContext(context);
  SDL_Quit();
}
