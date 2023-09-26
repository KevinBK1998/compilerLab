GPP = g++
LDFLAGS = -lGL -lGLEW -lglfw3 -lX11 -lpthread -ldl

app : Application.cpp
	$(CXX) $? -DGLEW_STATIC $(LDFLAGS) $(OUTPUT_OPTION)
execute : app
	./$<	