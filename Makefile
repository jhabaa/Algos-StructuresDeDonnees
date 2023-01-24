.PHONY: clean All

All:
	@echo "----------Building project:[ Graph - Debug ]----------"
	@cd "5IN0301\exercices\Graph" && "$(MAKE)" -f  "Graph.mk"
clean:
	@echo "----------Cleaning project:[ Graph - Debug ]----------"
	@cd "5IN0301\exercices\Graph" && "$(MAKE)" -f  "Graph.mk" clean
