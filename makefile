BUILD_NAME = sct
LINUX_LIBS = -lSDL2main -lSDL2 -lGL -lGLEW
SOURCE_FILES = main.cpp ShaderCompilerTool.cpp

linux: clean
	mkdir linux
	g++ $(SOURCE_FILES) -o linux/$(BUILD_NAME) $(LINUX_LIBS)

clean:
	rm -rf linux/
