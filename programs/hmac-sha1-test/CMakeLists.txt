add_executable(hmac-sha1-test hmac-sha1-test.c)
target_link_libraries(hmac-sha1-test polarssl)

install(TARGETS hmac-sha1-test
        DESTINATION "bin"
        PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE)
