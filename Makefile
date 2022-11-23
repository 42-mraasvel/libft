BUILD_DIR := target

build: $(BUILD_DIR)
	cmake --build $(BUILD_DIR)
$(BUILD_DIR):
	cmake -B $(BUILD_DIR) -S .
clean:
	$(RM) -r $(BUILD_DIR)

test: build
	$(BUILD_DIR)/test/test

.PHONY: build clean test
