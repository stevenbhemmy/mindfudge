.PHONY: build-configs
build-configs:
	cmake --preset=default -B build 

.PHONY: build-debug-configs
build-debug-configs: install-deps
	cmake --preset=default -B build -DCMAKE_BUILD_TYPE=Debug

.PHONY: build
build: build-configs
	cmake --preset=default --build build --clean-first

.PHONY: build-debug
build-debug: build-debug-configs
	cmake --preset=default --build build --clean-first

.PHONY: clean
clean:
	rm -rf build

.PHONY: format
format:
	find . -regex '.*\.\(cpp\|hpp\|cu\|cuh\|c\|h\)' -exec clang-format -style=file -i {} \;
