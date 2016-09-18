all: doxygen main

.PHONY: clean

SRCFILES = callbacks.cpp  callbacks.h  graphics.cpp  graphics.h  main.cpp rectangle.cpp rectangle.h shape.cpp shape.h FilledRectangle.h FilledRectangle.cpp

main: $(SRCFILES)
	@echo making main
	g++ $(SRCFILES) -o main -lglut -lGL -lGLU -lm

	@echo "    _    _    "
	@echo "   (o)--(o)   "
	@echo "  /.______.\\  "
	@echo "  \\________/  "
	@echo " ./        \\. "
	@echo "( .        , )"
	@echo " \\ \\_\\\\//_/ / "
	@echo "  ~~  ~~  ~~  "
	@echo "ASCII frog for to eat all the bugs"
	@echo made main

doxygen: doxy_config
	@echo making doxygen
	@doxygen doxy_config >/dev/null 2>&1
	@echo made doxygen successfully

clean:
	rm main
	rm -rf doxygen

.DEFAULT:
	@echo "I dont know how to make that!"
	@echo "¯\\(°_o)/¯"
