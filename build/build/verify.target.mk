# This file is generated by gyp; do not edit.

TOOLSET := target
TARGET := verify
DEFS_Debug := \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION' \
	'-DDEBUG' \
	'-D_DEBUG'

# Flags passed to all source files.
CFLAGS_Debug := \
	-Wall \
	-pthread \
	-m32 \
	-g \
	-O0

# Flags passed to only C files.
CFLAGS_C_Debug :=

# Flags passed to only C++ files.
CFLAGS_CC_Debug := \
	-fno-rtti \
	-fno-exceptions

INCS_Debug := \
	-I/root/.node-gyp/0.8.15/src \
	-I/root/.node-gyp/0.8.15/deps/uv/include \
	-I/root/.node-gyp/0.8.15/deps/v8/include

DEFS_Release := \
	'-D_LARGEFILE_SOURCE' \
	'-D_FILE_OFFSET_BITS=64' \
	'-DBUILDING_NODE_EXTENSION'

# Flags passed to all source files.
CFLAGS_Release := \
	-Wall \
	-pthread \
	-m32 \
	-O2 \
	-fno-strict-aliasing \
	-fno-tree-vrp \
	-fno-tree-sink

# Flags passed to only C files.
CFLAGS_C_Release :=

# Flags passed to only C++ files.
CFLAGS_CC_Release := \
	-fno-rtti \
	-fno-exceptions

INCS_Release := \
	-I/root/.node-gyp/0.8.15/src \
	-I/root/.node-gyp/0.8.15/deps/uv/include \
	-I/root/.node-gyp/0.8.15/deps/v8/include

OBJS := \
	$(obj).target/$(TARGET)/addon/verify.o \
	$(obj).target/$(TARGET)/addon/SimpleVerify.o \
	$(obj).target/$(TARGET)/addon/SimpleFilter.o

# Add to the list of files we specially track dependencies for.
all_deps += $(OBJS)

# CFLAGS et al overrides must be target-local.
# See "Target-specific Variable Values" in the GNU Make manual.
$(OBJS): TOOLSET := $(TOOLSET)
$(OBJS): GYP_CFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_C_$(BUILDTYPE))
$(OBJS): GYP_CXXFLAGS := $(DEFS_$(BUILDTYPE)) $(INCS_$(BUILDTYPE))  $(CFLAGS_$(BUILDTYPE)) $(CFLAGS_CC_$(BUILDTYPE))

# Suffix rules, putting all outputs into $(obj).

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(srcdir)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# Try building from generated source, too.

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj).$(TOOLSET)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

$(obj).$(TOOLSET)/$(TARGET)/%.o: $(obj)/%.cc FORCE_DO_CMD
	@$(call do_cmd,cxx,1)

# End of this set of suffix rules
### Rules for final target.
LDFLAGS_Debug := \
	-pthread \
	-rdynamic \
	-m32

LDFLAGS_Release := \
	-pthread \
	-rdynamic \
	-m32

LIBS :=

$(obj).target/verify.node: GYP_LDFLAGS := $(LDFLAGS_$(BUILDTYPE))
$(obj).target/verify.node: LIBS := $(LIBS)
$(obj).target/verify.node: TOOLSET := $(TOOLSET)
$(obj).target/verify.node: $(OBJS) FORCE_DO_CMD
	$(call do_cmd,solink_module)

all_deps += $(obj).target/verify.node
# Add target alias
.PHONY: verify
verify: $(builddir)/verify.node

# Copy this to the executable output path.
$(builddir)/verify.node: TOOLSET := $(TOOLSET)
$(builddir)/verify.node: $(obj).target/verify.node FORCE_DO_CMD
	$(call do_cmd,copy)

all_deps += $(builddir)/verify.node
# Short alias for building this executable.
.PHONY: verify.node
verify.node: $(obj).target/verify.node $(builddir)/verify.node

# Add executable to "all" target.
.PHONY: all
all: $(builddir)/verify.node

