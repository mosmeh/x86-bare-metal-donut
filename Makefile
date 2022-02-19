SRC_DIR := src

.PHONY: all clean run $(SRC_DIR)/donut

all: disk_image

disk_image: $(SRC_DIR)/donut
	cp '$<' iso/boot
	grub-mkrescue -o '$@' iso

$(SRC_DIR)/donut:
	@cd $(SRC_DIR) && $(MAKE) donut

clean:
	@cd $(SRC_DIR) && $(MAKE) $@
	rm -f iso/boot/donut disk_image

run: disk_image
	./run.sh
