bin_PROGRAMS = coredoc
coredoc_SOURCES = main.c coredoc.c markdown.c utils.c coredoc.h markdown.h utils.h
coredoc_CFLAGS = -Wall $(LOWDOWN_CFLAGS)
coredoc_LDADD = $(LOWDOWN_LIBS)

clean-local:
	@rm config.status configure config.log
	@rm Makefile
	@rm aclocal.m4
	@rm compile install-sh missing Makefile.in
