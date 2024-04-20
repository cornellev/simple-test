# Copyright (C) 2024 Ethan Uppal. All rights reserved.

.PHONY: install
install:
	mkdir -p /usr/local/include/simple_test
	cp simple_test.h /usr/local/include/simple_test

.PHONY: uninstall
uninstall:
	rm -f /usr/local/include/simple_test.h
