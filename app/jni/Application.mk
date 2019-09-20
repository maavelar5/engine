
# Uncomment this if you're using STL in your project
# See CPLUSPLUS-SUPPORT.html in the NDK documentation for more information
APP_STL := c++_shared

APP_ABI := x86

# Min runtime API level
APP_PLATFORM=android-22
APP_CFLAGS += -DPNG_ARM_NEON_OPT=0