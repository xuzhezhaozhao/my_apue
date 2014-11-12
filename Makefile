V ?= @

SRCFILES = $(wildcard *.c) 
DEPFILES = $(SRCFILES:%.c=obj/%.d)
OBJFILES = $(SRCFILES:%.c=obj/%.o)

TARGETS = $(SRCFILES:%.c=%)

.PHONY: all clean
	
all: $(TARGETS)

obj:
	$Vmkdir $@

CCFLAGS = -Wall -D_GNU_SOURCE
CC = gcc

-include $(DEPFILES)

obj/%.o : %.c | obj
	$V$(CC) -O3 $(CCFLAGS) -c -o $(@) -MMD -MP $(<)

# 指明目标从$(TARGETS)中获取
$(TARGETS): % : obj/%.o
	@echo linking $(@)
	$V$(CC) $(CCFLAGS) -o $@ $<

clean:
	@rm -rf $(TARGETS) obj/
