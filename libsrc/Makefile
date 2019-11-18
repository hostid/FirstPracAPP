
DIRS  = libu8g2
CROSS = 

all:
	@for SubDir in $(DIRS); do \
		if ! [ -d $$SubDir ]; then \
			echo "The $$SubDir is not exist !"; \
			exit 11; \
		fi; \
		make CROSS=$(CROSS) DEBUG=1 -C $$SubDir ; \
		if [ $$? -ne 0 ]; then \
			echo "Building $$SubDir is failed !"; \
			exit 12; \
		fi; \
	done

clean:
	@for SubDir in $(DIRS); do \
		if ! [ -d $$SubDir ]; then \
			echo "The $$SubDir is not exist !"; \
			exit 11; \
		fi; \
		echo "Cleaning $$SubDir ..."; \
		make clean -C $$SubDir ; \
		if [ $$? -ne 0 ]; then \
			echo "Clean $$SubDir is failed !"; \
			exit 12; \
		fi; \
	done

	-@rm -fr ../lib.arm/*
