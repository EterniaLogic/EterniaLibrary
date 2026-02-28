################### PACKAGING ###################





# Packaging
if(WIN32)
    set(CPACK_GENERATOR "NSIS;ZIP")
else()
    set(CPACK_GENERATOR "TGZ;DEB")
endif()

SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "EterniaLogic") #required
set(CPACK_DEBIAN_PACKAGE_NAME "libEternia")

set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "Low-end support library, which includes basic algorithms and data structures.")
#set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE ${PKG_ARCH})
#set(CPACK_DEBIAN_FILE_NAME "libeternia_${CPACK_PACKAGE_VERSION}_${PKG_ARCH}.deb")

set(CPACK_DEB_COMPONENT_INSTALL ON)

# 64-bit packaging
set(CPACK_DEBIAN_RUNTIME64_PACKAGE_NAME "libeternia")
set(CPACK_DEBIAN_RUNTIME64_PACKAGE_ARCHITECTURE "amd64")
#set(CPACK_DEBIAN_FILE_NAME "libeternia.deb")

# Configuration for the 32-bit package
set(CPACK_DEBIAN_RUNTIME32_PACKAGE_NAME "libeternia-i386")
set(CPACK_DEBIAN_RUNTIME32_PACKAGE_ARCHITECTURE "i386")
#set(CPACK_DEBIAN_FILE_NAME "libeternia_i386.deb")

set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/postinst"
    "${CMAKE_CURRENT_SOURCE_DIR}/debian/postrm"
)

#set(CPACK_RPM_PACKAGE_NAME "libEternia")
#set(CPACK_RPM_PACKAGE_DESCRIPTION "Low-end support library, which includes basic algorithms and data structures.")
INCLUDE(CPack)
