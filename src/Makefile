CC      := g++
INCS    := -I ../include

TARGETS := timer
OBJ     := main.o

.PHONY: all clean

all: $(TARGETS)

clean:
	rm -f $(OBJ)

$(OBJ): %.o : %.cpp
	$(CC) -c $< -o $@ $(INCS)

$(TARGETS): $(OBJ)
	$(CC) $^ -o $@ $(INCS)
