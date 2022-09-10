bin/class_screen: cppfiles/setting_pixels.cpp headers/screen.h headers/content_screen.cpp
	g++ -Isrc/include -Lsrc/lib -Iheaders/ -o bin/settingpixel.exe cppfiles/setting_pixels.cpp headers/screen.h headers/content_screen.cpp -lmingw32 -lSDL2main -lSDL2
	./bin/settingpixel.exe
clean:
	del -fR bin


# make sure You set compiler flags are in the following order for the make file to work for SDL.
# The order is:
# -lmingw32
# -lSDL2main
# -lSDL2
# -lSDL2_image
# -lSDL2_ttf
# -lSDL2_mixer
# - any other additional library You wish to add
