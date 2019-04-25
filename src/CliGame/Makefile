CC=g++
CFLAGS=
SRCDIR = ../                                                  
OBJDIR = build/obj
BUILDDIR = build

STRUCTURE := $(shell find $(SRCDIR) -type d)     
CODEFILES := $(addsuffix /*,$(STRUCTURE))
CODEFILES := $(wildcard $(CODEFILES)) 

# Filter Only Specific Files                                
SRCFILES := $(filter %.cpp,$(CODEFILES))
HDRFILES := $(filter %.h,$(CODEFILES))
OBJFILES := $(subst $(SRCDIR),$(OBJDIR),$(SRCFILES:%.c=%.o))

compile: $(OBJFILES)

$(OBJDIR)/%.o: $(addprefix $(SRCDIR)/,%.cpp %.h)
    $(CC) -c $< -o $@ $(CFLAGS) 


