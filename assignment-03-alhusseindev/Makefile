TASKS:=$(subst /,,$(dir $(wildcard task-*/)))

all: $(TASKS)

$(TASKS):
	@echo ---------- Running $@ ----------
	@$(MAKE) --no-print-directory -C $@ test
	-@$(MAKE) --no-print-directory -s -C $@ clean
	@echo ""

.PHONY: $(TASKS)
