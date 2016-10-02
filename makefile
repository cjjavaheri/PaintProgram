all: main doxygen

.PHONY: clean

SRCFILES = Callbacks.cpp Callbacks.h Graphics.cpp Graphics.h main.cpp Rectangle.cpp Rectangle.h Shape.cpp Shape.h FilledRectangle.h FilledRectangle.cpp Ellipse.h Ellipse.cpp FilledEllipse.h FilledEllipse.cpp Line.h Line.cpp

main: $(SRCFILES)
	@echo making main
	g++ $(SRCFILES) -o main -lglut -lGL -lGLU -lm -Wall

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

doxygen: doxy_config $(SRCFILES)
	@echo making doxygen
	@doxygen doxy_config >/dev/null 2>&1
	@echo made doxygen successfully

doxygen_warnings: doxy_config $(SRCFILES)
	doxygen doxy_config

clean:
	rm main
	rm -rf doxygen

.DEFAULT:
	@echo "I dont know how to make that!"
	@echo "¯\\(°_o)/¯"
