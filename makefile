#Directorios
OBJ_DIR=obj
BIN_DIR=bin
SRC_DIR=src

#Archivos
FILES = main fuerza_bruta algoritmo_inc algoritmo_inc_v2 algoritmo_bresenham keys dibujar lineas_aleatorias
OBJECTS=$(patsubst %, $(OBJ_DIR)/%.o, $(FILES))
OUTPUT=$(BIN_DIR)/main

######
CFLAGS=-I/usr/local/Mesa-3.4/include
LDLIBS=-lX11 -lglut -lGLU -lGL -lm -lXext -lXmu
LDFLAGS=-L/usr/local/Mesa-3.4/lib -L/usr/X11R6/lib

######
$(OUTPUT): $(OBJECTS)
	mkdir -p bin
	gcc $(OBJECTS) $(CFLAGS) $(LDFLAGS) $(LDLIBS) -o $(OUTPUT)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p obj
	gcc -g -c -MMD $< -o $@

-include $(OBJ_DIR)/*.d

run: $(OUTPUT)
	./$(OUTPUT) $(r) $(l) $(v)

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)
