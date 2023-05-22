LIB_PATH = /Users/matic/Projects/vulkan/engine/lib

CC = gcc
CFLAGS = -Wall -std=c99 -dynamiclib -o $(LIB_PATH)/libengine.dylib

#LDFLAGS= -I/opt/homebrew/include -L/opt/homebrew/lib/ -I/usr/local/include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

#LDFLAGS= -I/opt/homebrew/include -L/opt/homebrew/lib/ -I/usr/local/include  -lglfw.3.3 -framework Cocoa -framework OpenGL -framework IOKit

#LDFLAGS= -I./include -I/opt/homebrew/include -I/Users/matic/VulkanSDK/1.3.243.0/macOS/include -L/opt/homebrew/lib -L/Users/matic/VulkanSDK/1.3.243.0/macOS/lib -lglfw.3.3 -lvulkan.1 -lvulkan.1.3.243

LDFLAGS = -I./include

.PHONY: all
all: src/*.c
	$(CC) $(CFLAGS) $? $(LDFLAGS)