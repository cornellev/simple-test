# simple-test

After cloning, run `sudo make install` to install the header.
You can run `sudo make uninstall` to remove it later.

## Usage

1. Add the following lines to your Makefile:

	```make
	.PHONY: test
	test: test.c $(OBJ)
		@$(CC) $(CFLAGS) -DTEST -o _temp $^
		@echo 'Running tests...'
		@./_temp
		@rm -f ./_temp
	```

	Modify the target name (`test`) and testing source file (`test.c`), as well as the other values, as appropriate.

2. `#include` the header `simple_test.h`. 
	Surround with `extern "C" { ... }` if using C++.

3. In your testing source file, define a function `void test_main(void)` from which you call all your test functions or invoke other subroutines to call them.

## Testing

You can use the following testing functions.

| Testing Function | Notes
| --- | --- |
| `assert_equal(a, b)` | requires that `a` and `b` are primitive-comparable.
`assert_true(x)` | requires that `x` is boolean-like.
`assert_false(x)` | requires that `x` is boolean-like.
