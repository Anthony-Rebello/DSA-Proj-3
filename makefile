main:
	g++ -c main.cpp TextureManager.cpp -IC:/API/SFML-2.5.1/include -DSFML_STATIC
	g++ *.o -o sfml-app -LC:/API/SFML-2.5.1/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lwinmm -lopengl32 -lgdi32 -lfreetype
	sfml-app
