include make_settings/src_files.mk

.PHONY: all
all: $(NAME)

# Creating the library
$(NAME): $(OBJ)
	@echo Creating: $@
	@$(LINK) $@ $^

# Object Files
$(OBJ): $(ODIR)/%.o: $(SDIR)/%.c Makefile
	@echo Compiling: $@
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $(IFLAGS) $< -o $@

# Header Dependency Rules
$(DEP): $(DDIR)/%.d: $(SDIR)/%.c
	@echo Creating Dependency: $@
	@mkdir -p $(@D)
	@$(CC) $< -MM -MF $@ -MT $(ODIR)/$*.o $(CFLAGS) $(IFLAGS)

-include $(DEP)

# Cleanup
.PHONY: clean fclean re
clean:
	$(RM) -r $(TDIR)
fclean: clean
	$(RM) $(NAME)
re: fclean
	$(MAKE) all
